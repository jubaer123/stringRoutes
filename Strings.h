
#ifndef STRINGS_H
#define STRINGS_H

typedef char* String;

// a cover function for malloc()
// malloc and return memory for a string of stringsize characters
// return (char*)NULL on failure
String mallocString(int len);

// just a cover function for free()
void freeString(String s);

// create a duplicate string of s
// return it
// return (char*)NULL on failure
// should call mallocString(), and then strcpy()
String duplicateString(String s);

int fputString(FILE* fpout, String s);

String fgetString(FILE* pFin);

String getString();

int compareStrings(void* s1, void* s2);

String* duplicateStringList(String *s,int len);

#endif