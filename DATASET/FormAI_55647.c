//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 30

int main()
{
    int maze[ROWS][COLS];
    int i, j;

    srand(time(NULL)); // seed the random number generator

    // initialize the maze with random values
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = rand() % 2; // fill each cell with 0 or 1
        }
    }

    // print the maze
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] == 0) {
                printf("██"); // print a wall
            } else {
                printf("  "); // print a space
            }
        }
        printf("\n");
    }

    return 0;
}