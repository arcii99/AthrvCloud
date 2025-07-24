//FormAI DATASET v1.0 Category: Graph representation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 4

void printGraph(int graph[ROWS][COLS]) {
    // Print column indexes
    printf("  ");
    for (int col = 0; col < COLS; col++) {
        printf("%d ", col);
    }
    printf("\n");

    // Print graph
    for (int row = 0; row < ROWS; row++) {
        printf("%d|", row);
        for (int col = 0; col < COLS; col++) {
            printf("%d ", graph[row][col]);
        }
        printf("\n");
    }
}

void initializeGraph(int graph[ROWS][COLS]) {
    // Set all values in graph to 0
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            graph[row][col] = 0;
        }
    }
}

void addEdge(int graph[ROWS][COLS], int src, int dest) {
    // Add edge to graph
    graph[src][dest] = 1;
}

int main() {
    int graph[ROWS][COLS];

    initializeGraph(graph);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    printGraph(graph);

    return 0;
}