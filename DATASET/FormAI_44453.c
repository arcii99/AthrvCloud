//FormAI DATASET v1.0 Category: Graph representation ; Style: peaceful
#include <stdio.h>

// Define constants to represent graph properties
#define MAX_VERTICES 50
#define FALSE 0
#define TRUE 1

// Define the graph structure
typedef struct Graph {
    int nVertices;
    int nEdges;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Initialize the graph
void initializeGraph(Graph* graph) {
    int i, j;
    graph->nVertices = 0;
    graph->nEdges = 0;
    for(i = 0; i < MAX_VERTICES; i++) {
        for(j = 0; j < MAX_VERTICES; j++) {
            graph->adjacencyMatrix[i][j] = FALSE;
        }
    }
}

// Add a vertex to the graph
void addVertex(Graph* graph) {
    if(graph->nVertices < MAX_VERTICES) {
        graph->nVertices++;
    }
    else {
        printf("Error: Graph has reached maximum number of vertices.\n");
    }
}

// Add an edge to the graph
void addEdge(Graph* graph, int source, int destination) {
    if(source < graph->nVertices && destination < graph->nVertices) {
        graph->adjacencyMatrix[source][destination] = TRUE;
        graph->adjacencyMatrix[destination][source] = TRUE;
        graph->nEdges++;
    }
    else {
        printf("Error: Invalid vertex.\n");
    }
}

// Print the graph
void printGraph(Graph* graph) {
    int i, j;
    printf("Adjacency Matrix:\n");
    for(i = 0; i < graph->nVertices; i++) {
        for(j = 0; j < graph->nVertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph graph;
    initializeGraph(&graph);

    // Add vertices to the graph
    addVertex(&graph);
    addVertex(&graph);
    addVertex(&graph);
    addVertex(&graph);
    addVertex(&graph);

    // Add edges to the graph
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 2, 4);
    addEdge(&graph, 3, 4);

    // Print the graph
    printGraph(&graph);

    return 0;
}