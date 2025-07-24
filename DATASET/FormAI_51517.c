//FormAI DATASET v1.0 Category: Graph representation ; Style: rigorous
#include<stdio.h>

int main()
{
    int n, i, j, k;
    
    printf("Enter the number of vertices of Graph: ");
    scanf("%d", &n);

    int graph[n][n];
    
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }

    printf("\nGraph representation using adjacency matrix:\n\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }

    printf("\nGraph representation using adjacency list:\n\n");
    
    for(i=0;i<n;i++)
    {
        printf("Vertex %d : ", i+1);
        for(j=0,k=0;j<n;j++)
        {
            if(graph[i][j] == 1)
            {
                printf("%d ", j+1);
                k = 1;
            }
        }
        if(k == 0)
        {
            printf("No adjacent vertices");
        }
        printf("\n");
    }

    return 0;
}