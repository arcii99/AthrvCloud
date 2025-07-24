//FormAI DATASET v1.0 Category: Graph representation ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n, a[10][10], i, j, sum;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d", &a[i][j]);
    printf("The graph is:\n");
    for(i=1; i<=n; i++)
        {
            printf("\n%d : ", i);
            for(j=1; j<=n; j++)
                if(a[i][j]==1)
                    printf("->%d ", j);
        }
    printf("\n");
    for(i=1; i<=n; i++)
        {
            printf("\n%d : ", i);
            sum=0;
            for(j=1; j<=n; j++)
                sum+=a[i][j];
            printf("(%d) ", sum);
            for(j=1; j<=n; j++)
                if(a[i][j]==1)
                    printf("->%d ", j);
        }
    printf("\n");
}