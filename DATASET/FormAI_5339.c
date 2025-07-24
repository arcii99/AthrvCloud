//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10            // Size of the grid
#define EMPTY 0         // Empty site
#define BLOCKED 1       // Blocked site
#define OPEN 2          // Open site
#define PERCOLATES 3    // The system percolates
#define DEBUG 0         // Debugging flag

// Grid of sites
int grid[N][N];

// Prints the grid to the console
void printGrid() {
    printf("Grid:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            switch (grid[i][j]) {
                case EMPTY:
                    printf(". ");
                    break;
                case BLOCKED:
                    printf("# ");
                    break;
                case OPEN:
                    printf("O ");
                    break;
            }
        }
        printf("\n");
    }
}

// Initializes the grid with blocked sites
void initGrid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = BLOCKED;
        }
    }
}

// Fills the grid with open sites at random
void fillGrid(double p) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double random = (double) rand() / RAND_MAX;
            if (random < p) {
                grid[i][j] = OPEN;
            }
        }
    }
}

// Checks if the system percolates
int doesPercolate() {
    // Check if there is a path from the top row to the bottom row
    for (int i = 0; i < N; i++) {
        if (grid[0][i] == OPEN) {
            if (DEBUG) printf("Opening: 0, %d\n", i);
            int visited[N][N];
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    visited[j][k] = 0;
                }
            }
            if (visit(i, 0, visited)) {
                return PERCOLATES;
            }
        }
    }
    return BLOCKED;
}

// Visits an open site and recursively visits its neighbors
int visit(int x, int y, int visited[N][N]) {
    if (grid[x][y] == BLOCKED) {
        return 0;
    }
    visited[x][y] = 1;
    if (DEBUG) printf("Visiting: %d, %d\n", x, y);
    if (y == N-1) {
        return 1;
    }
    if (x > 0 && !visited[x-1][y]) {
        if (visit(x-1, y, visited)) {
            return 1;
        }
    }
    if (x < N-1 && !visited[x+1][y]) {
        if (visit(x+1, y, visited)) {
            return 1;
        }
    }
    if (y > 0 && !visited[x][y-1]) {
        if (visit(x, y-1, visited)) {
            return 1;
        }
    }
    if (y < N-1 && !visited[x][y+1]) {
        if (visit(x, y+1, visited)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    double p = 0.5; // Probability of a site being open
    initGrid();
    fillGrid(p);
    printGrid();
    if (doesPercolate()) {
        printf("The system percolates.\n");
    } else {
        printf("The system does not percolate.\n");
    }
    return 0;
}