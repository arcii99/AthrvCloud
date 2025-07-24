//FormAI DATASET v1.0 Category: Graph representation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Defining graph structure
typedef struct Graph {
    int V;
    int E;
    int adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Initialize graph
void initGraph(Graph *G) {
    // Initializing graph with zero vertices and edges
    G->V = 0;
    G->E = 0;
    // Setting adjacency matrix to zero
    for(int i = 0; i < MAX_VERTICES; i++) {
        for(int j = 0; j < MAX_VERTICES; j++) {
            G->adj[i][j] = 0;
        }
    }
}

// Add edge to graph
void addEdge(Graph *G, int u, int v) {
    // Check if vertices exist and the edge does not already exist
    if(u >= MAX_VERTICES || v >= MAX_VERTICES || u < 0 || v < 0 || G->adj[u][v] != 0) {
        printf("Cannot add edge %d - %d\n", u, v);
        return;
    }
    // Add edge and increment the number of edges
    G->adj[u][v] = 1;
    G->adj[v][u] = 1;
    G->E++;
}

// Remove edge from graph
void removeEdge(Graph *G, int u, int v) {
    // Check if vertices exist and the edge exists
    if(u >= MAX_VERTICES || v >= MAX_VERTICES || u < 0 || v < 0 || G->adj[u][v] == 0) {
        printf("Cannot remove edge %d - %d\n", u, v);
        return;
    }
    // Remove edge and decrement the number of edges
    G->adj[u][v] = 0;
    G->adj[v][u] = 0;
    G->E--;
}

// Print graph
void printGraph(Graph *G) {
    printf("Adjacency Matrix:\n");
    for(int i = 0; i < G->V; i++) {
        for(int j = 0; j < G->V; j++) {
            printf("%d ", G->adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Initialize graph
    Graph G;
    initGraph(&G);
    // Add edges to graph
    addEdge(&G, 0, 1);
    addEdge(&G, 1, 2);
    addEdge(&G, 2, 0);
    // Remove edge from graph
    removeEdge(&G, 1, 2);
    // Print graph
    printGraph(&G);
    return 0;
}