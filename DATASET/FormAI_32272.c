//FormAI DATASET v1.0 Category: Graph representation ; Style: automated
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 10

int main()
{
    int n, i, j, edges;
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix to 0 (no edges)
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Add edges to adjacency matrix
    for (i = 0; i < edges; i++) {
        int u, v;
        printf("Enter edge (u, v): ");
        scanf("%d %d", &u, &v);
        adjacency_matrix[u][v] = adjacency_matrix[v][u] = 1;
    }

    // Print adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}