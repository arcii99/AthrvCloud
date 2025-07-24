//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Constants
#define MAX_VERTICES 50
#define NOT_COLORED -1

// Structs
typedef struct {
    int vertices[MAX_VERTICES];
    int numVertices;
} Graph;

// Function declarations
void initializeGraph(Graph* graph);
void addVertex(Graph* graph, int vertex);
void addEdge(Graph* graph, int vertex1, int vertex2);
void printGraph(Graph* graph);
void colorGraph(Graph* graph);

// Main function
int main() {
    Graph graph;
    initializeGraph(&graph);

    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);
    addEdge(&graph, 4, 5);
    addEdge(&graph, 5, 1);
    addEdge(&graph, 2, 4);

    printf("Graph:\n");
    printGraph(&graph);

    printf("\nColoring graph...\n");
    colorGraph(&graph);

    printf("\nColored graph:\n");
    printGraph(&graph);

    return 0;
}

// Function definitions
void initializeGraph(Graph* graph) {
    graph->numVertices = 0;

    int i;
    for (i = 0; i < MAX_VERTICES; i++) {
        graph->vertices[i] = 0;
    }
}

void addVertex(Graph* graph, int vertex) {
    graph->vertices[graph->numVertices] = vertex;
    graph->numVertices++;
}

void addEdge(Graph* graph, int vertex1, int vertex2) {
    addVertex(graph, vertex1);
    addVertex(graph, vertex2);
}

void printGraph(Graph* graph) {
    int i, j;
    for (i = 0; i < graph->numVertices; i++) {
        printf("%d: ", graph->vertices[i]);

        for (j = 0; j < graph->numVertices; j++) {
            if (graph->vertices[i] == graph->vertices[j])
                continue;

            if (graph->vertices[j] % graph->vertices[i] == 0)
                printf("%d ", graph->vertices[j]);
        }

        printf("\n");
    }
}

void colorGraph(Graph* graph) {
    int colors[MAX_VERTICES];
    int i, j, k;

    for (i = 0; i < graph->numVertices; i++) {
        colors[i] = NOT_COLORED;
    }

    colors[0] = 0;

    for (i = 1; i < graph->numVertices; i++) {
        for (j = 0; j < graph->numVertices; j++) {
            if (graph->vertices[i] == graph->vertices[j])
                continue;

            if (graph->vertices[j] % graph->vertices[i] == 0) {
                if (colors[j] == NOT_COLORED)
                    continue;

                colors[i] = (colors[i] + colors[j]) % 2;
            }
        }

        if (colors[i] == NOT_COLORED)
            colors[i] = 0;
    }

    for (i = 0; i < graph->numVertices; i++) {
        for (j = i+1; j < graph->numVertices; j++) {
            if (graph->vertices[i] == graph->vertices[j])
                continue;

            if (graph->vertices[j] % graph->vertices[i] == 0) {
                if (colors[i] != colors[j]) {
                    printf("Error: Graph cannot be colored.");
                    exit(1);
                }
            }
        }
    }

    for (i = 0; i < graph->numVertices; i++) {
        graph->vertices[i] = colors[i];
    }
}