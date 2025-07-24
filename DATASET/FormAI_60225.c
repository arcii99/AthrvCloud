//FormAI DATASET v1.0 Category: Graph representation ; Style: satisfied
#include<stdio.h>

int main()
{
    int edges, vertices;
    printf("Enter the number of vertices and edges respectively: ");
    scanf("%d %d", &vertices, &edges);

    int adjMatrix[vertices][vertices];
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            adjMatrix[i][j] = 0;
        }
    }

    printf("Enter the edges between vertices as A B:\n");
    int u, v;
    for(int i=0;i<edges;i++){
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    printf("The adjacency matrix representation of the graph is:\n");
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}