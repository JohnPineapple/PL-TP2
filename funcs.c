#include "funcs.h"

void processInfo(char* info){

    char* tupleList [MAXPREDS] ;
    char* tripleList [MAXPREDS] ;

    int tupleLen = tokenizePreds(info,tupleList);
    //tokenizePreds(tripleList,tupleList,tupleLen);

   for (int i = 0; i < tupleLen; i++)
   {
       printf("%s\n",tupleList[i]);
   }
}

int tokenizePreds(char*info,char**tupleList){
    
    char* subtoken;
    char* endstr;
    char* token = strtok_r(info,TRIPLESEPARATOR,&endstr);
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


