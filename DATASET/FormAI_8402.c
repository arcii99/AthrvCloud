//FormAI DATASET v1.0 Category: Graph representation ; Style: innovative
#include <stdio.h>

/* Function to print the graph */
void printGraph(int graph[][5], int V) {
    printf("\nGraph Representation:\n");

    for (int i = 0; i < V; i++) {
        printf("%d: ", i);

        for (int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }

        printf("\n");
    }
}

int main() {
    /* Graph initialization */
    int graph[][5] = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}
    };

    /* Number of vertices */
    int V = 5;

    /* Printing the graph */
    printGraph(graph, V);

    return 0;
}