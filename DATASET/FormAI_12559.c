//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define PERCENT_FULL 50

// function prototypes
void print_grid(int grid[ROWS][COLS]);
int is_full(int grid[ROWS][COLS]);
void percolate(int grid[ROWS][COLS], int percent_full);

int main() {
    int grid[ROWS][COLS];

    // initialize random seed
    srand(time(NULL));

    // fill grid with random 0 and 1 values
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    // print initial grid
    printf("Initial grid:\n");
    print_grid(grid);

    // percolate the system with random percent full
    int percent_full = rand() % 101;  // 0 to 100 inclusive
    percolate(grid, percent_full);

    // print final grid
    printf("Final grid:\n");
    print_grid(grid);

    // check if system percolated
    if (is_full(grid)) {
        printf("The system percolated!\n");
    } else {
        printf("The system did not percolate.\n");
    }

    return 0;
}

// prints the grid
void print_grid(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// checks if the system is full
int is_full(int grid[ROWS][COLS]) {
    for (int j = 0; j < COLS; j++) {
        if (grid[0][j] == 1) {
            return 1;  // system is full
        }
    }
    return 0;  // system is not full
}

// percolates the system
void percolate(int grid[ROWS][COLS], int percent_full) {
    int fill_rows = percent_full * ROWS / 100;

    // fill top rows
    for (int i = 0; i < fill_rows; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = 1;
        }
    }

    // fill bottom rows
    for (int i = ROWS-1; i >= ROWS-fill_rows; i--) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = 1;
        }
    }
}