#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Strings.h"
#include "Point2D.h"
#include "Evaluate.h"

bR* mallocBusRoute(){
    bR* b=(bR*)malloc(sizeof(bR));
    return b;
}
bR** mallocBusRoutes(int n){
    bR** b=(bR**)malloc(sizeof(bR*)*n);
    return b;
}

bR** loadBusRoutes(int* n, FILE *f){
    fscanf(f,"%d",n);
    bR** routes=mallocBusRoutes(*n);
    if(routes==(bR**)NULL)return NULL;
    for(int i=0; i < *n; i++){
        routes[i]=mallocBusRoute();
	if(routes[i]==(bR*)NULL) return NULL;
        String s=mallocString(10001);
        if(s==(String)NULL)return NULL;
        fgets(s,10001,f);
        int n1;
        fscanf(f,"%d",&n1);
	routes[i]->num=n1;
        routes[i]->p2D=(Point2D**)malloc(sizeof(Point2D*)*n1);
	if(routes[i]->p2D==(Point2D**)NULL)return NULL;
        for(int j=0; j<n1; j++){
            double a,b;
            fscanf(f,"%lf%lf",&a,&b);
            routes[i]->p2D[j]=mallocPoint2D();
            routes[i]->p2D[j]=createPoint2D(a,b);
        }
	fgetc(f);
        routes[i]->s=mallocString(101);
	if(routes[i]->s==(String)NULL)return NULL;
        fscanf(f,"%[^\n]",routes[i]->s);
        free(s);
    }
    return routes;
}

void evaluate(String str, bR** routes, int n){
    double a,b;
    if(sscanf(str,"%lf%lf",&a,&b)!=2)
        return;
    while(!(*str>='A' && *str<='Z')){
        str=str+1;
    }
    str[strlen(str)-1]='\0';
    String name=mallocString(101);
    if(name==(String)NULL)return NULL;
    String rName;
    strcpy(name,str);
    int min=-1;
    int stop=0;
    Point2D* sP2D=createPoint2D(a,b);
    if(sP2D==(Point2D*)NULL)return NULL;
    for(int i=0; i<n; i++){
        for(int j=0; j<routes[i]->num;j++){
            double d=getDistancePoint2D(sP2D,routes[i]->p2D[j]);
            if(min==-1){
                min=d;
                stop=j+1;
                rName=routes[i]->s;
            }
            else{
                if (min>d){
                    min=d;
                    stop=j+1;
                    rName=routes[i]->s;
                }
            }
        }
    }
    printf("%s",name);
    if(strlen(name)<=15)
        printf("\t");
    printf("\t%s",rName);
    if(strlen(rName)<=12)
        printf("\t");
    printf("\t%d\n",stop);
    //Please comment out all other print statements from this file and driver class
    //and uncomment the following printf statement for more generic print format.
    //printf("Student Name: %s, Route Name: %s, Stop Number: %d.\n",name,rName,stop);
    free(name);
    free(sP2D);
}
