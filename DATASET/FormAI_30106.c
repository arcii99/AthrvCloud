//FormAI DATASET v1.0 Category: Graph representation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct {
    int data;
} vertex;

typedef struct {
    int edges[MAX_VERTICES][MAX_VERTICES];
    int n_vertices;
} graph;

void init_graph(graph *g) {
    for (int i=0; i<MAX_VERTICES; i++) {
        for (int j=0; j<MAX_VERTICES; j++) {
            g->edges[i][j] = 0;
        }
    }
    g->n_vertices = 0;
}

void add_vertex(graph *g, vertex v) {
    if (g->n_vertices < MAX_VERTICES) {
        g->n_vertices++;
    }
}

void add_edge(graph *g, int u, int v) {
    if (u >= g->n_vertices || v >= g->n_vertices) {
        printf("Invalid edge!\n");
        return;
    }
    g->edges[u][v] = 1;
    g->edges[v][u] = 1;
}

void print_graph(graph *g) {
    printf("Number of vertices: %d\n", g->n_vertices);
    printf("Edges:\n");
    for (int i=0; i<g->n_vertices; i++) {
        for (int j=i; j<g->n_vertices; j++) {
            if (g->edges[i][j] == 1) {
                printf("%d - %d\n", i, j);
            }
        }
    }
}

int main() {
    graph g;
    init_graph(&g);
    vertex v1 = {1};
    vertex v2 = {2};
    vertex v3 = {3};
    add_vertex(&g, v1);
    add_vertex(&g, v2);
    add_vertex(&g, v3);
    add_edge(&g, 0, 1);
    add_edge(&g, 0, 2);
    print_graph(&g);
    return 0;
}