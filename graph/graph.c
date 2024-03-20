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
        G->A++;
    }
}

void removeArc(int v,int w,Graph* G){
    if(G->adj[v][w].w != 1 ){
        return;
    }
    G->adj[v][w].w = 0;
    G->adj[w][v].w = 0;
    G->A--;
}


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

static void clearVisited(Graph* G){
    for(int i=0; i<G->V;i++){
        for(int j=0;j<G->V;j++){
            G->adj[i][j].visited = false;
        }
    }
}

static void DSF(Graph* G, Vertex v){
    printf("visited %d\n",v);
    for(int j=0; j<G->V;j++){
        if(G->adj[j][v].w ==1 ){
            G->adj[j][v].visited = true;
        }
    }
    for(int i=0; i<G->V;i++){
        if(G->adj[v][i].w == 1 && G->adj[v][i].visited==false){
            G->adj[v][i].visited = true;
            DSF(G,i);
        }
    }

}

void BFS(Graph* G,Vertex v){
    Vertex* queue = malloc(sizeof(int)*G->V);
    int front, rear =0;
    queue[rear] = v;
    rear++; 
    while(front!=rear){
        int element = queue[front];
        front++;
        printf("visited %d\n",element);    
        for(int j=0; j<G->V;j++){
           if(G->adj[element][j].w == 1){
                int neighbor = j;
                if(!G->adj[element][neighbor].visited){
                    for(int u=0; u<G->V;u++){
                        if(G->adj[u][neighbor].w ==1){
                            G->adj[u][neighbor].visited = true;
                        }
                    }
                    G->adj[neighbor][element].visited = true;
                    queue[rear] = neighbor;
                    rear++;
                }
            }     
        }
    }
}

void StartDFS(Graph *G, Vertex v){
    clearVisited(G);
    printf("DFS\n");
    DSF(G,v);
}

void StartBFS(Graph *G, Vertex v){
    clearVisited(G);
    printf("BFS\n");
    BFS(G,v);
}



