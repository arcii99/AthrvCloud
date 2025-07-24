//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: thoughtful
#include <stdio.h>
#include <stdbool.h>
#define MAX_NODES 1000

/* Store nodes as ints */
int nodes[MAX_NODES];
/* Adjacency matrix */
int graph[MAX_NODES][MAX_NODES];
/* Number of nodes in the graph */
int numNodes;
/* Array to store the color of each node */
int color[MAX_NODES];
/* Array to keep track of which colors have been used */
bool usedColors[MAX_NODES];

/* Function to check if a node can be colored with a given color */
bool canColor(int node, int c) {
    for (int i = 0; i < numNodes; i++) {
        if (graph[node][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

/* Recursive function to color each node in the graph */
bool colorGraph(int node) {
    /* Base case: if all nodes have been colored, we're done */
    if (node == numNodes) {
        return true;
    }

    /* Try each color for the current node */
    for (int c = 0; c < numNodes; c++) {
        if (canColor(nodes[node], c) && !usedColors[c]) {
            /* Mark the current color as used */
            usedColors[c] = true;
            /* Color the node with the current color */
            color[nodes[node]] = c;

            /* Recurse to color the next node */
            if (colorGraph(node+1)) {
                /* If we successfully colored all nodes, return true */
                return true;
            }

            /* If we couldn't color the next node, backtrack and try another color */
            color[nodes[node]] = -1;
            usedColors[c] = false;
        }
    }

    /* If we couldn't color the current node with any color, return false */
    return false;
}

/* Main function to create and solve a graph coloring problem */
int main() {
    /* Initialize variables */
    for (int i = 0; i < MAX_NODES; i++) {
        nodes[i] = i;
        for (int j = 0; j < MAX_NODES; j++) {
            graph[i][j] = 0;
        }
        color[i] = -1;
        usedColors[i] = false;
    }

    /* Read in the number of nodes */
    printf("Enter the number of nodes in the graph (up to %d): ", MAX_NODES);
    scanf("%d", &numNodes);
    if (numNodes > MAX_NODES) {
        printf("Error: too many nodes\n");
        return 1;
    }

    /* Read in the adjacency matrix */
    printf("Enter the adjacency matrix for the graph (0 for no edge, 1 for edge):\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    /* Solve the graph coloring problem */
    if (colorGraph(0)) {
        /* Print the solution */
        printf("Solution:\n");
        for (int i = 0; i < numNodes; i++) {
            printf("Node %d: color %d\n", nodes[i], color[nodes[i]]);
        }
    } else {
        printf("Error: could not color the graph\n");
    }

    return 0;
}