//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100  // Maximum number of nodes in the network

// Structure to represent a network node
typedef struct {
    char name[20];
    int num_links;
    int links[MAX_NODES];
} Node;

// Array to hold all the nodes in the network
Node nodes[MAX_NODES];

// Function to add a link between two nodes
void add_link(int node1, int node2) {
    nodes[node1].links[nodes[node1].num_links++] = node2;
    nodes[node2].links[nodes[node2].num_links++] = node1;
}

// Function to print the adjacency list for each node
void print_adjacency_list() {
    for (int i = 0; i < MAX_NODES; i++) {
        if (strlen(nodes[i].name) == 0) {
            continue;
        }

        printf("%s: ", nodes[i].name);
        for (int j = 0; j < nodes[i].num_links; j++) {
            printf("%s ", nodes[nodes[i].links[j]].name);
        }

        printf("\n");
    }
}

int main() {
    // Initialize all nodes in the network
    for (int i = 0; i < MAX_NODES; i++) {
        strcpy(nodes[i].name, "");
        nodes[i].num_links = 0;
    }

    // Add some nodes to the network
    strcpy(nodes[0].name, "Node A");
    strcpy(nodes[1].name, "Node B");
    strcpy(nodes[2].name, "Node C");
    strcpy(nodes[3].name, "Node D");

    // Add some links between the nodes
    add_link(0, 1);
    add_link(1, 2);
    add_link(2, 3);
    add_link(3, 0);

    // Print the adjacency list for each node
    print_adjacency_list();

    return 0;
}