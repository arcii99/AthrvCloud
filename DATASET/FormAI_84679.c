//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int num_nodes, colors[MAX_NODES];

// Function to check if a node can be assigned a certain color
int can_color(int node, int color) {
    for (int i = 0; i < num_nodes; i++) {
        if (graph[node][i] && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

// Recursive function to assign colors to all nodes in the graph
int color_graph(int node) {
    if (node == num_nodes) {
        return 1;
    }

    for (int color = 1; color <= num_nodes; color++) {
        if (can_color(node, color)) {
            colors[node] = color;
            if (color_graph(node + 1)) {
                return 1;
            }
            colors[node] = 0;
        }
    }
    return 0;
}

int main() {
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &num_nodes);

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (color_graph(0)) {
        printf("Graph can be colored using %d colors as follows:\n", num_nodes);
        for (int i = 0; i < num_nodes; i++) {
            printf("Node %d: Color %d\n", i+1, colors[i]);
        }
    }
    else {
        printf("Graph cannot be colored using %d colors!\n", num_nodes);
    }

    return 0;
}