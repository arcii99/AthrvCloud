//FormAI DATASET v1.0 Category: Graph representation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

// Graph structure
typedef struct {
    int edges[MAX_VERTICES][MAX_VERTICES];
    int degree[MAX_VERTICES];
    int n_vertices;
    int n_edges;
} Graph;

// Initialize an empty graph
void init_graph(Graph *G) {
    G->n_vertices = 0;
    G->n_edges = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        G->degree[i] = 0;
        for (int j = 0; j < MAX_VERTICES; j++) {
            G->edges[i][j] = 0;
        }
    }
}

// Add an edge between two vertices in the graph
void add_edge(Graph *G, int u, int v) {
    if (G->degree[u] == MAX_VERTICES || G->degree[v] == MAX_VERTICES) {
        printf("Error: Graph already at maximum capacity.\n");
        return;
    }
    G->edges[u][G->degree[u]++] = v;
    G->edges[v][G->degree[v]++] = u;
    G->n_edges++;
}

// Print the graph
void print_graph(Graph *G) {
    printf("\nGraph:\n");
    for (int i = 0; i < G->n_vertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < G->degree[i]; j++) {
            printf("%d ", G->edges[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    Graph G;
    init_graph(&G);

    // Add vertices
    G.n_vertices = 8;
    
    // Add edges between vertices
    add_edge(&G, 0, 1);
    add_edge(&G, 1, 2);
    add_edge(&G, 2, 3);
    add_edge(&G, 3, 4);
    add_edge(&G, 4, 5);
    add_edge(&G, 2, 6);
    add_edge(&G, 6, 7);

    // Print the graph
    print_graph(&G);

    return 0;
}