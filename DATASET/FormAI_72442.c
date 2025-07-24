//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 20 

bool is_safe(int node, int graph[MAX_NODES][MAX_NODES], int colors[], int color, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        if (graph[node][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}

bool graph_color_util(int graph[MAX_NODES][MAX_NODES], int colors[], int num_nodes, int num_colors, int node) {
    if (node == num_nodes) {
        return true;
    }

    for (int i = 1; i <= num_colors; i++) {
        if (is_safe(node, graph, colors, i, num_nodes)) {
            colors[node] = i;
            if (graph_color_util(graph, colors, num_nodes, num_colors, node + 1)) {
                return true;
            }
            colors[node] = 0;
        }
    }
    return false;
}

bool graph_color(int graph[MAX_NODES][MAX_NODES], int num_nodes, int num_colors) {
    int colors[MAX_NODES] = {0};

    if (!graph_color_util(graph, colors, num_nodes, num_colors, 0)) {
        return false;
    }

    printf("Solution Exists: \n");

    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d - Color %d \n", i, colors[i]);
    }

    return true;
}

int main() {
    int graph[MAX_NODES][MAX_NODES] = {
                        {0, 1, 0, 1, 1},
                        {1, 0, 1, 0, 1},
                        {0, 1, 0, 1, 0},
                        {1, 0, 1, 0, 1},
                        {1, 1, 0, 1, 0}
                        };
    int num_nodes = 5;
    int num_colors = 3;

    if (!graph_color(graph, num_nodes, num_colors)) {
        printf("No solution found.\n");
    }
    return 0;
}