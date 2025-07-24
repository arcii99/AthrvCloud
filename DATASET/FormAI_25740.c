//FormAI DATASET v1.0 Category: Graph representation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

int main() {
    int n, m, i, j, v1, v2;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];

    // ask for number of vertices and edges
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &m);

    // initialize the adjacency matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    // prompt user to enter the edges
    printf("Enter the edges (v1 v2):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d", &v1, &v2);
        adjMatrix[v1][v2] = 1;
        adjMatrix[v2][v1] = 1; // assuming undirected graph
    }

    // display the adjacency matrix
    printf("The adjacency matrix for the graph is:\n");
    printf("  ");
    for (i = 0; i < n; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%d ", i);
        for (j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    return 0; 
}