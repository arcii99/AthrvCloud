//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 50 // Define the maximum number of nodes that can be in the network.

// Define the adjacency matrix data structure.
struct node {
    char name[20];
    int adjacent[MAX_NODES];
    int num_adjacent;
    bool visited;
};

// Declare a global array of nodes.
struct node network[MAX_NODES];
int num_nodes = 0;

// Function to add a new node to the network.
void add_node(char *name) {
    // Check if the maximum number of nodes has been reached.
    if (num_nodes >= MAX_NODES) {
        printf("The network is full. Cannot add any more nodes.\n");
        return;
    }
    // Check if the node already exists.
    for (int i = 0; i < num_nodes; i++) {
        if (strcmp(network[i].name, name) == 0) {
            printf("Node %s already exists in the network.\n", name);
            return;
        }
    }
    // Add the node to the network.
    strcpy(network[num_nodes].name, name);
    network[num_nodes].num_adjacent = 0;
    network[num_nodes].visited = false;
    num_nodes++;
}

// Function to add an edge between two nodes.
void add_edge(char *node1, char *node2) {
    // Find the index of the nodes in the network array.
    int index1, index2;
    for (int i = 0; i < num_nodes; i++) {
        if (strcmp(network[i].name, node1) == 0) {
            index1 = i;
        }
        if (strcmp(network[i].name, node2) == 0) {
            index2 = i;
        }
    }
    // Check if the nodes are already adjacent.
    for (int i = 0; i < network[index1].num_adjacent; i++) {
        if (network[index1].adjacent[i] == index2) {
            printf("Nodes %s and %s are already adjacent.\n", node1, node2);
            return;
        }
    }
    // Add the edge between the nodes.
    network[index1].adjacent[network[index1].num_adjacent] = index2;
    network[index1].num_adjacent++;
    network[index2].adjacent[network[index2].num_adjacent] = index1;
    network[index2].num_adjacent++;
}

// Function to print the network topology.
void print_topology() {
    printf("Network Topology:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %s\n", i, network[i].name);
        printf("Adjacent Nodes: ");
        for (int j = 0; j < network[i].num_adjacent; j++) {
            printf("%s ", network[network[i].adjacent[j]].name);
        }
        printf("\n");
    }
}

// Function to implement Depth-First Search algorithm to find all reachable nodes from a given node.
void DFS(int start_node) {
    struct node current_node = network[start_node];
    current_node.visited = true;
    printf("%s ", current_node.name);
    for (int i = 0; i < current_node.num_adjacent; i++) {
        struct node adjacent_node = network[current_node.adjacent[i]];
        if (adjacent_node.visited == false) {
            DFS(current_node.adjacent[i]);
        }
    }
}

// Function to find all reachable nodes from a given node and print them.
void find_reachable_nodes(char *name) {
    // Find the index of the node in the network array.
    int index;
    for (int i = 0; i < num_nodes; i++) {
        if (strcmp(network[i].name, name) == 0) {
            index = i;
        }
    }
    // Call the DFS function to find all reachable nodes.
    printf("Reachable nodes from %s: ", name);
    DFS(index);
}

int main() {
    add_node("Node A");
    add_node("Node B");
    add_node("Node C");
    add_node("Node D");
    add_edge("Node A", "Node B");
    add_edge("Node A", "Node C");
    add_edge("Node B", "Node C");
    add_edge("Node C", "Node D");
    print_topology();
    find_reachable_nodes("Node A");
    return 0;
}