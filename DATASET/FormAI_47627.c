//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10 // Grid size
#define p 0.5 // Probability of site being open

typedef struct site {
    bool open;
    bool full;
} Site;

Site grid[N][N]; // N x N grid of sites

// Function prototypes
void initialize();
void percolate();
void print_grid();
bool is_full(int row, int col);

int main() {
    srand(time(NULL)); // Seed random number generator
    initialize(); // Initialize grid

    percolate(); // Run percolation algorithm

    print_grid(); // Print final state of grid

    return 0;
}

// Initialize the grid of sites
void initialize() {
    int r, c;
    for (r = 0; r < N; r++) {
        for (c = 0; c < N; c++) {
            if (((float)rand()/(float)(RAND_MAX)) <= p) { // Site is open with probability p
                grid[r][c].open = true;
            }
            else {
                grid[r][c].open = false;
            }
            grid[r][c].full = false;
        }
    }

    // Set top row to full
    for (c = 0; c < N; c++) {
        grid[0][c].full = true;
    }
}

// Perform percolation algorithm
void percolate() {
    int r, c;
    bool changed = true;

    while (changed) {
        changed = false;

        for (r = 1; r < N; r++) {
            for (c = 0; c < N; c++) {
                if (grid[r][c].open && !grid[r][c].full) {
                    // Check if any neighboring sites are full
                    if ((r > 0 && grid[r-1][c].full) ||
                        (c > 0 && grid[r][c-1].full) ||
                        (c < N-1 && grid[r][c+1].full)) {
                        grid[r][c].full = true; // Site becomes full
                        changed = true;
                    }
                }
            }
        }
    }
}

// Print grid to console
void print_grid() {
    int r, c;
    for (r = 0; r < N; r++) {
        for (c = 0; c < N; c++) {
            if (grid[r][c].full) { // Full site
                printf("X ");
            }
            else if (grid[r][c].open) { // Open site
                printf("O ");
            }
            else { // Blocked site
                printf("# ");
            }
        }
        printf("\n");
    }
}

// Check if site is full by recursive search
bool is_full(int row, int col) {
    if (row == 0 || grid[row][col].full) {
        return true;
    }
    if (!grid[row][col].open) {
        return false;
    }
    grid[row][col].full = true;
    return (row > 0 && is_full(row-1, col)) ||
           (col > 0 && is_full(row, col-1)) ||
           (col < N-1 && is_full(row, col+1));
}