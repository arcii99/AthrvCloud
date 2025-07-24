//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// function prototypes
void initialize(bool grid[][COLS]);
bool percolates(bool grid[][COLS], int row, int col);
void printGrid(bool grid[][COLS]);

int main()
{
    srand(time(NULL)); // seed for random number generation

    bool grid[ROWS][COLS];
    initialize(grid);

    printf("Initial grid:\n");
    printGrid(grid);

    int numFilled = 0;
    while (!percolates(grid, ROWS - 1, 0)) {
        int randRow = rand() % ROWS;
        int randCol = rand() % COLS;

        if (!grid[randRow][randCol]) {
            grid[randRow][randCol] = true;
            numFilled++;
        }

        printf("Step %d:\n", numFilled);
        printGrid(grid);
    }

    printf("Percolation achieved after %d steps.\n", numFilled);

    return 0;
}

/**
 * Initializes the grid with all sites blocked.
 */
void initialize(bool grid[][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = false;
        }
    }
}

/**
 * Checks if the grid percolates from the given site.
 */
bool percolates(bool grid[][COLS], int row, int col)
{
    if (row == 0 && col == COLS - 1) {
        return grid[0][COLS - 1];
    }

    if (grid[row][col] == false) {
        return false;
    }

    bool topConnected = false;
    bool bottomConnected = false;
    bool leftConnected = false;
    bool rightConnected = false;

    if (row > 0) {
        topConnected = percolates(grid, row - 1, col);
    }

    if (row < ROWS - 1) {
        bottomConnected = percolates(grid, row + 1, col);
    }

    if (col > 0) {
        leftConnected = percolates(grid, row, col - 1);
    }

    if (col < COLS - 1) {
        rightConnected = percolates(grid, row, col + 1);
    }

    return topConnected || bottomConnected || leftConnected || rightConnected;
}

/**
 * Prints the current state of the grid.
 */
void printGrid(bool grid[][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j]) {
                printf("* ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}