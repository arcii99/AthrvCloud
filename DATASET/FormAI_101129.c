//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

// Struct for defining a node in the network
typedef struct _node {
    int id;
    char name[50];
} node;

// Struct for defining an edge in the network
typedef struct _edge {
    int source_id;
    int dest_id;
    int cost;
} edge;

// Struct for defining the network topology
typedef struct _network_topology {
    int num_nodes;
    int num_edges;
    node nodes[MAX_NODES];
    edge edges[MAX_EDGES];
} network_topology;

// Function to add a node to the network topology
void add_node(network_topology* topology, char* name) {
    if (topology->num_nodes < MAX_NODES) {
        node n;
        n.id = topology->num_nodes;
        strcpy(n.name, name);
        topology->nodes[topology->num_nodes++] = n;
    }
}

// Function to add an edge to the network topology
void add_edge(network_topology* topology, int source_id, int dest_id, int cost) {
    if (topology->num_edges < MAX_EDGES) {
        edge e;
        e.source_id = source_id;
        e.dest_id = dest_id;
        e.cost = cost;
        topology->edges[topology->num_edges++] = e;
    }
}

// Function to print the network topology
void print_topology(network_topology* topology) {
    printf("Network Topology:\n");
    printf("%d nodes, %d edges\n", topology->num_nodes, topology->num_edges);
    printf("Nodes:\n");
    for (int i = 0; i < topology->num_nodes; i++) {
        printf("    %d: %s\n", topology->nodes[i].id, topology->nodes[i].name);
    }
    printf("Edges:\n");
    for (int i = 0; i < topology->num_edges; i++) {
        printf("    (%d, %d): cost=%d\n", topology->edges[i].source_id, topology->edges[i].dest_id, topology->edges[i].cost);
    }
}

// Main function to test the network topology mapper
int main() {
    network_topology topology;
    topology.num_nodes = 0;
    topology.num_edges = 0;

    // Add nodes to the topology
    add_node(&topology, "Node A");
    add_node(&topology, "Node B");
    add_node(&topology, "Node C");
    add_node(&topology, "Node D");

    // Add edges to the topology
    add_edge(&topology, 0, 1, 5);
    add_edge(&topology, 0, 2, 10);
    add_edge(&topology, 1, 2, 3);
    add_edge(&topology, 1, 3, 7);
    add_edge(&topology, 2, 3, 1);

    // Print the network topology
    print_topology(&topology);

    return 0;
}