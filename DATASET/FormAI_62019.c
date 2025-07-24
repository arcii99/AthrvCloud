//FormAI DATASET v1.0 Category: Graph representation ; Style: thoughtful
#include <stdio.h>

#define MAX_VERTICES 100

// Graph Data Structure
typedef struct {
    int vertices[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
    int numEdges;
} Graph;

// Initialize graph values
void initGraph(Graph *graph) {
    int i, j;
    graph->numVertices = 0;
    graph->numEdges = 0;
    for(i=0; i<MAX_VERTICES; i++) {
        for(j=0; j<MAX_VERTICES; j++) {
            graph->vertices[i][j] = 0;
        }
    }
}

// Add vertex to the graph
void addVertex(Graph *graph) {
    if(graph->numVertices == MAX_VERTICES) {
        printf("Cannot add vertex. Maximum number of vertices reached.\n");
        return;
    }
    graph->numVertices++;
}

// Add edge to the graph
void addEdge(Graph *graph, int src, int dest) {
    if(src >= graph->numVertices || dest >= graph->numVertices) {
        printf("Invalid edge. Vertices not in graph.\n");
        return;
    }
    graph->vertices[src][dest] = 1;
    graph->vertices[dest][src] = 1;
    graph->numEdges++;
}

// Print graph in matrix form
void printGraph(Graph *graph) {
    int i, j;
    printf("Vertices: %d, Edges: %d\n", graph->numVertices, graph->numEdges);
    for(i=0; i<graph->numVertices; i++) {
        for(j=0; j<graph->numVertices; j++) {
            printf("%d ", graph->vertices[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    Graph graph;
    initGraph(&graph);

    // Add 5 vertices to the graph
    int i;
    for(i=0; i<5; i++) {
        addVertex(&graph);
    }

    // Add 5 edges to the graph
    addEdge(&graph, 0, 1);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);
    addEdge(&graph, 4, 0);

    // Print graph
    printGraph(&graph);

    return 0;
}