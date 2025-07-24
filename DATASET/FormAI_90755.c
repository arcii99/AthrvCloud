//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int maze[ROWS][COLS]; // 2D array to store maze data

// Helper function to print maze
void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                printf("X "); // Wall
            } else {
                printf(". "); // Path
            }
        }
        printf("\n");
    }
}

// Helper function to check if cell is valid
int isValid(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || maze[row][col] == 1) {
        return 0; // Invalid
    }
    return 1; // Valid
}

// Recursive function to generate maze using depth-first search algorithm
void generateMaze(int row, int col) {
    int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // Array of possible directions
    int randomDirIndex, newRow, newCol;
    int visitedCount = 0;
    
    // Mark current cell as visited
    maze[row][col] = 0;
    
    // Randomly choose a direction
    do {
        randomDirIndex = rand() % 4;
        newRow = row + direction[randomDirIndex][0];
        newCol = col + direction[randomDirIndex][1];
        visitedCount++;
    } while(!isValid(newRow, newCol) && visitedCount < 4);
    
    // If all directions have been visited, backtrack
    if (visitedCount == 4) {
        return;
    }
    
    // Knock down wall between current and next cell
    if (newRow > row) {
        maze[row+1][col] = 0;
    } else if (newRow < row) {
        maze[row-1][col] = 0;
    } else if (newCol > col) {
        maze[row][col+1] = 0;
    } else {
        maze[row][col-1] = 0;
    }
    
    // Recursively generate maze for next cell
    generateMaze(newRow, newCol);
    generateMaze(row, col); // Backtrack
}

int main() {
    srand(time(NULL)); // Seed for random number generator
    // Initialize maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS-1 || j == 0 || j == COLS-1) {
                maze[i][j] = 1; // Set outer border as walls
            } else {
                maze[i][j] = 1; // Set all inner cells as walls
            }
        }
    }
    // Generate maze
    generateMaze(1, 1);
    // Print maze
    printMaze();
    return 0;
}