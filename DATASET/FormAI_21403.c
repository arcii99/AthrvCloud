//FormAI DATASET v1.0 Category: Graph representation ; Style: creative
#include <stdio.h>

int main() {
    printf("Welcome to the unique C Graph representation program!\n");

    // Setting up the graph data structure
    int graph[6][6] = { {0, 1, 1, 0, 0, 0},
                        {1, 0, 0, 1, 1, 0},
                        {1, 0, 0, 0, 1, 1},
                        {0, 1, 0, 0, 1, 0},
                        {0, 1, 1, 1, 0, 1},
                        {0, 0, 1, 0, 1, 0} };

    // Printing the graph in matrix form
    printf("\nGraph represented in matrix form:\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    // Printing the graph in adjacency list form
    printf("\nGraph represented in adjacency list form:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d: ", i + 1);
        for (int j = 0; j < 6; j++) {
            if (graph[i][j] == 1) {
                printf("%d ", j + 1);
            }
        }
        printf("\n");
    }

    // Printing the graph in adjacency matrix form
    printf("\nGraph represented in adjacency matrix form:\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nThanks for using the unique C Graph representation program!\n");

    return 0;
}