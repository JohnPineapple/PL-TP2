ag.exe : y.tab.o lex.yy.o funcs.o
	gcc -o ag.exe y.tab.o lex.yy.o funcs.o -ll

y.tab.o : y.tab.c
	gcc -c y.tab.c

lex.yy.o : lex.yy.c
	gcc -c lex.yy.c

y.tab.c y.tab.h : ag.y funcs.h
	yacc -d ag.y 

lex.yy.c : ag.l y.tab.h
	flex ag.l 

funcs.o : funcs.c funcs.h
	gcc -c funcs.c

clean : 
	rm ag.exe funcs.o lex.yy.c lex.yy.o y.tab.c y.tab.h y.tab.o

