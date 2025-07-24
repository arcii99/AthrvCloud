//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// Function prototypes
void generateMaze(char maze[ROWS][COLS]);
void printMaze(char maze[ROWS][COLS]);
int solveMaze(char maze[ROWS][COLS], int row, int col);
int validMove(char maze[ROWS][COLS], int row, int col);

int main() {
    // Initialize maze and solve it
    char maze[ROWS][COLS];
    generateMaze(maze);
    printf("Maze before solving:\n\n");
    printMaze(maze);
    int solved = solveMaze(maze, 0, 0);
    if (solved) {
        printf("\nMaze after solving:\n\n");
        printMaze(maze);
    } else {
        printf("\nNo solution found!\n\n");
    }

    return 0;
}

// Generate a random maze
void generateMaze(char maze[ROWS][COLS]) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1 || rand() % 4 == 0) {
                maze[i][j] = '#';
            } else {
                maze[i][j] = ' ';
            }
        }
    }
    maze[1][0] = 'S'; // Starting point
    maze[ROWS - 2][COLS - 1] = 'E'; // Ending point
}

// Print the maze
void printMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Solve the maze using recursion
int solveMaze(char maze[ROWS][COLS], int row, int col) {
    // Check if we have reached the end of the maze
    if (maze[row][col] == 'E') {
        return 1;
    }

    // Check if this spot is a valid move
    if (validMove(maze, row, col)) {
        maze[row][col] = 'x'; // Mark the spot as visited

        // Try moving in all four directions
        if (solveMaze(maze, row - 1, col)) { // Up
            return 1;
        }
        if (solveMaze(maze, row, col + 1)) { // Right
            return 1;
        }
        if (solveMaze(maze, row + 1, col)) { // Down
            return 1;
        }
        if (solveMaze(maze, row, col - 1)) { // Left
            return 1;
        }

        maze[row][col] = ' '; // Mark the spot as unvisited
    }

    return 0; // No solution found
}

// Check if a move is valid
int validMove(char maze[ROWS][COLS], int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0; // Spot is outside of maze
    }
    if (maze[row][col] == '#' || maze[row][col] == 'x') {
        return 0; // Spot is a wall or has already been visited
    }
    return 1; // Move is valid
}