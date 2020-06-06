%{
#include "y.tab.h"

%}

%%

[a-zA-Z]+([ ]?([a-zA-Z]|\([a-zA-Z]\)))*[ ][ ]+.+			{ 
																char* en = strdup(yytext);
																char* pt = "portufsds";

																yylval.t = en; return txt; 
															}
.|\n 														{ char* e = "bad"; yylval.t = e; return txt; }

%%

int yywrap()
{
	return 1;
}