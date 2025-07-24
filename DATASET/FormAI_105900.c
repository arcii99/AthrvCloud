//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the maze size
#define ROW_SIZE 7
#define COL_SIZE 7

// Maze data
int maze[ROW_SIZE][COL_SIZE] = {
    {0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0},
};

// Function to print the maze
void printMaze() {
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COL_SIZE; j++) {
            if (maze[i][j] == 0) {
                printf(" #"); // Wall
            } else if (maze[i][j] == 1) {
                printf("  "); // Path
            } else if (maze[i][j] == 2) {
                printf(" S"); // Start
            } else if (maze[i][j] == 3) {
                printf(" F"); // Finish
            }
        }
        printf("\n");
    }
}

// Function to find the path
int findPath(int row, int col) {
    if (row < 0 || row >= ROW_SIZE || col < 0 || col >= COL_SIZE) {
        // Out of bounds
        return 0;
    }

    if (maze[row][col] == 0 || maze[row][col] == 4) {
        // Wall or already visited
        return 0;
    }

    if (maze[row][col] == 3) {
        // Finish found
        return 1;
    }

    maze[row][col] = 4; // Mark as visited

    // Try moving in all directions
    if (findPath(row, col - 1)) {
        maze[row][col] = 1; // Mark as path
        return 1;
    }

    if (findPath(row, col + 1)) {
        maze[row][col] = 1; // Mark as path
        return 1;
    }

    if (findPath(row - 1, col)) {
        maze[row][col] = 1; // Mark as path
        return 1;
    }

    if (findPath(row + 1, col)) {
        maze[row][col] = 1; // Mark as path
        return 1;
    }

    return 0; // Path not found
}

int main() {
    printf("Maze Route Finder\n");

    // Print the initial maze
    printMaze();

    // Find the start position
    int startRow, startCol;
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COL_SIZE; j++) {
            if (maze[i][j] == 2) {
                startRow = i;
                startCol = j;
                break;
            }
        }
    }

    // Find the path
    int pathFound = findPath(startRow, startCol);

    // Print the final maze
    printf("\n");
    printf("Maze Solution:\n");
    printMaze();

    // Print the result
    if (pathFound) {
        printf("\nPath found!\n");
    } else {
        printf("\nPath not found!\n");
    }

    return 0;
}