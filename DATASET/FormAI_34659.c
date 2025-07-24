//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define maze dimensions and borders
#define ROWS 25
#define COLS 25
#define BORDER '*'

// Define possible directions for maze generation
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

// Define cell states
#define UNVISITED 0
#define VISITED 1

// Function to generate a random number based on current time
int generateRandomNumber() {
    srand(time(NULL));
    return rand() % 4;
}

int main() {
    // Initialize maze with border and unvisited cells
    int maze[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || j == 0 || i == ROWS - 1 || j == COLS - 1) {
                maze[i][j] = BORDER;
            } else {
                maze[i][j] = UNVISITED;
            }
        }
    }

    // Set starting point and mark as visited
    int currentRow = 1;
    int currentCol = 1;
    maze[currentRow][currentCol] = VISITED;

    // Generate maze
    while (1) {
        // Generate random direction
        int direction = generateRandomNumber();

        // Check if next cell in chosen direction has not been visited
        switch (direction) {
            case UP:
                if (maze[currentRow - 1][currentCol] == UNVISITED) {
                    // Open wall between current cell and next cell
                    maze[currentRow][currentCol] &= ~0x08;
                    maze[currentRow - 1][currentCol] &= ~0x02;

                    // Move to next cell and mark as visited
                    currentRow--;
                    maze[currentRow][currentCol] = VISITED;
                }
                break;
            
            case RIGHT:
                if (maze[currentRow][currentCol + 1] == UNVISITED) {
                    // Open wall between current cell and next cell
                    maze[currentRow][currentCol] &= ~0x04;
                    maze[currentRow][currentCol + 1] &= ~0x01;

                    // Move to next cell and mark as visited
                    currentCol++;
                    maze[currentRow][currentCol] = VISITED;
                }
                break;
            
            case DOWN:
                if (maze[currentRow + 1][currentCol] == UNVISITED) {
                    // Open wall between current cell and next cell
                    maze[currentRow][currentCol] &= ~0x02;
                    maze[currentRow + 1][currentCol] &= ~0x08;

                    // Move to next cell and mark as visited
                    currentRow++;
                    maze[currentRow][currentCol] = VISITED;
                }
                break;
            
            case LEFT:
                if (maze[currentRow][currentCol - 1] == UNVISITED) {
                    // Open wall between current cell and next cell
                    maze[currentRow][currentCol] &= ~0x01;
                    maze[currentRow][currentCol - 1] &= ~0x04;

                    // Move to next cell and mark as visited
                    currentCol--;
                    maze[currentRow][currentCol] = VISITED;
                }
                break;
        }

        // Check if maze has been fully generated
        if (maze[currentRow - 1][currentCol] == VISITED && maze[currentRow][currentCol + 1] == VISITED && maze[currentRow + 1][currentCol] == VISITED && maze[currentRow][currentCol - 1] == VISITED) {
            break;
        }
    }

    // Print maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}