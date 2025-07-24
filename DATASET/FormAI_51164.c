//FormAI DATASET v1.0 Category: Graph representation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 50

// Graph data structure
struct Graph {
    int num_nodes;
    int adjacency_matrix[MAX_NODES][MAX_NODES];
};

// Function to initialize a new graph
void init_graph(struct Graph *g, int num_nodes) {
    g->num_nodes = num_nodes;
    for(int i=0; i<num_nodes; i++) {
        for(int j=0; j<num_nodes; j++) {
            g->adjacency_matrix[i][j] = 0;
        }
    }
}

// Function to add a new edge to the graph
void add_edge(struct Graph *g, int node1, int node2, int weight) {
    g->adjacency_matrix[node1][node2] = weight;
    g->adjacency_matrix[node2][node1] = weight;
}

// Function to print the graph in a statistical style
void print_graph(struct Graph *g) {
    printf("\nGraph Representation:\n");

    int num_edges = 0;
    for(int i=0; i<g->num_nodes; i++) {
        for(int j=i+1; j<g->num_nodes; j++) {
            if(g->adjacency_matrix[i][j] != 0) {
                num_edges++;
            }
        }
    }

    printf("Number of nodes: %d\n", g->num_nodes);
    printf("Number of edges: %d\n", num_edges);

    printf("\nEdge List:\n");
    for(int i=0; i<g->num_nodes; i++) {
        for(int j=i+1; j<g->num_nodes; j++) {
            if(g->adjacency_matrix[i][j] != 0) {
                printf("(%d, %d): %d\n", i, j, g->adjacency_matrix[i][j]);
            }
        }
    }
}

int main() {
    // Initialize a new graph
    struct Graph g;
    init_graph(&g, 5);

    // Add some edges to the graph
    add_edge(&g, 0, 1, 2);
    add_edge(&g, 0, 3, 4);
    add_edge(&g, 1, 2, 1);
    add_edge(&g, 1, 3, 3);
    add_edge(&g, 2, 3, 2);
    add_edge(&g, 2, 4, 3);
    add_edge(&g, 3, 4, 1);

    // Print the graph in a statistical style
    print_graph(&g);

    return 0;
}