%{
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

char* eng;
char* pt;

%}

%name parser_name

%union {char* t;}

%token txt

%%

trad	: en en      				{ printf("EN: %s\nPT: %s\n",$1,$2); }
		;
en 		: txt						{ printf("txt 1 %s\n",$1); $$ = $1; }
		;

%%
#include "lex.yy.c"

int yyerror(char *s) { printf("ERRO: %s\n",s); return 0; }

int main()
{
	yyparse();

	return 0;
}