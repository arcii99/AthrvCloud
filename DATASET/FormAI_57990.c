//FormAI DATASET v1.0 Category: Graph representation ; Style: complete
#include<stdio.h>
#define MAX 100

int main()
{
    int n, i, j, matrix[MAX][MAX];

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for(i=0; i<n; i++)
    for(j=0; j<n; j++)
    scanf("%d", &matrix[i][j]);

    printf("\nGraph Representation:\n");
    printf("=====================\n");

    //Printing graph representation
    printf("  ");
    for(i=0; i<n; i++)
        printf("%d ", i+1);
    printf("\n");
    for(i=0; i<n; i++)
    {
        printf("%d ", i+1);
        for(j=0; j<n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    return 0;
}