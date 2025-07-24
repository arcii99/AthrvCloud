//FormAI DATASET v1.0 Category: Graph representation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Define a graph as an adjacency matrix
#define MAX_NODES 10
int graph[MAX_NODES][MAX_NODES];
int num_nodes = 0;

// Function to add an edge to the adjacency matrix
void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

// Function to print the adjacency matrix as a graph
void print_graph() {
    printf("   ");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < num_nodes; i++) {
        printf("%d: ", i);
        for (int j = 0; j < num_nodes; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Function to perform a shape-shift on the graph
void shape_shift() {
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            if (graph[i][j] == 1 && rand() % 2) {
                graph[i][j] = 0;
                graph[j][i] = 0;
                int k = rand() % num_nodes;
                int l = rand() % num_nodes;
                graph[k][l] = 1;
                graph[l][k] = 1;
            }
        }
    }
}

// Define the main function
int main() {
    // Add some edges to the graph
    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(0, 3);
    add_edge(1, 2);
    add_edge(2, 3);

    // Print the graph
    printf("Original Graph:\n");
    print_graph();

    // Perform a shape-shift on the graph
    shape_shift();

    // Print the graph after the shape-shift
    printf("\nGraph After Shape-Shifting:\n");
    print_graph();

    return 0;
}