//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define maximum nodes in the network
#define MAX_NODES 10

// Define a struct for each node in the network
struct Node {
    int id;
    int num_neighbors;
    int neighbors[MAX_NODES];
};

// Function to add a neighbor to a node
void add_neighbor(struct Node *node, int neighbor_id) {
    // Check if neighbor_id is already a neighbor
    for (int i = 0; i < node->num_neighbors; i++) {
        if (node->neighbors[i] == neighbor_id) {
            printf("Error: Node %d is already a neighbor of Node %d\n", neighbor_id, node->id);
            return;
        }
    }
    // Add neighbor_id to the list of neighbors
    node->neighbors[node->num_neighbors] = neighbor_id;
    node->num_neighbors++;
}

// Function to remove a neighbor from a node
void remove_neighbor(struct Node *node, int neighbor_id) {
    // Find index of neighbor_id in the list of neighbors
    int index = -1;
    for (int i = 0; i < node->num_neighbors; i++) {
        if (node->neighbors[i] == neighbor_id) {
            index = i;
            break;
        }
    }
    // If neighbor_id is not a neighbor, return error message
    if (index == -1) {
        printf("Error: Node %d is not a neighbor of Node %d\n", neighbor_id, node->id);
        return;
    }
    // Shift all neighbors after index down by one position
    for (int i = index; i < node->num_neighbors-1; i++) {
        node->neighbors[i] = node->neighbors[i+1];
    }
    node->num_neighbors--;
}

// Function to print the network topology
void print_topology(struct Node *nodes, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: ", nodes[i].id);
        for (int j = 0; j < nodes[i].num_neighbors; j++) {
            printf("%d ", nodes[i].neighbors[j]);
        }
        printf("\n");
    }
}

int main() {
    // Create an array of nodes
    struct Node nodes[MAX_NODES];
    // Initialize each node
    for (int i = 0; i < MAX_NODES; i++) {
        nodes[i].id = i;
        nodes[i].num_neighbors = 0;
    }
    // Add some neighbors to each node
    add_neighbor(&nodes[0], 1);
    add_neighbor(&nodes[1], 0);
    add_neighbor(&nodes[1], 2);
    add_neighbor(&nodes[1], 3);
    add_neighbor(&nodes[2], 1);
    add_neighbor(&nodes[2], 3);
    add_neighbor(&nodes[3], 1);
    add_neighbor(&nodes[3], 2);
    // Print the network topology
    print_topology(nodes, MAX_NODES);
    // Remove a neighbor from a node
    remove_neighbor(&nodes[1], 0);
    // Print the updated network topology
    print_topology(nodes, MAX_NODES);
    return 0;
}