//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Grid size
#define P 0.6 // Percolation probability

void initialize_grid(int grid[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if ((double) rand() / (double) RAND_MAX < P) {
                grid[i][j] = 1; // Site is open
            } else {
                grid[i][j] = 0; // Site is blocked
            }
        }
    }
}

int is_percolated(int grid[N][N]) {
    int i, j;
    int top_row[N] = {0}; // Array for top row
    int bottom_row[N] = {0}; // Array for bottom row

    // Check if there is a path of open sites from top to bottom
    for (i = 0; i < N; i++) {
        if (grid[0][i] == 1) {
            top_row[i] = 1;
        }
        if (grid[N-1][i] == 1) {
            bottom_row[i] = 1;
        }
    }

    for (i = 0; i < N; i++) {
        if (top_row[i] == 1 && bottom_row[i] == 1) {
            return 1; // Percolates
        }
    }

    return 0; // Does not percolate
}

void print_grid(int grid[N][N]) {
    int i, j;
    printf("-----------------------\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("-----------------------\n");
}

int main() {
    int grid[N][N];
    srand(time(NULL)); // Seed random number generator
    initialize_grid(grid);
    print_grid(grid);

    if (is_percolated(grid)) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate.\n");
    }

    return 0;
}