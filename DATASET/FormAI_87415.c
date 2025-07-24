//FormAI DATASET v1.0 Category: Game of Life ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the dimensions of the grid
#define ROWS 20
#define COLS 20

// Define the maximum number of generations to simulate
#define MAX_GEN 100

// Define the symbols to represent live/dead cells
#define LIVE_CELL '*'
#define DEAD_CELL ' '

// Function to randomly initialize the grid
void initGrid(char grid[ROWS][COLS]) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (rand() % 2) {
                grid[i][j] = LIVE_CELL;
            } else {
                grid[i][j] = DEAD_CELL;
            }
        }
    }
}

// Function to print the current generation of the grid
void printGrid(char grid[ROWS][COLS], int gen) {
    printf("Generation %d:\n", gen);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to count the number of live neighbors of a given cell
int countLiveNeighbors(char grid[ROWS][COLS], int row, int col) {
    int liveNeighbors = 0;
    for (int i = row-1; i <= row+1; i++) {
        for (int j = col-1; j <= col+1; j++) {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS && !(i == row && j == col)) {
                if (grid[i][j] == LIVE_CELL) {
                    liveNeighbors++;
                }
            }
        }
    }
    return liveNeighbors;
}

// Function to update the grid based on the rules of the game
void updateGrid(char grid[ROWS][COLS]) {
    char newGrid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int liveNeighbors = countLiveNeighbors(grid, i, j);
            if (grid[i][j] == LIVE_CELL) {
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    newGrid[i][j] = DEAD_CELL;
                } else {
                    newGrid[i][j] = LIVE_CELL;
                }
            } else {
                if (liveNeighbors == 3) {
                    newGrid[i][j] = LIVE_CELL;
                } else {
                    newGrid[i][j] = DEAD_CELL;
                }
            }
        }
    }
    // Copy the new grid back to the original grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    // Initialize the grid
    char grid[ROWS][COLS];
    initGrid(grid);

    // Simulate the generations
    for (int gen = 0; gen < MAX_GEN; gen++) {
        printGrid(grid, gen);
        updateGrid(grid);
    }

    return 0;
}