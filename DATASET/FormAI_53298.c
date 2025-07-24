//FormAI DATASET v1.0 Category: Graph representation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct graph {
    int vertices[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

void initialize_graph(Graph *g) {
    int i, j;

    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            g->vertices[i][j] = 0;
        }
    }

    g->num_vertices = 0;
}

void add_edge(Graph *g, int from, int to) {
    g->vertices[from][to] = 1;
}

void print_graph(Graph *g) {
    int i, j;

    for (i = 0; i < g->num_vertices; i++) {
        printf("%d: ", i);

        for (j = 0; j < g->num_vertices; j++) {
            if (g->vertices[i][j] == 1) {
                printf("%d ", j);
            }
        }

        printf("\n");
    }
}

int main() {
    Graph g;

    initialize_graph(&g);

    g.num_vertices = 6;

    add_edge(&g, 0, 1);
    add_edge(&g, 0, 2);
    add_edge(&g, 0, 3);
    add_edge(&g, 1, 4);
    add_edge(&g, 2, 4);
    add_edge(&g, 2, 5);
    add_edge(&g, 3, 5);

    printf("Graph Representation:\n");

    print_graph(&g);

    return 0;
}