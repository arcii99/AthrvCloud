//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10 // size of the grid
#define THRESHOLD 0.6 // probability that a site will be open
#define BLOCKED 0 // blocked site
#define OPEN 1 // open site
#define FULL 2 // site connected to the top row

int grid[SIZE][SIZE];
bool open[SIZE][SIZE];

bool percolates(void);
bool is_full(int row, int col);
void open_site(int row, int col);
void print_grid(void);

int main(void) {
    // seed random number generator
    srand(time(NULL));

    // initialize grid
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = BLOCKED;
            open[i][j] = false;
        }
    }

    // percolate until system percolates
    while (!percolates()) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        if (!open[row][col]) {
            open_site(row, col);
        }
    }

    printf("Percolation achieved!\n");
    print_grid();
}

// check if system percolates
bool percolates(void) {
    for (int i = 0; i < SIZE; i++) {
        if (is_full(SIZE - 1, i)) {
            return true;
        }
    }
    return false;
}

// check if site is connected to top row
bool is_full(int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return false;
    }
    if (grid[row][col] == BLOCKED || open[row][col]) {
        return false;
    }
    if (row == 0) {
        return true;
    }
    open[row][col] = true;
    return is_full(row - 1, col) || is_full(row, col + 1)
           || is_full(row + 1, col) || is_full(row, col - 1);
}

// open site and update grid
void open_site(int row, int col) {
    open[row][col] = true;
    if (row == 0) {
        grid[row][col] = FULL;
    } else {
        grid[row][col] = OPEN;
    }
}

// print state of grid
void print_grid(void) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == BLOCKED) {
                printf("# ");
            } else if (grid[i][j] == OPEN) {
                printf(". ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }
}