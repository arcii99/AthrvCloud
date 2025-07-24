//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 8
#define COL 8

// Maze structure
int maze[ROW][COL] = {
    {1,1,0,0,0,0,0,0},
    {1,1,1,1,1,0,1,0},
    {0,1,0,0,1,1,0,0},
    {1,1,1,0,1,1,0,1},
    {0,1,0,0,0,1,0,1},
    {0,1,1,1,1,1,1,1},
    {0,0,0,0,0,1,0,0},
    {0,0,0,0,0,1,9,0}
};

// Function to print the maze
void printMaze() {
    printf("The maze:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to determine if a move is valid
bool isValid(int row, int col) {
    if (row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] != 0) {
        return true;
    } else {
        return false;
    }
}

// Function to determine if a cell is the exit cell
bool isExit(int row, int col) {
    if (maze[row][col] == 9) {
        return true;
    } else {
        return false;
    }
}

// Function to solve the maze using recursion and backtracking
bool solveMaze(int row, int col) {
    // If the cell is the exit cell, return true
    if (isExit(row, col)) {
        return true;
    }
    
    // If the move is valid, mark the cell as visited
    if (isValid(row, col)) {
        maze[row][col] = 0;
        
        // Recursively check the next moves in all four directions
        if (solveMaze(row+1, col)) {  // Move down
            return true;
        }
        if (solveMaze(row-1, col)) {  // Move up
            return true;
        }
        if (solveMaze(row, col+1)) {  // Move right
            return true;
        }
        if (solveMaze(row, col-1)) {  // Move left
            return true;
        }
        
        // If none of the moves are successful, unmark the cell and backtrack
        maze[row][col] = 1;
        return false;
    }
    
    // If the move is not valid, return false
    return false;
}

// Main function
int main() {
    printMaze();
    printf("\n");
    
    // Start solving the maze from the top left corner
    bool success = solveMaze(0,0);
    
    // If a solution is found, print the solved maze
    if (success) {
        printf("The solved maze:\n");
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (maze[i][j] == 0) {
                    printf(". ");
                } else {
                    printf("%d ", maze[i][j]);
                }
            }
            printf("\n");
        }
    } else {
        printf("No solution found.\n");
    }
    
    return 0;
}