//FormAI DATASET v1.0 Category: Graph representation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Graph Structure
struct Graph {
    int vertices;
    int edges[MAX_VERTICES][MAX_VERTICES];
};

// Initialize graph with no edges
void initializeGraph(struct Graph *graph) {
    graph->vertices = 0;
    for(int i = 0; i < MAX_VERTICES; i++) {
        for(int j = 0; j < MAX_VERTICES; j++) {
            graph->edges[i][j] = 0;
        }
    }
}

// Add edge between vertices
void addEdge(struct Graph *graph, int vertex1, int vertex2) {
    if(vertex1 >= graph->vertices || vertex2 >= graph->vertices) {
        printf("Invalid vertices!\n");
        return;
    }
    graph->edges[vertex1][vertex2] = 1;
    graph->edges[vertex2][vertex1] = 1;
}

// Print the graph
void printGraph(struct Graph graph) {
    printf("   ");
    for(int i = 0; i < graph.vertices; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for(int i = 0; i < graph.vertices; i++) {
        printf("%d: ", i);
        for(int j = 0; j < graph.vertices; j++) {
            printf("%d ", graph.edges[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct Graph graph;
    initializeGraph(&graph);

    // Add vertices
    graph.vertices = 5;

    // Add edges
    addEdge(&graph, 0, 1);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);
    addEdge(&graph, 4, 0);

    // Print graph
    printGraph(graph);

    return 0;
}