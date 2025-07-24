//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define number of nodes in network
#define NODE_COUNT 5

int main() {
    // Define an adjacency matrix to represent connections between nodes
    int network[NODE_COUNT][NODE_COUNT] = {
        {0, 1, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 0}
    };

    // Define a character array to represent node names
    char nodes[] = {'A', 'B', 'C', 'D', 'E'};

    // Print header
    printf("+------------+\n");
    printf("| NETWORK MAP |\n");
    printf("+------------+\n");

    // Print horizontal line
    for (int i = 0; i < NODE_COUNT; i++) {
        printf("+---");
    }
    printf("+\n");

    // Print node names
    for (int i = 0; i < NODE_COUNT; i++) {
        printf("| %c ", nodes[i]);
    }
    printf("|\n");

    // Print horizontal line
    for (int i = 0; i < NODE_COUNT; i++) {
        printf("+---");
    }
    printf("+\n");

    // Print adjacency matrix
    for (int i = 0; i < NODE_COUNT; i++) {
        for (int j = 0; j < NODE_COUNT; j++) {
            printf("| %d ", network[i][j]);
        }
        printf("|\n");

        // Print horizontal line
        for (int k = 0; k < NODE_COUNT; k++) {
            printf("+---");
        }
        printf("+\n");
    }

    // Print footer
    printf("+------------+\n");

    return 0;
}