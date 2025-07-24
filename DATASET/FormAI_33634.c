//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

// Function to generate a random maze
void generateMaze(int maze[][SIZE]) {
    // Initialize the maze
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            maze[i][j] = rand() % 2;
        }
    }
    
    // Set the start and end points
    maze[0][0] = 1;
    maze[SIZE-1][SIZE-1] = 1;
}

// Function to print the maze
void printMaze(int maze[][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (maze[i][j] == 1) {
                printf("X ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// Function to check if the current position is valid
int isValidPosition(int maze[][SIZE], int x, int y) {
    if (x >= 0 && x < SIZE && y >= 0 && y < SIZE && maze[x][y] == 0) {
        return 1;
    }
    return 0;
}

// Recursive function to find the path through the maze
int findPath(int maze[][SIZE], int x, int y) {
    // If we have reached the end, return success
    if (x == SIZE-1 && y == SIZE-1) {
        maze[x][y] = 2; // Mark the end point
        return 1;
    }
    
    // If this is a valid position, mark it as part of the path
    if (isValidPosition(maze, x, y)) {
        maze[x][y] = 2;
        
        // Try moving right
        if (findPath(maze, x, y+1)) {
            return 1;
        }
        
        // Try moving down
        if (findPath(maze, x+1, y)) {
            return 1;
        }
        
        // Try moving left
        if (findPath(maze, x, y-1)) {
            return 1;
        }
        
        // Try moving up
        if (findPath(maze, x-1, y)) {
            return 1;
        }
        
        // If none of the moves worked, backtrack
        maze[x][y] = 0;
    }
    
    return 0; // Return failure
}

int main() {
    int maze[SIZE][SIZE];
    int success;
    
    // Generate the maze
    generateMaze(maze);
    
    // Print the maze
    printf("Maze: \n");
    printMaze(maze);
    
    // Find the path through the maze
    printf("\nFinding path...\n");
    success = findPath(maze, 0, 0);
    
    if (success) {
        // Print the solved maze
        printf("\nSolution: \n");
        printMaze(maze);
    } else {
        printf("\nNo solution found.\n");
    }
    
    return 0;
}