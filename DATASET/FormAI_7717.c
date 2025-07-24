//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>
#include <stdbool.h>

#define MAX_NODES 10 // Maximum number of nodes for simplicity.
#define MAX_ADJACENTS MAX_NODES // Maximum number of adjacent nodes. 

struct Node {
    int node_id;
    int adjacents[MAX_ADJACENTS]; // Array of id's for adjacent nodes
    int num_adjacents; // Number of adjacent nodes
};

typedef struct Node Node;

// Declare adjacency matrix to represent topology
int adjacencyMatrix[MAX_NODES][MAX_NODES];
Node nodeSet[MAX_NODES];
int numNodes;

// Declare function to add edges 
void addEdge(int src, int dest) {
    adjacencyMatrix[src][dest] = adjacencyMatrix[dest][src] = 1;
}

int main() {
    numNodes = 5;
    int edges[][2] = {{0,1},{1,2},{2,3},{3,4},{4,0}};  // Define node edges
    // Initialize nodes
    for(int i = 0; i < numNodes; i++){
        nodeSet[i].node_id = i;
        nodeSet[i].num_adjacents = 0;
    }
    // Add edges to adjacency matrix and nodeSet
    for(int i = 0; i < sizeof(edges)/sizeof(edges[0]); i++){
        int src = edges[i][0];
        int dest = edges[i][1];
        nodeSet[src].adjacents[nodeSet[src].num_adjacents++] = dest;
        nodeSet[dest].adjacents[nodeSet[dest].num_adjacents++] = src;
        addEdge(src, dest);
    }
    // Print topology
    printf("Network Topology:\n");
    for(int i = 0; i < numNodes; i++){
        printf("Node %d is adjacent to nodes: ", i);
        for(int j = 0; j < nodeSet[i].num_adjacents; j++){
            printf("%d ", nodeSet[i].adjacents[j]);
        }
        printf("\n");
    }
    return 0;
}