//FormAI DATASET v1.0 Category: Graph representation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices[MAX_VERTICES];
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

void add_vertex(Graph *g, int v) {
    if (g->num_vertices < MAX_VERTICES) {
        g->vertices[g->num_vertices++] = v;
    } else {
        printf("Graph is full\n");
    }
}

void add_edge(Graph *g, int v1, int v2, int weight) {
    int i, j;
    if (v1 >= g->num_vertices || v2 >= g->num_vertices) {
        printf("Invalid vertex\n");
        return;
    }
    g->adj_matrix[v1][v2] = weight;
    g->adj_matrix[v2][v1] = weight;
}

void display(Graph *g) {
    int i, j;
    for (i = 0; i < g->num_vertices; i++) {
        printf("%d: ", g->vertices[i]);
        for (j = 0; j < g->num_vertices; j++) {
            printf("%d ", g->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    g.num_vertices = 0;

    add_vertex(&g, 0);
    add_vertex(&g, 1);
    add_vertex(&g, 2);
    add_vertex(&g, 3);

    add_edge(&g, 0, 1, 1);
    add_edge(&g, 0, 2, 0);
    add_edge(&g, 1, 2, 1);
    add_edge(&g, 2, 3, 1);

    display(&g);

    return 0;
}