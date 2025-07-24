//FormAI DATASET v1.0 Category: Graph representation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// Graph structure to store vertices and edges
typedef struct Graph {
    int vertices;
    int adjmatrix[MAX][MAX];
} Graph;

// Function to initialize graph with zero edge weights
void initGraph(Graph *graph) {
    graph->vertices = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            graph->adjmatrix[i][j] = 0;
        }
    }
}

// Function to add edge to the graph
void addEdge(Graph *graph, int src, int dest) {
    graph->adjmatrix[src][dest] = 1;
    graph->adjmatrix[dest][src] = 1;
}

// Function to print the graph
void printGraph(Graph *graph) {
    printf("\nGraph:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adjmatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    Graph graph;
    initGraph(&graph);

    // Add vertices
    graph.vertices = 5;

    // Add edges
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);
    addEdge(&graph, 4, 0);

    // Print the graph
    printGraph(&graph);

    return 0;
}