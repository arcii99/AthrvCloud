//FormAI DATASET v1.0 Category: Graph representation ; Style: innovative
#include <stdio.h>

// define the maximum number of nodes in the graph
#define MAX_NODES 10

// function to print the graph in matrix form
void printGraph(int graph[MAX_NODES][MAX_NODES], int numNodes) {
    // print column headers
    printf("Node|");
    for (int i = 0; i < numNodes; i++) {
        printf("%d  ", i);
    }
    printf("\n");
    // print separator
    printf("----");
    for (int i = 0; i < numNodes; i++) {
        printf("---");
    }
    printf("\n");
    // print matrix
    for (int i = 0; i < numNodes; i++) {
        printf("%d   |", i);
        for (int j = 0; j < numNodes; j++) {
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // initialize the graph with 0s
    int graph[MAX_NODES][MAX_NODES] = {{0}};
    
    // add edges to the graph
    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[2][1] = 1;
    graph[2][3] = 1;
    graph[3][2] = 1;
    graph[3][4] = 1;
    graph[4][3] = 1;
    graph[0][4] = 1;
    graph[4][0] = 1;
    
    // print the graph
    printGraph(graph, 5);
    
    return 0;
}