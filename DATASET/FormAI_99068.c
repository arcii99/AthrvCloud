//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Ken Thompson
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int grid[ROWS][COLS];
int size = ROWS * COLS;

// Union-Find data structure for percolation simulation
int find(int* parent, int p) {
    while (p != parent[p]) {
        parent[p] = parent[parent[p]];
        p = parent[p];
    }
    return p;
}

void union_sets(int* parent, int* size, int p, int q) {
    int root_p = find(parent, p);
    int root_q = find(parent, q);
    if (root_p == root_q) return;
    if (size[root_p] < size[root_q]) {
        parent[root_p] = root_q;
        size[root_q] += size[root_p];
    } else {
        parent[root_q] = root_p;
        size[root_p] += size[root_q];
    }
}

bool percolates(int* parent) {
    return find(parent, 0) == find(parent, size-1);
}

// Randomly open cells in the grid and check for percolation
void run_percolation() {
    int open_count = 0;
    int parent[size];
    int size[size];
    for (int i = 0; i < size; i++) {
        parent[i] = i;
        size[i] = 1;
    }

    // Keep opening cells until the system percolates
    while (!percolates(parent)) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (grid[row][col] == 0) {
            grid[row][col] = 1;
            open_count++;
            int p = row * COLS + col;
            if (row > 0 && grid[row-1][col] == 1) {
                int q = (row-1) * COLS + col;
                union_sets(parent, size, p, q);
            }
            if (row < ROWS-1 && grid[row+1][col] == 1) {
                int q = (row+1) * COLS + col;
                union_sets(parent, size, p, q);
            }
            if (col > 0 && grid[row][col-1] == 1) {
                int q = row * COLS + (col-1);
                union_sets(parent, size, p, q);
            }
            if (col < COLS-1 && grid[row][col+1] == 1) {
                int q = row * COLS + (col+1);
                union_sets(parent, size, p, q);
            }
        }
    }

    // Print final state of the grid
    printf("Final Grid:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    printf("Number of cells opened: %d\n", open_count);
}

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Initialize grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = 0;
        }
    }

    run_percolation();

    return 0;
}