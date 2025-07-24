//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int maze[ROWS][COLS] = {{0}};

void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 0) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    // Create random starting point
    int currRow = rand() % ROWS;
    int currCol = rand() % COLS;
    maze[currRow][currCol] = 1;

    // Start generating maze
    while (1) {
        int direction = rand() % 4;
        int newRow = currRow;
        int newCol = currCol;

        // Move based on randomly generated direction
        switch (direction) {
            case 0: // Move up
                if (currRow > 0) {
                    newRow--;
                }
                break;
            case 1: // Move down
                if (currRow < ROWS - 1) {
                    newRow++;
                }
                break;
            case 2: // Move left
                if (currCol > 0) {
                    newCol--;
                }
                break;
            case 3: // Move right
                if (currCol < COLS - 1) {
                    newCol++;
                }
                break;
        }

        // If new cell has not been visited, mark it as visited and move to new cell
        if (maze[newRow][newCol] == 0) {
            maze[newRow][newCol] = 1;
            currRow = newRow;
            currCol = newCol;
        }

        int visitedCount = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (maze[i][j] == 1) {
                    visitedCount++;
                }
            }
        }

        // If all cells have been visited, stop generating maze
        if (visitedCount == ROWS * COLS) {
            break;
        }
    }

    printMaze();

    return 0;
}