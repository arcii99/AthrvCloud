//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: recursive
#include <stdio.h>
#include <stdbool.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// 2D Array representing the maze
int maze[MAX_ROWS][MAX_COLS] = {
    {1, 0, 1, 1, 0, 1, 0, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
    {0, 0, 0, 1, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 0},
    {1, 0, 0, 1, 1, 0, 0, 1, 0, 1},
    {1, 1, 0, 1, 0, 0, 1, 1, 1, 1},
    {0, 0, 1, 1, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 1, 1, 0},
    {0, 1, 0, 1, 0, 1, 1, 1, 0, 1},
};

// Function to check if a given row and column is a valid move
bool isValidMove(int row, int col) {
    return (row >= 0) && (row < MAX_ROWS) && 
           (col >= 0) && (col < MAX_COLS) && 
           (maze[row][col] == 1);
}

// Function to solve the maze using recursion
bool solveMaze(int row, int col) {
    // If we have reached the end of the maze, return true
    if (row == MAX_ROWS - 1 && col == MAX_COLS - 1) {
        return true;
    }

    // Check if the current row and col is a valid move
    if (isValidMove(row, col)) {
        // Mark the current cell as visited
        maze[row][col] = 2;

        // Check if we can move down
        if (solveMaze(row + 1, col)) {
            return true;
        }

        // Check if we can move right
        if (solveMaze(row, col + 1)) {
            return true;
        }

        // Check if we can move up
        if (solveMaze(row - 1, col)) {
            return true;
        }

        // Check if we can move left
        if (solveMaze(row, col - 1)) {
            return true;
        }

        // If we reach this point, that means we can't move in any direction
        // so we need to backtrack and mark the current cell as unvisited
        maze[row][col] = 1;
        return false;
    }

    // If we reach this point, that means the current cell is not a valid move
    // so we need to backtrack
    return false;
}

int main() {
    // Print the initial maze
    printf("The initial maze :\n");
    for(int i = 0; i < MAX_ROWS; i++) {
        for(int j = 0; j < MAX_COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    // Solve the maze
    if (solveMaze(0, 0)) {
        // Print the final maze with the path
        printf("\nThe path with the maze :\n");
        for(int i = 0; i < MAX_ROWS; i++) {
            for(int j = 0; j < MAX_COLS; j++) {
                if (maze[i][j] == 2) {
                    printf("* ");
                } else {
                    printf("%d ", maze[i][j]);   
                }
            }
            printf("\n");
        }
    } else {
        printf("There is no possible path.\n");
    }

    return 0;
}