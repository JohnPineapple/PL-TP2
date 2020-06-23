// #include <sys/stat.h>
// #include <sys/types.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include <errno.h>
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


// typedef struct Ontologia
// {
//     URI sujeito;
//     predicado[] predicados;
//     struct Ontologia* nextOntologia;
// }*ontologia;

// typedef struct Predicado
// {
// 	URI predicado;
// 	object[] objetos;
// }*predicado

// //struct para inserir no gNode. de cada vez que encontramos um owl:NamedIndividual vamos inseri-lo na n-ary tree genealogica

// typedef struct Individuo
// {
//     URI id;
//     int sexo;
//     URI mae;
//     URI pai;
// }Individuo; 

