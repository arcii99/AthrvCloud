//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

#define BLOCKED 0
#define OPEN 1

int grid[ROWS][COLS];
int percThreshold = 50;

void initializeGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            srand(time(NULL));
            if (rand() % 100 < percThreshold) {
                grid[i][j] = OPEN;
            } else {
                grid[i][j] = BLOCKED;
            }
        }
    }
}

void printGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == OPEN) {
                printf(" ");
            } else {
                printf("+");
            }
        }
        printf("\n");
    }
}

void floodFill(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) return;
    if (grid[row][col] == BLOCKED) return;
    grid[row][col] = BLOCKED;
    floodFill(row + 1, col);
    floodFill(row - 1, col);
    floodFill(row, col + 1);
    floodFill(row, col - 1);
}

void runSimulation() {
    initializeGrid();
    printGrid();
    printf("\n");
    printf("Running simulation...\n");
    for (int i = 0; i < COLS; i++) {
        if (grid[0][i] == OPEN) {
            floodFill(0, i);
        }
    }
    printf("Simulation complete.\n");
    printf("\n");
    printGrid();
}

int main() {
    runSimulation();
    return 0;
}