//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 500

typedef struct {
    int node1;
    int node2;
} Edge;

typedef struct {
    int nodes[MAX_NODES];
    Edge edges[MAX_EDGES];
    int num_nodes;
    int num_edges;
} Graph;

void add_node(Graph* g, int node) {
    if (g->num_nodes == MAX_NODES) {
        printf("Error: maximum number of nodes reached.\n");
        exit(1);
    } else {
        g->nodes[g->num_nodes] = node;
        g->num_nodes++;
    }
}

void add_edge(Graph* g, int node1, int node2) {
    if (g->num_edges == MAX_EDGES) {
        printf("Error: maximum number of edges reached.\n");
        exit(1);
    } else {
        g->edges[g->num_edges].node1 = node1;
        g->edges[g->num_edges].node2 = node2;
        g->num_edges++;
    }
}

void map_topology(Graph* g) {
    printf("Current Network Topology:\n");
    for (int i = 0; i < g->num_nodes; i++) {
        printf("%d:", g->nodes[i]);
        for (int j = 0; j < g->num_edges; j++) {
            if (g->edges[j].node1 == g->nodes[i]) {
                printf(" %d", g->edges[j].node2);
            } else if (g->edges[j].node2 == g->nodes[i]) {
                printf(" %d", g->edges[j].node1);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    g.num_nodes = 0;
    g.num_edges = 0;

    add_node(&g, 1);
    add_node(&g, 2);
    add_node(&g, 3);
    add_node(&g, 4);
    add_node(&g, 5);

    add_edge(&g, 1, 2);
    add_edge(&g, 1, 4);
    add_edge(&g, 2, 3);
    add_edge(&g, 2, 4);
    add_edge(&g, 3, 5);
    add_edge(&g, 4, 5);

    map_topology(&g);

    return 0;
}