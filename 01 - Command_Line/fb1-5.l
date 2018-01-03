

%{
# include "fb1-5.tab.h"
# include <string.h>
%}

%%
[ ]"-r"    { ECHO; yylval = yytext; printf("opt recur\n"); return OPT_RECUR; }
[ ]"-u"    { ECHO; yylval = yytext; printf("opt recur\n"); return OPT_UPERM; }
[ ]"-g"    { ECHO; yylval = yytext; printf("opt recur\n"); return OPT_GPERM; }
[ ]"-o"    { ECHO; yylval = yytext; printf("opt recur\n"); return OPT_OPERM; }
[ ]"-opt"    { ECHO; yylval = yytext; printf("opt recur\n"); return OPT_OPTIONS; }
[0-7][0-7][0-7] {return OPT_TRIPLE;}
[0-9]+	{ yylval = atoi(yytext); return NUMBER; }
[A-Za-z][A-Za-z0-9]* {yylval = strdup(yytext);; printf("Word %s\n", yytext); return WORD;}
\n      { return EOL; }
"//".*\n  {}
[ \t]   { /* ignore white space */ }
.	{ yyerror("Mystery character %c\n", *yytext); }
%%
