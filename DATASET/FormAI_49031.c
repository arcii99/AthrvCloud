//FormAI DATASET v1.0 Category: Graph representation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct _graph {
    int num_vertices;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

/*
 * Function to initialize the graph.
 */
Graph* initGraph(int num_vertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph -> num_vertices = num_vertices;
    
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph -> adj_matrix[i][j] = 0;
        }
    }
    
    return graph;
}

/*
 * Function to add an edge to the graph.
 */
void addEdge(Graph* graph, int vertex1, int vertex2) {
    graph -> adj_matrix[vertex1][vertex2] = 1;
    graph -> adj_matrix[vertex2][vertex1] = 1;
}

/*
 * Function to print the graph.
 */
void printGraph(Graph* graph) {
    for (int i = 0; i < graph -> num_vertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < graph -> num_vertices; j++) {
            printf("%d ", graph -> adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = initGraph(6);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    
    printGraph(graph);
    
    return 0;
}