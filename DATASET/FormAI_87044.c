//FormAI DATASET v1.0 Category: Graph representation ; Style: introspective
#include <stdio.h>

int main() {
    // let's first define our graph
    int graph[5][5] = { { 0, 1, 0, 1, 1 },
                        { 0, 0, 1, 0, 0 },
                        { 1, 0, 0, 1, 0 },
                        { 0, 0, 1, 0, 1 },
                        { 0, 1, 0, 0, 0 } };
    // now let's print the graph
    printf("The graph representation is: \n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", graph[i][j]); // printing each element of the matrix
        }
        printf("\n"); // moving to the next row
    }
    return 0;
}