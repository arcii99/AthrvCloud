//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10 
#define COLS 10

void printMaze(int maze[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int maze[ROWS][COLS];
    srand(time(NULL));

    // Initialization
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) {
                maze[i][j] = 1; // Wall
            } else {
                maze[i][j] = 0; // Empty
            }
        }
    }

    // Generation
    int r = rand() % (ROWS - 2) + 1;
    int c = rand() % (COLS - 2) + 1;
    maze[r][c] = 2; // Starting point

    while (1) {
        int directions[4] = {0, 1, 2, 3}; // North, West, East, South
        int nDirections = 4;

        // Shuffle the directions
        for (int i = 0; i < 4; i++) {
            int temp = directions[i];
            int j = rand() % 4;
            directions[i] = directions[j];
            directions[j] = temp;
        }

        // Try each direction
        for (int i = 0; i < 4; i++) {
            int dr = 0, dc = 0;
            switch (directions[i]) {
                case 0: // North
                    dr = -1; dc = 0; break;
                case 1: // West
                    dr = 0; dc = -1; break;
                case 2: // East
                    dr = 0; dc = 1; break;
                case 3: // South
                    dr = 1; dc = 0; break;
            }

            int r2 = r + dr;
            int c2 = c + dc;

            if (maze[r2][c2] == 0) {
                maze[r2][c2] = 1; // Mark as visited
                maze[r+dr/2][c+dc/2] = 1; // Break the wall
                r = r2; c = c2; // Move to the new cell
                break;
            }

            nDirections--;
        }

        if (nDirections == 0) { // No directions to go
            break;
        }
    }

    maze[r][c] = 3; // Ending point

    printMaze(maze);

    return 0;
}