//FormAI DATASET v1.0 Category: Graph representation ; Style: creative
#include<stdio.h>

int main()
{
    printf("Welcome to my unique C Graph representation program!\n");

    //creating a graph with 5 nodes and 6 edges
    int nodes = 5;
    int edges = 6;
    int adj_matrix[nodes][nodes];
    int i,j;

    //initializing adjacency matrix with all zeros
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            adj_matrix[i][j] = 0;
        }
    }

    //adding edges to the graph
    adj_matrix[0][1] = 1;
    adj_matrix[1][0] = 1;
    adj_matrix[0][2] = 1;
    adj_matrix[2][0] = 1;
    adj_matrix[1][2] = 1;
    adj_matrix[2][1] = 1;
    adj_matrix[1][3] = 1;
    adj_matrix[3][1] = 1;
    adj_matrix[2][3] = 1;
    adj_matrix[3][2] = 1;
    adj_matrix[3][4] = 1;
    adj_matrix[4][3] = 1;

    //printing the graph
    printf("Graph representation using Adjacency Matrix:\n\n");

    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            printf("%d ",adj_matrix[i][j]);
        }
        printf("\n");
    }

    //creating a graph with 5 nodes and 6 edges
    edges = 5;
    int adj_list[nodes][edges];
    int deg[nodes];

    //initializing adjacency list and degree array
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<edges;j++)
        {
            adj_list[i][j] = -1;
        }
        deg[i] = 0;
    }

    //adding edges to the graph
    adj_list[0][0] = 1;
    adj_list[0][1] = 2;
    adj_list[1][0] = 0;
    adj_list[1][1] = 2;
    adj_list[1][2] = 3;
    adj_list[2][0] = 0;
    adj_list[2][1] = 1;
    adj_list[2][2] = 3;
    adj_list[3][0] = 1;
    adj_list[3][1] = 2;
    adj_list[3][2] = 4;
    adj_list[4][0] = 3;

    //updating degree array
    for(i=0;i<nodes;i++)
    {
        j=0;
        while(adj_list[i][j]!=-1)
        {
            deg[i]++;
            j++;
        }
    }

    //printing the graph
    printf("\nGraph representation using Adjacency List:\n\n");
    for(i=0;i<nodes;i++)
    {
        printf("%d: ",i);
        for(j=0;j<deg[i];j++)
        {
            printf("%d ",adj_list[i][j]);
        }
        printf("\n");
    }

    return 0;
}