//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 1000
#define MAX_EDGES 1000

// Define a structure for representing nodes
typedef struct {
    char name[32];
    int id;
} Node;

// Define a structure for representing edges
typedef struct {
    int start_node_id;
    int end_node_id;
} Edge;

// Global arrays for storing nodes and edges
Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];

// Global variables for tracking the number of nodes and edges
int num_nodes = 0;
int num_edges = 0;

// Function for adding a new node to the network
void add_node(char *name) {
    // Create a new node with the given name and ID
    Node node = { .id = num_nodes };
    strncpy(node.name, name, 32);
    
    // Add the new node to the array of nodes
    nodes[num_nodes++] = node;
}

// Function for adding a new edge to the network
void add_edge(int start_node_id, int end_node_id) {
    // Create a new edge with the given start and end node IDs
    Edge edge = { .start_node_id = start_node_id, .end_node_id = end_node_id };
    
    // Add the new edge to the array of edges
    edges[num_edges++] = edge;
}

// Function for printing the network topology
void print_topology() {
    printf("Network Topology:\n");
    
    // Loop through all of the nodes and print their names
    for (int i = 0; i < num_nodes; i++) {
        printf("%d: %s\n", nodes[i].id, nodes[i].name);
    }
    
    // Loop through all of the edges and print their connections
    for (int i = 0; i < num_edges; i++) {
        printf("%d -> %d\n", edges[i].start_node_id, edges[i].end_node_id);
    }
}

int main() {
    // Add some nodes to the network
    add_node("Node A");
    add_node("Node B");
    add_node("Node C");
    add_node("Node D");
    
    // Add some edges to the network
    add_edge(0, 1);
    add_edge(1, 2);
    add_edge(2, 3);
    add_edge(3, 0);
    
    // Print the network topology
    print_topology();
    
    return EXIT_SUCCESS;
}