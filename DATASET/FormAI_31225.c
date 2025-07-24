//FormAI DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ROWS 30
#define COLS 30
#define GENERATIONS 1000

int grid[ROWS][COLS];
int copy[ROWS][COLS];

// Function to initialize the grid randomly
void initGrid() {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to print the grid
void printGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("██");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to count the number of live neighbors of a given cell
int countNeighbors(int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i == row && j == col) continue;
            if (i < 0 || i >= ROWS || j < 0 || j >= COLS) continue;
            if (grid[i][j] == 1) count++;
        }
    }
    return count;
}

// Function to update the grid for the next generation
void updateGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(i, j);
            if (grid[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    copy[i][j] = 0;
                } else {
                    copy[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    copy[i][j] = 1;
                } else {
                    copy[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = copy[i][j];
        }
    }
}

int main() {
    initGrid();
    for (int i = 0; i < GENERATIONS; i++) {
        printf("Generation %d:\n", i);
        printGrid();
        updateGrid();
        usleep(100000);
    }
    return 0;
}