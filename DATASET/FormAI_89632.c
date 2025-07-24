//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 15

int main()
{
    srand(time(NULL)); // Seed the random number generator
    int maze[ROWS][COLS]; // Define the maze as a 2D array

    // Initialize the maze with random values
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            maze[row][col] = rand() % 2;
        }
    }

    // Set the starting and ending points of the maze
    maze[0][0] = 1; // Starting point is always (0, 0)
    maze[ROWS-1][COLS-1] = 1; // Ending point is always (ROWS-1, COLS-1)

    // Print the maze
    printf("Procedurally Generated Maze Example:\n");
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (maze[row][col] == 1) {
                printf(" "); // Print a space for every "open" cell in the maze
            } else {
                printf("#"); // Print a hash symbol for every "blocked" cell in the maze
            }
        }
        printf("\n");
    }

    return 0;
}