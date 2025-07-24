//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// Function to print the maze
void printMaze(int maze[ROWS][COLS]) {
    for(int i=0; i < ROWS; i++) {
        for(int j=0; j < COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a cell is valid or not
int isValidCell(int row, int col, int maze[ROWS][COLS]) {
    if(row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] == 1) {
        return 1;
    }
    return 0;
}

// Function to find the route through the maze
int findRoute(int row, int col, int maze[ROWS][COLS], int path[ROWS][COLS]) {
    // Check if we have reached the end of the maze
    if(row == ROWS-1 && col == COLS-1) {
        path[row][col] = 1;
        return 1;
    }
    
    // Check if the current cell is valid or not
    if(isValidCell(row, col, maze) == 1) {
        path[row][col] = 1;
        
        // Move right
        if(findRoute(row, col+1, maze, path) == 1) {
            return 1;
        }
        
        // Move down
        if(findRoute(row+1, col, maze, path) == 1) {
            return 1;
        }
        
        // If we cannot move right or down, backtrack and mark current cell as 0
        path[row][col] = 0;
        return 0;
    }
    
    return 0;
}

int main() {
    // Initialize the maze
    int maze[ROWS][COLS] = {
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 0, 0, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 1}
    };
    
    // Initialize the path
    int path[ROWS][COLS] = {0};

    // Find the route through the maze
    if(findRoute(0, 0, maze, path) == 0) {
        printf("No path found\n");
        return 0;
    }
    
    // Print the solution
    printf("Solution:\n");
    printMaze(path);
    
    return 0;
}