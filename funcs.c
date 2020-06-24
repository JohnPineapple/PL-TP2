#include "funcs.h"

void processInfo(char* info){

    char* tupleList [MAXPREDS] ;
    Predicado tripleList [MAXPREDS] ;

    int tupleLen = tokenizePreds(info,tupleList);

    char* individualsList [tupleLen];
    Projenitor parentList [tupleLen]; 
    Filho childList [tupleLen];
    Avo avoList [tupleLen];
    Irmao irmaoList [tupleLen];

    parsePreds(tripleList,tupleList,tupleLen);
    
    int individualsLen=parseIndividuals(tripleList,tupleLen,individualsList);
    int relacoesLen=parseRelacoes(tripleList,tupleLen,parentList,childList);
    int avoLen=parseAvos(individualsList,individualsLen,parentList,relacoesLen,avoList);
    int irmaoLen=parseIrmaos(individualsList,individualsLen,parentList,childList,relacoesLen,irmaoList);
    //Irmao,tio,primo

    printf("%d",irmaoLen);
    printDiagram(tripleList,tupleLen);


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

int parseRelacoes(Predicado* tripleList,int tupleLen,Projenitor* parentList,Filho* childList){
    
    int relacoesLen=0;

    for(int i=0;i<tupleLen;i++){
        if((strcmp(tripleList[i].predicado,TEMMAE)==0||strcmp(tripleList[i].predicado,TEMPAI)==0)){
            Projenitor p1 = {.sujeito=tripleList[i].sujeito,
                             .projenitor=tripleList[i].objeto};
            Filho f1 = {.sujeito=tripleList[i].objeto,
                        .filho=tripleList[i].sujeito};   

            parentList[relacoesLen]=p1;                          
            childList[relacoesLen]=f1; 

            relacoesLen++;                
        }
    }
    return relacoesLen;
}

int parseIndividuals(Predicado* tripleList,int tupleLen,char** individualList){
    
    int individualLen=0;

    for(int i=0;i<tupleLen;i++){
        if((strcmp(tripleList[i].predicado,TYPE)==0)&&(strcmp(tripleList[i].objeto,INDIVIDUAL)==0)){                      
            individualList[individualLen]=tripleList[i].sujeito; 
            individualLen++;                
        }
    }
    return individualLen;
}

int parseAvos(char** individualsList,int individualsLen,Projenitor* parentList,int relacoesLen,Avo* avoList){

    int avoLen=0;

    for (int i = 0; i < individualsLen; i++)
    {
        for (int k = 0; k < relacoesLen; k++)
        {   
            if(strcmp(individualsList[i],parentList[k].sujeito)==0){
                for (int j = 0; j < relacoesLen; j++)
                {   
                    if(strcmp(parentList[k].projenitor,parentList[j].sujeito)==0){
                        Avo a1={.sujeito=individualsList[i],
                                .avo=parentList[j].projenitor
                                };
                        avoList[avoLen]= a1;
                        avoLen++;
                    }
                }
            }
        }   
    }
    return avoLen;
}

int parseIrmaos(char** individualsList,int individualsLen,Projenitor* parentList,Filho* childList,int relacoesLen, Irmao* irmaoList){
    
    int irmaoLen=0;

    for (int i = 0; i < individualsLen; i++)
    {
        for (int k = 0; k < relacoesLen; k++)
        {   
            if(strcmp(individualsList[i],parentList[k].sujeito)==0){
                for (int j = 0; j < relacoesLen; j++)
                {   
                    //Encontrar um filho do pai que nao o proprio
                    if((strcmp(parentList[k].projenitor,childList[j].sujeito)==0)&&(strcmp(individualsList[i],childList[j].filho)!=0)){
                        Irmao i1={.sujeito=individualsList[i],
                                  .irmao=childList[j].filho
                                };
                        irmaoList[irmaoLen]= i1;
                        irmaoLen++;
                    }
                }
            }
        }   
    }
    return irmaoLen;
}





void printDiagram(Predicado* tripleList,int tupleLen){

    printf("digraph { \n");
    for(int i=0;i<tupleLen;i++){
        printf("\"%s\" -> \"%s\"[label=\"%s\"]\n",tripleList[i].sujeito,tripleList[i].objeto,tripleList[i].predicado);
    }
    printf("}");
}



