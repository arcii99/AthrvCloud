//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define MAX_SITES (N*N)

int grid[N][N];
int sz[MAX_SITES];
int parent[MAX_SITES];
int openSites = 0;

// Initialize grid and site arrays
void initGrid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = 0;
            int index = (i * N) + j;
            sz[index] = 1;
            parent[index] = index;
        }
    }
}

// Find the root of the given site
int find(int p) {
    while (p != parent[p]) {
        parent[p] = parent[parent[p]];
        p = parent[p];
    }
    return p;
}

// Union the given sites
void unionSites(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);
    if (rootP == rootQ) return;
    if (sz[rootP] > sz[rootQ]) {
        parent[rootQ] = rootP;
        sz[rootP] += sz[rootQ];
    } else {
        parent[rootP] = rootQ;
        sz[rootQ] += sz[rootP];
    }
}

// Open the given site
void openSite(int row, int col) {
    if (row < 0 || row > N-1 || col < 0 || col > N-1) return;
    if (grid[row][col] == 1) return;
    grid[row][col] = 1;
    int index = (row * N) + col;
    openSites++;
    if (row == 0) {
        unionSites(index, MAX_SITES-2);
    }
    if (row == N-1) {
        unionSites(index, MAX_SITES-1);
    }
    if (row > 0 && grid[row-1][col] == 1) {
        unionSites(index, index-N);
    }
    if (row < N-1 && grid[row+1][col] == 1) {
        unionSites(index, index+N);
    }
    if (col > 0 && grid[row][col-1] == 1) {
        unionSites(index, index-1);
    }
    if (col < N-1 && grid[row][col+1] == 1) {
        unionSites(index, index+1);
    }
}

// Check if the system percolates
int percolates() {
    return find(MAX_SITES-2) == find(MAX_SITES-1);
}

// Run the simulator
void runSimulator() {
    while (!percolates()) {
        int row = rand() % N;
        int col = rand() % N;
        openSite(row, col);
    }
}

// Print the percolation status of each site
void printGrid() {
    printf("Status of each site:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    initGrid();
    runSimulator();
    printGrid();
    printf("Total number of open sites: %d\n", openSites);
    return 0;
}