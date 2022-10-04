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
    for(int i=0; i<n; i++){
        printf("%s\n",routes[i]->s);
        for(int j=0; j<routes[i]->num;j++)
            printf("%.2lf %.2lf\n",routes[i]->p2D[j]->x,routes[i]->p2D[j]->y);
    }
    fclose(f);
    for(int i=0; i<n; i++){
        free(routes[i]->s);
        for(int j=0; j<routes[i]->num;j++)
            free(routes[i]->p2D[j]);
        free(routes[i]);
    }
    free(routes);
    return EXIT_SUCCESS;
}
