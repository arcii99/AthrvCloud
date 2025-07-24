//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 20

void carvePath(int maze[][COLS], int curRow, int curCol);
void printMaze(int maze[][COLS]);

int main(void) {
    int maze[ROWS][COLS];
    int i, j;

    // Initialize maze with walls
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = 1;
        }
    }

    // Set seed for random number generation
    srand(time(NULL));

    // Carve a path starting from the top left corner
    carvePath(maze, 0, 0);

    // Print the generated maze
    printMaze(maze);

    return 0;
}

void carvePath(int maze[][COLS], int curRow, int curCol) {
    // Mark the current cell as visited
    maze[curRow][curCol] = 0;

    // Shuffle the directions to randomly choose which one to take
    int directions[4] = {0, 1, 2, 3};
    int i, temp, nextRow, nextCol;
    for (i = 0; i < 4; i++) {
        int randIndex = rand() % 4;
        temp = directions[i];
        directions[i] = directions[randIndex];
        directions[randIndex] = temp;
    }

    // Try to move in each direction
    for (i = 0; i < 4; i++) {
        switch (directions[i]) {
            case 0: // Up
                nextRow = curRow - 1;
                nextCol = curCol;
                break;
            case 1: // Right
                nextRow = curRow;
                nextCol = curCol + 1;
                break;
            case 2: // Down
                nextRow = curRow + 1;
                nextCol = curCol;
                break;
            case 3: // Left
                nextRow = curRow;
                nextCol = curCol - 1;
                break;
        }

        // Check if the next cell is within the maze and hasn't been visited
        if (nextRow >= 0 && nextRow < ROWS && nextCol >= 0 && nextCol < COLS && maze[nextRow][nextCol] == 1) {
            // Knock down the wall between the current cell and the next cell
            if (nextRow == curRow) {
                if (nextCol > curCol) {
                    maze[curRow][curCol + 1] = 0;
                } else {
                    maze[curRow][curCol - 1] = 0;
                }
            } else {
                if (nextRow > curRow) {
                    maze[curRow + 1][curCol] = 0;
                } else {
                    maze[curRow - 1][curCol] = 0;
                }
            }

            // Move to the next cell and recursively carve a path from there
            carvePath(maze, nextRow, nextCol);
        }
    }
}

void printMaze(int maze[][COLS]) {
    int i, j;

    // Print top border
    printf("+");
    for (i = 0; i < COLS; i++) {
        printf("--+");
    }
    printf("\n");

    // Print maze cells
    for (i = 0; i < ROWS; i++) {
        printf("|");
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                printf("##");
            } else {
                printf("  ");
            }
            printf("|");
        }
        printf("\n");

        // Print bottom border after each row except the last one
        if (i != ROWS - 1) {
            printf("+");
            for (j = 0; j < COLS; j++) {
                printf("--+");
            }
            printf("\n");
        }
    }

    // Print bottom border
    printf("+");
    for (i = 0; i < COLS; i++) {
        printf("--+");
    }
    printf("\n");
}