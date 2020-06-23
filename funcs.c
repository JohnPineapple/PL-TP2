#include "funcs.h"

void processInfo(char* info){

    char* tupleList [MAXPREDS] ;
    Predicado tripleList [MAXPREDS] ;

    int tupleLen = tokenizePreds(info,tupleList);

    parsePreds(tripleList,tupleList,tupleLen);

    for (int i = 0; i < tupleLen; i++)
    {
        printf("%s,%s,%s\n",tripleList[i].sujeito,tripleList[i].predicado,tripleList[i].objeto);
    }
    
}

int tokenizePreds(char*info,char**tupleList){
    
    char* endstr;
    char* token = strtok_r(info,TRIPLESEPARATOR,&endstr);
    char* subtoken;
    int tupleLen = 0;

    while( token != NULL ) {

        char* endtoken;  
        subtoken = strtok_r(token,PREDSEPARATOR,&endtoken);

        while (subtoken!=NULL) {
          tupleList[tupleLen]=subtoken;
          tupleLen++;
          subtoken = strtok_r(NULL, PREDSEPARATOR,&endtoken);
          } 
        token = strtok_r(NULL,TRIPLESEPARATOR,&endstr);

   }
    return tupleLen;
}

void parsePreds(Predicado* tripleList,char** tupleList,int tupleLen){
    //SUJ PRED OBJ
    char* sentence[SENTENCESIZE];
    char* tokenpred[SENTENCESIZE];
    char*token;
    int predpointer;
    int tokensize;
    int predstartpoint;

    for (int i = 0; i < tupleLen; i++)
    {   
        predpointer=0;
        tokensize=0;
        token=strtok(tupleList[i],OBJSEPARATOR);
        while(token!=NULL){
            tokenpred[predpointer]=strdup(token);
            token=strtok(NULL,OBJSEPARATOR);
            predpointer++;
            tokensize++;
        }
        predstartpoint=SENTENCESIZE-tokensize;
        for(int i=0;i<tokensize;i++){
            sentence[predstartpoint+i]=tokenpred[i];
        }
        Predicado p1 = {.sujeito = strdup(sentence[0]),
                        .predicado = strdup(sentence[1]),
                        .objeto = strdup(sentence[2])};
        tripleList[i] = p1;
    }

    
}



