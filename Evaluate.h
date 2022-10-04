#ifndef EVALUATE_H
#define EVALUATE_H

typedef struct busRoutes{
    String s;
    Point2D** p2D;
    int num;
}bR;

bR* mallocBusRoute();
bR** mallocBusRoutes(int n);
bR** loadBusRoutes(int* n, FILE *f);
void evaluate(String str, bR** routes, int n);

#endif