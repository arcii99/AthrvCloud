//FormAI DATASET v1.0 Category: Graph representation ; Style: thoughtful
#include<stdio.h>

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    int graph[n][n];

    //initialize the graph with zeros
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            graph[i][j] = 0;
        }
    }

    //accept the edges from user
    int e;
    printf("Enter the number of edges: ");
    scanf("%d",&e);
    printf("Enter the edges as 'u v':\n");
    for(int i=0;i<e;i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    //display the graph
    printf("\nThe graph representation using C program is:\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}