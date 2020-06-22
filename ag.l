%{
#include "y.tab.h"
%}

%%

[ \t\n\r] ;

#.*	{}

[a-zA-Z0-9]*:[a-zA-Z0-9]+ {yylval.svalue=strdup(yytext); return uri;}

[a-zA-Z]+ {yylval.svalue=strdup(yytext); return string;}

((\+|\-)?[1-9][0-9]*|0).?[0-9]+ {yylval.svalue=strdup(yytext); return string;}

((\+|\-)?[1-9][0-9]*|0) {yylval.svalue=strdup(yytext); return string;}
