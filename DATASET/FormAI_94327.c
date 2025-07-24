//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define maximum number of nodes
#define MAX_NODES 20

// Function to generate a random number between min and max
int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Define the adjacency matrix
    int adjacency_matrix[MAX_NODES][MAX_NODES];
    memset(adjacency_matrix, 0, sizeof(adjacency_matrix)); // Initialize the matrix to 0
    
    // Generate a random number of nodes
    int num_nodes = random_number(2, MAX_NODES); // Minimum 2 nodes
    
    // Initialize the nodes
    char nodes[MAX_NODES][10];
    for (int i = 0; i < num_nodes; i++) {
        sprintf(nodes[i], "node%d", i);
    }
    
    // Generate a random topology
    for (int i = 0; i < num_nodes; i++) {
        for (int j = i + 1; j < num_nodes; j++) {
            if (random_number(0, 1)) { // 50% chance of connection between two nodes
                int weight = random_number(1, 10); // Generate a random weight
                adjacency_matrix[i][j] = weight;
                adjacency_matrix[j][i] = weight;
            }
        }
    }
    
    // Print the adjacency matrix
    printf("Adjacency Matrix:\n");
    printf("  ");
    for (int i = 0; i < num_nodes; i++) {
        printf("%s ", nodes[i]);
    }
    printf("\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%s ", nodes[i]);
        for (int j = 0; j < num_nodes; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}