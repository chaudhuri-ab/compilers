

%{
#  include <stdio.h>
#  include "global.h"
#  include "main.tab.h"
#  define YYERROR_VERBOSE
    extern char* yytext;
    extern int yylineno;
%}
%define parse.lac full

%union
{
    int intValue;
    double floatValue;
    char *stringValue;
}

/* declare tokens */
%token <stringValue> ID STRING CHAR_CONST
%token NUMBER  
%token ADD SUB 
%token MUL DIV ABS MOD 
%token LT GT LEQ GEQ EQUAL_TO ASSIGN NOT UNSIGNED SIGNED
%token AND OR BITWISE_AND BITWISE_OR BITWISE_XOR
%token OP CP LB RB
%token INCREMENT DECREMENT
%token EOL END_OF_FILE
%token COLON PERIOD COMMA POINTER_TO_MEMBER SEMI_COLON
%token INT FLOAT CHAR DOUBLE SHORT LONG
%token IF ELSE WHILE FOR DO RETURN
%token INCLUDE

%type<intValue> type type_specifier

%%


program: statements {printf("End Program!\n");}
;


/* Statements */
statements: statements statement
            | statement
;

statement: include_file
            | direct_declaration
;

/* Individual Statements */
include_file: INCLUDE LT ID PERIOD ID GT {printf("[BISON - include_file] %s.%s\n",$3, $5); free($3); free($5);}
 ;
 
 direct_declaration: type_specifier ID SEMI_COLON { printf("[BISON - Direct Declaration] %d - %s\n", $1, $2); free($2); }
 ;
 
 
 /* Data Type */
 type_specifier: type {$$ = $1; }
        | SIGNED type {$$ = $2; }
        | UNSIGNED type {$$ = $2; }
 ;
 
 type: CHAR {$$ = CHAR; }
        | SHORT {$$ = SHORT; }
        | INT {$$ = INT;}
        | LONG {$$ = LONG; }
        | FLOAT {$$ = FLOAT; }
        | DOUBLE {$$ = DOUBLE; }
 ;
 

%%
main()
{
  symbol_table_init();
  yyparse();

   //return 0;
//   int tok;
//   while(tok = yylex()) {
//       printf("Line: %03d | %d", yylineno, tok);
//       if(tok == NUMBER) {
//            printf(" = %s\n", yytext);
//       }else if(tok == EOL){
//           printf(" = \\n\n");
//       }else{
//           //printf("\n");
//          printf(" = %s\n", yytext);
//       }
//   }
}

yyerror(char *s)
{
    fprintf(stderr, "Error2 - Line %d: %s\n", yylineno, s);
    int c;
//    while ((c = getchar()) != EOF && c != ';'){
//        printf("%c", c);
//    }
}

