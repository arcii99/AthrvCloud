//FormAI DATASET v1.0 Category: Graph representation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 500

// Struct for each vertex in the graph
typedef struct vertex {
    int value;
    int num_neighbors;
    int neighbor_indices[MAX_EDGES];
} Vertex;

// Struct for the graph itself
typedef struct graph {
    int num_vertices;
    Vertex vertices[MAX_VERTICES];
} Graph;

// Function to add an edge between two vertices
void add_edge(Graph *g, int u, int v) {
    // Add the second vertex to the list of neighbors for the first vertex
    g->vertices[u].neighbor_indices[g->vertices[u].num_neighbors] = v;
    g->vertices[u].num_neighbors++;

    // Add the first vertex to the list of neighbors for the second vertex
    g->vertices[v].neighbor_indices[g->vertices[v].num_neighbors] = u;
    g->vertices[v].num_neighbors++;
}

int main() {
    Graph g;

    // Set up vertices with initial values and no neighbors
    g.num_vertices = 5;
    for (int i = 0; i < g.num_vertices; i++) {
        g.vertices[i].value = i;
        g.vertices[i].num_neighbors = 0;
    }

    // Add edges between the vertices
    add_edge(&g, 0, 1);
    add_edge(&g, 0, 3);
    add_edge(&g, 1, 2);
    add_edge(&g, 1, 3);
    add_edge(&g, 2, 4);
    add_edge(&g, 3, 4);

    // Print out the graph
    printf("Graph:\n");
    for (int i = 0; i < g.num_vertices; i++) {
        printf("Vertex %d neighbors:", g.vertices[i].value);
        for (int j = 0; j < g.vertices[i].num_neighbors; j++) {
            printf(" %d", g.vertices[i].neighbor_indices[j]);
        }
        printf("\n");
    }

    return 0;
}