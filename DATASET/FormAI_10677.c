//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: recursive
#include <stdio.h>

#define ROW 5
#define COL 5

// Function prototypes
void printPath(int path[ROW][COL], int row, int col);

// Recursive function to find the path
void findPath(int maze[ROW][COL], int row, int col, int path[ROW][COL]) {
    if (row < 0 || col < 0 || row >= ROW || col >= COL || maze[row][col] == 0 || path[row][col] == 1)
        return;
    
    // Mark the current cell as visited
    path[row][col] = 1;
    
    // Check if the current cell is the end cell
    if (row == ROW - 1 && col == COL - 1) {
        // Print the path
        printPath(path, ROW, COL);
        return;
    }
    
    // Recursively search for the path
    findPath(maze, row - 1, col, path);  // Move up
    findPath(maze, row, col + 1, path);  // Move right
    findPath(maze, row + 1, col, path);  // Move down
    findPath(maze, row, col - 1, path);  // Move left
    
    // Mark the current cell as unvisited
    path[row][col] = 0;
}

// Function to print the path
void printPath(int path[ROW][COL], int row, int col) {
    printf("The path is:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int maze[ROW][COL] = {
        { 1, 0, 0, 0, 0 },
        { 1, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 1 },
        { 0, 0, 0, 0, 1 },
        { 0, 0, 0, 0, 1 }
    };
    
    int path[ROW][COL] = { 0 };
    
    findPath(maze, 0, 0, path);
    
    return 0;
}