//FormAI DATASET v1.0 Category: Graph representation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRAPH_SIZE 10 // size of the graph(adjacency matrix)

void printGraph(int graph[][GRAPH_SIZE], int n);

int main() {
    int graph[GRAPH_SIZE][GRAPH_SIZE] = {0}; // initialize all vertices to zero
    int i, j;
    srand(time(0)); // seeds random number generator with current time

    // randomly generate edges in graph
    for (i = 0; i < GRAPH_SIZE; i++) {
        for (j = i; j < GRAPH_SIZE; j++) { // since graph is undirected, only fill in half of the matrix
            if (i != j && rand() % 2 == 1) { // randomly decide whether to create an edge between vertices i and j
                graph[i][j] = 1;
                graph[j][i] = 1;
            }
        }
    }

    // print graph to console
    printGraph(graph, GRAPH_SIZE);

    return 0;
}

// prints the adjacency matrix of a graph to the console
void printGraph(int graph[][GRAPH_SIZE], int n) {
    int i, j;

    printf("Graph Adjacency Matrix:\n");
    // print column headers
    printf(" | ");
    for (i = 0; i < n; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // print separating line
    for (i = 0; i < n+1; i++) {
        printf("--");
    }
    printf("\n");

    // print row headers and data
    for (i = 0; i < n; i++) {
        printf("%d| ", i);
        for (j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}