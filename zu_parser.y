%{
// $Id: zu_parser.y,v 1.22 2016/05/20 05:24:07 ist179042 Exp $
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <cdk/compiler.h>
#include "ast/all.h"
#define LINE       compiler->scanner()->lineno()
#define yylex()    compiler->scanner()->scan()
#define yyerror(s) compiler->scanner()->error(s)
#define YYPARSE_PARAM_TYPE std::shared_ptr<cdk::compiler>
#define YYPARSE_PARAM      compiler
//-- don't change *any* of these --- END!
%}

%union {
  int                   i;	/* integer value */
  std::string          *s;	/* symbol name or string literal */
  cdk::basic_node      *node;	/* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  zu::lvalue_node  *lvalue;
  basic_type *type;
  zu::function_call_node *fcall;
  double d;
  zu::for_node *forn;

};

%token <i> tINTEGER
%token <s> tIDENTIFIER tSTRING
%token <d> tDOUBLE
%token tPRINT tREAD tRETURN tBREAK tCONTINUE tPRINTLN tGE tLE tEQ tNE

%nonassoc tIFX
%nonassoc ':'

%right '='
%left '&' '|'
%left tGE tLE tEQ tNE '>' '<'
%left '+' '-'
%left '*' '/' '%'
// FIXME '?'
// FIXME '?'
%nonassoc tUNARY '~'

%type <node> function intruction declaration condition variable
%type <sequence> variables body declarations block intructions expressions
%type <expression> expr literal
%type <lvalue> lval
%type <type> type
%type <fcall> fun_call
%type <forn> iteration

%{
//-- The rules below will be included in yyparse, the main parsing function.
%}
%%

file : declarations   { compiler->ast($1); }
     |                { compiler->ast(new cdk::nil_node(LINE));}
     ;

declarations : declarations declaration  { $$ = new cdk::sequence_node(LINE,$2,$1); }
             | declaration               { $$ = new cdk::sequence_node(LINE,$1); }
             ;

declaration : variable ';'   { $$ = $1; }
            | function       { $$ = $1; }
            ;

function    : type tIDENTIFIER '!' '(' variables ')' '='  literal body  { $$ = new zu::function_def_node(LINE,$2,$5,$1,$9,true,$8); }
            | type tIDENTIFIER '(' variables ')'                        { $$ = new zu::function_dec_node(LINE,$2,$4,$1,true); }
            | type tIDENTIFIER '!' '('')' '=' literal  body             { $$ = new zu::function_def_node(LINE,$2,nullptr,$1,$8,true,$7); }
            | '!' tIDENTIFIER '!' '(' variables ')''=' literal  body    { $$ = new zu::function_def_node(LINE,$2,$5,nullptr,$9,true,$8); } //FIXME: Need to add other function nodes
            | '!' tIDENTIFIER '(' variables ')'                         { $$ = new zu::function_dec_node(LINE,$2,$4,nullptr,false);}
            | '!' tIDENTIFIER '!' '('')' '=' literal  body              {  $$ = new zu::function_def_node(LINE,$2,nullptr,nullptr,$8,true,$7);  }
            ;

body : block            {  $$ = $1 ;  }
     ;

block : '{' declarations intructions '}'      { $$ = new cdk::sequence_node(LINE,$2,$3);}
      | '{' declarations '}'                  { $$ = new cdk::sequence_node(LINE,$2); }
      | '{' intructions '}'                   { $$ = new cdk::sequence_node(LINE,$2); }
      | '{' '}'                               { $$ = new cdk::sequence_node(LINE,nullptr); }
      ;

type : '#'           { $$ = new basic_type(4, basic_type::TYPE_INT);}
     | '%'           { $$ = new basic_type(8, basic_type::TYPE_DOUBLE);}
     | '$'           { $$ = new basic_type(1, basic_type::TYPE_STRING);}
     | '<' type '>'  { $$ = new basic_type(4, basic_type::TYPE_POINTER); $$->_subtype = $2; }
     ;

expr : literal		         { $$ = $1; }
     | '-' expr %prec tUNARY     { $$ = new cdk::neg_node(LINE, $2); }
     | '~'  expr                 { $$ = new zu::not_node(LINE,$2); }
     | '+' expr %prec tUNARY     { $$ = new zu::id_node(LINE,$2); }
     | expr '+' expr	         { $$ = new cdk::add_node(LINE, $1, $3); }
     | expr '-' expr	         { $$ = new cdk::sub_node(LINE, $1, $3); }
     | expr '*' expr	         { $$ = new cdk::mul_node(LINE, $1, $3); }
     | expr '/' expr	         { $$ = new cdk::div_node(LINE, $1, $3); }
     | expr '%' expr	         { $$ = new cdk::mod_node(LINE, $1, $3); }
     | expr '<' expr	         { $$ = new cdk::lt_node(LINE, $1, $3); }
     | expr '>' expr	         { $$ = new cdk::gt_node(LINE, $1, $3); }
     | expr tGE expr	         { $$ = new cdk::ge_node(LINE, $1, $3); }
     | expr tLE expr             { $$ = new cdk::le_node(LINE, $1, $3); }
     | expr tNE expr	         { $$ = new cdk::ne_node(LINE, $1, $3); }
     | expr tEQ expr	         { $$ = new cdk::eq_node(LINE, $1, $3); }
     | expr '&' expr             { $$ = new zu::and_node(LINE,$1,$3); }
     | expr '|' expr             { $$ = new zu::or_node(LINE,$1,$3); }
     | '(' expr ')'              { $$ = $2; }
     | '[' expr ']'              { $$ = new zu::malloc_node(LINE, $2); }
     | lval                      { $$ = new zu::rvalue_node(LINE, $1); }  //FIXME
     | lval '=' expr             { $$ = new zu::assignment_node(LINE, $1, $3); }
     | lval '?'	%prec tUNARY     { $$ = new zu::pos_node(LINE,$1); }
     | '@'                       { $$ = new zu::read_node(LINE); }
     | fun_call                  { $$ = $1; }
     ;

expressions : expressions ',' expr   { $$ = new cdk::sequence_node(LINE,$3,$1); }
            | expr                   { $$ = new cdk::sequence_node(LINE,$1); }
            ;

fun_call : tIDENTIFIER '(' expressions ')'     { $$ = new zu::function_call_node(LINE,$1,$3); }
         | tIDENTIFIER '(' ')'                 { $$ = new zu::function_call_node(LINE,$1,nullptr); }
         ;

intructions : intruction               { $$ = new cdk::sequence_node(LINE,$1); }
            | intructions intruction   { $$ = new cdk::sequence_node(LINE,$2,$1); }
            ;

intruction : expr ';'            { $$ = new zu::evaluation_node(LINE,$1); }
           | expr '!'            { $$ = new zu::print_node(LINE,$1); }
           | expr tPRINTLN       { $$ = new zu::println_node(LINE,$1); }
           | tBREAK              { $$ = new zu::break_node(LINE); }
           | tCONTINUE           { $$ = new zu::continue_node(LINE); }
           | tRETURN             { $$ = new zu::return_node(LINE); }
           | condition           { $$ = $1; }
           | iteration           { $$ = $1; }
           | block               { $$ = $1; }
           ;

variables : variable                { $$ = new cdk::sequence_node(LINE,$1); }
          | variable ',' variables  { $$ = new cdk::sequence_node(LINE, $1,$3); }
          ;

variable : type tIDENTIFIER '!' '=' expr    { $$ = new zu::variable_def_node(LINE,$2,$1,$5,true); }
         | type tIDENTIFIER '=' expr        { $$ = new zu::variable_def_node(LINE,$2,$1,$4,false); }
         | type tIDENTIFIER '!'             { $$ = new zu::variable_dec_node(LINE,$2,$1,true); }
         | type tIDENTIFIER '?'             { $$ = new zu::variable_dec_node(LINE,$2,$1,false); }
         | type tIDENTIFIER                 { $$ = new zu::variable_dec_node(LINE,$2,$1,false); }
         ;

iteration : '[' variables ';' expressions ';' expressions ']' intruction      {  $$ = new zu::for_node(LINE, $2, $4, $6, $8 ); }
          | '[' expressions ';' expressions ';' expressions ']' intruction    {  $$ = new zu::for_node(LINE, $2, $4, $6, $8 ); }
          | '['  ';' expressions ';' ']' intruction    {  $$ = new zu::for_node(LINE, nullptr, $3, nullptr, $6 ); }
          ;

condition : '[' expr ']' '#' intruction                 { $$ = new zu::if_node(LINE,$2,$5); }
          | '[' expr ']' '?' intruction  %prec tIFX     { $$ = new zu::if_node(LINE,$2,$5); }
          | '[' expr ']' '?' intruction ':' intruction  { $$ = new zu::if_else_node(LINE,$2,$5,$7); }
          ;


lval :  tIDENTIFIER             { $$ = new zu::variable_node(LINE, $1); }
     |  lval '[' expr ']'       { $$ = new zu::index_node(LINE,$1,$3); }
     ;

literal : tINTEGER	{ $$ = new cdk::integer_node(LINE, $1); }
        | tDOUBLE	{ $$ = new cdk::double_node(LINE, $1); }
        | tSTRING	{ $$ = new cdk::string_node(LINE, $1); }
        ;

%%
