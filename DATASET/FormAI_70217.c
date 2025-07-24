//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000

struct graph {
    int adj_matrix[MAX_NODES][MAX_NODES];
    int num_nodes;
};

void dfs(struct graph *g, int visited[], int current_node) {
    visited[current_node] = 1;
    int i;
    printf("%d ", current_node);
    for (i = 0 ; i < g->num_nodes ; i++) {
        if (g->adj_matrix[current_node][i] && !visited[i]) {
            dfs(g, visited, i);
        }
    }
}

void print_topology(struct graph *g) {
    int visited[MAX_NODES] = {0};
    int i;

    for (i = 0 ; i < g->num_nodes ; i++) {
        if (!visited[i]) {
            dfs(g, visited, i);
            printf("\n");
        }
    }
}

void add_edge(struct graph *g, int u, int v) {
    g->adj_matrix[u][v] = 1;
    g->adj_matrix[v][u] = 1;
}

void remove_edge(struct graph *g, int u, int v) {
    g->adj_matrix[u][v] = 0;
    g->adj_matrix[v][u] = 0;
}

int main(void) {
    struct graph *g = malloc(sizeof(struct graph));
    memset(g, 0, sizeof(struct graph));

    g->num_nodes = 5;

    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);
    add_edge(g, 2, 4);

    print_topology(g);

    remove_edge(g, 2, 4);

    printf("Topology after removing edge between nodes 2 and 4\n");

    print_topology(g);

    free(g);
    return 0;
}