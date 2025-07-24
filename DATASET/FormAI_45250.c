//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 500

typedef struct {
    int start_node;
    int end_node;
} Edge;

int main() {
    int num_nodes, num_edges;
    char node_names[MAX_NODES][20];
    Edge edges[MAX_EDGES];

    srand(time(NULL)); // Seed the random number generator

    // Generate random number of nodes
    num_nodes = rand() % MAX_NODES + 1; // Add 1 to avoid 0 nodes
    printf("Generating %d nodes...\n", num_nodes);

    // Generate random node names
    for (int i = 0; i < num_nodes; i++) {
        sprintf(node_names[i], "Node%d", i+1);
    }

    // Generate random number of edges
    num_edges = rand() % MAX_EDGES + 1;
    printf("Generating %d edges...\n", num_edges);

    // Generate random edges
    for (int i = 0; i < num_edges; i++) {
        edges[i].start_node = rand() % num_nodes;
        edges[i].end_node = rand() % num_nodes;
    }

    // Print mapping
    printf("Mapping:\n");
    for (int i = 0; i < num_edges; i++) {
        printf("%s -> %s\n", node_names[edges[i].start_node], node_names[edges[i].end_node]);
    }

    return 0;
}