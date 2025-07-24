//FormAI DATASET v1.0 Category: Graph representation ; Style: excited
#include <stdio.h>

void printGraph(int graph[5][5]) {
    printf("\n\nHere's your graph, my friend!\n\n");

    // Loop through each row and column of the graph
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {

            // If value at this position is 1, print an X, else a space
            if (graph[row][col] == 1) {
                printf("X ");
            } else {
                printf("  ");
            }
        }

        // Move to the next row
        printf("\n");
    }
}

int main() {
    // Here's an example graph in adjacency matrix form
    int graph[5][5] = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}
    };

    printGraph(graph);

    return 0;
}