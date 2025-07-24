//FormAI DATASET v1.0 Category: Graph representation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of nodes in the graph
#define MAX_NODES 10

// Define a struct to represent the edges between nodes
typedef struct {
    int node1;
    int node2;
} Edge;

// Define a struct to represent the graph
typedef struct {
    int num_nodes;
    Edge edges[MAX_NODES];
} Graph;

// Function to add an edge to the graph
void add_edge(Graph *graph, int node1, int node2) {
    Edge edge = {node1, node2};
    graph->edges[graph->num_nodes++] = edge;
}

// Function to print the graph
void print_graph(Graph graph) {
    printf("Number of nodes: %d\n", graph.num_nodes);
    printf("Edges:\n");
    for (int i = 0; i < graph.num_nodes; i++) {
        printf("%d-%d\n", graph.edges[i].node1, graph.edges[i].node2);
    }
}

int main() {

    // Create a new graph
    Graph graph;
    graph.num_nodes = 0;

    // Add some edges
    add_edge(&graph, 0, 1);
    add_edge(&graph, 0, 2);
    add_edge(&graph, 1, 2);
    add_edge(&graph, 2, 3);
    add_edge(&graph, 3, 4);

    // Print the graph
    print_graph(graph);

    return 0;
}