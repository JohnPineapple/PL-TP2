ag.exe : y.tab.o lex.yy.o 
	gcc -o ag.exe y.tab.o lex.yy.o  -ll

y.tab.o : y.tab.c
	gcc -c y.tab.c

lex.yy.o : lex.yy.c
	gcc -c lex.yy.c

y.tab.c y.tab.h : ag.y 
	yacc -d ag.y 

lex.yy.c : ag.l y.tab.h
	flex ag.l 
