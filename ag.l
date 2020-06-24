%{
#include "y.tab.h"
%}

%%

[ \t\r\n] ;

#.*	{}

[^ ,;:.\n\r\t]*:[^ ,;:.\n\r\t]+ {yylval.svalue=strdup(yytext); return uri;}

[a-zA-Z]+ {yylval.svalue=strdup(yytext); return string;}

((\+|\-)?[1-9][0-9]*|0).?[0-9]+ {yylval.svalue=strdup(yytext); return string;}

((\+|\-)?[1-9][0-9]*|0) {yylval.svalue=strdup(yytext); return string;}

,  { return(COMMA);}
;  { return(SEMICOLON);}
\. { return(DOT);}

%%
