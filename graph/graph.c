#include "graph.h"

static void fillWithZeros(Graph* G,int n){
    for(int i=0;i<n;i++){
        for(int j=0; j<n;j++){
            G->adj[i][j].w = 0;
        }
    }
}

Graph* GraphInit(int n){
    Graph* G = malloc(sizeof(Graph));
    G->V = n;
    G->A =0;
    G->adj = calloc(n,sizeof(Link));
    for(int i = 0;i<n;i++){
        G->adj[i] = calloc(n,sizeof(Link));
    }
    fillWithZeros(G,n);
    return G;
}

void destroyGraph(Graph* G) {
    if (G != NULL) {
        for (int i = 0; i < G->V; i++) {
            free(G->adj[i]);
        }
        free(G->adj);
        G->V = 0;
        G->A = 0;
        free(G);
    }
}

void insertArc(int v, int w, Graph* G){
    if(G->adj[v][w].w == 0){
        G->adj[v][w].w = 1;
        G->adj[w][v].w = 1;
        G->A+=2;
    }
}

void removeArc(int v,int w,Graph* G){
    if(G->adj[v][w].w != 1 ){
        return;
    }
    G->adj[v][w].w = 0;
    G->adj[w][v].w = 0;
    G->A-=2;
}

// void printGraph(Graph* G){
//     printf("Total of vertices: %d, total of arcs: %d\n",G->V,G->A);
//     for(int i=0; i<G->V;i++){
//         printf("Vertex %d, arcs:",i);
//         for(int j=0; j<G->V;j++){
//             if(G->adj[i][j].w == 1){
//                 printf(" %d,",j);
//             }
//         }
//         printf("\n");

//     }
// }
void printGraph(Graph* G) {
    printf("Total of vertices: %d, total of arcs: %d\n", G->V, G->A);
    
    for (int i = 0; i < G->V; i++) {
        printf("Vertex %d, arcs:", i);
        
        int printedArc = 0; // Variable to track if an arc has been printed

        for (int j = 0; j < G->V; j++) {
            if (G->adj[i][j].w == 1) {
                if (printedArc > 0) {
                    printf(",");
                }
                printf(" %d", j);
                printedArc++;
            }
        }

        printf("\n");
    }
}







