//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIMENSION 10 // n x n grid

/* Struct for cell data */
typedef struct {
    int row, col, status;
} Cell;

/* Array of cells for the grid */
Cell grid[DIMENSION][DIMENSION];

/* Function to initialize the grid */
void initializeGrid() {
    int i, j;
    for (i = 0; i < DIMENSION; i++) {
        for (j = 0; j < DIMENSION; j++) {
            grid[i][j].row = i;
            grid[i][j].col = j;
            grid[i][j].status = 0; // 0 = blocked, 1 = open
        }
    }
}

/* Function to randomly open cells in the grid */
void randomizeGrid() {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < DIMENSION; i++) {
        for (j = 0; j < DIMENSION; j++) {
            if (rand() % 2 == 0) {
                grid[i][j].status = 1;
            }
        }
    }
}

/* Function to print the grid with ASCII art */
void printGrid() {
    int i, j;
    for (i = 0; i < DIMENSION; i++) {
        printf("|");
        for (j = 0; j < DIMENSION; j++) {
            if (grid[i][j].status == 0) {
                printf("X|"); // Blocked
            } else {
                printf(" |"); // Open
            }
        }
        printf("\n");
    }
}

/* Function to check if percolation has occurred */
int checkPercolation() {
    int i, j;
    for (j = 0; j < DIMENSION; j++) {
        if (grid[0][j].status == 1) { // Check if top row is open
            for (i = 0; i < DIMENSION; i++) {
                if (grid[i][j].status == 1 && i == DIMENSION - 1) { // Check if bottom row is open
                    return 1; // Percolation has occurred
                } else if (grid[i][j].status == 0) {
                    break; // Cell is blocked, no percolation through this path
                }
            }
        }
    }
    return 0; // Percolation has not occurred
}

/* Main function */
int main() {
    initializeGrid();
    randomizeGrid();
    printGrid();
    if (checkPercolation() == 1) {
        printf("Percolation has occurred!\n");
    } else {
        printf("Percolation has not occurred.\n");
    }
    return 0;
}