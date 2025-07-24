//FormAI DATASET v1.0 Category: Graph representation ; Style: excited
#include <stdio.h>

#define MAX_VERTICES 10

int main() {

    // Graph representation
    int graph[MAX_VERTICES][MAX_VERTICES];
    int vertices = 5;

    // Initializing graph
    for (int i=0; i<vertices; i++) {
        for (int j=0; j<vertices; j++) {
            graph[i][j] = 0;
        }
    }

    // Adding edges
    graph[0][1] = 1;
    graph[1][2] = 1;
    graph[2][3] = 1;
    graph[3][4] = 1;
    graph[4][0] = 1;

    // Printing graph
    printf("Here's the graph representation:\n");

    for (int i=0; i<vertices; i++) {
        for (int j=0; j<vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}