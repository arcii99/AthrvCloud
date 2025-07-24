//FormAI DATASET v1.0 Category: Graph representation ; Style: active
#include<stdio.h>
#include<stdlib.h>

// Structure to represent the graph
struct Graph{
    int V; // Number of vertices
    int **adjMatrix; // Adjacency matrix
};

// Function to create the graph
struct Graph createGraph(int V){
    struct Graph G;
    G.V = V;
    G.adjMatrix = (int **) malloc(sizeof(int *) * V);
    for (int i = 0; i < V; ++i){
        G.adjMatrix[i] = (int *) calloc(V, sizeof(int));
    }
    return G;
}

// Function to add edge to the graph
void addEdge(struct Graph *G, int src, int dest){
    G->adjMatrix[src][dest] = 1;
    G->adjMatrix[dest][src] = 1;
}

// Function to print the graph
void printGraph(struct Graph G){
    for (int i = 0; i < G.V; ++i){
        for (int j = 0; j < G.V; ++j){
            printf("%d ", G.adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    struct Graph G = createGraph(5);
    addEdge(&G, 0, 1);
    addEdge(&G, 1, 2);
    addEdge(&G, 2, 3);
    addEdge(&G, 3, 4);
    addEdge(&G, 4, 0);
    addEdge(&G, 0, 3);
    printGraph(G);
    return 0;
}