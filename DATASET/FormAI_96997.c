//FormAI DATASET v1.0 Category: Graph representation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100 // maximum number of nodes

int graph[MAX_NODES][MAX_NODES]; // 2D array to store the graph

int main() {
    int nodes, edges, i, j, u, v, w;
    printf("Enter the number of nodes and edges in the graph:\n");
    scanf("%d %d", &nodes, &edges);

    // initialize graph with zeros
    for(i = 0; i < MAX_NODES; i++) {
        for(j = 0; j < MAX_NODES; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges with their weights:\n");
    for(i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w; // assuming undirected graph
        graph[v][u] = w;
    }

    // print the graph
    printf("The graph is:\n");
    for(i = 0; i < nodes; i++) {
        for(j = 0; j < nodes; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    // do some processing on the graph here...

    return 0;
}