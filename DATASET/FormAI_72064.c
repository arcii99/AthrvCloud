//FormAI DATASET v1.0 Category: Graph representation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct {
    int numVertices;
    int numEdges;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = 0;
    int i, j;
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(Graph* graph, int vertex1, int vertex2) {
    graph->adjacencyMatrix[vertex1][vertex2] = 1;
    graph->adjacencyMatrix[vertex2][vertex1] = 1;
    graph->numEdges++;
}

void displayGraph(Graph* graph) {
    int i, j;
    printf("\n   ");
    for (i = 0; i < graph->numVertices; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        for (j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    displayGraph(graph);
    free(graph);
    return 0;
}