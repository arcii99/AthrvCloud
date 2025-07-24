//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
#include <stdio.h>

// Define the number of nodes in the graph
#define NODES 6

// Define the number of colors
#define COLORS 3

// Define a 2D array to represent the adjacency of nodes
int adjacencyMatrix[NODES][NODES] = {
    {0, 1, 1, 0, 0, 0},
    {1, 0, 1, 1, 1, 0},
    {1, 1, 0, 0, 1, 1},
    {0, 1, 0, 0, 1, 0},
    {0, 1, 1, 1, 0, 1},
    {0, 0, 1, 0, 1, 0}
};

// Define an array to store the color of each node
int nodeColors[NODES];

// A function to check if a color can be assigned to a node
int isValidColor(int node, int color) {
    for (int i = 0; i < NODES; i++) {
        if (adjacencyMatrix[node][i] && color == nodeColors[i]) {
            return 0;
        }
    }
    return 1;
}

// A recursive function to assign colors to nodes
int assignColors(int node) {
    if (node == NODES) {
        // All nodes have been assigned colors
        return 1;
    }
    for (int color = 1; color <= COLORS; color++) {
        if (isValidColor(node, color)) {
            nodeColors[node] = color;
            if (assignColors(node + 1)) {
                return 1;
            }
            nodeColors[node] = 0;
        }
    }
    return 0;
}

int main() {
    // Assign colors to nodes
    if (assignColors(0)) {
        // Print the colors assigned to each node
        printf("Colors assigned:\n");
        for (int i = 0; i < NODES; i++) {
            printf("Node %d: Color %d\n", i, nodeColors[i]);
        }
    } else {
        printf("No solution found.\n");
    }
    return 0;
}