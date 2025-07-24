//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20 // size of the grid
#define OPEN 1 // flag for open site
#define FULL 2 // flag for full site

int grid[N][N]; // 2D array to store the grid
int openCount = 0; // count of open sites

// function to randomly open a site
void openSite() {
    int i = rand() % N;
    int j = rand() % N;
    if (grid[i][j] == 0) {
        grid[i][j] = OPEN;
        openCount++;
    }
}

// function to check if neighbors are open
int isNeighborOpen(int i, int j) {
    // check left neighbor
    if (j > 0 && grid[i][j - 1] == FULL) {
        return 1;
    }
    // check right neighbor
    if (j < N - 1 && grid[i][j + 1] == FULL) {
        return 1;
    }
    // check top neighbor
    if (i > 0 && grid[i - 1][j] == FULL) {
        return 1;
    }
    // check bottom neighbor
    if (i < N - 1 && grid[i + 1][j] == FULL) {
        return 1;
    }
    return 0;
}

// function to fill neighboring open sites
void fillNeighboring() {
    int filled = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (filled == 0 && grid[i][j] == OPEN && isNeighborOpen(i, j)) {
                grid[i][j] = FULL;
                filled = 1;
            }
        }
    }
}

// function to print the grid
void printGrid() {
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == FULL) {
                printf("# ");
            } else if (grid[i][j] == OPEN) {
                printf(". ");
            } else {
                printf("? ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // seed the random number generator
    // initialize the grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = 0;
        }
    }
    // open some sites randomly
    while ((float)openCount / (N * N) < 0.5) {
        openSite();
    }
    // fill neighboring open sites
    int filled = 1;
    while (filled) {
        filled = 0;
        fillNeighboring();
        if (openCount == N * N) {
            filled = 0;
        }
        printGrid();
    }
    return 0;
}