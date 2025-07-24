//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10

struct Node {
    char name[10];
    int num_neighbors;
    int neighbors[MAX_NODES];
} nodes[MAX_NODES];

void add_neighbor(int node_idx, int neighbor_idx) {
    if (nodes[node_idx].num_neighbors < MAX_NODES) {
        nodes[node_idx].neighbors[nodes[node_idx].num_neighbors] = neighbor_idx;
        nodes[node_idx].num_neighbors++;
    }
}

void print_topology() {
    printf("Network Topology:\n");
    for (int i = 0; i < MAX_NODES; i++) {
        printf("%s: ", nodes[i].name);
        for (int j = 0; j < nodes[i].num_neighbors; j++) {
            int neighbor_idx = nodes[i].neighbors[j];
            printf("%s ", nodes[neighbor_idx].name);
        }
        printf("\n");
    }
}

int main() {
    // Initialize nodes
    strcpy(nodes[0].name, "Node1");
    strcpy(nodes[1].name, "Node2");
    strcpy(nodes[2].name, "Node3");
    strcpy(nodes[3].name, "Node4");

    // Add neighbors
    add_neighbor(0, 1);
    add_neighbor(0, 2);
    add_neighbor(1, 0);
    add_neighbor(1, 3);
    add_neighbor(2, 0);
    add_neighbor(2, 3);
    add_neighbor(3, 1);
    add_neighbor(3, 2);

    // Print topology
    print_topology();

    return 0;
}