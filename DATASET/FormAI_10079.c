//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void printGrid(int grid[][N], int n) {
    printf(" ");
    for (int i = 0; i < n * 3; i++) printf("-");
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("| ");
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) printf("O ");
            else if (grid[i][j] == -1) printf("X ");
            else printf("- ");
        }
        printf("|\n");
    }
    printf(" ");
    for (int i = 0; i < n * 3; i++) printf("-");
    printf("\n");
}

void percolate(int grid[][N], int n, int row, int col) {
    if (row < 0 || row >= n || col < 0 || col >= n) return;
    if (grid[row][col] != 1) return;

    grid[row][col] = -1;

    percolate(grid, n, row - 1, col);
    percolate(grid, n, row + 1, col);
    percolate(grid, n, row, col - 1);
    percolate(grid, n, row, col + 1);
}

int main() {
    int grid[N][N] = {0};

    // Seed random number generator
    srand(time(NULL));

    // Initialize top row to open
    for (int i = 0; i < N; i++) {
        grid[0][i] = 1;
    }

    // Percolate the grid
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i-1][j] == 1 && rand() % 2 == 0) {
                grid[i][j] = 1;
            }
        }
    }

    // Check if bottom row percolates
    int percolates = 0;
    for (int j = 0; j < N; j++) {
        if (grid[N-1][j] == 1) {
            percolate(grid, N, N-1, j);
        }
        if (grid[N-1][j] == -1) {
            percolates = 1;
        }
    }

    // Print the grid
    printGrid(grid, N);

    // Print if grid percolates or not
    if (percolates) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate.\n");
    }

    return 0;
}