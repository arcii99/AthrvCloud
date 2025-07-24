//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold information for each node on the network
struct Node {
    char* name;
    int num_neighbors;
    struct Node** neighbors;
};

// Declare a function to free the memory allocated for a node and its neighbors
void free_node(struct Node* node);

int main() {
    // Declare variables to hold information about the network topology
    int num_nodes;
    printf("How many nodes are on the network? ");
    scanf("%d", &num_nodes);
    struct Node** nodes = (struct Node**) malloc(num_nodes * sizeof(struct Node*));
    char buffer[256];

    // Gather information about each node on the network
    for (int i = 0; i < num_nodes; i++) {
        // Allocate memory for the node structure and its name
        nodes[i] = (struct Node*) malloc(sizeof(struct Node));
        printf("Enter the name of node %d: ", i);
        scanf("%s", buffer);
        nodes[i]->name = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(nodes[i]->name, buffer);

        // Gather information about the node's neighbors
        printf("How many neighbors does node %d have? ", i);
        scanf("%d", &(nodes[i]->num_neighbors));
        nodes[i]->neighbors = (struct Node**) malloc(nodes[i]->num_neighbors * sizeof(struct Node*));
        for (int j = 0; j < nodes[i]->num_neighbors; j++) {
            int neighbor_index;
            printf("Enter the index of neighbor %d for node %d: ", j, i);
            scanf("%d", &neighbor_index);
            nodes[i]->neighbors[j] = nodes[neighbor_index];
        }
    }

    // Print out the network topology
    printf("Network Topology:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%s:", nodes[i]->name);
        for (int j = 0; j < nodes[i]->num_neighbors; j++) {
            printf(" %s", nodes[i]->neighbors[j]->name);
        }
        printf("\n");
    }

    // Free the memory allocated for each node and its neighbors
    for (int i = 0; i < num_nodes; i++) {
        free_node(nodes[i]);
        free(nodes[i]);
    }
    free(nodes);

    return 0;
}

void free_node(struct Node* node) {
    for (int i = 0; i < node->num_neighbors; i++) {
        free(node->neighbors[i]);
    }
    free(node->neighbors);
    free(node->name);
}