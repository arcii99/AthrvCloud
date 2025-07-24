//FormAI DATASET v1.0 Category: Graph representation ; Style: mathematical
#include <stdio.h>

#define MAX_VERTICES 10

typedef struct {
    int matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

void initializeGraph(Graph *graph) {
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            graph->matrix[i][j] = 0;
        }
    }
    graph->num_vertices = 0;
}

void addVertex(Graph *graph) {
    if (graph->num_vertices < MAX_VERTICES) {
        graph->num_vertices++;
    }
}

void addEdge(Graph *graph, int v1, int v2) {
    graph->matrix[v1][v2] = 1;
    graph->matrix[v2][v1] = 1;
}

void printGraph(Graph *graph) {
    int i, j;
    for (i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: ", i);
        for (j = 0; j < graph->num_vertices; j++) {
            if (graph->matrix[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph graph;
    initializeGraph(&graph);

    addVertex(&graph);
    addVertex(&graph);
    addVertex(&graph);
    addVertex(&graph);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 3);

    printGraph(&graph);

    return 0;
}