//FormAI DATASET v1.0 Category: Graph representation ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Graph represented with an adjacency matrix
typedef struct Graph {
    int vertices[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

// Function to initialize the graph
void initialize_graph(Graph* graph, int num_vertices) {
    graph->num_vertices = num_vertices;

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->vertices[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void add_edge(Graph* graph, int vertex1, int vertex2) {
    graph->vertices[vertex1][vertex2] = 1;
    graph->vertices[vertex2][vertex1] = 1;
}

// Function to print the graph
void print_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->vertices[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph graph;
    initialize_graph(&graph, 5);

    add_edge(&graph, 0, 1);
    add_edge(&graph, 1, 2);
    add_edge(&graph, 2, 3);
    add_edge(&graph, 3, 4);
    add_edge(&graph, 4, 0);

    print_graph(&graph);

    return 0;
}