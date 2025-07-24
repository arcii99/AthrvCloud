//FormAI DATASET v1.0 Category: Graph representation ; Style: unmistakable
#include <stdio.h>

#define MAX_VERTICES 10

// Function to print the adjacency matrix
void printGraph(int graph[][MAX_VERTICES], int V) {
    int i, j;
    printf("Adjacency matrix representation of the graph:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V, E, i, j, v1, v2;

    // Get number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    // Create adjacency matrix
    int graph[MAX_VERTICES][MAX_VERTICES];
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    // Add edges to the graph
    for (i = 0; i < E; i++) {
        printf("Enter edge %d: ", i + 1);
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    // Print the adjacency matrix
    printGraph(graph, V);

    return 0;
}