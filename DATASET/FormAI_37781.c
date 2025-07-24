//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void generateMaze(int maze[ROWS][COLS]) {
    // Initialize maze with all walls up
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            maze[row][col] = 15; // 15 in binary is 1111, representing all walls up
        }
    }

    srand(time(NULL)); // Seed random number generator

    // Start at top-left corner
    int row = 0;
    int col = 0;
    maze[row][col] &= ~1; // Clear left wall

    while (true) {
        // Generate random number between 0 and 3 (inclusive)
        int direction = rand() % 4;

        if (direction == 0 && row > 0) { // Up
            if (maze[row-1][col] == 15) { // Check if cell hasn't been visited
                maze[row][col] &= ~8; // Clear top wall of current cell
                row--;
                maze[row][col] &= ~4; // Clear bottom wall of new cell
            }
        }

        if (direction == 1 && row < ROWS-1) { // Down
            if (maze[row+1][col] == 15) {
                maze[row][col] &= ~4; // Clear bottom wall of current cell
                row++;
                maze[row][col] &= ~8; // Clear top wall of new cell
            }
        }

        if (direction == 2 && col > 0) { // Left
            if (maze[row][col-1] == 15) {
                maze[row][col] &= ~1; // Clear left wall of current cell
                col--;
                maze[row][col] &= ~2; // Clear right wall of new cell
            }
        }

        if (direction == 3 && col < COLS-1) { // Right
            if (maze[row][col+1] == 15) {
                maze[row][col] &= ~2; // Clear right wall of current cell
                col++;
                maze[row][col] &= ~1; // Clear left wall of new cell
            }
        }

        // Check if all cells have been visited
        bool done = true;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (maze[r][c] == 15) {
                    done = false;
                    break;
                }
            }
            if (!done) {
                break;
            }
        }
        if (done) {
            break;
        }
    }
}

void printMaze(int maze[ROWS][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        // Print top walls
        for (int col = 0; col < COLS; col++) {
            printf("+");
            if (maze[row][col] & 1) { // Check left wall
                printf("-");
            } else {
                printf(" ");
            }
        }
        printf("+\n");
        // Print left walls and spaces
        for (int col = 0; col < COLS; col++) {
            if (maze[row][col] & 8) { // Check top wall
                printf("|");
            } else {
                printf(" ");
            }
            printf(" ");
        }
        if (maze[row][COLS-1] & 2) { // Check right wall of last cell
            printf("|");
        } else {
            printf(" ");
        }
        printf("\n");
    }
    // Print bottom walls
    for (int col = 0; col < COLS; col++) {
        printf("+");
        if (maze[ROWS-1][col] & 4) { // Check bottom wall of last row
            printf("-");
        } else {
            printf(" ");
        }
    }
    printf("+\n");
}

int main() {
    int maze[ROWS][COLS];
    generateMaze(maze);
    printMaze(maze);
    return 0;
}