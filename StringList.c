
#include <stdio.h>
#include "StringList.h"



StringList* mallocStringList(int iNElements){
    StringList* pSLThis = (StringList*) malloc(sizeof(StringList));
    pSLThis->Slist=(String*)malloc(sizeof(String)*iNElements);
    pSLThis->length = iNElements;
    for(int i = 0; i<pSLThis->length; i++){
        pSLThis->Slist[i] = (String)NULL;
    }
    return pSLThis;
}

void freeStringList(StringList* pSLThis){
    for(int i = 0; i<pSLThis->length; i++)
        free(pSLThis->Slist[i]);
    free(pSLThis);
}

int setElementStringsList(StringList* pSLThis, String sThis, int index){
    // How do we tell if the element previously held a String?
    if(index>=pSLThis->length) return -1;
    if(pSLThis->Slist[index] != (String)NULL)
        freeString(pSLThis->Slist[index]);
    
    String s = duplicateString(sThis);
    if(s == (String) NULL) return -1;
    pSLThis->Slist[index] = duplicateString(sThis);
    return index;
}

String getElementStringList(StringList* pSLThis, int index){
    if(pSLThis->Slist[index] == (String)NULL ) return (String)NULL;
    String s = duplicateString(pSLThis->Slist[index]);
    return s;
}

StringList* duplicateStringsList(StringList* pSLThis){
    StringList* pSLThat = mallocStringList(pSLThis->length);
    if(pSLThat == (StringList*)NULL) return pSLThat;
    for(int i = 0; i<pSLThis->length; i++){
        pSLThat->Slist[i] = duplicateString(pSLThis->Slist[i]);
        if(pSLThat->Slist[i] == (String)NULL) {
            //free all pSLThat elements and then the SLThat structure
            for(int i=0; i<pSLThat->length; i++)
                free(pSLThat->Slist[i]);
            return (StringList*)NULL;
        }
    }
    return pSLThat;

}

