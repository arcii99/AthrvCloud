//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Function to generate a random maze
void generateMaze(int maze[ROWS][COLS]) {
    srand(time(NULL)); // Seed the random number generator

    // Set the borders of the maze to be walls
    for (int i = 0; i < ROWS; i++) {
        maze[i][0] = 1; // Left wall
        maze[i][COLS-1] = 1; // Right wall
    }
    for (int i = 0; i < COLS; i++) {
        maze[0][i] = 1; // Top wall
        maze[ROWS-1][i] = 1; // Bottom wall
    }

    // Generate inner walls
    for (int i = 1; i < ROWS-1; i++) {
        for (int j = 1; j < COLS-1; j++) {
            int r = rand() % 3;
            if (r == 0) {
                maze[i][j] = 1; // Wall
            } else {
                maze[i][j] = 0; // Path
            }
        }
    }
    
    // Set starting and ending points
    maze[1][1] = 0; // Starting point
    maze[ROWS-2][COLS-2] = 0; // Ending point
}

// Function to print the maze
void printMaze(int maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                printf("#"); // Wall
            } else {
                printf("."); // Path
            }
        }
        printf("\n");
    }
}

// Function to find a route through the maze
void findRoute(int maze[ROWS][COLS], int row, int col) {
    if (maze[row][col] == 0) {
        maze[row][col] = 2; // Visited
        if (row == ROWS-2 && col == COLS-2) {
            printf("Found the exit!\n");
            return;
        }
        if (row > 0) {
            findRoute(maze, row-1, col); // Move up
        }
        if (row < ROWS-1) {
            findRoute(maze, row+1, col); // Move down
        }
        if (col > 0) {
            findRoute(maze, row, col-1); // Move left
        }
        if (col < COLS-1) {
            findRoute(maze, row, col+1); // Move right
        }
    }
}

int main() {
    int maze[ROWS][COLS]; // Maze array
    generateMaze(maze); // Generate the maze
    printf("Maze:\n");
    printMaze(maze); // Print the maze
    printf("\n");

    printf("Finding the route...\n");
    findRoute(maze, 1, 1); // Find the route
    printf("\n");

    printf("Solution:\n");
    printMaze(maze); // Print the solution
    printf("\n");
    
    return 0;
}