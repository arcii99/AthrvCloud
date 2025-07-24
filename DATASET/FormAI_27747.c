//FormAI DATASET v1.0 Category: Graph representation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct {
    int matrix[MAX_VERTICES][MAX_VERTICES];
    int nvertices;
} graph;

void init_graph(graph *g) {
    int i, j;
    g->nvertices = 0;
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            g->matrix[i][j] = 0;
        }
    }
}

void add_edge(graph *g, int u, int v) {
    g->matrix[u][v] = 1;
    g->matrix[v][u] = 1;
}

void print_graph(graph *g) {
    int i, j;
    printf("    ");
    for (i = 0; i < g->nvertices; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 0; i < g->nvertices; i++) {
        printf("%d : ", i);
        for (j = 0; j < g->nvertices; j++) {
            printf("%d ", g->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    graph G;
    init_graph(&G);

    // Add edges
    add_edge(&G, 0, 1);
    add_edge(&G, 0, 2);
    add_edge(&G, 1, 2);
    add_edge(&G, 2, 3);

    // Print the graph
    print_graph(&G);

    return 0;
}