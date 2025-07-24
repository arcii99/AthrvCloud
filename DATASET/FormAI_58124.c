//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 20

typedef struct {
    int id;
    int num_neighbors;
    int neighbor_ids[MAX_NODES];
} Node;

typedef struct {
    int num_nodes;
    Node nodes[MAX_NODES];
} Network;

int main() {
    Network my_network = {0};

    // Add nodes to the network
    Node node1 = {1, 2, {2, 3}};
    Node node2 = {2, 3, {1, 3, 4}};
    Node node3 = {3, 2, {1, 2}};
    Node node4 = {4, 1, {2}};

    my_network.nodes[0] = node1;
    my_network.nodes[1] = node2;
    my_network.nodes[2] = node3;
    my_network.nodes[3] = node4;
    my_network.num_nodes = 4;

    // Create an adjacency matrix to represent the network topology
    int adjacency_matrix[MAX_NODES][MAX_NODES] = {0};

    for (int i = 0; i < my_network.num_nodes; i++) {
        Node node = my_network.nodes[i];

        for (int j = 0; j < node.num_neighbors; j++) {
            int neighbor_id = node.neighbor_ids[j] - 1;
            adjacency_matrix[i][neighbor_id] = 1;
            adjacency_matrix[neighbor_id][i] = 1;
        }
    }

    // Print the adjacency matrix
    printf("Adjacency Matrix:\n\n");

    for (int i = 0; i < my_network.num_nodes; i++) {
        for (int j = 0; j < my_network.num_nodes; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }

        printf("\n");
    }

    return 0;
}