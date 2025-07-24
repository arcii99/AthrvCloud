//FormAI DATASET v1.0 Category: Data structures visualization ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define configuration values for the visualization
#define ROWS 6
#define COLS 6
#define EMPTY_CELL " "
#define NON_EMPTY_CELL "*"

// Struct for the data structure we want to visualize
typedef struct {
    int data[ROWS][COLS];
} Grid;

// Function to initialize the grid with random values
void initGrid(Grid* grid) {
    int r, c;
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            // Randomly set a cell to be empty or non-empty
            grid->data[r][c] = rand() % 2;
        }
    }
}

// Function to print the grid as a visualization
void printGrid(Grid* grid) {
    int r, c;
    printf("+");
    for (c = 0; c < COLS; c++) {
        printf("-");
    }
    printf("+\n");
    for (r = 0; r < ROWS; r++) {
        printf("|");
        for (c = 0; c < COLS; c++) {
            if (grid->data[r][c]) {
                printf(NON_EMPTY_CELL);
            } else {
                printf(EMPTY_CELL);
            }
        }
        printf("|\n");
    }
    printf("+");
    for (c = 0; c < COLS; c++) {
        printf("-");
    }
    printf("+\n");
}

// Main function to test the visualization
int main() {
    // Initialize the random number generator
    srand(0);

    // Create a grid and initialize it with random values
    Grid grid;
    initGrid(&grid);

    // Print the grid as a visualization
    printGrid(&grid);
    return 0;
}