%{
#include "funcs.h"



%}

%token sujeito, predicado, objeto

%%

ontologia  : sujeito predicados						{ 
														ontologia o = malloc(sizeof(ontologia));
														o.sujeito = $1;
														o.predicados = $2; 
													}
		   ;

predicados : predicado objetos						{
														predicado p = malloc(sizeof(predicado));
														p.predicado = $1;
														p.objects = $2;
													}
		   | predicado objetos ';' predicados 		{
		   												predicado p = malloc(sizeof(predicado));
														p.predicado = $1;
														p.objects = $2;

														// E os outros são $3
		   											}
		   ;  

objetos    : objeto									{

													}
		   | objeto ',' objetos						{
		   												 
		   											}
		   ;


%%
#include "lex.yy.c"

int yyerror(char *s) { printf("ERRO: %s\n",s); return 0; }

int main()
{
	yyparse();

	return 0;
}
