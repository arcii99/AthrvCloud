//FormAI DATASET v1.0 Category: Graph representation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10

// Data structure to represent a graph
struct Graph {
    int adjMatrix[MAX_NODES][MAX_NODES];
    int numNodes;
};

// Function to initialize a graph
void initGraph(struct Graph *graph, int numNodes) {
    graph->numNodes = numNodes;

    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge to a graph
void addEdge(struct Graph *graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

// Function to print a graph
void printGraph(struct Graph *graph) {
    printf("Graph:\n");

    for (int i = 0; i < graph->numNodes; i++) {
        printf("%d: ", i);

        for (int j = 0; j < graph->numNodes; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }

        printf("\n");
    }
}

int main() {
    // Create a graph with 5 nodes
    struct Graph *graph = (struct Graph*) malloc(sizeof(struct Graph));
    initGraph(graph, 5);

    // Add some edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    // Print the graph
    printGraph(graph);

    return 0;
}