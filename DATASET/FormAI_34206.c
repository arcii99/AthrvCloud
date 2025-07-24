//FormAI DATASET v1.0 Category: Graph representation ; Style: high level of detail
#include <stdio.h>

#define MAX_VERTICES 100

int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
int num_vertices;

void addEdge(int src, int dest) {
    adjacency_matrix[src][dest] = 1;
    adjacency_matrix[dest][src] = 1;
}

void printGraph() {
    printf("Graph (Adjacency Matrix):\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    num_vertices = 6; // Set the number of vertices in the graph

    // Add edges between vertices
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(3, 5);

    // Print the graph representation
    printGraph();

    return 0;
}