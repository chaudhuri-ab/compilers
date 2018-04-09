

%{
    # include "main.tab.h"
    char err [2000];
%}

%option noyywrap warn nodefault yylineno

%%
"->"    { return POINTER_TO_MEMBER; }
"+"	{ return ADD; }
"-"	{ return SUB; }
"*"	{ return MUL; }
"/"	{ return DIV; }
"|"     { return ABS; }
"%"     { return MOD; }
"="     { return ASSIGN; }
"("     { return OP; }
")"     { return CP; }
"{"     { return LB; }
"}"     { return RB;}
"<"     { return LT; }
">"     { return GT; }
"<="    { return LEQ; }
">="    { return GEQ; }
"=="    { return EQUAL_TO; }
"int"   { return INT; }
"float" { return FLOAT; }
"char"  { return CHAR; }
"double" { return DOUBLE; }
"if"    { return IF; }
"else"  { return ELSE; }
"while" { return WHILE; }
"for"   { return FOR; }
"do"    { return DO; }
"return" { return RETURN; }
"++"    { return INCREMENT; }
"--"    { return DECREMENT; }
"&&"    { return AND; }
"||"    { return OR; }
"!"     { return NOT; }
"."     { return PERIOD; }
"|"     { return BITWISE_OR; }
"&"     { return BITWISE_AND; }
"^"     { return BITWISE_XOR; }
","     { return COMMA; }
";"     { return COLON; }
"unsigned" { return UNSIGNED; }


\/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+\/ {/* ignore white space C Comment */}

"#include" {return INCLUDE; }


(0x|0X)[a-fA-F]+ { return NUMBER; }
([0-9]*\.?[0-9]+|[0-9]+\.) { return NUMBER; }
[_a-zA-Z]([a-zA-Z0-9_])* {return ID;}
\"(\\.|[^\\"])*\" {return STRING; }
\'([ ]|.)\' {return CHAR_CONST; }



"//".*    {/* ignore inline comment */ }
[ \t\v\n\f]   { /* ignore white space */ }
        

.	{ sprintf(err, "Mystery character %c\n", *yytext);
        yyerror(err); }
%%

