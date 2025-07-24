//FormAI DATASET v1.0 Category: Graph representation ; Style: authentic
#include <stdio.h>

#define MAX_NODES 20

// Function to display the adjacency matrix
void displayAdjMatrix(int adjMatrix[][MAX_NODES], int n) {
    printf("\nAdjacency Matrix:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            printf("%d ", adjMatrix[i][j]);
        printf("\n");
    }
}

// Function to create graph from user input
void createGraph(int adjMatrix[][MAX_NODES], int n) {
    int edgesCount;
    printf("Enter number of edges in the graph: ");
    scanf("%d", &edgesCount);

    printf("Enter the vertices u and v, where u -> v are the edges:\n");
    for(int i=0; i<edgesCount; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
}

int main() {
    int n;
    printf("Enter number of nodes in the graph (<= %d): ", MAX_NODES);
    scanf("%d", &n);

    int adjMatrix[MAX_NODES][MAX_NODES] = {0};

    createGraph(adjMatrix, n);
    displayAdjMatrix(adjMatrix, n);

    return 0;
}