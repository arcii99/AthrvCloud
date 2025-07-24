//FormAI DATASET v1.0 Category: Graph representation ; Style: satisfied
#include<stdio.h>

int main(){
    int vertices, edges, i, j;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    int graph[vertices][vertices];
    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++){
            graph[i][j]=0;
        }
    }

    printf("\nEnter %d edges: \n", edges);
    int u,v;
    for(i=0;i<edges;i++){
        printf("Edge %d: ", i+1);
        scanf("%d %d", &u, &v);
        graph[u][v]=1;
        graph[v][u]=1;
    }

    printf("\nAdjacency Matrix: \n");
    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nGraph Representation: \n");
    for(i=0;i<vertices;i++){
        printf("%d -> ", i);
        for(j=0;j<vertices;j++){
            if(graph[i][j]){
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    return 0;
}