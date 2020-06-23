%{
#include "funcs.h"
int yylex();
int yyerror();
%}

%union{
    char *svalue;
};

%token COMMA SEMICOLON DOT
%token uri string 
%type <svalue> COMMA SEMICOLON DOT
%type <svalue> Sujeito Predicado Objeto
%type <svalue> string uri

%%

Ontologia: ListaTriplos {printf("ola");}
	;

ListaTriplos: ListaTriplos Triplo {printf(" lista triplos ");}
	| Triplo {printf(" lista triplos ");}
	;

Triplo: Sujeito Predicado Objeto ListaPreds DOT {printf(" triplo\n");}
	;

ListaPreds: SEMICOLON Predicado Objeto ListaPreds {printf("%s %s %s lista preds\n",$1,$2,$3);}
	| 		COMMA Objeto ListaPreds {printf("%s %s lista preds\n",$1,$2);}
	|  {}
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