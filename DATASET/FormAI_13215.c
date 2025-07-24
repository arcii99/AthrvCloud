//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Defines the dimensions of the maze
#define ROWS 10
#define COLUMNS 10

// Maze definition with '1' representing blocked area and '0' representing path
int maze[ROWS][COLUMNS] = {
    {0, 0, 0, 1, 0, 1, 1, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0}
};

// Function to print maze
void printMaze() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a given position is valid
int isValid(int row, int col) {
    if(row < 0 || row >= ROWS || col < 0 || col >= COLUMNS) {
        return 0;
    }
    if(maze[row][col] == 1) {
        return 0;
    }
    return 1;
}

// Function to solve maze
void solveMaze(int row, int col) {
    // If goal is reached, print solution matrix
    if(row == ROWS - 1 && col == COLUMNS - 1) {
        maze[row][col] = 2;
        printMaze();
        maze[row][col] = 0;
        return;
    }

    // Check if current cell is valid
    if(isValid(row, col)) {
        // Set current cell as part of solution
        maze[row][col] = 2;

        // Move down
        solveMaze(row + 1, col);

        // Move right
        solveMaze(row, col + 1);

        // Move up
        solveMaze(row - 1, col);

        // Move left
        solveMaze(row, col - 1);

        // Set current cell back to unvisited
        maze[row][col] = 0;
    }
}

int main() {
    printf("Maze route finder\n\n");
    printf("Maze:\n");
    printMaze();
    printf("\nSolution:\n");
    solveMaze(0, 0);
    return 0;
}