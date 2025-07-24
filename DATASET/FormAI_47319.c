//FormAI DATASET v1.0 Category: Graph representation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10

int main() {
    printf("Welcome to the happiest graph program ever!\n");

    int num_nodes, num_edges, node1, node2;
    int adj_matrix[MAX_NODES][MAX_NODES] = {0};

    // Get input from user
    printf("How many nodes are in your graph? (max %d) ", MAX_NODES);
    scanf("%d", &num_nodes);

    printf("How many edges are in your graph? ");
    scanf("%d", &num_edges);

    // Populate adjacency matrix
    printf("Enter the two nodes that are connected by each edge:\n");
    for (int i = 0; i < num_edges; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &node1, &node2);

        // Add edge to adjacency matrix
        adj_matrix[node1 - 1][node2 - 1] = 1;
        adj_matrix[node2 - 1][node1 - 1] = 1;
    }

    // Print out adjacency matrix
    printf("\nYour graph represented as an adjacency matrix:\n");
    printf("   ");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < num_nodes; i++) {
        printf("%d: ", i + 1);
        for (int j = 0; j < num_nodes; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nThanks for using this happy graph program! Have a great day!\n");
    return 0;
}