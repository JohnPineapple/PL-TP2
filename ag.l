%{
#include "y.tab.h"
#include "funcs.h"

//

%}

%x Meta Suj Pred Obj

%%
.										{ BEGIN Suj; }


#.*										{ // Comentário }


<Suj>:[a-zA-Z]+(_[a-zA-Z]+)*[ ]+rdf:type owl:NamedIndividual 			{ BEGIN Pred; yylval = yytext; return sujeito; }
<Suj>#.*		 							{ // Comentário }

<Pred>[ ]+:[a-zA-Z]								{ BEGIN Obj; yylval = yytext; return predicado; }
<Pred>#.*		 							{ // Comentário }

<Obj>[ ]+([a-zA-Z0-9]+|:[a-zA-Z])						{ yylval = yytext; return objeto; }
<Obj>[ ]+;									{ BEGIN Pred; //Novo predicado }
<Obj>[ ]+,									{ // Outro objeto }
<Obj>[ ]+.									{ BEGIN Suj; }
<Obj>#.*									{ // Comentário }

%%

int yywrap()
{
	return 1;
}
