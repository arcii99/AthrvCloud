//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: interoperable
#include<stdio.h>

int main()
{
    int Adjacency_Matrix[10][10], Color[10], n, m, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter the number of edges: ");
    scanf("%d",&m);

    printf("Enter the adjacency matrix: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&Adjacency_Matrix[i][j]);
        }
    }
    printf("\n");

    for(i=0;i<n;i++)
    {
        Color[i]=0;
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(Adjacency_Matrix[i][j]==1 && Color[j]!=0)
            {
                Color[i]=Color[j];
            }
        }
        if(Color[i]==0)
        {
            Color[i]=i+1;
        }
    }

    printf("The vertices along with their assigned colors are: \n");
    for(i=0;i<n;i++)
    {
        printf("Vertex %d --> Color %d\n",(i+1),Color[i]);
    }
    return 0;
}