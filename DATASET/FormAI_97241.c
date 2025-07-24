//FormAI DATASET v1.0 Category: Graph representation ; Style: introspective
#include <stdio.h>

/* This program demonstrates a unique representation of a graph in C using an adjacency matrix */

/* Define the number of vertices in the graph */
#define N 6

/* Function to add edges to the graph */
void addEdge(int graph[][N], int src, int dest, int weight)
{
    /* Add the edge to the adjacency matrix */
    graph[src][dest] = weight;
    /* Since this is an undirected graph, add the edge in the opposite direction as well */
    graph[dest][src] = weight;
}

int main()
{
    int graph[N][N] = {0}; /* Initialize the adjacency matrix to 0 */

    /* Add edges to the graph */
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 3, 4);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 4, 6);
    addEdge(graph, 3, 4, 7);
    addEdge(graph, 3, 5, 8);
    addEdge(graph, 4, 5, 9);

    /* Print the adjacency matrix */
    printf("  ");
    for (int i = 0; i < N; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", i);
        for (int j = 0; j < N; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}