//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int grid[ROWS][COLS];
int open[ROWS * COLS]; // keep track of open sites
int sz[ROWS * COLS]; // keep track of sizes for weighted quick-union

// helper function to convert 2D array indices to 1D array index
int index(int row, int col) {
    return row * COLS + col;
}

// helper function to check if a given cell is valid
int is_valid(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

// helper function to check if a given cell is open
int is_open(int row, int col) {
    return grid[row][col];
}

// helper function to open a given cell
void open_site(int row, int col) {
    int idx = index(row, col);
    grid[row][col] = 1;
    open[idx] = 1;
    sz[idx] = 1;
}

// helper function to get the root of a given site in the weighted quick-union
int root(int site) {
    while (site != open[site]) {
        open[site] = open[open[site]]; // path compression
        site = open[site];
    }
    return site;
}

// helper function to connect two sites in the weighted quick-union
void connect(int p, int q) {
    int root_p = root(p);
    int root_q = root(q);
    if (root_p == root_q) return;
    if (sz[root_p] < sz[root_q]) {
        open[root_p] = root_q;
        sz[root_q] += sz[root_p];
    } else {
        open[root_q] = root_p;
        sz[root_p] += sz[root_q];
    }
}

// helper function to check if two cells are connected in the weighted quick-union
int is_connected(int p, int q) {
    return root(p) == root(q);
}

// helper function to print the grid to the console
void print_grid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j]) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

// main function
int main() {
    // initialize random number generator
    srand(time(NULL));

    // initialize grid to all closed cells
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = 0;
        }
    }

    // open top and bottom rows
    for (int j = 0; j < COLS; j++) {
        open_site(0, j);
        open_site(ROWS - 1, j);
    }

    // percolation loop
    while (!is_connected(0, (ROWS - 1) * COLS)) {
        // pick a random site
        int row = rand() % ROWS;
        int col = rand() % COLS;
        // check if site is already open
        if (!is_open(row, col)) {
            // open the site
            open_site(row, col);
            // connect to neighboring open sites
            if (is_valid(row - 1, col) && is_open(row - 1, col)) {
                connect(index(row, col), index(row - 1, col));
            }
            if (is_valid(row + 1, col) && is_open(row + 1, col)) {
                connect(index(row, col), index(row + 1, col));
            }
            if (is_valid(row, col - 1) && is_open(row, col - 1)) {
                connect(index(row, col), index(row, col - 1));
            }
            if (is_valid(row, col + 1) && is_open(row, col + 1)) {
                connect(index(row, col), index(row, col + 1));
            }
        }
    }

    // print the final grid
    print_grid();

    return 0;
}