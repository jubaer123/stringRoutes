#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Strings.h"
#include "Point2D.h"
#include "Evaluate.h"


int main(int argc, String* argv){
    if(argc<2)
        return EXIT_FAILURE;
    FILE* f= fopen(argv[1],"r");
    if(f==NULL)
        return EXIT_FAILURE;
    int n;
    bR** routes=loadBusRoutes(&n,f);
    if(routes==(bR**)NULL)
        return EXIT_FAILURE;

    String str=mallocString(1001);
    if(str==(String)NULL)
        return EXIT_FAILURE;
    printf("Name\t\t\tBus Route\t\tStop Number\n");
    printf("--------------------\t--------------------\t-----------\n");
    while (fgets(str, 1001, stdin)!=NULL)
        evaluate(str,routes,n);
    fclose(f);
    free(str);
    for(int i=0; i<n; i++){
        free(routes[i]->s);
        for(int j=0; j<routes[i]->num;j++)
            free(routes[i]->p2D[j]);
        free(routes[i]);
    }
    free(routes);
    return EXIT_SUCCESS;
}