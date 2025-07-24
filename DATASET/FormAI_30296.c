//FormAI DATASET v1.0 Category: Graph representation ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 100

struct Graph {
    int adj[MAX_NODES][MAX_NODES];
    int num_nodes;
};

typedef struct Graph graph;

void init_graph(graph *g, int num_nodes) {
    g->num_nodes = num_nodes;

    for(int i = 0; i < num_nodes; i++)
        for(int j = 0; j < num_nodes; j++)
            g->adj[i][j] = 0;
}

void add_edge(graph *g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

void print_graph(graph *g) {
    printf("Graph representation:\n");
    for(int i = 0; i < g->num_nodes; i++) {
        for(int j = 0; j < g->num_nodes; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    graph g;
    int num_nodes = 5;
    init_graph(&g, num_nodes);

    add_edge(&g, 0, 1);
    add_edge(&g, 0, 2);
    add_edge(&g, 1, 3);
    add_edge(&g, 2, 4);

    print_graph(&g);
    return 0;
}