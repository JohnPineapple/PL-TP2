
#define _GNU_SOURCE
#define MAXPREDS 20000
#define MAXURISIZE 100
#define SENTENCESIZE 3

#define FALSE 0
#define TRUE 1

#define TRIPLESEPARATOR "\n"
#define PREDSEPARATOR "/"
#define OBJSEPARATOR " "

//Predicados Especiais
#define TEMMAE ":temMae"
#define TEMPAI ":temPai" 
#define TYPE   "rdf:type"
#define INDIVIDUAL "owl:NamedIndividual"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef char* URI;
typedef void* object;
typedef struct predicado {
    char* sujeito;
    char* predicado;
    char* objeto;
}Predicado;

typedef struct projenitor {
    char* sujeito;
    char* projenitor;
}Projenitor;

typedef struct filho {
    char* sujeito;
    char* filho;
}Filho;
typedef struct avo {
    char* sujeito;
    char* avo;
}Avo;

typedef struct irmao {
    char* sujeito;
    char* irmao;
}Irmao;

typedef struct tio {
    char* sujeito;
    char* tio;
}Tio;

typedef struct primo {
    char* sujeito;
    char* primo;
}Primo;

void processInfo(char* info);

int tokenizePreds(char*info, char**TupleList);

void parsePreds(Predicado* tripleList,char** tupleList,int tupleLen);

int parseIndividuals(Predicado* tripleList,int tupleLen,char** individualList);

int parseRelacoes(Predicado* tripleList,int tupleLen,Projenitor* parentList,Filho* childList);

int parseAvos(char** individualsList,int individualsLen,Projenitor* parentList,int relacoesLen,Avo* avoList);

int parseIrmaos(char** individualsList,int individualsLen,Projenitor* parentList,Filho* childList,int relacoesLen,Irmao* irmaoList);

int igualIrmao(Irmao i1,Irmao i2);

int parseTios(char** individualsList,int individualsLen,Irmao* irmaoList,int irmaoLen,Projenitor* parentList,int relacoesLen,Tio* tioList);

int parsePrimos(char** individualsList,int individualsLen,Tio* tioList,int tioLen,Filho* childList,int relacoesLen, Primo* primoList);

int igualPrimo(Primo p1,Primo p2);

void printDiagram(Predicado* tripleList,int tupleLen,Avo* avoList,int avoLen,Irmao* irmaoList,int irmaoLen,Tio* tioList,int tioLen, Primo* primoList,int primoLen);


