//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: complete
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Size of the grid

int grid[N*N];
bool open[N*N]; // Keeps track of which sites are open
int num_open = 0; // Number of open sites
int top, bottom; // Virtual sites

// Given the row and column, return the corresponding index of the site
int site_index(int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= N) {
        return -1;
    }
    return row * N + col;
}

// Initialise the grid to be blocked
void initialize_grid() {
    for (int i = 0; i < N*N; i++) {
        grid[i] = 0;
        open[i] = false;
    }
    // Create virtual sites
    top = N * N;
    bottom = N * N + 1;
}

// Open a site at the given row and column
void open_site(int row, int col) {
    int index = site_index(row, col);
    if (grid[index] == 0) { // Only open if it is blocked
        grid[index] = 1;
        open[index] = true;
        num_open++;
    }
}

// Connect the site at (row1, col1) to the site at (row2, col2)
void connect_sites(int row1, int col1, int row2, int col2) {
    int index1 = site_index(row1, col1);
    int index2 = site_index(row2, col2);

    // Connect using the union-find algorithm
    int p = index1; // Parent of the first site
    while (p != grid[p]) {
        p = grid[p];
    }
    int q = index2; // Parent of the second site
    while (q != grid[q]) {
        q = grid[q];
    }

    if (p != q) { // Only connect if they belong to different components
        grid[p] = q;
    }
}

// Check if the sites at (row1, col1) and (row2, col2) are connected
bool is_connected(int row1, int col1, int row2, int col2) {
    int index1 = site_index(row1, col1);
    int index2 = site_index(row2, col2);
    // Connected if they have the same parent using the union-find algorithm
    int p = index1;
    while (p != grid[p]) {
        p = grid[p];
    }
    int q = index2;
    while (q != grid[q]) {
        q = grid[q];
    }
    return p == q;
}

// Check if the system percolates
bool does_percolate() {
    for (int col = 0; col < N; col++) {
        if (is_connected(0, col, N-1, col)) {
            return true;
        }
    }
    return false;
}

// Print the grid
void print_grid() {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (open[site_index(row, col)]) {
                printf(" %c ", is_connected(row, col, 0, 0) ? '*' : '-');
            } else {
                printf(" X ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    initialize_grid();

    // Open random sites until the grid percolates
    while (!does_percolate()) {
        int row = rand() % N;
        int col = rand() % N;
        open_site(row, col);

        // Connect the site to its neighbours
        if (row > 0 && open[site_index(row-1, col)]) {
            connect_sites(row, col, row-1, col);
        }
        if (col > 0 && open[site_index(row, col-1)]) {
            connect_sites(row, col, row, col-1);
        }
        if (row < N-1 && open[site_index(row+1, col)]) {
            connect_sites(row, col, row+1, col);
        }
        if (col < N-1 && open[site_index(row, col+1)]) {
            connect_sites(row, col, row, col+1);
        }
    }

    printf("Final configuration:\n");
    print_grid();
    printf("Percolates! %d open sites\n", num_open);

    return 0;
}