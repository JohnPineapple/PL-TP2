%{
#include "funcs.h"
int yylex();
int yyerror();
int asprintf();
%}

%union{
    char *svalue;
};

%token COMMA SEMICOLON DOT
%token uri string 
%type <svalue> COMMA SEMICOLON DOT
%type <svalue> ListaTriplos Triplo ListaPreds
%type <svalue> Sujeito Predicado Objeto 
%type <svalue> string uri

%%

Ontologia: ListaTriplos {printf("Ontologia done\n%s",$1);}
	;

ListaTriplos:  ListaTriplos Triplo   {asprintf(&$$,"%s%s",$1,$2);}
	| Triplo {$$=$1;}
	;

Triplo: Sujeito Predicado Objeto ListaPreds DOT {asprintf(&$$,"%s %s %s/%s\n",$1,$2,$3,$4);}
	;

ListaPreds: SEMICOLON Predicado Objeto ListaPreds {asprintf(&$$,"%s %s/%s",$2,$3,$4);}
	|	COMMA Objeto ListaPreds {asprintf(&$$,"%s/%s",$2,$3);}
	|  	{$$="";}
	;

Sujeito: uri {$$=$1;}
	; 

Predicado: uri {$$=$1;}
	;	

Objeto: uri {$$=$1;}
	| string {$$=$1;}
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