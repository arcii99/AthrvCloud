//FormAI DATASET v1.0 Category: Game ; Style: enthusiastic
// Welcome to my awesome C game program!
// This program will take you on a journey through a mysterious maze.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10 // Define the number of rows in the maze
#define COLS 10 // Define the number of columns in the maze

// Create a struct to represent the maze
struct Maze {
    int board[ROWS][COLS]; // 2D array to store the maze
    int playerRow; // row index of player's position
    int playerCol; // column index of player's position
};

// Function to print the maze
void printMaze(struct Maze maze) {
    printf("\n"); // Print a newline before the maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze.board[i][j] == 0) {
                printf("# "); // print a wall
            } else if (maze.playerRow == i && maze.playerCol == j) {
                printf("P "); // print the player
            } else {
                printf(". "); // print a space
            }
        }
        printf("\n"); // Print a newline after each row
    }
}

// Function to generate the maze
void generateMaze(struct Maze *maze) {
    // Initialize the random number generator
    srand(time(NULL));
    
    // Set the player's initial position
    maze->playerRow = ROWS / 2;
    maze->playerCol = COLS / 2;
    
    // Set all walls in the maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze->board[i][j] = 0;
        }
    }
    
    // Create the maze by randomly selecting cells to break down walls
    int totalCells = ROWS * COLS;
    int visitedCells = 1;
    int currentRow = 0;
    int currentCol = 0;
    while (visitedCells < totalCells) {
        // Move to a random neighboring cell
        int direction = rand() % 4;
        switch (direction) {
            case 0: // move up
                if (currentRow > 0 && maze->board[currentRow - 1][currentCol] == 0) {
                    maze->board[currentRow][currentCol] |= 1; // break down current cell's top wall
                    maze->board[currentRow - 1][currentCol] |= 2; // break down neighboring cell's bottom wall
                    currentRow--;
                    visitedCells++;
                }
                break;
            case 1: // move right
                if (currentCol < COLS - 1 && maze->board[currentRow][currentCol + 1] == 0) {
                    maze->board[currentRow][currentCol] |= 2; // break down current cell's right wall
                    maze->board[currentRow][currentCol + 1] |= 1; // break down neighboring cell's left wall
                    currentCol++;
                    visitedCells++;
                }
                break;
            case 2: // move down
                if (currentRow < ROWS - 1 && maze->board[currentRow + 1][currentCol] == 0) {
                    maze->board[currentRow][currentCol] |= 4; // break down current cell's bottom wall
                    maze->board[currentRow + 1][currentCol] |= 8; // break down neighboring cell's top wall
                    currentRow++;
                    visitedCells++;
                }
                break;
            case 3: // move left
                if (currentCol > 0 && maze->board[currentRow][currentCol - 1] == 0) {
                    maze->board[currentRow][currentCol] |= 8; // break down current cell's left wall
                    maze->board[currentRow][currentCol - 1] |= 4; // break down neighboring cell's right wall
                    currentCol--;
                    visitedCells++;
                }
                break;
        }
    }
}

int main() {
    struct Maze maze;
    generateMaze(&maze);
    printMaze(maze);
    return 0;
}