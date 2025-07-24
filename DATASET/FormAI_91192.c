//FormAI DATASET v1.0 Category: Graph representation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100 // maximum number of vertices in the graph

typedef struct {
    int vertexCount; // number of vertices in the graph
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix representation of the graph
} Graph;

// function to create an empty graph
Graph* createGraph(int vertexCount) {
    Graph* graph = malloc(sizeof(Graph));
    graph->vertexCount = vertexCount;
    // initialize all entries in the adjacency matrix to 0
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
    return graph;
}

// function to add an edge to the graph
void addEdge(Graph* graph, int v1, int v2) {
    // update the adjacency matrix entries for both vertices
    graph->adjacencyMatrix[v1][v2] = 1;
    graph->adjacencyMatrix[v2][v1] = 1;
}

// function to print the adjacency matrix representation of the graph
void printGraph(Graph* graph) {
    printf("Adjacency Matrix Representation of the Graph:\n");
    for (int i = 0; i < graph->vertexCount; i++) {
        for (int j = 0; j < graph->vertexCount; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // create a new graph with 5 vertices
    Graph* graph = createGraph(5);
    // add some edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);
    // print the adjacency matrix representation of the graph
    printGraph(graph);
    // free the memory allocated to the graph
    free(graph);
    return 0;
}