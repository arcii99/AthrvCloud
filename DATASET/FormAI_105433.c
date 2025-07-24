//FormAI DATASET v1.0 Category: Graph representation ; Style: accurate
#include <stdio.h>

#define MAX_VERTICES 100

// Define the graph data structure
typedef struct {
    int matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

// Initialize the graph with blank values
void initializeGraph(Graph* graph, int num_vertices) {
    graph->num_vertices = num_vertices;

    for(int i = 0; i < num_vertices; i++) {
        for(int j = 0; j < num_vertices; j++) {
            graph->matrix[i][j] = 0;
        }
    }
}

// Add a directed edge to the graph
void addEdge(Graph* graph, int source, int destination) {
    graph->matrix[source][destination] = 1;
}

// Print the graph as an adjacency matrix
void printGraph(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for(int i = 0; i < graph->num_vertices; i++) {
        for(int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph graph;
    initializeGraph(&graph, 6);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 4);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 2, 4);
    addEdge(&graph, 3, 4);
    addEdge(&graph, 4, 5);

    printGraph(&graph);

    return 0;
}