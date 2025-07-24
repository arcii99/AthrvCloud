//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 10
#define MAX_EDGES 20

// Struct for a node
typedef struct node {
    char name[20];
    bool visited;
} Node;

// Struct for an edge
typedef struct edge {
    int source;
    int dest;
} Edge;

// Global variables for graph
Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];
int adj_matrix[MAX_NODES][MAX_NODES];
int num_nodes = 0;
int num_edges = 0;

/**
 * Function to add a node to the graph
 */
void add_node(char* name) {
    Node n;
    strcpy(n.name, name);
    n.visited = false;
    nodes[num_nodes++] = n;
}

/**
 * Function to add an edge to the graph
 */
void add_edge(int source, int dest) {
    Edge e;
    e.source = source;
    e.dest = dest;
    edges[num_edges++] = e;
    adj_matrix[source][dest] = 1;
    adj_matrix[dest][source] = 1;
}

/**
 * Depth First Search (DFS) algorithm to traverse the graph
 */
void traverse_graph(int node_index) {
    Node n = nodes[node_index];
    printf("%s\n", n.name);
    n.visited = true;
    for (int i = 0; i < num_nodes; i++) {
        if (adj_matrix[node_index][i] == 1 && !nodes[i].visited) {
            traverse_graph(i);
        }
    }
}

/**
 * Main function to test the program
 */
int main() {
    // Create the nodes
    add_node("A");
    add_node("B");
    add_node("C");
    add_node("D");
    add_node("E");

    // Create the edges
    add_edge(0, 1);
    add_edge(1, 2);
    add_edge(2, 3);
    add_edge(3, 4);
    add_edge(4, 0);

    // Traverse the graph
    traverse_graph(0);
}