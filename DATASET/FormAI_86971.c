//FormAI DATASET v1.0 Category: Graph representation ; Style: imaginative
#include <stdio.h>

#define ROWS 5
#define COLS 5

// Function to print the graph
void printGraph(int graph[ROWS][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (graph[i][j] == 1) { // If there is an edge between the two vertices
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n"); // Move to next row
    }
}

int main() {
    int graph[ROWS][COLS] = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0}
    };

    printf("Welcome to the magical world of Graphs!\n\n");
    printf("Behold, the representation of a Graph:\n");
    printGraph(graph);
    printf("\n");

    printf("Amazing isn't it? Do you want to see something more magical?\n");
    printf("With the power of programming, we can modify this Graph as we please.\n");

    // Adding an edge between vertices 3 and 5
    graph[2][4] = 1;
    graph[4][2] = 1;

    printf("Let me show you the new Graph:\n");
    printGraph(graph);
    printf("\n");

    printf("I hope you enjoyed this little demonstration of Graphs.\n");
    printf("Now go out there and create your own magical Graphs!\n");

    return 0;
}