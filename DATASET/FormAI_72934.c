//FormAI DATASET v1.0 Category: Graph representation ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Graph representation using an adjacency matrix
typedef struct Graph {
    int numNodes;
    int matrix[MAX_NODES][MAX_NODES];
} Graph;

// Function to create a new graph with n nodes
Graph* createGraph(int n) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numNodes = n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            graph->matrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge between two nodes in the graph
void addEdge(Graph* graph, int node1, int node2) {
    graph->matrix[node1][node2] = 1;
    graph->matrix[node2][node1] = 1;
}

// Function to print the graph representation
void printGraph(Graph* graph) {
    printf("Graph representation using adjacency matrix:\n");
    for(int i=0; i<graph->numNodes; i++) {
        for(int j=0; j<graph->numNodes; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Create a new graph with 5 nodes
    Graph* graph = createGraph(5);
    
    // Add some edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    
    // Print the graph representation
    printGraph(graph);
    
    // Free memory allocated for the graph
    free(graph);
    
    return 0;
}