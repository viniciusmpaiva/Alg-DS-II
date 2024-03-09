#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

#define Vertex int
typedef struct Matrix *Link;



typedef struct Matrix{
    Vertex w;
}Matrix;

typedef struct Graph{
    int V;
    int A;
    Link *adj;
}Graph;


Graph* GraphInit(int n);
void destroyGraph(Graph* G);
void insertArc(int v, int w,Graph* G);
void removeArc(int v,int w,Graph* G);
void printGraph(Graph *G);

#endif