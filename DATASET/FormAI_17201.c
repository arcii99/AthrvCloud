//FormAI DATASET v1.0 Category: Graph representation ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int nodes, edges;
    printf("Enter the number of nodes: ");
    scanf("%d",&nodes);

    int **graph = (int**)malloc(sizeof(int*)*nodes);
    
    for(int i=0;i<nodes;i++){
        graph[i] = (int*)calloc(nodes,sizeof(int));
    }

    printf("Enter the number of edges: ");
    scanf("%d",&edges);

    printf("Enter the connections b/w the edges: \n");
    int u,v;
    for(int i=0;i<edges;i++){
        printf("Enter edge %d: ",i+1);
        scanf("%d %d",&u,&v);
        graph[u][v]=1;
        graph[v][u]=1;  // Assuming an undirected graph
    }

    printf("The graph representation in adjacency matrix form: \n");
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<nodes;i++){
        free(graph[i]);
    }
    free(graph);

    return 0;
}