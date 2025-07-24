//FormAI DATASET v1.0 Category: Graph representation ; Style: statistical
#include <stdio.h>

// Define a constant size for the graph matrix
#define MAX_SIZE 10

// Define a struct to hold the graph information
struct Graph {
    int vertices;
    int edges;
    int matrix[MAX_SIZE][MAX_SIZE];
};

// Function to initialize the graph with zero weights
void initializeGraph(struct Graph *graph) {
    int i, j;
    for (i=0; i<graph->vertices; i++) {
        for (j=0; j<graph->vertices; j++) {
            graph->matrix[i][j] = 0;
        }
    }
}

// Function to add an edge with weight to the graph
void addEdge(struct Graph *graph, int source, int destination, int weight) {
    graph->matrix[source][destination] = weight;
    graph->matrix[destination][source] = weight;
    graph->edges++;
}

// Function to print the graph matrix
void printGraph(struct Graph *graph) {
    int i, j;
    for (i=0; i<graph->vertices; i++) {
        for (j=0; j<graph->vertices; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct Graph graph;
    graph.vertices = 5;
    graph.edges = 0;
    initializeGraph(&graph);
    addEdge(&graph, 0, 1, 5);
    addEdge(&graph, 1, 2, 4);
    addEdge(&graph, 2, 3, 3);
    addEdge(&graph, 3, 4, 2);
    addEdge(&graph, 4, 0, 1);
    printGraph(&graph);
    return 0;
}