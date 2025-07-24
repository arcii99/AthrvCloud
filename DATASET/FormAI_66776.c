//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 50

typedef struct node {
    int color;
    bool taken;
} Node;

typedef struct graph {
    int num_nodes;
    bool edges[MAX_NODES][MAX_NODES];
    Node nodes[MAX_NODES];
} Graph;

void init_graph(Graph* g, int num_nodes) {
    g->num_nodes = num_nodes;
    for (int i = 0; i < num_nodes; i++) {
        g->nodes[i].taken = false;
        for (int j = 0; j < num_nodes; j++) {
            g->edges[i][j] = false;
        }
    }
}

void add_edge(Graph* g, int u, int v) {
    g->edges[u][v] = true;
    g->edges[v][u] = true;
}

bool can_color(Graph* g, int node_idx, int color) {
    for (int i = 0; i < g->num_nodes; i++) {
        if (g->edges[node_idx][i] && g->nodes[i].color == color) {
            return false;
        }
    }
    return true;
}

bool color_graph(Graph* g, int node_idx, int max_colors) {
    if (node_idx == g->num_nodes) {
        return true;
    }
    for (int i = 1; i <= max_colors; i++) {
        if (can_color(g, node_idx, i)) {
            g->nodes[node_idx].color = i;
            if (color_graph(g, node_idx + 1, max_colors)) {
                return true;
            }
            g->nodes[node_idx].color = 0;
        }
    }
    return false;
}

void print_graph(Graph* g) {
    printf("Graph has %d nodes and is colored as follows:\n", g->num_nodes);
    for (int i = 0; i < g->num_nodes; i++) {
        printf("Node %d is colored with %d\n", i, g->nodes[i].color);
    }
}

int main() {
    int num_nodes = 5;
    int max_colors = 3;
    Graph g;
    init_graph(&g, num_nodes);
    add_edge(&g, 0, 1);
    add_edge(&g, 0, 2);
    add_edge(&g, 1, 2);
    add_edge(&g, 2, 3);
    add_edge(&g, 3, 4);
    if (color_graph(&g, 0, max_colors)) {
        print_graph(&g);
    } else {
        printf("Graph cannot be colored with %d colors\n", max_colors);
    }
    return 0;
}