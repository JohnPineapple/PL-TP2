%{
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>



%}

%token sujeito, predicado, objeto

%%

ontologia  : sujeito predicados						{ }
		   ;

predicados : predicado objetos						{ }
		   | predicado objetos ';' predicados 		{ }
		   ;  

objetos    : objeto									{ }
		   | objeto ',' objetos						{ }
		   ;


%%
#include "lex.yy.c"

int yyerror(char *s) { printf("ERRO: %s\n",s); return 0; }

int main()
{
	yyparse();

	return 0;
}
