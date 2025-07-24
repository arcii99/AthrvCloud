//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: futuristic
#include<stdio.h>

int main()
{
    int n, i, j, adj_matrix[50][50];
    
    printf("Enter the number of nodes in the network topology: ");
    scanf("%d",&n);
    
    // Input the adjacency matrix
    printf("\nEnter the adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&adj_matrix[i][j]);
        }
    }

    // Display the network topology diagram
    printf("\n\nThe network topology diagram is:\n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(adj_matrix[i][j]==1)
                printf("<--%d-->%d ",i+1,j+1);
        }
        printf("\n");
    }

    return 0;
}