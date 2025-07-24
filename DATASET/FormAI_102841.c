//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 20
#define MAX_EDGES 30

typedef struct node {
    int id;
    int x;
    int y;
} Node;

typedef struct edge {
    int id;
    int source;
    int target;
} Edge;

typedef struct graph {
    Node nodes[MAX_NODES];
    Edge edges[MAX_EDGES];
    int num_nodes;
    int num_edges;
} Graph;

void add_node(Graph *g, int id, int x, int y) {
    Node n = { id, x, y };
    g->nodes[g->num_nodes++] = n;
}

void add_edge(Graph *g, int id, int source, int target) {
    Edge e = { id, source, target };
    g->edges[g->num_edges++] = e;
}

void print_graph(Graph *g) {
    printf("Nodes:\n");
    for (int i = 0; i < g->num_nodes; i++) {
        printf("  %d: (%d, %d)\n", g->nodes[i].id, g->nodes[i].x, g->nodes[i].y);
    }
    printf("Edges:\n");
    for (int i = 0; i < g->num_edges; i++) {
        printf("  %d: %d -> %d\n", g->edges[i].id, g->edges[i].source, g->edges[i].target);
    }
}

int main() {
    Graph g = { 0 };
    add_node(&g, 0, 10, 10);
    add_node(&g, 1, 20, 20);
    add_node(&g, 2, 30, 30);
    add_node(&g, 3, 40, 40);
    add_edge(&g, 0, 0, 1);
    add_edge(&g, 1, 1, 2);
    add_edge(&g, 2, 2, 3);
    print_graph(&g);
    return 0;
}