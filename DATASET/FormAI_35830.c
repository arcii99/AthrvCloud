//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

// The input maze
int maze[ROW][COL] = {
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
    {0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
    {1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Utility function to print the maze
void printMaze(int maze[][COL])
{
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// Utility function to check if the given position is valid
int isValidPosition(int row, int col)
{
    return (row >= 0) &&
           (col >= 0) &&
           (row < ROW) &&
           (col < COL) &&
           maze[row][col];
}

// Recursive function to find the path through the maze
int findPath(int row, int col, int path[][COL], int index)
{
    // Base cases
    if (row == ROW - 1 && col == COL - 1) {
        // Destination reached
        path[row][col] = index;
        return 1;
    }

    if (!isValidPosition(row, col)) {
        // Invalid position
        return 0;
    }

    if (path[row][col] != -1) {
        // Already visited the position
        return 0;
    }

    // Set the current position as visited
    path[row][col] = index;

    // Check for all directions
    if (findPath(row + 1, col, path, index + 1) ||
        findPath(row - 1, col, path, index + 1) ||
        findPath(row, col + 1, path, index + 1) ||
        findPath(row, col - 1, path, index + 1)) {
        // Path found
        return 1;
    }

    // Mark the current position as unvisited
    path[row][col] = -1;

    // Path not found
    return 0;
}

int main()
{
    // The path array to store the final path
    int path[ROW][COL];

    // Initialize the path array with -1
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            path[i][j] = -1;
        }
    }

    // Find the path through the maze
    int foundPath = findPath(0, 0, path, 0);

    if (foundPath) {
        printf("Path found through the maze:\n");
        printMaze(path);
    } else {
        printf("No path found through the maze\n");
    }

    return 0; 
}