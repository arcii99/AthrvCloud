//FormAI DATASET v1.0 Category: Graph representation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int V;
    int E;
    int adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

void init_graph(Graph* G, int V) {
    G->V = V;
    G->E = 0;
    int i, j;
    for (i = 0; i < G->V; i++) {
        for (j = 0; j < G->V; j++) {
            G->adj[i][j] = 0;
        }
    }
}

void insert_edge(Graph* G, int u, int v) {
    G->adj[u][v] = 1;
    G->adj[v][u] = 1;
    G->E++;
}

void print_graph(Graph* G) {
    int i, j;
    for (i = 0; i < G->V; i++) {
        printf("%d: ", i);
        for (j = 0; j < G->V; j++) {
            if (G->adj[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph G;
    init_graph(&G, 6);
    insert_edge(&G, 0, 1);
    insert_edge(&G, 0, 2);
    insert_edge(&G, 0, 3);
    insert_edge(&G, 1, 4);
    insert_edge(&G, 1, 5);
    insert_edge(&G, 2, 4);
    insert_edge(&G, 2, 5);
    print_graph(&G);
    return 0;
}