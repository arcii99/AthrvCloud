//FormAI DATASET v1.0 Category: Graph representation ; Style: protected
#include <stdio.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

typedef enum {
    false, true
} bool;

typedef struct {
    int u, v; // source, destination vertex indices
    int weight;
} Edge;

typedef struct {
    Edge edges[MAX_EDGES];
    int num_edges;
    int num_vertices;
} Graph;

void createGraph(Graph* g, int num_vertices) {
    g->num_vertices = num_vertices;
    g->num_edges = 0;
}

void addEdge(Graph* g, int u, int v, int weight) {
    if (g->num_edges < MAX_EDGES) {
        g->edges[g->num_edges].u = u;
        g->edges[g->num_edges].v = v;
        g->edges[g->num_edges].weight = weight;
        ++g->num_edges;
    }
}

void printGraph(Graph g) {
    printf("Vertices: %d\n", g.num_vertices);
    printf("Edges: %d\n", g.num_edges);
    printf("Edge list:\n");
    for (int i = 0; i < g.num_edges; ++i) {
        printf("(%d, %d) - %d\n", g.edges[i].u, g.edges[i].v, g.edges[i].weight);
    }
}

int main() {
    Graph g;
    createGraph(&g, 5);
    addEdge(&g, 0, 1, 2);
    addEdge(&g, 1, 2, 3);
    addEdge(&g, 2, 3, 1);
    addEdge(&g, 3, 4, 5);
    addEdge(&g, 4, 0, 4);
    printGraph(g);
    return 0;
}