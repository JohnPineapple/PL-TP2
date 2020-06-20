%{
#include "y.tab.h"

%}

%%

#.*										{ // Comentario }											{ // Comentário }
:[a-zA-Z]+(_[a-zA-Z]+)*[ ]+:[a-zA-Z]+[ ]+([a-zA-Z0-9]+|:[a-zA-Z]+)		{ // Sujeito   + predicado + objeto }
[ ]+:[a-zA-Z]+[ ]+([a-zA-Z0-9]+|:[a-zA-Z]+)					{ // Predicado + objeto }
[ ]+([a-zA-Z0-9]+|:[a-zA-Z]+)							{ // Objeto }
.|\n										{ }
%%

int yywrap()
{
	return 1;
}
