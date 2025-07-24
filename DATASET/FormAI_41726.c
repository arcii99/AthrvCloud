//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

// function to create random grid
void create_random_grid(int grid[N][N], float p) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (((float) rand() / RAND_MAX) < p) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
}

// function to print the grid
void print_grid(int grid[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// function to check if the grid percolates
int percolates(int grid[N][N]) {
    int i, j;
    int top_row[N], bottom_row[N];
    for (i = 0; i < N; i++) {
        top_row[i] = 0;
        bottom_row[i] = 0;
    }
    for (j = 0; j < N; j++) {
        if (grid[0][j]) {
            top_row[j] = 1;
        }
        if (grid[N-1][j]) {
            bottom_row[j] = 1;
        }
    }
    for (i = 0; i < N; i++) {
        if (top_row[i]) {
            for (j = 0; j < N; j++) {
                if (grid[i][j] && bottom_row[j]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int grid[N][N];
    float p = 0.3;
    create_random_grid(grid, p);
    print_grid(grid);
    if (percolates(grid)) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate.\n");
    }
    return 0;
}