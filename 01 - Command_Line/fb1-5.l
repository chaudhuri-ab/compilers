

%{
# include "fb1-5.tab.h"
# include <string.h>
%}

%%
[ ]"-r"    { yylval = yytext; printf("opt recur\n"); return OPT_RECUR; }
[ ]"-u"    { yylval = yytext; printf("opt recur\n"); return OPT_UPERM; }
[ ]"-g"    { yylval = yytext; printf("opt recur\n"); return OPT_GPERM; }
[ ]"-o"    { yylval = yytext; printf("opt recur\n"); return OPT_OPERM; }
[ ]"-opt"    {yylval = yytext; printf("opt recur\n"); return OPT_OPTIONS; }
[0-7]{3} {yylval = strdup(yytext); return OPT_TRIPLE;}
[0-7]{4} {yylval = strdup(yytext); return OPT_FOUR_TUPLE;}
[0-9]+	{ yylval = atoi(yytext); return NUMBER; }
[A-Za-z][A-Za-z0-9]* {yylval = strdup(yytext); printf("Word %s\n", yytext); return WORD;}
\n      { return EOL; }
"//".*\n  {}
[ \t]   { /* ignore white space */ }
.	{ yyerror("Mystery character %c\n", *yytext); }
%%
