//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define maze size
#define MAZE_SIZE 10

// Define wall and path characters for easier readability
#define WALL '*'
#define PATH ' '

// Initialize maze as a 2D array of characters
char maze[MAZE_SIZE][MAZE_SIZE];

// Function prototypes
void generateMaze();
void printMaze();
void placeWall(int row, int col);
void placePath(int row, int col);
int validMove(int row, int col);
int isWallAdjacent(int row, int col);

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Generate maze
    generateMaze();
    
    // Print maze
    printMaze();
    
    return 0;
}

// Function to generate maze
void generateMaze() {
    // Initialize maze with walls
    int i, j;
    for (i = 0; i < MAZE_SIZE; i++) {
        for (j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = WALL;
        }
    }
    
    // Starting position in top left corner
    int row = 1;
    int col = 1;
    placePath(row, col);
    
    // Loop until end of maze is reached
    while (row != MAZE_SIZE-2 || col != MAZE_SIZE-2) {
        int valid = 0;
        while (!valid) {
            // Choose random direction to move
            int dir = rand() % 4;
            switch (dir) {
                case 0:
                    // Move up
                    if (validMove(row-2, col) && isWallAdjacent(row-2, col)) {
                        // Carve path
                        placePath(row-1, col);
                        placePath(row-2, col);
                        row -= 2;
                        valid = 1;
                    }
                    break;
                case 1:
                    // Move right
                    if (validMove(row, col+2) && isWallAdjacent(row, col+2)) {
                        // Carve path
                        placePath(row, col+1);
                        placePath(row, col+2);
                        col += 2;
                        valid = 1;
                    }
                    break;
                case 2:
                    // Move down
                    if (validMove(row+2, col) && isWallAdjacent(row+2, col)) {
                        // Carve path
                        placePath(row+1, col);
                        placePath(row+2, col);
                        row += 2;
                        valid = 1;
                    }
                    break;
                case 3:
                    // Move left
                    if (validMove(row, col-2) && isWallAdjacent(row, col-2)) {
                        // Carve path
                        placePath(row, col-1);
                        placePath(row, col-2);
                        col -= 2;
                        valid = 1;
                    }
                    break;
            }
        }
    }
}

// Function to print maze
void printMaze() {
    int i, j;
    for (i = 0; i < MAZE_SIZE; i++) {
        for (j = 0; j < MAZE_SIZE; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to place wall at given row and column
void placeWall(int row, int col) {
    maze[row][col] = WALL;
}

// Function to place path at given row and column
void placePath(int row, int col) {
    maze[row][col] = PATH;
}

// Function to check if move is valid
int validMove(int row, int col) {
    // Check if within maze bounds
    if (row < 0 || row >= MAZE_SIZE || col < 0 || col >= MAZE_SIZE) {
        return 0;
    }
    
    // Check if destination is a wall
    if (maze[row][col] == WALL) {
        return 1;
    }
    return 0;
}

// Function to check if a wall is adjacent to the given row and column
int isWallAdjacent(int row, int col) {
    if (maze[row-1][col] == WALL || maze[row][col+1] == WALL || maze[row+1][col] == WALL || maze[row][col-1] == WALL) {
        return 1;
    }
    return 0;
}