//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Donald Knuth
#include <stdio.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

// The maze grid
int maze[ROWS][COLS] = {
    { 0, 1, 1, 0, 0 },
    { 0, 0, 1, 0, 1 },
    { 0, 0, 0, 0, 0 },
    { 1, 1, 0, 0, 1 },
    { 0, 0, 0, 0, 0 }
};

// The solution path
int path[ROWS][COLS] = {
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 }
};

// Check if the given cell (row, col) is a valid cell
bool isValidCell(int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] == 0;
}

// Recursive function to find the path through the maze
bool findPath(int row, int col) {
    // If we've reached the exit, return true
    if (row == ROWS - 1 && col == COLS - 1) {
        path[row][col] = 1;
        return true;
    }
    
    // Check if the current cell is a valid cell
    if (isValidCell(row, col)) {
        // Mark the current cell as part of the path
        path[row][col] = 1;
        
        // Move to the right
        if (findPath(row, col + 1)) {
            return true;
        }
        // Move down
        if (findPath(row + 1, col)) {
            return true;
        }
        // Move to the left
        if (findPath(row, col - 1)) {
            return true;
        }
        // Move up
        if (findPath(row - 1, col)) {
            return true;
        }
        
        // If none of the adjacent cells lead to the exit, backtrack
        path[row][col] = 0;
        return false;
    }
    
    // If the current cell is not a valid cell, return false
    return false;
}

int main() {
    // Find the solution path
    if (findPath(0, 0)) {
        // Print the solution path
        printf("Solution path:\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%d ", path[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("There is no solution!\n");
    }
    return 0;
}