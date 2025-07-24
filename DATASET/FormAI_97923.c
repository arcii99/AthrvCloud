//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Claude Shannon
/* C Percolation Simulator */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void displayGrid(int grid[ROWS][COLS])
{
    printf("Grid:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 0) {
                printf("|_|");
            } else {
                printf("|%c|", grid[i][j]);
            }
        }
        printf("\n");
    }
}

void initializeGrid(int grid[ROWS][COLS])
{
    // Set all cells to be blocked
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = 0;
        }
    }

    // Set top and bottom rows to be open
    for (int j = 0; j < COLS; j++) {
        grid[0][j] = ' ';
        grid[ROWS-1][j] = ' ';
    }

    // Set left and right columns to be open
    for (int i = 0; i < ROWS; i++) {
        grid[i][0] = ' ';
        grid[i][COLS-1] = ' ';
    }
}

void percolate(int grid[ROWS][COLS])
{
    // Set the seed for the random number generator
    srand(time(NULL));

    // Open cells from the top row down
    for (int j = 1; j < COLS-1; j++) {
        if (rand() % 2 == 0) {
            grid[1][j] = ' ';
        }
    }

    // Continue opening cells until the bottom row is reached
    int percolates = 0;
    while (percolates == 0) {
        for (int i = 1; i < ROWS-1; i++) {
            for (int j = 1; j < COLS-1; j++) {
                if (grid[i][j] == ' ' && grid[i+1][j] == 0) {
                    if (rand() % 2 == 0) {
                        grid[i+1][j] = ' ';
                    }
                }
            }
        }

        // Check if there is a path from top to bottom
        percolates = 1;
        for (int j = 1; j < COLS-1; j++) {
            if (grid[ROWS-2][j] == ' ' && grid[ROWS-1][j] == ' ') {
                percolates = 2;
                break;
            }
        }
    }

    if (percolates == 2) {
        printf("Percolates!\n");
    } else {
        printf("Does not percolate.\n");
    }
}

int main()
{
    int grid[ROWS][COLS];

    // Initialize the grid
    initializeGrid(grid);

    // Display the initial grid
    displayGrid(grid);

    // Percolate the grid
    percolate(grid);

    // Display the final grid
    displayGrid(grid);

    return 0;
}