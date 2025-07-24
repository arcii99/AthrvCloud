//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define OPEN 1
#define FULL 2
#define BLOCKED 0
#define PERCOLATION_THRESHOLD 0.7

int grid[N + 2][N + 2] = {BLOCKED};
int num_open_sites = 0;

void print_grid();

void open(int i, int j);

void main() {
    srand(time(0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if ((double) rand() / RAND_MAX < PERCOLATION_THRESHOLD) {
                grid[i][j] = OPEN;
                num_open_sites++;
            }
        }
    }
    print_grid();
    printf("Percolates? %s\n", percolates() ? "YES" : "NO");
}

int percolates() {
    for (int j = 1; j <= N; j++) {
        if (grid[1][j] == FULL) {
            return 1;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (grid[i][j] == FULL) {
                if (grid[i - 1][j] == OPEN) {
                    open(i - 1, j);
                }
                if (grid[i + 1][j] == OPEN) {
                    open(i + 1, j);
                }
                if (grid[i][j - 1] == OPEN) {
                    open(i, j - 1);
                }
                if (grid[i][j + 1] == OPEN) {
                    open(i, j + 1);
                }
            }
        }
    }
    for (int j = 1; j <= N; j++) {
        if (grid[N][j] == FULL) {
            return 1;
        }
    }
    return 0;
}

void open(int i, int j) {
    if (grid[i][j] != OPEN) {
        return;
    }
    grid[i][j] = FULL;
    num_open_sites++;
    if (grid[i - 1][j] == OPEN) {
        open(i - 1, j);
    }
    if (grid[i + 1][j] == OPEN) {
        open(i + 1, j);
    }
    if (grid[i][j - 1] == OPEN) {
        open(i, j - 1);
    }
    if (grid[i][j + 1] == OPEN) {
        open(i, j + 1);
          }
}

void print_grid() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (grid[i][j] == BLOCKED) {
                printf("X ");
            } else if (grid[i][j] == OPEN) {
                printf("O ");
            } else if (grid[i][j] == FULL) {
                printf("# ");
            }
        }
        printf("\n");
    }
    printf("%d / %d (%.2f%%) open\n", num_open_sites, N * N, (double) num_open_sites / (N * N) * 100);
}