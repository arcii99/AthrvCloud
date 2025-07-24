//FormAI DATASET v1.0 Category: Graph representation ; Style: thoughtful
#include<stdio.h>

void main()
{
    //declare variables for the graph
    int nodes,edges,i,j,x,y;
    printf("Enter number of nodes in the graph:");
    scanf("%d",&nodes);
    printf("Enter number of edges in the graph:");
    scanf("%d",&edges);

    //initialize the graph with nodes
    int graph[nodes][nodes];
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            graph[i][j]=0;
        }
    }

    //add edges to the graph
    printf("Enter the edges separated by space:\n");
    for(i=0;i<edges;i++)
    {
        scanf("%d%d",&x,&y);
        graph[x][y]=1;
    }

    //display the graph
    printf("\nGraph:\n");
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}