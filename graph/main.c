#include "graph.h"

int main(){
    int n;
    scanf("%d",&n);
    Graph* G = GraphInit(n);
    
    int v,w;
    for(int i=0; i<=n;i++){
        scanf("%d %d",&v,&w);
        insertArc(v,w,G);
    }
    
    StartDFS(G,0);
    StartBFS(G,0);
    destroyGraph(G);
}   

