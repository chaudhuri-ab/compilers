

%{
#  include <stdio.h>
    extern char* yytext;
    extern int yylineno;
%}

/* declare tokens */
%token ID NUMBER STRING CHAR_CONST
%token ADD SUB 
%token MUL DIV ABS MOD 
%token LT GT LEQ GEQ EQUAL_TO ASSIGN NOT UNSIGNED
%token AND OR BITWISE_AND BITWISE_OR BITWISE_XOR
%token OP CP LB RB
%token INCREMENT DECREMENT
%token EOL
%token COLON PERIOD COMMA POINTER_TO_MEMBER 
%token INT FLOAT CHAR DOUBLE
%token IF ELSE WHILE FOR DO RETURN
%token INCLUDE
%%
include_file: INCLUDE LT ID GT {printf("Include File: %s\n", $3); }
 ;
calclist: /* nothing */
 | calclist exp EOL { printf("= %d\n> ", $2); }
 | calclist EOL { printf("> "); } /* blank line or a comment */
 ;

exp: factor
 | exp ADD exp { $$ = $1 + $3; }
 | exp SUB factor { $$ = $1 - $3; }
 | exp ABS factor { $$ = $1 | $3; }
 ;

factor: term
 | factor MUL term { $$ = $1 * $3; }
 | factor DIV term { $$ = $1 / $3; }
 ;

term: NUMBER
 | ABS term { $$ = $2 >= 0? $2 : - $2; }
 | OP exp CP { $$ = $2; }
 ;
%%
main()
{
  printf("> "); 
  //yyparse();
   int tok;
   while(tok = yylex()) {
       printf("Line: %03d | %d", yylineno, tok);
       if(tok == NUMBER) {
            printf(" = %s\n", yytext);
       }else if(tok == EOL){
           printf(" = \\n\n");
       }else{
           //printf("\n");
          printf(" = %s\n", yytext);
       }
   }
}

yyerror(char *s)
{
    fprintf(stderr, "error: %s\n", s);
}

