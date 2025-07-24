//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the size of the grid
#define GRID_SIZE 10

// Define the probability of an element being open
#define OPEN_PROBABILITY 0.6

// Define the symbols for an open and closed element
#define OPEN_SYMBOL "."
#define CLOSED_SYMBOL "#"

// Define the symbols for a full and empty path
#define FULL_SYMBOL "X"
#define EMPTY_SYMBOL " "

// Define the grid array
bool grid[GRID_SIZE][GRID_SIZE];

// Define the function to check if site (i, j) is open
bool is_open(int i, int j) {
    if (i < 0 || i >= GRID_SIZE || j < 0 || j >= GRID_SIZE)
        return false;
    return grid[i][j];
}

// Define the function to check if site (i, j) is full
bool is_full(int i, int j) {
    if (i < 0 || i >= GRID_SIZE || j < 0 || j >= GRID_SIZE)
        return false;
    if (!is_open(i, j))
        return false;
    if (i == 0 || i == GRID_SIZE - 1 || j == 0 || j == GRID_SIZE - 1)
        return true;
    return is_full(i-1, j) || is_full(i+1, j) || is_full(i, j-1) || is_full(i, j+1);
}

// Define the main function
int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the grid to be closed
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = false;
        }
    }

    // Open sites randomly with probability OPEN_PROBABILITY
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if ((double)rand() / (double)RAND_MAX < OPEN_PROBABILITY) {
                grid[i][j] = true;
            }
        }
    }

    // Print the grid
    printf("Initial Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j]) {
                printf("%s ", OPEN_SYMBOL);
            } else {
                printf("%s ", CLOSED_SYMBOL);
            }
        }
        printf("\n");
    }

    // Fill the full sites with FULL_SYMBOL
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (is_full(i, j)) {
                grid[i][j] = true;
            }
        }
    }

    // Print the final grid
    printf("\nFinal Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j]) {
                printf("%s ", FULL_SYMBOL);
            } else {
                printf("%s ", EMPTY_SYMBOL);
            }
        }
        printf("\n");
    }

    return 0;
}