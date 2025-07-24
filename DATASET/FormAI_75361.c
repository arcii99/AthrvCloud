//FormAI DATASET v1.0 Category: Graph representation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

// Structure to represent edges of the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent the graph
struct Graph {
    int n_vertices, n_edges;
    struct Edge edges[MAX_VERTICES];
};

// Function to read the graph input from the user
void read_graph(struct Graph *G) {
    printf("Enter number of vertices: ");
    scanf("%d", &G->n_vertices);
    printf("Enter number of edges: ");
    scanf("%d", &G->n_edges);
    printf("Enter edges and weights\n");
    for (int i = 0; i < G->n_edges; i++) {
        scanf("%d%d%d", &G->edges[i].src, &G->edges[i].dest, &G->edges[i].weight);
    }
}

// Function to print the graph
void print_graph(struct Graph G) {
    printf("Number of vertices: %d\n", G.n_vertices);
    printf("Number of edges: %d\n", G.n_edges);
    printf("Edges and weights: ");
    for (int i = 0; i < G.n_edges; i++) {
        printf("(%d, %d, %d) ", G.edges[i].src, G.edges[i].dest, G.edges[i].weight);
    }
    printf("\n");
}

int main() {
    struct Graph G;
    read_graph(&G);
    print_graph(G);
    return 0;
}