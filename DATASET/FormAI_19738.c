//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100 // Maximum number of nodes
#define MAX_EDGES 1000 // Maximum number of edges
#define MAX_NAME_SIZE 20 // Maximum size for node names

// Structure to hold node information
typedef struct {
    char name[MAX_NAME_SIZE];
    int id;
    int x, y; // Coordinates for visualization
} node_t;

// Structure to hold edge (connection) information
typedef struct {
    int node1_id, node2_id; // IDs of nodes it connects
    int weight;
} edge_t;

// Function to print graph information
void print_graph(node_t* nodes, edge_t* edges, int num_nodes, int num_edges) {
    printf("Nodes:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("    %d. %s (%d,%d)\n", nodes[i].id, nodes[i].name, nodes[i].x, nodes[i].y);
    }
    printf("Edges:\n");
    for (int i = 0; i < num_edges; i++) {
        printf("    %d. (%s,%s) weight=%d\n", i+1, nodes[edges[i].node1_id].name, nodes[edges[i].node2_id].name, edges[i].weight);
    }
}

int main() {
    node_t nodes[MAX_NODES];
    edge_t edges[MAX_EDGES];
    int num_nodes = 0;
    int num_edges = 0;

    // Add some nodes
    strcpy(nodes[num_nodes].name, "Router 1");
    nodes[num_nodes].id = num_nodes;
    nodes[num_nodes].x = 0;
    nodes[num_nodes].y = 0;
    num_nodes++;

    strcpy(nodes[num_nodes].name, "Switch 1");
    nodes[num_nodes].id = num_nodes;
    nodes[num_nodes].x = 1;
    nodes[num_nodes].y = 1;
    num_nodes++;

    strcpy(nodes[num_nodes].name, "Router 2");
    nodes[num_nodes].id = num_nodes;
    nodes[num_nodes].x = 2;
    nodes[num_nodes].y = 0;
    num_nodes++;

    // Add some edges
    edges[num_edges].node1_id = 0;
    edges[num_edges].node2_id = 1;
    edges[num_edges].weight = 5;
    num_edges++;

    edges[num_edges].node1_id = 1;
    edges[num_edges].node2_id = 2;
    edges[num_edges].weight = 10;
    num_edges++;

    // Print the graph
    print_graph(nodes, edges, num_nodes, num_edges);

    return 0;
}