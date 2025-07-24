//FormAI DATASET v1.0 Category: Graph representation ; Style: real-life
#include <stdio.h>

int main() {
    // Declare variables
    int vertices, edges;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);
    
    // Create adjacency matrix
    int graph[vertices][vertices];
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }
    
    // Take input for edges
    printf("Enter the edges:\n");
    int u, v;
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d: ", i+1);
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // Since this is an undirected graph
    }
    
    // Print adjacency matrix
    printf("The graph can be represented as follows:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}