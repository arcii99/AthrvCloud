//FormAI DATASET v1.0 Category: Graph representation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 4

int main()
{
    int matrix[MAX_VERTICES][MAX_VERTICES] = {{0, 1, 0, 1}, {1, 0, 1, 1}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    int i, j;

    printf("Graph Representation in Adjacency Matrix:\n");
    for(i = 0; i < MAX_VERTICES; i++)
    {
        for(j = 0; j < MAX_VERTICES; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }

    return 0;
}