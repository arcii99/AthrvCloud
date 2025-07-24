//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define maximum number of nodes that can be colored
#define MAX_NODES 100

// Define maximum number of connections between nodes
#define MAX_EDGES 500

// Function to color the nodes and check if it's a valid coloring
int colorNodes(int nodes[], int colors[], int adjMat[][MAX_NODES], int numNodes, int numColors, int nodeIndex) {
    int i, j;

    // Check if all nodes have been colored
    if (nodeIndex == numNodes) {
        // Check if all connections have valid colors
        for (i = 0; i < numNodes; i++) {
            for (j = 0; j < numNodes; j++) {
                if (adjMat[i][j] && colors[i] == colors[j]) {
                    // Invalid coloring
                    return 0;
                }
            }
        }
        // Valid coloring
        return 1;
    }

    // Try all possible colors for this node
    for (i = 0; i < numColors; i++) {
        nodes[nodeIndex] = i;
        if (colorNodes(nodes, colors, adjMat, numNodes, numColors, nodeIndex + 1)) {
            memcpy(colors, nodes, numNodes * sizeof(int));
            return 1;
        }
    }

    // Invalid coloring
    return 0;
}

int main() {
    int adjMat[MAX_NODES][MAX_NODES], numNodes, numEdges, i, j, x, y, numColors = 4;
    int nodes[MAX_NODES], colors[MAX_NODES];

    // Get the number of nodes (vertices) and edges in the graph
    printf("Enter the number of nodes (maximum of %d): ", MAX_NODES);
    scanf("%d", &numNodes);
    printf("Enter the number of edges (maximum of %d): ", MAX_EDGES);
    scanf("%d", &numEdges);

    // Generate adjacency matrix for the graph
    memset(adjMat, 0, sizeof(adjMat));
    for (i = 0; i < numEdges; i++) {
        printf("Enter the two nodes that are connected by edge #%d: ", i+1);
        scanf("%d %d", &x, &y);
        adjMat[x][y] = adjMat[y][x] = 1;
    }

    // Color the nodes
    if (colorNodes(nodes, colors, adjMat, numNodes, numColors, 0)) {
        // Print the coloring
        printf("Valid Coloring:\n");
        for (i = 0; i < numNodes; i++) {
            printf("Node %d: Color %d\n", i, colors[i]);
        }
    } else {
        printf("Invalid Coloring\n");
    }

    return 0;
}