//FormAI DATASET v1.0 Category: Graph representation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    int graph[numNodes][numNodes];
    int i, j;

    // Initialize all elements to 0
    for(i = 0; i < numNodes; i++) {
        for(j = 0; j < numNodes; j++) {
            graph[i][j] = 0;
        }
    }

    // Create random connections between nodes
    int numConnections = rand() % (numNodes * (numNodes - 1) / 2);
    int connCount = 0;

    while(connCount < numConnections) {
        i = rand() % numNodes;
        j = rand() % numNodes;

        if(i != j && graph[i][j] == 0) {
            // Create connection in both directions
            graph[i][j] = 1;
            graph[j][i] = 1;
            connCount++;
        }
    }

    // Print graph
    printf("Graph:\n");

    for(i = 0; i < numNodes; i++) {
        for(j = 0; j < numNodes; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}