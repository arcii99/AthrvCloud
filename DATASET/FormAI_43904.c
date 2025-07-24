//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10 // Size of grid
#define P 0.5 // Probability of site being open

int grid[N][N];
int size[N][N];
bool visited[N][N];

void initializeGrid() {
    // Initialize grid and size arrays
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            grid[i][j] = rand() < P * RAND_MAX;
            size[i][j] = 1;
            visited[i][j] = false;
        }
    }
}

int findRoot(int i, int j) {
    // Find the root node of site at (i, j)
    while (grid[i][j] != i*N+j) {
        int temp = grid[i][j];
        grid[i][j] = grid[temp/N][temp%N];
        i = temp/N;
        j = temp%N;
    }
    return i*N+j;
}

void connect(int i, int j, int m, int n) {
    // Connect site at (i, j) to site at (m, n)
    int p = findRoot(i, j);
    int q = findRoot(m, n);
    if (p == q)
        return;
    if (size[p/N][p%N] < size[q/N][q%N]) {
        grid[p/N][p%N] = q;
        size[q/N][q%N] += size[p/N][p%N];
    } else {
        grid[q/N][q%N] = p;
        size[p/N][p%N] += size[q/N][q%N];
    }
}

void percolate() {
    // Connect all open adjacent sites
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (grid[i][j] == 1) {
                if (i < N-1 && grid[i+1][j] == 1)
                    connect(i, j, i+1, j);
                if (j < N-1 && grid[i][j+1] == 1)
                    connect(i, j, i, j+1);
                if (i > 0 && grid[i-1][j] == 1)
                    connect(i, j, i-1, j);
                if (j > 0 && grid[i][j-1] == 1)
                    connect(i, j, i, j-1);
            }
        }
    }
}

bool percolates() {
    // Check if top and bottom are connected
    for (int j=0; j<N; j++) {
        if (grid[0][j] == 1 && grid[N-1][j] == 1) {
            int p = findRoot(0, j);
            int q = findRoot(N-1, j);
            if (p == q)
                return true;
        }
    }
    return false;
}

void printGrid() {
    // Print the grid and size arrays
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("%d", grid[i][j]);
        }
        printf("\t");
        for (int j=0; j<N; j++) {
            printf("%d", size[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    initializeGrid();
    percolate();
    printGrid();
    if (percolates())
        printf("System percolates!\n");
    else
        printf("System does not percolate.\n");
    return 0;
}