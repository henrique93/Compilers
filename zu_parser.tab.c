/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20150711

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "zu_parser.y"
/* $Id: zu_parser.y,v 1.22 2016/05/20 05:24:07 ist179042 Exp $*/
/*-- don't change *any* of these: if you do, you'll break the compiler.*/
#include <cdk/compiler.h>
#include "ast/all.h"
#define LINE       compiler->scanner()->lineno()
#define yylex()    compiler->scanner()->scan()
#define yyerror(s) compiler->scanner()->error(s)
#define YYPARSE_PARAM_TYPE std::shared_ptr<cdk::compiler>
#define YYPARSE_PARAM      compiler
/*-- don't change *any* of these --- END!*/
#line 14 "zu_parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
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

} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 54 "zu_parser.y"
/*-- The rules below will be included in yyparse, the main parsing function.*/
#line 55 "zu_parser.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define tINTEGER 257
#define tIDENTIFIER 258
#define tSTRING 259
#define tDOUBLE 260
#define tPRINT 261
#define tREAD 262
#define tRETURN 263
#define tBREAK 264
#define tCONTINUE 265
#define tPRINTLN 266
#define tGE 267
#define tLE 268
#define tEQ 269
#define tNE 270
#define tIFX 271
#define tUNARY 272
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    8,    8,    3,    3,    1,    1,    1,    1,
    1,    1,    7,    9,    9,    9,    9,   15,   15,   15,
   15,   12,   12,   12,   12,   12,   12,   12,   12,   12,
   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,
   12,   12,   12,   12,   12,   11,   11,   16,   16,   10,
   10,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    6,    6,    5,    5,    5,    5,    5,   17,   17,   17,
    4,    4,    4,   14,   14,   13,   13,   13,
};
static const YYINT yylen[] = {                            2,
    1,    0,    2,    1,    2,    1,    9,    5,    8,    9,
    5,    8,    1,    4,    3,    3,    2,    1,    1,    1,
    3,    1,    2,    2,    2,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    1,    3,    2,    1,    1,    3,    1,    4,    3,    1,
    2,    2,    2,    2,    1,    1,    1,    1,    1,    1,
    1,    3,    5,    4,    3,    3,    2,    8,    8,    6,
    5,    5,    7,    1,    4,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,   19,    0,   18,   20,    0,    6,    4,    0,    0,
    0,    0,    0,    5,    3,    0,   21,    0,    0,    0,
    0,    0,   66,    0,    0,    0,    0,   76,    0,   78,
   77,    0,    0,    0,    0,    0,   44,    0,   22,    0,
   45,    0,    0,    0,    0,    0,    0,   11,    0,    0,
   25,   23,   24,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   43,    0,    0,    0,    8,    0,    0,   62,    0,   49,
    0,    0,   39,   40,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   28,   29,   30,    0,    0,    0,
    0,    0,    0,   48,    0,   75,    0,    0,    0,   12,
   13,    0,    0,    9,    0,   57,   55,   56,   17,    0,
   50,   58,    0,   60,    0,    0,   59,   10,    7,    0,
    0,    0,    0,   15,    0,   16,   51,   54,   52,   53,
    0,    0,    0,    0,   14,    0,    0,    0,    0,    0,
    0,    0,    0,   71,    0,   70,    0,    0,    0,    0,
    0,   73,   68,   69,
};
static const YYINT yydgoto[] = {                          6,
    7,  121,    8,  122,   25,   26,  110,   10,  124,  125,
   81,  126,   39,   40,   27,   41,  127,
};
static const YYINT yysindex[] = {                       185,
  229,    0, -256,    0,    0,    0,    0,    0,  -56,  185,
 -243,  -30,  -17,    0,    0,   17,    0,  -16,  229,  706,
   13,  229,    0,   75,   10,   18, -193,    0,   47,    0,
    0,  706,  706,  706,  706,  706,    0,  414,    0,  -43,
    0,  706,  277,   58,   52,   78,  229,    0,   84,  654,
    0,    0,    0,  201,  279,  706,  706,  706,  706,  706,
  706,  706,  706,  706,  706,  706,  706,  706,  706,  706,
    0,  414,   60,   98,    0,   86,   87,    0,   94,    0,
  133,  414,    0,    0,  305,  305,  305,  305,  403,  403,
  305,  305,  273,  273,    0,    0,    0,  414,  349,   86,
  105,   37,   86,    0,  706,    0,   37,   86,  475,    0,
    0,   37,  414,    0,   37,    0,    0,    0,    0,  519,
    0,    0,  497,    0,  530,   30,    0,    0,    0,  706,
  119,   50,  379,    0,  563,    0,    0,    0,    0,    0,
   83,  706,  706,  -22,    0,   90,  121,  144,  596,  596,
  596,  706,  706,    0,  136,    0,  -38,  -37,  596,  596,
  596,    0,    0,    0,
};
static const YYINT yyrindex[] = {                       205,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  206,
    0,    0,    0,    0,    0,  149,    0,    0,    0,    0,
  154,    0,    0,    0,   29,    0,    0,    0,  -33,    0,
    0,    0,    0,    0,    0,    0,    0,   61,    0,    2,
    0,    0,    0,    0,    0,    0,    0,    0,  168,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  170,    0,    0,    0,    0,    0,    0,  294,    0,
    0,   -7,    0,    0,   99,  108,  131,  138,  457,  458,
  166,  216,   38,   63,    0,    0,    0,   -8,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   25,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  197,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   91,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  586,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,  142,   -9,    0,   93,   -5,  173,  110,  172,  107,
   43,  832,   81,    0,   21,    0,    0,
};
#define YYTABLESIZE 985
static const YYINT yytable[] = {                         74,
   15,   13,   14,   74,   74,  105,  105,   74,   74,   74,
   74,   74,  149,   74,   16,   18,   44,   69,   46,   71,
   11,   12,   19,   24,   42,   74,   74,   74,   74,   74,
   11,   17,   42,   47,   41,   42,   47,   74,   41,   41,
  150,   78,   41,   41,   41,   41,   41,   70,   41,   21,
   42,   47,   43,   47,  160,  161,   22,   74,   48,   74,
   41,   41,  140,   41,   49,   46,   68,   60,   46,   61,
   26,   66,   64,   42,   65,   26,   67,   20,   26,   23,
   26,   26,   26,   46,   42,   47,   50,   61,  139,   63,
   74,   62,    9,  105,   41,   27,   26,   26,   75,   26,
   27,   64,    9,   27,   64,   27,   27,   27,  143,    4,
    5,    2,   76,   15,  131,   45,   79,   46,   77,   64,
  100,   27,   27,   40,   27,   41,  105,   40,   40,   11,
   26,   33,   40,   40,    1,   40,   33,   40,  101,   33,
   34,  146,   33,   11,   20,   34,   23,  103,   34,   40,
   40,   34,   40,   61,   42,   27,  102,   33,   33,  109,
   33,   26,  132,   36,  105,  108,   34,   34,   36,   34,
   35,   36,  141,  104,   36,   35,  105,  142,   35,  152,
  107,   35,  151,  112,  147,  148,   27,  105,  115,   36,
   36,   33,   36,  159,  157,  158,   35,   35,   32,   35,
   34,    9,  153,   32,    2,    1,   32,   67,   67,   32,
   63,   67,   65,   63,   40,    9,    0,    3,  123,    4,
    5,    2,   33,   36,   32,   32,   67,   32,   63,  135,
   35,   34,   74,   74,   74,   74,   74,   68,   60,    0,
   47,   83,   66,   64,    1,   65,    0,   67,   31,    0,
    0,    0,    0,   31,   36,   47,   31,   42,   32,   31,
   63,   35,   62,    4,    5,    2,  137,   41,   41,   41,
   41,   41,    0,  111,   31,   31,  137,   31,  111,  114,
    0,    0,    0,  111,  128,    0,  111,  129,    1,   32,
  154,  155,  156,    0,    0,  138,   56,   57,   58,   59,
  162,  163,  164,   26,   26,   26,   26,   26,   31,   68,
    0,    4,    5,    2,   66,   68,   60,   73,    0,   67,
   66,   64,    0,   65,   61,   67,    0,    0,   27,   27,
   27,   27,   27,    0,   65,    0,    1,   65,   63,   31,
   62,   68,   28,    0,   30,   31,   66,   64,    0,   65,
    0,   67,   65,    0,    0,    0,   40,   40,   40,   40,
   40,    0,    0,    0,   33,   33,   33,   33,   33,    0,
    0,   84,    0,   34,   34,   34,   34,   34,    0,    0,
    0,    0,    0,    0,    0,   68,   60,    0,    0,    0,
   66,   64,    0,   65,    0,   67,   36,   36,   36,   36,
   36,    0,   61,   35,   35,   35,   35,   35,   63,    0,
   62,    0,    0,    0,    0,   68,   60,    0,    0,    0,
   66,   64,    0,   65,    0,   67,    0,    0,    0,    0,
    0,   32,   32,   32,   32,   32,    0,    0,   63,   68,
   62,  106,    0,    0,   66,   64,    0,   65,    0,   67,
   68,   60,    0,    0,    0,   66,   64,    0,   65,    0,
   67,    0,   63,    0,   62,    0,    0,   56,   57,   58,
   59,  144,   61,   63,    0,   62,    0,    0,    0,    0,
    0,   31,   31,   31,   31,   31,    0,    0,    0,   37,
   38,    0,    0,    0,   37,   38,    0,   37,   38,    0,
   37,   38,   61,    0,    0,    0,    0,    3,    0,    4,
    5,    2,    0,    0,   35,   37,   38,   32,    0,   33,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    3,
    0,    4,    5,    2,    1,    0,   35,   61,   37,   32,
    0,   33,    0,    0,    0,   56,   57,   58,   59,   37,
   38,    0,    0,    4,    5,    2,    1,    0,   35,    0,
   37,   32,    0,   33,    0,  120,    0,    0,    0,   35,
    0,    0,   32,    0,   33,    0,    0,  130,    1,    0,
   37,   38,   37,    0,    0,    0,    0,  120,    0,    0,
    0,    0,    0,   37,    0,    0,    0,  109,    0,  119,
   34,    0,   35,    0,    0,   32,    0,   33,    0,   36,
    0,    0,    0,    0,    0,   56,   57,   58,   59,  109,
  120,  134,   34,    0,    0,   72,   37,    0,   72,    0,
   72,    0,    0,    0,    0,   35,    0,    0,   32,    0,
   33,    0,    0,    0,   34,   56,   57,   58,   59,   72,
    0,    0,  109,  120,  136,   34,    0,    0,    0,   37,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   56,
   57,   58,   59,    0,    0,    0,   72,    0,    0,    0,
   56,   57,   58,   59,    0,  109,  120,  145,   34,    0,
    0,    0,    0,   35,   80,    0,   32,    0,   33,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   72,    0,
   72,   72,    0,    0,    0,    0,    0,   37,  109,    0,
    0,   34,   37,   38,    0,    0,    0,    0,    0,    0,
    0,   28,   29,   30,   31,    0,    0,  116,  117,  118,
    0,    0,    0,    0,   36,   35,    0,    0,   32,    0,
   33,    0,    0,   28,   29,   30,   31,    0,    0,  116,
  117,  118,    0,    0,    0,    0,    0,    0,    0,   37,
    0,    0,    0,    0,    0,   28,   29,   30,   31,   34,
    0,    0,    0,    0,    0,    0,   28,   29,   30,   31,
    0,    0,  116,  117,  118,    0,   36,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   28,
   29,   30,   31,    0,    0,  116,  117,  118,    0,    0,
    0,   34,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   72,   72,   72,   72,    0,    0,   72,   72,
   72,   38,   28,   29,   30,   31,    0,    0,  116,  117,
  118,    0,    0,   51,   52,   53,   54,   55,    0,    0,
    0,    0,    0,   72,    0,    0,    0,    0,    0,    0,
    0,   82,    0,    0,    0,    0,    0,   85,   86,   87,
   88,   89,   90,   91,   92,   93,   94,   95,   96,   97,
   98,   99,    0,    0,    0,    0,    0,    0,    0,    0,
   28,   29,   30,   31,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  113,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  133,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   82,   28,   29,   30,   31,    0,    0,    0,    0,
    0,    0,    0,   82,   82,    0,    0,    0,    0,    0,
    0,    0,    0,   82,   82,
};
static const YYINT yycheck[] = {                         33,
   10,  258,   59,   37,   38,   44,   44,   41,   42,   43,
   44,   45,   35,   47,  258,   33,   22,   61,   24,   63,
    0,    1,   40,   40,   33,   59,   60,   61,   62,   63,
   10,   62,   41,   41,   33,   44,   44,   43,   37,   38,
   63,   47,   41,   42,   43,   44,   45,   91,   47,   33,
   59,   59,   40,   44,   93,   93,   40,   91,   41,   93,
   59,   60,   33,   62,  258,   41,   37,   38,   44,   41,
   33,   42,   43,   61,   45,   38,   47,   61,   41,   63,
   43,   44,   45,   59,   93,   93,   40,   59,   59,   60,
  124,   62,    0,   44,   93,   33,   59,   60,   41,   62,
   38,   41,   10,   41,   44,   43,   44,   45,   59,   35,
   36,   37,   61,  123,  120,   41,   33,   93,   41,   59,
   61,   59,   60,   33,   62,  124,   44,   37,   38,  109,
   93,   33,   42,   43,   60,   45,   38,   47,   41,   41,
   33,   59,   44,  123,   61,   38,   63,   61,   41,   59,
   60,   44,   62,  124,   61,   93,   76,   59,   60,  123,
   62,  124,  120,   33,   44,   61,   59,   60,   38,   62,
   33,   41,  130,   41,   44,   38,   44,   59,   41,   59,
  100,   44,   93,  103,  142,  143,  124,   44,  108,   59,
   60,   93,   62,   58,  152,  153,   59,   60,   33,   62,
   93,  109,   59,   38,    0,    0,   41,   59,   41,   44,
   41,   44,   59,   44,  124,  123,   -1,   33,  109,   35,
   36,   37,  124,   93,   59,   60,   59,   62,   59,  123,
   93,  124,  266,  267,  268,  269,  270,   37,   38,   -1,
   44,   41,   42,   43,   60,   45,   -1,   47,   33,   -1,
   -1,   -1,   -1,   38,  124,   59,   41,  266,   93,   44,
   60,  124,   62,   35,   36,   37,  125,  266,  267,  268,
  269,  270,   -1,  102,   59,   60,  135,   62,  107,  107,
   -1,   -1,   -1,  112,  112,   -1,  115,  115,   60,  124,
  149,  150,  151,   -1,   -1,  266,  267,  268,  269,  270,
  159,  160,  161,  266,  267,  268,  269,  270,   93,   37,
   -1,   35,   36,   37,   42,   37,   38,   41,   -1,   47,
   42,   43,   -1,   45,  124,   47,   -1,   -1,  266,  267,
  268,  269,  270,   -1,   41,   -1,   60,   44,   60,  124,
   62,   37,  257,   -1,  259,  260,   42,   43,   -1,   45,
   -1,   47,   59,   -1,   -1,   -1,  266,  267,  268,  269,
  270,   -1,   -1,   -1,  266,  267,  268,  269,  270,   -1,
   -1,   93,   -1,  266,  267,  268,  269,  270,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   37,   38,   -1,   -1,   -1,
   42,   43,   -1,   45,   -1,   47,  266,  267,  268,  269,
  270,   -1,  124,  266,  267,  268,  269,  270,   60,   -1,
   62,   -1,   -1,   -1,   -1,   37,   38,   -1,   -1,   -1,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,
   -1,  266,  267,  268,  269,  270,   -1,   -1,   60,   37,
   62,   93,   -1,   -1,   42,   43,   -1,   45,   -1,   47,
   37,   38,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,
   47,   -1,   60,   -1,   62,   -1,   -1,  267,  268,  269,
  270,   93,  124,   60,   -1,   62,   -1,   -1,   -1,   -1,
   -1,  266,  267,  268,  269,  270,   -1,   -1,   -1,   33,
   33,   -1,   -1,   -1,   38,   38,   -1,   41,   41,   -1,
   44,   44,  124,   -1,   -1,   -1,   -1,   33,   -1,   35,
   36,   37,   -1,   -1,   40,   59,   59,   43,   -1,   45,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   33,
   -1,   35,   36,   37,   60,   -1,   40,  124,   64,   43,
   -1,   45,   -1,   -1,   -1,  267,  268,  269,  270,   93,
   93,   -1,   -1,   35,   36,   37,   60,   -1,   40,   -1,
   64,   43,   -1,   45,   -1,   91,   -1,   -1,   -1,   40,
   -1,   -1,   43,   -1,   45,   -1,   -1,   59,   60,   -1,
  124,  124,   64,   -1,   -1,   -1,   -1,   91,   -1,   -1,
   -1,   -1,   -1,   64,   -1,   -1,   -1,  123,   -1,  125,
  126,   -1,   40,   -1,   -1,   43,   -1,   45,   -1,   91,
   -1,   -1,   -1,   -1,   -1,  267,  268,  269,  270,  123,
   91,  125,  126,   -1,   -1,   40,   64,   -1,   43,   -1,
   45,   -1,   -1,   -1,   -1,   40,   -1,   -1,   43,   -1,
   45,   -1,   -1,   -1,  126,  267,  268,  269,  270,   64,
   -1,   -1,  123,   91,  125,  126,   -1,   -1,   -1,   64,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,
  268,  269,  270,   -1,   -1,   -1,   91,   -1,   -1,   -1,
  267,  268,  269,  270,   -1,  123,   91,  125,  126,   -1,
   -1,   -1,   -1,   40,   41,   -1,   43,   -1,   45,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,
  125,  126,   -1,   -1,   -1,   -1,   -1,   64,  123,   -1,
   -1,  126,  266,  266,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  257,  258,  259,  260,   -1,   -1,  263,  264,  265,
   -1,   -1,   -1,   -1,   91,   40,   -1,   -1,   43,   -1,
   45,   -1,   -1,  257,  258,  259,  260,   -1,   -1,  263,
  264,  265,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   64,
   -1,   -1,   -1,   -1,   -1,  257,  258,  259,  260,  126,
   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,  260,
   -1,   -1,  263,  264,  265,   -1,   91,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,
  258,  259,  260,   -1,   -1,  263,  264,  265,   -1,   -1,
   -1,  126,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  257,  258,  259,  260,   -1,   -1,  263,  264,
  265,   20,  257,  258,  259,  260,   -1,   -1,  263,  264,
  265,   -1,   -1,   32,   33,   34,   35,   36,   -1,   -1,
   -1,   -1,   -1,   42,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   50,   -1,   -1,   -1,   -1,   -1,   56,   57,   58,
   59,   60,   61,   62,   63,   64,   65,   66,   67,   68,
   69,   70,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  257,  258,  259,  260,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  105,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  120,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  130,  257,  258,  259,  260,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  142,  143,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  152,  153,
};
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 272
#define YYUNDFTOKEN 292
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'","'$'","'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,
0,0,0,0,0,0,0,0,0,"':'","';'","'<'","'='","'>'","'?'","'@'",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"tINTEGER",
"tIDENTIFIER","tSTRING","tDOUBLE","tPRINT","tREAD","tRETURN","tBREAK",
"tCONTINUE","tPRINTLN","tGE","tLE","tEQ","tNE","tIFX","tUNARY",0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file : declarations",
"file :",
"declarations : declarations declaration",
"declarations : declaration",
"declaration : variable ';'",
"declaration : function",
"function : type tIDENTIFIER '!' '(' variables ')' '=' literal body",
"function : type tIDENTIFIER '(' variables ')'",
"function : type tIDENTIFIER '!' '(' ')' '=' literal body",
"function : '!' tIDENTIFIER '!' '(' variables ')' '=' literal body",
"function : '!' tIDENTIFIER '(' variables ')'",
"function : '!' tIDENTIFIER '!' '(' ')' '=' literal body",
"body : block",
"block : '{' declarations intructions '}'",
"block : '{' declarations '}'",
"block : '{' intructions '}'",
"block : '{' '}'",
"type : '#'",
"type : '%'",
"type : '$'",
"type : '<' type '>'",
"expr : literal",
"expr : '-' expr",
"expr : '~' expr",
"expr : '+' expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr tGE expr",
"expr : expr tLE expr",
"expr : expr tNE expr",
"expr : expr tEQ expr",
"expr : expr '&' expr",
"expr : expr '|' expr",
"expr : '(' expr ')'",
"expr : '[' expr ']'",
"expr : lval",
"expr : lval '=' expr",
"expr : lval '?'",
"expr : '@'",
"expr : fun_call",
"expressions : expressions ',' expr",
"expressions : expr",
"fun_call : tIDENTIFIER '(' expressions ')'",
"fun_call : tIDENTIFIER '(' ')'",
"intructions : intruction",
"intructions : intructions intruction",
"intruction : expr ';'",
"intruction : expr '!'",
"intruction : expr tPRINTLN",
"intruction : tBREAK",
"intruction : tCONTINUE",
"intruction : tRETURN",
"intruction : condition",
"intruction : iteration",
"intruction : block",
"variables : variable",
"variables : variable ',' variables",
"variable : type tIDENTIFIER '!' '=' expr",
"variable : type tIDENTIFIER '=' expr",
"variable : type tIDENTIFIER '!'",
"variable : type tIDENTIFIER '?'",
"variable : type tIDENTIFIER",
"iteration : '[' variables ';' expressions ';' expressions ']' intruction",
"iteration : '[' expressions ';' expressions ';' expressions ']' intruction",
"iteration : '[' ';' expressions ';' ']' intruction",
"condition : '[' expr ']' '#' intruction",
"condition : '[' expr ']' '?' intruction",
"condition : '[' expr ']' '?' intruction ':' intruction",
"lval : tIDENTIFIER",
"lval : lval '[' expr ']'",
"literal : tINTEGER",
"literal : tDOUBLE",
"literal : tSTRING",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 58 "zu_parser.y"
	{ compiler->ast(yystack.l_mark[0].sequence); }
break;
case 2:
#line 59 "zu_parser.y"
	{ compiler->ast(new cdk::nil_node(LINE));}
break;
case 3:
#line 62 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE,yystack.l_mark[0].node,yystack.l_mark[-1].sequence); }
break;
case 4:
#line 63 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE,yystack.l_mark[0].node); }
break;
case 5:
#line 66 "zu_parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 6:
#line 67 "zu_parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 7:
#line 70 "zu_parser.y"
	{ yyval.node = new zu::function_def_node(LINE,yystack.l_mark[-7].s,yystack.l_mark[-4].sequence,yystack.l_mark[-8].type,yystack.l_mark[0].sequence,true,yystack.l_mark[-1].expression); }
break;
case 8:
#line 71 "zu_parser.y"
	{ yyval.node = new zu::function_dec_node(LINE,yystack.l_mark[-3].s,yystack.l_mark[-1].sequence,yystack.l_mark[-4].type,true); }
break;
case 9:
#line 72 "zu_parser.y"
	{ yyval.node = new zu::function_def_node(LINE,yystack.l_mark[-6].s,nullptr,yystack.l_mark[-7].type,yystack.l_mark[0].sequence,true,yystack.l_mark[-1].expression); }
break;
case 10:
#line 73 "zu_parser.y"
	{ yyval.node = new zu::function_def_node(LINE,yystack.l_mark[-7].s,yystack.l_mark[-4].sequence,nullptr,yystack.l_mark[0].sequence,true,yystack.l_mark[-1].expression); }
break;
case 11:
#line 74 "zu_parser.y"
	{ yyval.node = new zu::function_dec_node(LINE,yystack.l_mark[-3].s,yystack.l_mark[-1].sequence,nullptr,false);}
break;
case 12:
#line 75 "zu_parser.y"
	{  yyval.node = new zu::function_def_node(LINE,yystack.l_mark[-6].s,nullptr,nullptr,yystack.l_mark[0].sequence,true,yystack.l_mark[-1].expression);  }
break;
case 13:
#line 78 "zu_parser.y"
	{  yyval.sequence = yystack.l_mark[0].sequence ;  }
break;
case 14:
#line 81 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE,yystack.l_mark[-2].sequence,yystack.l_mark[-1].sequence);}
break;
case 15:
#line 82 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE,yystack.l_mark[-1].sequence); }
break;
case 16:
#line 83 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE,yystack.l_mark[-1].sequence); }
break;
case 17:
#line 84 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE,nullptr); }
break;
case 18:
#line 87 "zu_parser.y"
	{ yyval.type = new basic_type(4, basic_type::TYPE_INT);}
break;
case 19:
#line 88 "zu_parser.y"
	{ yyval.type = new basic_type(8, basic_type::TYPE_DOUBLE);}
break;
case 20:
#line 89 "zu_parser.y"
	{ yyval.type = new basic_type(1, basic_type::TYPE_STRING);}
break;
case 21:
#line 90 "zu_parser.y"
	{ yyval.type = new basic_type(4, basic_type::TYPE_POINTER); yyval.type->_subtype = yystack.l_mark[-1].type; }
break;
case 22:
#line 93 "zu_parser.y"
	{ yyval.expression = yystack.l_mark[0].expression; }
break;
case 23:
#line 94 "zu_parser.y"
	{ yyval.expression = new cdk::neg_node(LINE, yystack.l_mark[0].expression); }
break;
case 24:
#line 95 "zu_parser.y"
	{ yyval.expression = new zu::not_node(LINE,yystack.l_mark[0].expression); }
break;
case 25:
#line 96 "zu_parser.y"
	{ yyval.expression = new zu::id_node(LINE,yystack.l_mark[0].expression); }
break;
case 26:
#line 97 "zu_parser.y"
	{ yyval.expression = new cdk::add_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 27:
#line 98 "zu_parser.y"
	{ yyval.expression = new cdk::sub_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 28:
#line 99 "zu_parser.y"
	{ yyval.expression = new cdk::mul_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 29:
#line 100 "zu_parser.y"
	{ yyval.expression = new cdk::div_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 30:
#line 101 "zu_parser.y"
	{ yyval.expression = new cdk::mod_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 31:
#line 102 "zu_parser.y"
	{ yyval.expression = new cdk::lt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 32:
#line 103 "zu_parser.y"
	{ yyval.expression = new cdk::gt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 33:
#line 104 "zu_parser.y"
	{ yyval.expression = new cdk::ge_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 34:
#line 105 "zu_parser.y"
	{ yyval.expression = new cdk::le_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 35:
#line 106 "zu_parser.y"
	{ yyval.expression = new cdk::ne_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 36:
#line 107 "zu_parser.y"
	{ yyval.expression = new cdk::eq_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 37:
#line 108 "zu_parser.y"
	{ yyval.expression = new zu::and_node(LINE,yystack.l_mark[-2].expression,yystack.l_mark[0].expression); }
break;
case 38:
#line 109 "zu_parser.y"
	{ yyval.expression = new zu::or_node(LINE,yystack.l_mark[-2].expression,yystack.l_mark[0].expression); }
break;
case 39:
#line 110 "zu_parser.y"
	{ yyval.expression = yystack.l_mark[-1].expression; }
break;
case 40:
#line 111 "zu_parser.y"
	{ yyval.expression = new zu::malloc_node(LINE, yystack.l_mark[-1].expression); }
break;
case 41:
#line 112 "zu_parser.y"
	{ yyval.expression = new zu::rvalue_node(LINE, yystack.l_mark[0].lvalue); }
break;
case 42:
#line 113 "zu_parser.y"
	{ yyval.expression = new zu::assignment_node(LINE, yystack.l_mark[-2].lvalue, yystack.l_mark[0].expression); }
break;
case 43:
#line 114 "zu_parser.y"
	{ yyval.expression = new zu::pos_node(LINE,yystack.l_mark[-1].lvalue); }
break;
case 44:
#line 115 "zu_parser.y"
	{ yyval.expression = new zu::read_node(LINE); }
break;
case 45:
#line 116 "zu_parser.y"
	{ yyval.expression = yystack.l_mark[0].fcall; }
break;
case 46:
#line 119 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE,yystack.l_mark[0].expression,yystack.l_mark[-2].sequence); }
break;
case 47:
#line 120 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE,yystack.l_mark[0].expression); }
break;
case 48:
#line 123 "zu_parser.y"
	{ yyval.fcall = new zu::function_call_node(LINE,yystack.l_mark[-3].s,yystack.l_mark[-1].sequence); }
break;
case 49:
#line 124 "zu_parser.y"
	{ yyval.fcall = new zu::function_call_node(LINE,yystack.l_mark[-2].s,nullptr); }
break;
case 50:
#line 127 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE,yystack.l_mark[0].node); }
break;
case 51:
#line 128 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE,yystack.l_mark[0].node,yystack.l_mark[-1].sequence); }
break;
case 52:
#line 131 "zu_parser.y"
	{ yyval.node = new zu::evaluation_node(LINE,yystack.l_mark[-1].expression); }
break;
case 53:
#line 132 "zu_parser.y"
	{ yyval.node = new zu::print_node(LINE,yystack.l_mark[-1].expression); }
break;
case 54:
#line 133 "zu_parser.y"
	{ yyval.node = new zu::println_node(LINE,yystack.l_mark[-1].expression); }
break;
case 55:
#line 134 "zu_parser.y"
	{ yyval.node = new zu::break_node(LINE); }
break;
case 56:
#line 135 "zu_parser.y"
	{ yyval.node = new zu::continue_node(LINE); }
break;
case 57:
#line 136 "zu_parser.y"
	{ yyval.node = new zu::return_node(LINE); }
break;
case 58:
#line 137 "zu_parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 59:
#line 138 "zu_parser.y"
	{ yyval.node = yystack.l_mark[0].forn; }
break;
case 60:
#line 139 "zu_parser.y"
	{ yyval.node = yystack.l_mark[0].sequence; }
break;
case 61:
#line 142 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE,yystack.l_mark[0].node); }
break;
case 62:
#line 143 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[-2].node,yystack.l_mark[0].sequence); }
break;
case 63:
#line 146 "zu_parser.y"
	{ yyval.node = new zu::variable_def_node(LINE,yystack.l_mark[-3].s,yystack.l_mark[-4].type,yystack.l_mark[0].expression,true); }
break;
case 64:
#line 147 "zu_parser.y"
	{ yyval.node = new zu::variable_def_node(LINE,yystack.l_mark[-2].s,yystack.l_mark[-3].type,yystack.l_mark[0].expression,false); }
break;
case 65:
#line 148 "zu_parser.y"
	{ yyval.node = new zu::variable_dec_node(LINE,yystack.l_mark[-1].s,yystack.l_mark[-2].type,true); }
break;
case 66:
#line 149 "zu_parser.y"
	{ yyval.node = new zu::variable_dec_node(LINE,yystack.l_mark[-1].s,yystack.l_mark[-2].type,false); }
break;
case 67:
#line 150 "zu_parser.y"
	{ yyval.node = new zu::variable_dec_node(LINE,yystack.l_mark[0].s,yystack.l_mark[-1].type,false); }
break;
case 68:
#line 153 "zu_parser.y"
	{  yyval.forn = new zu::for_node(LINE, yystack.l_mark[-6].sequence, yystack.l_mark[-4].sequence, yystack.l_mark[-2].sequence, yystack.l_mark[0].node ); }
break;
case 69:
#line 154 "zu_parser.y"
	{  yyval.forn = new zu::for_node(LINE, yystack.l_mark[-6].sequence, yystack.l_mark[-4].sequence, yystack.l_mark[-2].sequence, yystack.l_mark[0].node ); }
break;
case 70:
#line 155 "zu_parser.y"
	{  yyval.forn = new zu::for_node(LINE, nullptr, yystack.l_mark[-3].sequence, nullptr, yystack.l_mark[0].node ); }
break;
case 71:
#line 158 "zu_parser.y"
	{ yyval.node = new zu::if_node(LINE,yystack.l_mark[-3].expression,yystack.l_mark[0].node); }
break;
case 72:
#line 159 "zu_parser.y"
	{ yyval.node = new zu::if_node(LINE,yystack.l_mark[-3].expression,yystack.l_mark[0].node); }
break;
case 73:
#line 160 "zu_parser.y"
	{ yyval.node = new zu::if_else_node(LINE,yystack.l_mark[-5].expression,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 74:
#line 164 "zu_parser.y"
	{ yyval.lvalue = new zu::variable_node(LINE, yystack.l_mark[0].s); }
break;
case 75:
#line 165 "zu_parser.y"
	{ yyval.lvalue = new zu::index_node(LINE,yystack.l_mark[-3].lvalue,yystack.l_mark[-1].expression); }
break;
case 76:
#line 168 "zu_parser.y"
	{ yyval.expression = new cdk::integer_node(LINE, yystack.l_mark[0].i); }
break;
case 77:
#line 169 "zu_parser.y"
	{ yyval.expression = new cdk::double_node(LINE, yystack.l_mark[0].d); }
break;
case 78:
#line 170 "zu_parser.y"
	{ yyval.expression = new cdk::string_node(LINE, yystack.l_mark[0].s); }
break;
#line 1046 "zu_parser.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
