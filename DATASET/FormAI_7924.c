//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 500

typedef struct {
    int src;
    int dest;
    float value;
} Edge;

int numNodes = 0;
int numEdges = 0;
int adjMatrix[MAX_NODES][MAX_NODES];
Edge edges[MAX_EDGES];

int addNode() {
    if(numNodes < MAX_NODES) {
        numNodes++;
        return numNodes-1;
    }
    return -1;
}

int addEdge(int src, int dest, float value) {
    if(numEdges < MAX_EDGES) {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
        
        edges[numEdges].src = src;
        edges[numEdges].dest = dest;
        edges[numEdges].value = value;
        
        numEdges++;
        return numEdges-1;
    }
    return -1;
}

void printMatrix() {
    printf("  ");
    for(int i=0;i<numNodes;i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for(int i=0;i<numNodes;i++) {
        printf("%d ", i);
        for(int j=0;j<numNodes;j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void printEdges() {
    for(int i=0;i<numEdges;i++) {
        printf("%d -> %d [%.2f]\n", edges[i].src, edges[i].dest, edges[i].value);
    }
}

int main() {
    int node1 = addNode();
    int node2 = addNode();
    int node3 = addNode();
    int edge1 = addEdge(node1, node2, 10.0);
    int edge2 = addEdge(node1, node3, 5.0);
    int edge3 = addEdge(node2, node3, 3.0);
    
    printf("Adjacency Matrix:\n");
    printMatrix();
    
    printf("List of Edges:\n");
    printEdges();
    
    return 0;
}