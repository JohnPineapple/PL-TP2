
#define _GNU_SOURCE
#define MAXPREDS 20000
#define MAXURISIZE 100
#define SENTENCESIZE 3

#define TRIPLESEPARATOR "\n"
#define PREDSEPARATOR "/"
#define OBJSEPARATOR " "


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

void processInfo(char* info);

int tokenizePreds(char*info, char**TupleList);
void parsePreds(Predicado* tripleList,char** tupleList,int tupleLen);
void printDiagram(Predicado* tripleList,int tupleLen);


// typedef struct Individuo
// {
//     URI id;
//     int sexo;
//     URI mae;
//     URI pai;
// }Individuo; 

