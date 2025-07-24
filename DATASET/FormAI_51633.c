//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Sherlock Holmes
// Sherlock Holmes Procedurally Generated Maze in C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25 // Number of Rows
#define COLS 75 // Number of Columns
#define WALL '#'
#define PATH '.'

char maze[ROWS][COLS]; // 2D array to store the maze

void generateMaze(int row, int col) {
    // Initialize the maze with walls
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = WALL;
        }
    }

    // Randomly select starting point
    srand(time(NULL));
    int startRow = rand() % row;
    int startCol = rand() % col;
    maze[startRow][startCol] = PATH;

    // Recursive Backtracking algorithm
    int stackRow[ROWS * COLS];
    int stackCol[ROWS * COLS];
    int top = 0;

    stackRow[top] = startRow;
    stackCol[top] = startCol;

    while (top >= 0) {
        int currentRow = stackRow[top];
        int currentCol = stackCol[top];

        int directions[4] = {0, 1, 2, 3};
        int numDirections = 4;

        // Shuffle the directions array to make it random
        for (int i = 0; i < numDirections; i++) {
            int shuffleIndex = rand() % numDirections;
            int temp = directions[i];
            directions[i] = directions[shuffleIndex];
            directions[shuffleIndex] = temp;
        }

        int nextRow, nextCol;

        int foundNext = 0;

        // Check all directions
        for (int i = 0; i < numDirections; i++) {
            switch (directions[i]) {
                case 0: // Up
                    nextRow = currentRow - 2;
                    nextCol = currentCol;
                    break;
                case 1: // Right
                    nextRow = currentRow;
                    nextCol = currentCol + 2;
                    break;
                case 2: // Down
                    nextRow = currentRow + 2;
                    nextCol = currentCol;
                    break;
                case 3: // Left
                    nextRow = currentRow;
                    nextCol = currentCol - 2;
                    break;
            }

            // Check if next move is valid
            if (nextRow >= 0 && nextCol >= 0 && nextRow < row && nextCol < col && maze[nextRow][nextCol] == WALL) {
                maze[(nextRow + currentRow) / 2][(nextCol + currentCol) / 2] = PATH; // Remove wall
                maze[nextRow][nextCol] = PATH; // Move to next cell
                stackRow[++top] = nextRow;
                stackCol[top] = nextCol;
                foundNext = 1;
                break;
            }
        }

        // If no valid moves found, backtrack
        if (!foundNext) {
            top--;
        }
    }
}

void printMaze() {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    generateMaze(ROWS, COLS);
    printf("Sherlock Holmes Procedurally Generated Maze in C\n");
    printf("===============================================\n");
    printMaze();
    return 0;
}