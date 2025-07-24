//FormAI DATASET v1.0 Category: Graph representation ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>

#define MAX 20

struct graph{
    int V;
    int E;
    int adj[MAX][MAX];
};

void createGraph(struct graph *G){
    printf("Enter number of vertices:\n");
    scanf("%d",&G->V);
    printf("Enter number of edges:\n");
    scanf("%d",&G->E);

    int i, j, u, v;
    printf("Enter edge pairs (starting from 0 index)\n");
    for(i=0;i<G->E;i++){
        scanf("%d%d",&u,&v);
        G->adj[u][v] = 1;
        G->adj[v][u] = 1;
    }
}

void displayGraph(struct graph G){
    int i, j;
    printf("Adjacency Matrix of given Graph:\n");
    for(i=0;i<G.V;i++){
        for(j=0;j<G.V;j++){
            printf("%d ",G.adj[i][j]);
        }
        printf("\n");
    }
}

int main(){
    struct graph G;
    createGraph(&G);
    displayGraph(G);

    return 0;
}