#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
//#include <glib.h>
//#include <gmodule.h>
#include <stdio.h>

typedef char* URI;
typedef void* object;

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
