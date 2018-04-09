/* Companion source code for "flex & bison", published by O'Reilly
 * Media, ISBN 978-0-596-15597-1
 * Copyright (c) 2009, Taughannock Networks. All rights reserved.
 * See the README file for license conditions and contact info.
 * $Header: /home/johnl/flnb/code/RCS/fb1-5.l,v 2.1 2009/11/08 02:53:18 johnl Exp $
 */

/* recognize tokens for the calculator and print them out */

%{
    # include "main.tab.h"
    char err [2000];
%}

%option noyywrap warn nodefault yylineno

%%
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

