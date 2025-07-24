//FormAI DATASET v1.0 Category: Graph representation ; Style: bold
#include <stdio.h>

int main() {
    printf("\033[1m"); // activating bold mode
    
    int nodes, edges, source, destination;
    printf("Enter the number of nodes and edges in the graph: ");
    scanf("%d%d", &nodes, &edges);

    int graph[nodes][nodes];

    printf("\nEnter the source and destination of each edge:\n");
    for(int i = 0; i < edges; i++) {
        printf("\nEdge %d\n", i + 1);
        printf("Source: ");
        scanf("%d", &source);
        printf("Destination: ");
        scanf("%d", &destination);

        graph[source][destination] = 1;
        graph[destination][source] = 1;
    }

    printf("\nGraph Representation:\n");

    // printing node numbers
    for(int i = 0; i < nodes; i++) {
        printf("\t%d", i);
    }

    printf("\n");

    // printing edges
    for(int i = 0; i < nodes; i++) {
        printf("%d", i);
        for(int j = 0; j < nodes; j++) {
            printf("\t%d", graph[i][j]);
        }
        printf("\n");
    }

    printf("\033[0m"); // deactivating bold mode
    
    return 0;
}