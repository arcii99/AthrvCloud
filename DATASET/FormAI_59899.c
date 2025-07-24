//FormAI DATASET v1.0 Category: Graph representation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10

typedef struct Graph {
    int numVertices;
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    
    for(int i=0; i<numVertices; i++) {
        for(int j=0; j<numVertices; j++) {
            graph->adjacency_matrix[i][j] = 0;
        }
    }
    
    return graph;
}

void addEdge(Graph* graph, int source, int destination, int weight) {
    graph->adjacency_matrix[source][destination] = weight;
}

void printGraph(Graph* graph) {
    for(int i=0; i<graph->numVertices; i++) {
        for(int j=0; j<graph->numVertices; j++) {
            printf("%d ", graph->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(4);
    addEdge(graph, 0, 1, 5);
    addEdge(graph, 0, 2, 7);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 2, 0, 3);
    addEdge(graph, 2, 3, 2);
    addEdge(graph, 3, 3, 1);
    
    printf("\nGraph Representation:\n");
    printGraph(graph);
    
    return 0;
}