//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: protected
#include <stdio.h>

#define MAX_NODE 5 // Maximum number of nodes in network

int adjacencyMatrix[MAX_NODE][MAX_NODE]; // Adjacency matrix to store the topology

void initializeTopology() {
    // Initialize the adjacency matrix with 0 to indicate no link between nodes
    for(int i=0; i<MAX_NODE; i++) {
        for(int j=0; j<MAX_NODE; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
}

void addLink(int from, int to) {
    // Add a link between the two nodes by updating the adjacency matrix
    adjacencyMatrix[from][to] = 1;
    adjacencyMatrix[to][from] = 1;
}

void printTopology() {
    // Print the current topology
    printf("Current Network Topology: \n");

    // Print the header row
    printf("   ");
    for(int i=0; i<MAX_NODE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // Print the adjacency matrix
    for(int i=0; i<MAX_NODE; i++) {
        printf("%d |", i);
        for(int j=0; j<MAX_NODE; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void removeLink(int from, int to) {
    // Remove the link between the two nodes by updating the adjacency matrix
    adjacencyMatrix[from][to] = 0;
    adjacencyMatrix[to][from] = 0;
}

int main() {
    initializeTopology(); // Initialize the network topology
    addLink(0, 1); // Add link between node 0 and node 1
    addLink(1, 2); // Add link between node 1 and node 2
    addLink(2, 3); // Add link between node 2 and node 3
    addLink(3, 4); // Add link between node 3 and node 4
    printTopology(); // Print the current topology
    
    removeLink(1, 2); // Remove link between node 1 and node 2
    printTopology(); // Print the updated topology
    
    return 0;
}