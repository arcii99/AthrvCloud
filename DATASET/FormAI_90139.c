//FormAI DATASET v1.0 Category: Graph representation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Generate random numbers based on current time

    int graph[10][10]; // Declare 2D array for graph
    int i, j;

    // Fill 2D array with random numbers between 0 and 1
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            graph[i][j] = rand() % 2;
        }
    }

    // Print the graph in a cheerful way
    printf("Let's take a look at our happy graph:\n");

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            // If current node is connected to another node
            if (graph[i][j] == 1) {
                printf(":)");

            // If current node is not connected to another node
            } else {
                printf(":D");
            }
        }
        printf("\n");
    }

    return 0;
}