//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N 10 // size of the grid

bool percolates(int grid[N][N]) {
    int visited[N][N];
    int i, j;

    // Initialize visited array
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            visited[i][j] = 0;
        }
    }

    // Check bottom row for open cells
    for (i = 0; i < N; i++) {
        if (grid[N-1][i] == 1) {
            visited[N-1][i] = 1;
        }
    }

    // Traverse grid
    for (i = N-2; i >= 0; i--) {
        for (j = 0; j < N; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                // Mark cell as visited
                visited[i][j] = 1;

                // Check adjacent cells
                if (j > 0 && grid[i][j-1] == 1 && !visited[i][j-1]) {
                    visited[i][j-1] = 1;
                }
                if (j < N-1 && grid[i][j+1] == 1 && !visited[i][j+1]) {
                    visited[i][j+1] = 1;
                }
                if (i < N-1 && grid[i+1][j] == 1 && !visited[i+1][j]) {
                    visited[i+1][j] = 1;
                }

                // Check if percolates
                if (i == 0) {
                    for (j = 0; j < N; j++) {
                        if (grid[i][j] == 1 && visited[i][j] == 1) {
                            return true; // percolates
                        }
                    }
                }
            }
        }
    }

    return false; // does not percolate
}

int main() {
    int grid[N][N];
    int i, j;
    srand(time(NULL));

    // Initialize grid
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (((double) rand() / (RAND_MAX)) < 0.5) {
                grid[i][j] = 0; // blockage
            } else {
                grid[i][j] = 1; // open cell
            }
        }
    }

    // Print grid
    printf("Initial Grid\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Determine if percolates
    if (percolates(grid)) {
        printf("Percolates!\n");
    } else {
        printf("Does not percolate.\n");
    }

    return 0;
}