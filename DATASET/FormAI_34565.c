//FormAI DATASET v1.0 Category: Graph representation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

// Graph struct
struct Graph {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
};

// Initializes the graph with numVertices
void initGraph(struct Graph* graph, int numVertices) {
    graph->numVertices = numVertices;

    // Set all edges to 0 (no connections)
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

// Adds an edge between vertices v1 and v2
void addEdge(struct Graph* graph, int v1, int v2) {
    // Set edges both ways (undirected)
    graph->adjMatrix[v1][v2] = 1;
    graph->adjMatrix[v2][v1] = 1;
}

// Prints the adjacency matrix (graph representation)
void printAdjMatrix(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Initialize graph with 5 vertices
    struct Graph graph;
    initGraph(&graph, 5);

    // Add some edges
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 4);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);

    // Print the adjacency matrix
    printf("Adjacency Matrix:\n");
    printAdjMatrix(&graph);

    return 0;
}