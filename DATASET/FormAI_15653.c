//FormAI DATASET v1.0 Category: Graph representation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

struct Graph{
    int V;
    int E;
    int **Adj;
};

struct Graph *createGraph(int V, int E){
    struct Graph *G = (struct Graph *) malloc(sizeof(struct Graph));
    G->V = V;
    G->E = E;
    G->Adj = (int **) malloc(V * sizeof(int *));
    for(int i=0; i<V; i++){
        G->Adj[i] = (int *) malloc(V * sizeof(int));
        for(int j=0; j<V; j++){
            G->Adj[i][j] = 0;
        }
    }
    return G;
}

void addEdge(struct Graph *G, int u, int v){
    G->Adj[u][v] = 1;
    G->Adj[v][u] = 1; //assuming an undirected Graph
}

void printGraph(struct Graph *G){
    printf("\nGraph:\n");
    for(int i=0; i<G->V; i++){
        for(int j=0; j<G->V; j++){
            printf("%d ", G->Adj[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int V = 5, E = 3;
    struct Graph *G = createGraph(V, E);
    addEdge(G, 0, 1);
    addEdge(G, 1, 2);
    addEdge(G, 3, 4);
    printGraph(G);
    return 0;
}