//FormAI DATASET v1.0 Category: Graph representation ; Style: calm
#include <stdio.h>

#define MAX_VERTICES 100

/* Definition of Graph type */
typedef struct {
    int n; // Number of vertices
    int A[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
} Graph;

/* Initialize a Graph with n vertices */
void init(Graph *G, int n) {
    G->n = n;
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            G->A[i][j] = 0;
        }
    }
}

/* Add an edge (u, v) to Graph G */
void add_edge(Graph *G, int u, int v) {
    G->A[u][v] = 1;
    G->A[v][u] = 1;
}

/* Print the adjacency matrix of Graph G */
void print_graph(Graph *G) {
    int i, j;
    printf("Adjacency Matrix:\n");
    for (i = 1; i <= G->n; i++) {
        for (j = 1; j <= G->n; j++) {
            printf("%d ", G->A[i][j]);
        }
        printf("\n");
    }
}

/* Example usage */
int main() {
    Graph G;
    init(&G, 5);
    add_edge(&G, 1, 2);
    add_edge(&G, 2, 3);
    add_edge(&G, 3, 4);
    add_edge(&G, 4, 5);
    add_edge(&G, 5, 1);
    print_graph(&G);
    return 0;
}