//FormAI DATASET v1.0 Category: Graph representation ; Style: light-weight
#include<stdio.h>

#define MAX 100

int adjMatrix[MAX][MAX]; //to store the graph representation

void addEdge(int startNode, int endNode) {
    //add edge to the graph
    adjMatrix[startNode][endNode] = 1; 
    adjMatrix[endNode][startNode] = 1; 
}

int main() {
    int nodes, edges;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &nodes);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    // Initialize all elements to 0 in adjMatrix
    for(int i = 0; i < nodes; i++)
        for(int j = 0; j < nodes; j++)
            adjMatrix[i][j] = 0;

    // Loop to add edges in the graph
    for(int i = 0; i < edges; i++) {
        int startNode, endNode;
        printf("Enter edge %d (startNode endNode): ", i+1);
        scanf("%d %d", &startNode, &endNode);
        addEdge(startNode, endNode);
    }

    // Printing Graph Representation
    printf("\nGraph Representation using Adjacency Matrix:\n");

    for(int i = 0; i < nodes; i++) {
        for(int j = 0; j < nodes; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}