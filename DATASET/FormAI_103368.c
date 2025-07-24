//FormAI DATASET v1.0 Category: Graph representation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

int main()
{
    int i, j, numVertices, numEdges;
    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    // initialize graph to all zeroes
    for(i=0; i<numVertices; i++) {
        for(j=0; j<numVertices; j++) {
            graph[i][j] = 0;
        }
    }

    // read in edges and add to graph
    for(i=0; i<numEdges; i++) {
        int u, v;
        printf("Enter edge %d: ", i+1);
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // print out the graph representation
    printf("\n\nGraph representation:\n");

    for(i=0; i<numVertices; i++) {
        for(j=0; j<numVertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}