//FormAI DATASET v1.0 Category: Graph representation ; Style: intelligent
#include <stdio.h>

int main() {
    int vertices, edges, i, j, v1, v2;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    int graph[vertices][vertices];

    for(i = 0; i < vertices; i++) {
        for(j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges:\n");

    for(i = 0; i < edges; i++) {
        printf("Edge %d:\n", i+1);
        printf("Enter vertex 1: ");
        scanf("%d", &v1);
        printf("Enter vertex 2: ");
        scanf("%d", &v2);

        graph[v1-1][v2-1] = 1;
        graph[v2-1][v1-1] = 1;
    }

    printf("\nAdjacency Matrix:\n");

    for(i = 0; i < vertices; i++) {
        for(j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}