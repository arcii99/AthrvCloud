//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 50
#define MAX_EDGES 100

typedef struct {
    int node1;
    int node2;
    double value;
} Edge;

int nodeCount = 0;
int edgeCount = 0;
double nodeValues[MAX_NODES];
Edge edges[MAX_EDGES];

void addEdge(int node1, int node2, double value) {
    if (edgeCount < MAX_EDGES) {
        edges[edgeCount].node1 = node1;
        edges[edgeCount].node2 = node2;
        edges[edgeCount].value = value;
        edgeCount++;
    }
}

void addNode(double value) {
    if (nodeCount < MAX_NODES) {
        nodeValues[nodeCount] = value;
        nodeCount++;
    }
}

void printNodes() {
    printf("Nodes:\n");
    for (int i = 0; i < nodeCount; i++) {
        printf("%d: %f\n", i, nodeValues[i]);
    }
}

void printEdges() {
    printf("Edges:\n");
    for (int i = 0; i < edgeCount; i++) {
        printf("%d--%f--%d\n", edges[i].node1, edges[i].value, edges[i].node2);
    }
}

int main() {
    addNode(5.0);
    addNode(10.0);
    addEdge(0, 1, 2.0);
    printNodes();
    printEdges();
    return 0;
}