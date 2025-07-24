//FormAI DATASET v1.0 Category: Graph representation ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Graph definition
struct Graph {
    int V; // Number of vertices
    int **adj; // Adjacency matrix
};

// Creates a new graph with V vertices and no edges
struct Graph *createGraph(int V) {
    struct Graph *graph = (struct Graph *) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (int **) malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int *) calloc(V, sizeof(int));
    }
    return graph;
}

// Adds an edge between u and v
void addEdge(struct Graph *graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
}

// Prints the graph
void printGraph(struct Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d: ", i);
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct Graph *graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);
    addEdge(graph, 1, 4);
    printGraph(graph);
    return 0;
}