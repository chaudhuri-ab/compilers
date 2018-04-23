

%{
#  include <stdio.h>
#  include "global.h"
#  include "main.tab.h"
#  define YYERROR_VERBOSE
    extern char* yytext;
    extern int yylineno;
%}
%define parse.lac full

%nonassoc LBRACKET
%nonassoc "type_spec"

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
%token LP RP LB RB LBRACKET RBRACKET
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

semi_colon_list: /* Epsilon */
            | semi_colon_list SEMI_COLON

/* Statements */
statements: statements statement
            | statement
;

statement: include_file
            | direct_declaration
            | function_declaration
;

/* Include File */
include_file: INCLUDE LT ID PERIOD ID GT {printf("[BISON - include_file] %s.%s\n",$3, $5); free($3); free($5);}
 ;
 
 direct_declaration: type_specifier ID semi_colon_list { printf("[BISON - Direct Declaration] %d - %s\n", $1, $2); free($2); }
            | type_specifier ID LBRACKET RBRACKET ASSIGN STRING semi_colon_list { printf("[BISON - String Literal Declaration] - %s=%s\n", $2, $6); free($2); free($6); } 
 ;
 
 
 /* Data Type */

 
 type_specifier: type %prec "type_spec" {$$ = $1; }
        | SIGNED type {$$ = $2; }
        | UNSIGNED type {$$ = $2 & 0x80000000; }
 ;
 
 type: CHAR {$$ = CHAR; }
        | SHORT {$$ = SHORT; }
        | INT {$$ = INT;}
        | LONG {$$ = LONG; }
        | FLOAT {$$ = FLOAT; }
        | DOUBLE {$$ = DOUBLE; }
 ;
 

 /* Type List */
 
 type_specifier_list: type_specifier
        | type_specifier_list COMMA type_specifier
 
 ;
 
 
 /* Parameter List */
 parameter_specifier_list: /* epsilon */
        | type_specifier ID
        | parameter_specifier_list COMMA type_specifier ID
 ;
 
 /* Function Declaration & Direct Variable Declaration */
 function_declaration: type_specifier ID LP parameter_specifier_list RP semi_colon_list{ printf("[BISON - FCN Declaration] %d - %s\n", $1, $2); free($2); }
        | type_specifier ID LP parameter_specifier_list RP LB statements RB{ printf("[BISON - FCN Declaration] %d - %s\n", $1, $2); free($2); }
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

