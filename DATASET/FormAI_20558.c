//FormAI DATASET v1.0 Category: Graph representation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
    int V;
    int E;
    int** adjMatrix;
} Graph;

Graph* createGraph(int V, int E) {
    Graph* G = (Graph*)malloc(sizeof(Graph));
    G->V = V;
    G->E = E;
    G->adjMatrix = (int**)calloc(V, sizeof(int*));
    for (int i=0; i<V; i++) {
        G->adjMatrix[i] = (int*)calloc(V, sizeof(int));
    }
    return G;
}

void addEdge(Graph* G, int from, int to, int weight) {
    G->adjMatrix[from][to] = weight;
    G->adjMatrix[to][from] = weight;
}

void displayGraph(Graph* G) {
    printf("Adjacency Matrix:\n");
    for (int i=0; i<G->V; i++) {
        for (int j=0; j<G->V; j++) {
            printf("%d ", G->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V = 5;
    int E = 7;
    Graph* G = createGraph(V, E);
    addEdge(G, 0, 1, 10);
    addEdge(G, 0, 3, 5);
    addEdge(G, 1, 2, 12);
    addEdge(G, 1, 3, 8);
    addEdge(G, 2, 4, 7);
    addEdge(G, 3, 4, 6);
    addEdge(G, 4, 0, 4);
    displayGraph(G);
    return 0;
}