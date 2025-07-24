//FormAI DATASET v1.0 Category: Game of Life ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Define the grid size */
#define ROWS 20
#define COLS 40

/* Define the cell states */
#define DEAD 0
#define ALIVE 1

/* Function declarations */
void initGrid(int grid[][COLS]);
void printGrid(int grid[][COLS]);
int getNeighborCount(int grid[][COLS], int row, int col);
void updateGrid(int grid[][COLS]);

/* Function to initialize the grid */
void initGrid(int grid[][COLS]) {
    /* Set all cells to dead */
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            grid[row][col] = DEAD;
        }
    }
    /* Set some cells to alive */
    grid[5][10] = ALIVE;
    grid[5][11] = ALIVE;
    grid[5][12] = ALIVE;
    grid[10][20] = ALIVE;
    grid[10][21] = ALIVE;
    grid[10][22] = ALIVE;
    grid[15][30] = ALIVE;
    grid[15][31] = ALIVE;
    grid[15][32] = ALIVE;
}

/* Function to print the grid */
void printGrid(int grid[][COLS]) {
    /* Clear the screen */
    system("clear");
    /* Print the grid */
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (grid[row][col] == ALIVE) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

/* Function to get the number of live neighbors */
int getNeighborCount(int grid[][COLS], int row, int col) {
    /* Check all neighbors and count the live ones */
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            /* Skip the center cell */
            if (i == 0 && j == 0) {
                continue;
            }
            /* Check if the neighbor cell is alive */
            int neighborRow = row + i;
            int neighborCol = col + j;
            if (neighborRow >= 0 && neighborRow < ROWS && neighborCol >= 0 && neighborCol < COLS && grid[neighborRow][neighborCol] == ALIVE) {
                count++;
            }
        }
    }
    return count;
}

/* Function to update the grid */
void updateGrid(int grid[][COLS]) {
    /* Create a copy of the grid */
    int copyGrid[ROWS][COLS];
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            copyGrid[row][col] = grid[row][col];
        }
    }
    /* Update each cell based on the rules of the game */
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            int neighborCount = getNeighborCount(copyGrid, row, col);
            if (copyGrid[row][col] == ALIVE && (neighborCount < 2 || neighborCount > 3)) {
                grid[row][col] = DEAD;
            } else if (copyGrid[row][col] == DEAD && neighborCount == 3) {
                grid[row][col] = ALIVE;
            }
        }
    }
}

/* Main function */
int main() {
    int grid[ROWS][COLS];
    /* Initialize the grid */
    initGrid(grid);
    /* Run the simulation */
    while (1) {
        /* Print the grid */
        printGrid(grid);
        /* Update the grid */
        updateGrid(grid);
        /* Wait for a moment */
        usleep(100000);
    }
    return 0;
}