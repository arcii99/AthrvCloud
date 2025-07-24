//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

// Function to print the given maze
void printMaze(int maze[ROWS][COLS]) {
    printf("Maze:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the given position is valid
int isPositionValid(int maze[ROWS][COLS], int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] == 0);
}

// Function to find a route in the maze
int findRoute(int maze[ROWS][COLS], int x, int y, int destX, int destY, int sol[ROWS][COLS]) {
    // Base case: if destination is reached, return true
    if (x == destX && y == destY) {
        sol[x][y] = 1;
        return 1;
    }
    // Check if current position is valid
    if (isPositionValid(maze, x, y) == 1) {
        // Set solution position to 1
        sol[x][y] = 1;
        // Move in the right direction
        if (findRoute(maze, x, y+1, destX, destY, sol) == 1) {
            return 1;
        }
        // Move in the down direction
        if (findRoute(maze, x+1, y, destX, destY, sol) == 1) {
            return 1;
        }
        // Move in the left direction
        if (findRoute(maze, x, y-1, destX, destY, sol) == 1) {
            return 1;
        }
        // Move in the up direction
        if (findRoute(maze, x-1, y, destX, destY, sol) == 1) {
            return 1;
        }
        // If none of the directions work, backtrack and set the solution position to 0
        sol[x][y] = 0;
        return 0;
    }
    return 0;
}

int main() {
    int maze[ROWS][COLS] = {
        {0, 0, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };
    int sol[ROWS][COLS] = {0};
    int startX = 0, startY = 0;
    int destX = 4, destY = 4;
    
    // Print the starting maze
    printMaze(maze);
    
    // Find route in the maze
    if (findRoute(maze, startX, startY, destX, destY, sol) == 1) {
        printf("Solution:\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%d ", sol[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution found.\n");
    }
    
    return 0;
}