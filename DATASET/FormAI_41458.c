//FormAI DATASET v1.0 Category: Graph representation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100 // Maximum number of vertices

typedef struct {
    int n; // Number of vertices
    int adj_mat[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
} Graph;

// Function to initialize the graph
void init_graph(Graph* g, int n) {
    int i, j;
    g->n = n;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            g->adj_mat[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void add_edge(Graph* g, int u, int v) {
    g->adj_mat[u][v] = 1;
    g->adj_mat[v][u] = 1;
}

// Function to print the graph
void print_graph(Graph g) {
    int i, j;
    printf("Adjacency Matrix:\n");
    for (i = 0; i < g.n; i++) {
        for (j = 0; j < g.n; j++) {
            printf("%d ", g.adj_mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph g; // Declare a graph
    init_graph(&g, 5); // Initialize the graph with 5 vertices

    // Add some edges to the graph
    add_edge(&g, 0, 1);
    add_edge(&g, 0, 2);
    add_edge(&g, 1, 3);
    add_edge(&g, 2, 3);
    add_edge(&g, 3, 4);

    // Print the graph
    print_graph(g);

    return 0;
}