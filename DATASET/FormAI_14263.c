//FormAI DATASET v1.0 Category: Graph representation ; Style: inquisitive
#include <stdio.h>

// Define a constant for the maximum number of vertices
#define MAX_VERTICES 10

// Define a struct to represent a vertex
typedef struct {
    int label;
    int visited;
} Vertex;

// Define a struct to represent a graph
typedef struct {
    int numVertices;
    int numEdges;
    Vertex vertices[MAX_VERTICES];
    int edges[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Define a function to initialize a graph
void initGraph(Graph* graph) {
    graph->numVertices = 0;
    graph->numEdges = 0;
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++) {
        graph->vertices[i].label = -1;
        graph->vertices[i].visited = 0;
        for (j = 0; j < MAX_VERTICES; j++) {
            graph->edges[i][j] = 0;
        }
    }
}

// Define a function to add a vertex to a graph
void addVertex(Graph* graph, int label) {
    if (graph->numVertices < MAX_VERTICES) {
        graph->vertices[graph->numVertices].label = label;
        graph->numVertices++;
    } else {
        printf("Error: graph is full\n");
    }
}

// Define a function to add an edge to a graph
void addEdge(Graph* graph, int vertex1, int vertex2) {
    if (vertex1 >= 0 && vertex1 < graph->numVertices && vertex2 >= 0 && vertex2 < graph->numVertices) {
        graph->edges[vertex1][vertex2] = 1;
        graph->edges[vertex2][vertex1] = 1;
        graph->numEdges++;
    } else {
        printf("Error: invalid vertex\n");
    }
}

// Define a function to print a graph
void printGraph(Graph* graph) {
    int i, j;
    printf("Number of vertices: %d\n", graph->numVertices);
    printf("Number of edges: %d\n", graph->numEdges);
    printf("Vertices: ");
    for (i = 0; i < graph->numVertices; i++) {
        printf("%d ", graph->vertices[i].label);
    }
    printf("\nEdges:\n");
    for (i = 0; i < graph->numVertices; i++) {
        for (j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->edges[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph graph;
    initGraph(&graph);
    addVertex(&graph, 1);
    addVertex(&graph, 2);
    addVertex(&graph, 3);
    addVertex(&graph, 4);
    addEdge(&graph, 0, 1);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 0);
    printGraph(&graph);
    return 0;
}