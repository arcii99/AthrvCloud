//FormAI DATASET v1.0 Category: Graph representation ; Style: scalable
#include <stdio.h>

#define MAX_VERTICES 100

typedef struct {
    int matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

Graph createEmptyGraph(int num_vertices) {
    Graph graph;
    graph.num_vertices = num_vertices;

    int i, j;
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            graph.matrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(Graph *graph, int vertex1, int vertex2) {
    graph->matrix[vertex1][vertex2] = 1;
    graph->matrix[vertex2][vertex1] = 1;
}

void removeEdge(Graph *graph, int vertex1, int vertex2) {
    graph->matrix[vertex1][vertex2] = 0;
    graph->matrix[vertex2][vertex1] = 0;
}

void printGraph(Graph *graph) {
    int i, j;
    for (i = 0; i < graph->num_vertices; i++) {
        for (j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph graph = createEmptyGraph(5);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 2, 4);
    addEdge(&graph, 3, 4);

    printGraph(&graph);

    removeEdge(&graph, 2, 4);

    printf("\n");

    printGraph(&graph);

    return 0;
}