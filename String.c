#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Strings.h"

String mallocString(int len){
    String s=(String)malloc(sizeof(char)*len);
    if(s==(String)NULL)
    return NULL;
    return s;
}

void freeString(String s){
    free(s);
}

String duplicateString(String s){
    String s2= mallocString(strlen(s)+1);
    if(s2==(String)NULL)
        return NULL;
    strcpy(s2,s);
    return s2;
}

int fputString(FILE* fpout, String s){
    fprintf(fpout,"%d\n",strlen(s));
    if(strlen(s)>0){
        for(int i=0; i<strlen(s); i++)
            fprintf(fpout,"%c",*(s+i));
    }
    return strlen(s);
}

String fgetString(FILE* pFin){
    char c;
    int len;
    fscanf(pFin,"%d%c",&len,&c);
    if(len>0){
        String ns=(String) malloc(len+10);
        int temp=0;
        while ((c = fgetc(pFin)) != EOF){
            *(ns+temp)= c;
            temp++;
        }
        *(ns+temp)= '\0';
        return ns;
    }
    return NULL;
}

String getString(){
    int max_char=100001;
    String fileChar=(String) malloc(100001);
    String buffer=fileChar;
    while (fgets(buffer, max_char, stdin) != NULL){
        buffer=(fileChar+strlen(fileChar));
        max_char=100001-strlen(fileChar);
    }
    return fileChar;
}

int compareStrings(void *s1,void *s2) { 
    String* ss1 = (String)s1;
    String* ss2 = (String)s2;
    return strcmp(*ss1, *ss2);
} 

String* duplicateStringList(String *s,int len){
    String* sLCopy = (String*)malloc(sizeof(String)*len);
    for(int i=0; i<len; i++)
      sLCopy[i] = duplicateString(s[i]);
    return sLCopy;
}


