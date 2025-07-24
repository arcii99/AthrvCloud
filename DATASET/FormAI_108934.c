//FormAI DATASET v1.0 Category: Graph representation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// struct definition for graph
typedef struct {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
}Graph;

// function to initialize a graph - sets all edges to 0
void initializeGraph(Graph *graph, int numVertices) {
    graph->numVertices = numVertices;
    for(int i = 0; i < numVertices; i++) {
        for(int j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

// function to add an edge to the graph
void addEdge(Graph *graph, int vertice1, int vertice2) {
    graph->adjacencyMatrix[vertice1][vertice2] = 1;
    graph->adjacencyMatrix[vertice2][vertice1] = 1;
}

// function to print the graph
void printGraph(Graph *graph) {
    printf("\nAdjacency Matrix:\n  ");
    for(int i = 0; i < graph->numVertices; i++) {
        printf(" %d",i);
    }
    printf("\n");
    for(int i = 0; i < graph->numVertices; i++) {
        printf("%d|",i);
        for(int j = 0; j < graph->numVertices; j++) {
            printf(" %d",graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // create a graph with 5 vertices
    Graph graph;
    initializeGraph(&graph, 5);
    
    // add edges to the graph
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 4);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);
    
    // print the graph
    printGraph(&graph);
    
    return 0;
}