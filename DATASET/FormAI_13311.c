//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10
#define MAX_EDGES 20

struct node {
    char name[20];
    int x;
    int y;
};

struct edge {
    char source[20];
    char destination[20];
    int weight;
};

struct graph {
    int num_nodes;
    int num_edges;
    struct node nodes[MAX_NODES];
    struct edge edges[MAX_EDGES];
};

void add_node(struct graph *g, char *name, int x, int y) {
    if (g->num_nodes >= MAX_NODES) {
        printf("Cannot add node - maximum number of nodes reached!\n");
        return;
    }
    strcpy(g->nodes[g->num_nodes].name, name);
    g->nodes[g->num_nodes].x = x;
    g->nodes[g->num_nodes].y = y;
    g->num_nodes++;
}

void add_edge(struct graph *g, char *source, char *destination, int weight) {
    if (g->num_edges >= MAX_EDGES) {
        printf("Cannot add edge - maximum number of edges reached!\n");
        return;
    }
    strcpy(g->edges[g->num_edges].source, source);
    strcpy(g->edges[g->num_edges].destination, destination);
    g->edges[g->num_edges].weight = weight;
    g->num_edges++;
}

void print_graph(struct graph *g) {
    printf("Nodes:\n");
    for (int i = 0; i < g->num_nodes; i++) {
        printf("%s (%d,%d)\n", g->nodes[i].name, g->nodes[i].x, g->nodes[i].y);
    }
    printf("\nEdges:\n");
    for (int i = 0; i < g->num_edges; i++) {
        printf("%s to %s (weight: %d)\n", g->edges[i].source, g->edges[i].destination, g->edges[i].weight);
    }
}

int main() {
    struct graph g;
    g.num_nodes = 0;
    g.num_edges = 0;

    // Add nodes
    add_node(&g, "A", 10, 20);
    add_node(&g, "B", 30, 40);
    add_node(&g, "C", 50, 60);
    add_node(&g, "D", 70, 80);

    // Add edges
    add_edge(&g, "A", "B", 5);
    add_edge(&g, "A", "C", 10);
    add_edge(&g, "B", "D", 15);
    add_edge(&g, "C", "D", 20);

    // Print graph
    print_graph(&g);

    return 0;
}