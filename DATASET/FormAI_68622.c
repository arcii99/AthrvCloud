//FormAI DATASET v1.0 Category: Graph representation ; Style: automated
#include<stdio.h>
#include<stdlib.h>

int main() {
    int vertices, edges, i, j, v1, v2;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    // Dynamically allocate memory for the Adjacency Matrix
    int** adjMatrix = (int**)malloc(sizeof(int*) * vertices);
    for (i = 0; i < vertices; i++) {
        adjMatrix[i] = (int*)malloc(sizeof(int) * vertices);
        for (j = 0; j < vertices; j++)
            adjMatrix[i][j] = 0;
    }

    // Inputting the edges of the graph
    printf("Enter the edges of the graph:\n");
    for (i = 0; i < edges; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &v1, &v2);
        adjMatrix[v1 - 1][v2 - 1] = 1;
        adjMatrix[v2 - 1][v1 - 1] = 1;
    }

    // Printing the Adjacency Matrix
    printf("\nAdjacency Matrix:\n");
    printf("   ");
    for (i = 0; i < vertices; i++) printf("%2d ", i+1);
    printf("\n");
    for (i = 0; i < vertices; i++) {
        printf("%2d ", i+1);
        for (j = 0; j < vertices; j++)
            printf("%2d ", adjMatrix[i][j]);
        printf("\n");
    }

    // Freeing the dynamically allocated memory
    for (i = 0; i < vertices; i++) free(adjMatrix[i]);
    free(adjMatrix);

    return 0;
}