//FormAI DATASET v1.0 Category: Graph representation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int weight;
    int source;
    int dest;
} edge_t;

typedef struct {
    int num_vertices;
    int num_edges;
    edge_t edges[MAX_VERTICES * (MAX_VERTICES-1) / 2];
} graph_t;

void add_edge(graph_t *g, int source, int dest, int weight) {
    edge_t edge = { weight, source, dest };
    g->edges[g->num_edges] = edge;
    g->num_edges++;
}

void print_graph(graph_t g) {
    printf("Graph with %d vertices and %d edges:\n", g.num_vertices, g.num_edges);
    
    for (int i=0; i<g.num_edges; i++) {
        edge_t edge = g.edges[i];
        printf("(%d) %d -> %d\n", edge.weight, edge.source, edge.dest);
    }
}

int main() {
    graph_t g;
    g.num_vertices = 5;
    g.num_edges = 0;
    
    add_edge(&g, 0, 1, 10);
    add_edge(&g, 0, 3, 5);
    add_edge(&g, 1, 2, 1);
    add_edge(&g, 1, 3, 2);
    add_edge(&g, 2, 4, 4);
    add_edge(&g, 3, 1, 3);
    add_edge(&g, 3, 2, 9);
    add_edge(&g, 3, 4, 2);
    add_edge(&g, 4, 0, 7);
    
    print_graph(g);
    
    return 0;
}