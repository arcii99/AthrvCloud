//FormAI DATASET v1.0 Category: Graph representation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10

typedef struct {
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

void init_graph(Graph* g, int num_vertices) {
    g->num_vertices = num_vertices;
    int i, j;
    for (i = 0; i < num_vertices; ++i) {
        for (j = 0; j < num_vertices; ++j) {
            g->adj_matrix[i][j] = 0;
        }
    }
}

void add_edge(Graph* g, int vertex1, int vertex2) {
    g->adj_matrix[vertex1][vertex2] = 1;
    g->adj_matrix[vertex2][vertex1] = 1;
}

void print_graph(Graph* g) {
    printf("Adjacency matrix of the graph:\n");
    int i, j;
    for (i = 0; i < g->num_vertices; ++i) {
        for (j = 0; j < g->num_vertices; ++j) {
            printf("%d ", g->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    init_graph(&g, 5);
    add_edge(&g, 0, 1);
    add_edge(&g, 0, 4);
    add_edge(&g, 1, 2);
    add_edge(&g, 1, 3);
    add_edge(&g, 1, 4);
    add_edge(&g, 2, 3);
    add_edge(&g, 3, 4);
    print_graph(&g);
    return EXIT_SUCCESS;
}