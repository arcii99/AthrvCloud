//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Size of the grid

typedef struct {
    int row;
    int col;
} Site;

typedef struct {
    int size;
    int* id;
} UnionFind;

void initializeGrid(int grid[][N], int p) {
    srand(time(NULL)); // Initialize random seed
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int randNumber = rand() % 100;
            if (randNumber < p) {
                grid[i][j] = 1; // Site is open
            } else {
                grid[i][j] = 0; // Site is closed
            }
        }
    }
}

void printGrid(int grid[][N]) {
    printf("Grid:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int getSiteIndex(int row, int col) {
    return row * N + col;
}

Site getSite(int index) {
    Site site;
    site.row = index / N;
    site.col = index % N;
    return site;
}

int isConnected(UnionFind uf, int p, int q) {
    return uf.id[p] == uf.id[q];
}

void unionSites(UnionFind* uf, int p, int q) {
    if (isConnected(*uf, p, q)) {
        return;
    }

    int pid = uf->id[p];
    int qid = uf->id[q];

    for (int i = 0; i < uf->size; i++) {
        if (uf->id[i] == pid) {
            uf->id[i] = qid;
        }
    }
}

int percolates(int grid[][N]) {
    // Initialize UnionFind structure
    UnionFind uf;
    uf.size = N * N + 2;
    uf.id = (int*) malloc(uf.size * sizeof(int));
    for (int i = 0; i < uf.size; i++) {
        uf.id[i] = i;
    }

    // Connect top virtual site to top row
    for (int j = 0; j < N; j++) {
        if (grid[0][j]) {
            unionSites(&uf, 0, getSiteIndex(0, j) + 1);
        }
    }

    // Connect bottom virtual site to bottom row
    for (int j = 0; j < N; j++) {
        if (grid[N - 1][j]) {
            unionSites(&uf, N * N + 1, getSiteIndex(N - 1, j) + 1);
        }
    }

    // Connect open sites to adjacent open sites
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j]) {
                if (i > 0 && grid[i - 1][j]) {
                    unionSites(&uf, getSiteIndex(i, j) + 1, getSiteIndex(i - 1, j) + 1);
                }
                if (i < N - 1 && grid[i + 1][j]) {
                    unionSites(&uf, getSiteIndex(i, j) + 1, getSiteIndex(i + 1, j) + 1);
                }
                if (j > 0 && grid[i][j - 1]) {
                    unionSites(&uf, getSiteIndex(i, j) + 1, getSiteIndex(i, j - 1) + 1);
                }
                if (j < N - 1 && grid[i][j + 1]) {
                    unionSites(&uf, getSiteIndex(i, j) + 1, getSiteIndex(i, j + 1) + 1);
                }
            }
        }
    }

    // Check if top virtual site is connected to bottom virtual site
    int isPercolating = isConnected(uf, 0, N * N + 1);

    // Free memory
    free(uf.id);

    return isPercolating;
}

int main() {
    int grid[N][N];
    int p = 30; // Probability that a site is open (in percentage)
    initializeGrid(grid, p);
    printGrid(grid);
    int isPercolating = percolates(grid);
    printf("Percolation: %d\n", isPercolating);
    return 0;
}