# PL-TP2 19/20

O trabalho foi resolvido sobre a proposta de trabalho 2 da cadeira de Processamento de linguagens e consiste num conversor de 
ontologias para a linguagem DOT, para posterior visualização em grafo. O trabalho foi realizado através das Ferramentas Lex+Yacc e C

## Makefile

O projeto contém uma Makefile cujo comando "make" gera o executável "ag.exe", o projeto não tem nenhuma dependência externa para além das ferramentas referidas acima. 

## Utilização

Para fazer a conversão de uma ontologia para DOT o executável deve ser executado da seguinte maneira:
"./ag.exe   < sourcefolder/sourcefile.txt   > destinyfolder/destinyfile.dot "
