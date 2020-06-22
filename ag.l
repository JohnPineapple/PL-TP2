%{
#include "y.tab.h"
%}

%%

[ \t\n\r] ;

#.*	{}

[a-zA-Z0-9]*:[a-zA-Z0-9]+ {yylval.svalue=strdup(yylex); return uri}

[a-zA-Z]+ {yylval.svalue=strdup(yylex); return string}

[0-9]+ {yylval.ivalue=atoi(yylex); return int}

((+|-)?[1-9][0-9]*|0).?[0-9]+ {yylval.svalue=strdup(yylex); return string}

((+|-)?[1-9][0-9]*|0) {yylval.svalue=strdup(yylex); return string}

%%

int yywrap()
{
	return 1;
}
