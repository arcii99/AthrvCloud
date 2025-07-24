//FormAI DATASET v1.0 Category: Graph representation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

// Define a struct for a vertex
typedef struct vertex {
    int data;
    int visited;
} vertex;

// Define a struct for edges
typedef struct edge {
    int start;
    int end;
    int weight;
} edge;

// Define a struct for a graph
typedef struct graph {
    vertex vertices[MAX_VERTICES];
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
    int numEdges;
} graph;

// Initialize a new graph
void initGraph(graph* g) {
    int i, j;
    g->numVertices = 0;
    g->numEdges = 0;
    for (i = 0; i < MAX_VERTICES; i++) {
        g->vertices[i].visited = 0;
        for (j = 0; j < MAX_VERTICES; j++) {
            g->adjacencyMatrix[i][j] = 0;
        }
    }
}

// Add a vertex to the graph
void addVertex(graph* g, int data) {
    g->vertices[g->numVertices].data = data;
    g->numVertices++;
}

// Add an edge to the graph
void addEdge(graph* g, int start, int end, int weight) {
    g->adjacencyMatrix[start][end] = weight;
    g->numEdges++;
}

// Print the adjacency matrix of the graph
void printGraph(graph* g) {
    int i, j;
    printf("Adjacency Matrix:\n");
    for (i = 0; i < g->numVertices; i++) {
        for (j = 0; j < g->numVertices; j++) {
            printf("%d\t", g->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    graph g;
    initGraph(&g);

    // Add vertices to the graph
    addVertex(&g, 1);
    addVertex(&g, 2);
    addVertex(&g, 3);
    addVertex(&g, 4);
    addVertex(&g, 5);

    // Add edges to the graph
    addEdge(&g, 0, 1, 1);
    addEdge(&g, 0, 2, 2);
    addEdge(&g, 1, 2, 3);
    addEdge(&g, 1, 3, 4);
    addEdge(&g, 2, 3, 5);
    addEdge(&g, 3, 4, 6);

    // Print the adjacency matrix of the graph
    printGraph(&g);

    return 0;
}