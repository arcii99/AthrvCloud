//FormAI DATASET v1.0 Category: Graph representation ; Style: optimized
#include <stdio.h>

#define MAX_VERTICES 50

int main() {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0}; // adjacency matrix to represent graph
    int numVertices, numEdges;
    
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);
    
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);
    
    // read in edges and populate adjacency matrix
    int edgeStart, edgeEnd;
    for(int i = 0; i < numEdges; i++) {
        printf("Enter edge %d (start end): ", i+1);
        scanf("%d %d", &edgeStart, &edgeEnd);
        adjMatrix[edgeStart][edgeEnd] = 1;
        adjMatrix[edgeEnd][edgeStart] = 1;
    }
    
    // print out adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for(int i = 0; i < numVertices; i++) {
        for(int j = 0; j < numVertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}