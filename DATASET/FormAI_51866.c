//FormAI DATASET v1.0 Category: Graph representation ; Style: systematic
#include<stdio.h>

int main()
{
    int adjacency_matrix[10][10], n, i, j;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);

    //Initialize the adjacency matrix with zeros
    for(i=0; i < n; i++)
    {
        for(j=0; j < n; j++)
        {
            adjacency_matrix[i][j] = 0;
        }
    }

    //Input the adjacency matrix
    printf("\nEnter the adjacency matrix of the graph:\n");
    for(i=0; i < n; i++)
    {
        for(j=0; j < n; j++)
        {
            scanf("%d", &adjacency_matrix[i][j]);
        }
    }

    //Print the adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for(i=0; i < n; i++)
    {
        for(j=0; j < n; j++)
        {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}