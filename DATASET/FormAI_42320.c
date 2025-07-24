//FormAI DATASET v1.0 Category: Graph representation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main() {
    int graph[MAX][MAX];
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    //Initialize Graph with zeros
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    //Get the edges from the user
    for(int i = 0; i < edges; i++) {
        int u, v, w;
        printf("Enter the edge (u, v): ");
        scanf("%d%d", &u, &v);
        printf("Enter the weight of the edge: ");
        scanf("%d", &w);
        graph[u-1][v-1] = w;
        graph[v-1][u-1] = w;
    }

    //Print the Graph
    printf("\nGraph Representation: \n\n");
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}