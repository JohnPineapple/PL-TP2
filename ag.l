%{
#include "y.tab.h"

%}

%%

#.*															{ //Comentário }
:[a-zA-Z]+(_[a-zA-Z]+)*[ ]*:[a-zA-Z]+[ ]*([a-zA-Z]+|)		{ }
.|\n 														{ }

%%

int yywrap()
{
	return 1;
}
