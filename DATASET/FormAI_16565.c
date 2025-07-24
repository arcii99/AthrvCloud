//FormAI DATASET v1.0 Category: Graph representation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Function to initialize a graph with random weights
void init_graph(int graph[][MAX_COLS], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else if (rand() % 2) {
                graph[i][j] = rand() % 10 + 1;
            } else {
                graph[i][j] = 0;
            }
        }
    }
}

// Function to print the graph
void print_graph(int graph[][MAX_COLS], int rows, int cols) {
    int i, j;
    printf("\nGraph Representation:\n");

    // Print column headers
    printf("  ");
    for (i = 0; i < cols; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // Print rows with their respective weights
    for (i = 0; i < rows; i++) {
        printf("%d ", i);
        for (j = 0; j < cols; j++) {
            if (graph[i][j]) {
                printf("%d ", graph[i][j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int main() {
    int rows = 5;
    int cols = 5;
    int graph[MAX_ROWS][MAX_COLS];

    // Initialize the graph with random weights
    init_graph(graph, rows, cols);

    // Print the graph
    print_graph(graph, rows, cols);

    return 0;
}