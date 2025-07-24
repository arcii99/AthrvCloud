//FormAI DATASET v1.0 Category: Graph representation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 25

typedef struct graph_t {

    int matrix[MAX_VERTICES][MAX_VERTICES];
    int num_of_vertices;
    int num_of_edges;

} graph_t;

void init_graph(graph_t *g) {
    int i, j;
    g->num_of_vertices = 0;
    g->num_of_edges = 0;

    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            g->matrix[i][j] = 0;
        }
    }
}

void add_edge(graph_t *g, int u, int v, int weight) {
    g->matrix[u][v] = weight;
    g->num_of_edges++;
}

void print_graph(graph_t *g) {
    int i, j;

    printf("Number of vertices: %d\n", g->num_of_vertices);
    printf("Number of edges: %d\n", g->num_of_edges);
    printf("Adjacency matrix:\n");

    for (i = 0; i < g->num_of_vertices; i++) {
        printf("  ");
        for (j = 0; j < g->num_of_vertices; j++) {
            printf("%d ", g->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    graph_t g;
    init_graph(&g);

    g.num_of_vertices = 5;

    add_edge(&g, 0, 1, 1);
    add_edge(&g, 0, 2, 1);
    add_edge(&g, 1, 3, 1);
    add_edge(&g, 2, 4, 1);

    print_graph(&g);

    return EXIT_SUCCESS;
}