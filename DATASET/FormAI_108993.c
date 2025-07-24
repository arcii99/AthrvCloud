//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define MAX 500

void initialize(int grid[N][N], int *open_count, int *percolates) {
    int i, j;
    *open_count = 0;
    *percolates = 0;
    srand(time(NULL)); // seed the random number generator
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            grid[i][j] = 0; // all cells start as blocked
        }
    }
}

void print_grid(int grid[N][N]) {
    int i, j;
    printf("\nGrid:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (grid[i][j] == 0) {
                printf("."); // blocked cell
            }
            else if (grid[i][j] == 1) {
                printf("o"); // open cell
            }
            else if (grid[i][j] == 2) {
                printf("#"); // cell connected to top and bottom
            }
        }
        printf("\n");
    }
    printf("\n");
}

void open_cell(int grid[N][N], int *open_count, int *percolates) {
    int i, j, row, col, empty_found = 0;
    // look for a randomly selected blocked cell to open
    while (!empty_found) {
        row = rand() % N;
        col = rand() % N;
        if (grid[row][col] == 0) {
            empty_found = 1; // found a blocked cell to open
        }
    }
    grid[row][col] = 1; // open the selected cell
    (*open_count)++;
    // check if top or bottom row has been reached
    if (row == 0 || row == N-1) {
        grid[row][col] = 2; // mark as connected to top or bottom
        *percolates = 1; // system percolates
    }
    // check neighbors to see if they are also open
    if (row > 0 && grid[row-1][col] == 1) {
        grid[row][col] = 2; // mark as connected to top or bottom
        *percolates = 1; // system percolates
    }
    if (row < N-1 && grid[row+1][col] == 1) {
        grid[row][col] = 2; // mark as connected to top or bottom
        *percolates = 1; // system percolates
    }
    if (col > 0 && grid[row][col-1] == 1) {
        grid[row][col] = 2; // mark as connected to top or bottom
        *percolates = 1; // system percolates
    }
    if (col < N-1 && grid[row][col+1] == 1) {
        grid[row][col] = 2; // mark as connected to top or bottom
        *percolates = 1; // system percolates
    }
}

int main() {
    int grid[N][N];
    int open_count = 0;
    int percolates = 0;
    int i;
    printf("Percolation Simulator\n\n");
    initialize(grid, &open_count, &percolates);
    for (i = 0; i < MAX && !percolates; i++) {
        open_cell(grid, &open_count, &percolates);
        printf("Iteration %d\n", i+1);
        print_grid(grid);
    }
    if (percolates) {
        printf("The system percolates after %d iterations.\n", i);
    }
    else {
        printf("The system does not percolate after %d iterations.\n", i);
    }
    return 0;
}