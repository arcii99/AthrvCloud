//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define WALL '#'
#define PATH ' '
#define START 'S'
#define END 'E'

// Define maze size
#define ROWS 15
#define COLS 15

// Function to print the maze
void printMaze(char maze[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to generate the maze
void generateMaze(char maze[ROWS][COLS], int startRow, int startCol, int endRow, int endCol) {
    int i, j;

    // Initialize maze with walls
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = WALL;
        }
    }

    // Place start and end points
    maze[startRow][startCol] = START;
    maze[endRow][endCol] = END;

    // Generate random paths
    srand(time(NULL));
    int row = startRow + 1;
    int col = startCol;

    while (row != endRow || col != endCol) {
        maze[row][col] = PATH;

        if (rand() % 2 == 0) {
            // Move horizontally
            if (col < endCol) {
                col++;
            }
            else if (col > endCol) {
                col--;
            }
        }
        else {
            // Move vertically
            if (row < endRow) {
                row++;
            }
            else if (row > endRow) {
                row--;
            }
        }
    }
}

int main() {
    // Define variables
    char maze[ROWS][COLS];
    int startRow = 1, startCol = 1;
    int endRow = ROWS - 2, endCol = COLS - 2;

    // Generate maze
    generateMaze(maze, startRow, startCol, endRow, endCol);

    // Print maze
    printMaze(maze);

    return 0;
}