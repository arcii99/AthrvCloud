//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: complete
#include <stdio.h>

#define ROW_SIZE 10
#define COL_SIZE 10

void printMaze(int maze[ROW_SIZE][COL_SIZE]) {
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COL_SIZE; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int findPathUtil(int maze[ROW_SIZE][COL_SIZE], int row, int col, int path[ROW_SIZE][COL_SIZE]) {
    if (row < 0 || row >= ROW_SIZE || col < 0 || col >= COL_SIZE) {
        // Invalid position
        return 0;
    }
    
    if (maze[row][col] == 0) {
        // Wall
        return 0;
    }
    
    if (path[row][col] == 1) {
        // Already visited
        return 0;
    }
    
    path[row][col] = 1;
    
    // Check if destination is reached
    if (row == ROW_SIZE - 1 && col == COL_SIZE - 1) {
        return 1;
    }
    
    // Check in all four directions
    if (findPathUtil(maze, row+1, col, path) == 1) {
        return 1; // Down
    }
    
    if (findPathUtil(maze, row, col+1, path) == 1) {
        return 1; // Right
    }
    
    if (findPathUtil(maze, row-1, col, path) == 1) {
        return 1; // Up
    }
    
    if (findPathUtil(maze, row, col-1, path) == 1) {
        return 1; // Left
    }
    
    // No path found
    return 0;
}

void findPath(int maze[ROW_SIZE][COL_SIZE]) {
    int path[ROW_SIZE][COL_SIZE] = {0}; // Initialize to 0
    
    if (findPathUtil(maze, 0, 0, path) == 1) {
        printf("Path found!\n");
        printMaze(path);
    } else {
        printf("No path found\n");
    }
}

int main() {
    int maze[ROW_SIZE][COL_SIZE] = {
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    
    findPath(maze);
    
    return 0;
}