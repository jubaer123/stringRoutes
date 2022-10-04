#include <stdlib.h>
#include "Strings.h"

#ifndef STRINGLIST_H
#define STRINGLIST_H

typedef struct stringlist {
    int length;
    String* Slist;
} StringList;

StringList* mallocStringList(int iNElements);

void freeStringList(StringList* pSLThis);

int setElementStringsList(StringList* pSLThis, String sThis, int index);

String getElementStringList(StringList* pSLThis, int index);

StringList* duplicateStringsList(StringList* pSLThis);

#endif