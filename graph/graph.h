#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>    

#define Vertex int
typedef struct Matrix *Link;



typedef struct Matrix{
    Vertex w;
    bool visited;
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
void StartDFS(Graph *G, Vertex v);
void StartBFS(Graph *G, Vertex v);

#endif