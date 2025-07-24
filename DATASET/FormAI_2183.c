//FormAI DATASET v1.0 Category: Graph representation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 10000

typedef struct {
    int start;
    int end;
    int weight;
} Edge;

typedef struct {
    Edge edges[MAX_EDGES];
    int num_vertices;
    int num_edges;    
} Graph;

void add_edge(Graph *G, int u, int v, int w) {
    G->edges[G->num_edges].start = u;
    G->edges[G->num_edges].end = v;
    G->edges[G->num_edges].weight = w;

    G->num_edges++;
}

void print_graph(Graph G) {
    printf("Vertices: %d, Edges: %d\n\n", G.num_vertices, G.num_edges);

    for (int i = 0; i < G.num_edges; i++) {
        printf("(%d,%d) Weight: %d\n", G.edges[i].start, G.edges[i].end, G.edges[i].weight);
    }
}

int main() {
    Graph G;
    G.num_vertices = 6;
    G.num_edges = 0;

    add_edge(&G, 1, 2, 3);
    add_edge(&G, 1, 4, 5);
    add_edge(&G, 2, 3, 2);
    add_edge(&G, 2, 4, 4);
    add_edge(&G, 2, 5, 8);
    add_edge(&G, 3, 5, 1);
    add_edge(&G, 4, 5, 6);
    add_edge(&G, 4, 6, 5);
    add_edge(&G, 5, 6, 7);

    print_graph(G);

    return 0;
}