%{
#include "funcs.h"
%}

%union{
    char *svalue;
};

%token uri string
%type <svalue> Sujeito Predicado Objeto
%type <svalue> string uri

%%

Ontologia 
	: ListaTriplos {printf("ola");}
	;

ListaTriplos 
	: ListaTriplos Triplo {}
	| Triplo {}

Triplo  
	: Sujeito Predicado Objeto ListaPreds '.' {}
	;

ListaPreds 
	: ';' Predicado	Objeto ListaPreds {}
	| ',' Objeto ListaPreds {}
	;

Sujeito 
	: uri
	; 

Predicado 
	: uri
	;	

Objeto : uri {}
	| string {}
	;


%%
int main()
{
	yyparse();
	return 0;
}

int yyerror(char *s) {
	 printf("ERRO: %s\n",s); return 0; 
}