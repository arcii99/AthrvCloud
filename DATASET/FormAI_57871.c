//FormAI DATASET v1.0 Category: Graph representation ; Style: accurate
#include <stdio.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 10

// Define the graph structure
struct Graph {
    int numOfVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Define a function to initialize the graph
void initGraph(struct Graph* graph, int numOfVertices) {
    graph->numOfVertices = numOfVertices;

    for (int i = 0; i < numOfVertices; i++) {
        for (int j = 0; j < numOfVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

// Define a function to add an edge between two vertices
void addEdge(struct Graph* graph, int u, int v) {
    graph->adjacencyMatrix[u][v] = 1;
    graph->adjacencyMatrix[v][u] = 1;
}

// Define a function to print the graph
void printGraph(struct Graph* graph) {
    printf("The graph is:\n\n");

    for (int i = 0; i < graph->numOfVertices; i++) {
        for (int j = 0; j < graph->numOfVertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        
        printf("\n");
    }
}

// Define the main function
int main() {
    struct Graph graph;

    initGraph(&graph, 5);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 3);

    printGraph(&graph);

    return 0;
}