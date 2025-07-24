//FormAI DATASET v1.0 Category: Graph representation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

struct graph {
    int vertices;
    int **adjacency_matrix;
};

typedef struct graph Graph;

Graph *create_graph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjacency_matrix = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        graph->adjacency_matrix[i] = (int *)calloc(vertices, sizeof(int));
    }
    return graph;
}

void add_edge(Graph *graph, int source, int destination) {
    graph->adjacency_matrix[source][destination] = 1;
    graph->adjacency_matrix[destination][source] = 1;
}

void display_adjacency_matrix(Graph *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph *graph = create_graph(5);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    printf("The adjacency matrix of the graph is:\n");
    display_adjacency_matrix(graph);
    return 0;
}