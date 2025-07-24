//FormAI DATASET v1.0 Category: Graph representation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10

int main()
{
    int graph[MAX_NODES][MAX_NODES] = { {0} };
    int num_nodes, i, j;

    printf("Enter the number of nodes in the graph(<= %d): ", MAX_NODES);
    scanf("%d", &num_nodes);

    printf("Enter the adjacency matrix of the graph:\n");
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < num_nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("The graph representation using adjacency matrix is as follows:\n");
    printf("   ");
    for (i = 0; i < num_nodes; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    for (i = 0; i < num_nodes; i++) {
        printf("%2d ", i);
        for (j = 0; j < num_nodes; j++) {
            printf("%2d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}