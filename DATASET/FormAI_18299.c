//FormAI DATASET v1.0 Category: Graph representation ; Style: innovative
#include <stdio.h>

int main()
{
    int i, j, n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    char vertices[n];
    int edges[n][n];

    printf("Enter the names of the nodes: ");
    for(i=0; i<n; i++)
        scanf(" %c", &vertices[i]);

    printf("Enter the edges between the nodes: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("Is there an edge between node %c and node %c? (1 for yes, 0 for no): ", vertices[i], vertices[j]);
            scanf("%d", &edges[i][j]);
        }
    }

    printf("The graph is represented as:\n");

    //printing the vertices
    printf("\nVertices: ");
    for(i=0; i<n; i++)
        printf("%c ", vertices[i]);

    //printing the edges
    printf("\nEdges:\n   ");
    for(i=0; i<n; i++)
        printf("%c ", vertices[i]);
    for(i=0; i<n; i++)
    {
        printf("\n%c  ", vertices[i]);
        for(j=0; j<n; j++)
        {
            printf("%d ", edges[i][j]);
        }
    }

    return 0;
}