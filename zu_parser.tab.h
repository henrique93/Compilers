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
extern YYSTYPE yylval;
