//FormAI DATASET v1.0 Category: Graph representation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Graph represented using adjacency matrix
int graph[MAX_VERTICES][MAX_VERTICES];

// Helper function to initialize graph to all zeros
void initializeGraph() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = 0;
        }
    }
}

// Helper function to add an edge to the graph
void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

// Helper function to print the graph
void printGraph() {
    printf("\nGraph:\n");

    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            printf("%d ", graph[i][j]);
        }

        printf("\n");
    }
}

// Main function
int main() {
    initializeGraph();

    // Add edges to the graph
    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(3, 5);
    addEdge(4, 5);

    printGraph();

    return 0;
}