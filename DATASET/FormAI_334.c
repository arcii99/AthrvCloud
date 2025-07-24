//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROWS 20
#define COLS 20
#define PERCOLATION_THRESHOLD 0.6

int grid[ROWS][COLS];
int size[ROWS][COLS];
int num_components = 0;


int root(int i, int j) {
    while (i != size[i][j]) {
        size[i][j] = size[size[i][j]][size[i][j]];
        i = size[i][j];
    }
    return i;
}

void unify(int p, int q) {
    int root_p = root(p / COLS, p % COLS);
    int root_q = root(q / COLS, q % COLS);
    if (root_p == root_q) return;
    size[root_p / COLS][root_p % COLS] = root_q;
    num_components--;
}

void percolate(int n) {
    srand(time(NULL));
    for (int i = 0; i < n * n; i++) {
        int x1 = rand() % n, y1 = rand() % n;
        if (grid[x1][y1] == 0) {
            grid[x1][y1] = 1;
            if (x1 > 0 && grid[x1 - 1][y1]) {
                unify(x1 * n + y1, (x1 - 1) * n + y1);
            }
            if (y1 > 0 && grid[x1][y1 - 1]) {
                unify(x1 * n + y1, x1 * n + y1 - 1);
            }
            if (x1 < n - 1 && grid[x1 + 1][y1]) {
                unify(x1 * n + y1, (x1 + 1) * n + y1);
            }
            if (y1 < n - 1 && grid[x1][y1 + 1]) {
                unify(x1 * n + y1, x1 * n + y1 + 1);
            }
            if (num_components == 1 || (double) num_components / (n * n) <= PERCOLATION_THRESHOLD) {
                printf("Percolates at %d th open site(%d, %d).\n", i + 1, x1, y1);
                break;
            }
        }
    }
}

int main() {
    num_components = ROWS * COLS;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = 0;
            size[i][j] = i * COLS + j;
        }
    }

    percolate(ROWS);

    return 0;
}