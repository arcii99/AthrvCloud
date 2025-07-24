//FormAI DATASET v1.0 Category: Graph representation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

/* This program generates a unique C Graph representation using adjacency matrix */

int main() {
    int vertices, edges, i, j, v1, v2;
    
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);
    
    int **adjMatrix = (int**) malloc(vertices * sizeof(int*)); // allocate memory for the adjacency matrix
    
    for(i = 0; i < vertices; i++) {
        adjMatrix[i] = (int*) calloc(vertices, sizeof(int)); // initialize the adjacency matrix to 0
    }

    // adding edges to the graph
    for(i = 0; i < edges; i++) {
        printf("Enter vertices that are connected by edge %d (Example: 1 2): ", i+1);
        scanf("%d %d", &v1, &v2);
        adjMatrix[v1-1][v2-1] = 1; // set the adjacency matrix values accordingly
        adjMatrix[v2-1][v1-1] = 1;
    }

    // printing the adjacency matrix
    printf("\nThe adjacency matrix representation of the graph is:\n");
    for(i = 0; i < vertices; i++) {
        for(j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    // free the allocated memory
    for(i = 0; i < vertices; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    
    return 0;
}