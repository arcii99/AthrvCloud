//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // grid size
#define p 0.6 // probability of site being open
#define CLOSED 0 // status of closed site
#define OPEN 1 // status of open site
#define FULL 2 // status of full site

// Function to initialize grid with closed sites
void initialize(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = CLOSED;
        }
    }
}

// Function to randomly open sites based on probability p
void randomlyOpen(int grid[N][N]) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((double) rand() / (double) RAND_MAX < p) {
                grid[i][j] = OPEN;
            }
        }
    }
}

// Function to check if a site is connected to the top
int isConnectedToTop(int grid[N][N], int row, int col) {
    if (row == 0) return 1; // top row is always connected
    if (grid[row - 1][col] == FULL) return 1; // connected to full site above
    if (grid[row - 1][col] == OPEN) {
        grid[row - 1][col] = FULL;
        return isConnectedToTop(grid, row - 1, col); // recursively check if site above is connected
    }
    return 0; // not connected
}

// Function to percolate open sites from top to bottom
int percolate(int grid[N][N]) {
    for (int j = 0; j < N; j++) {
        if (grid[0][j] == OPEN) {
            grid[0][j] = FULL;
            isConnectedToTop(grid, 0, j); // recursively check for connected sites
        }
    }
    for (int j = 0; j < N; j++) {
        if (grid[N - 1][j] == FULL) {
            return 1; // percolation is successful
        }
    }
    return 0; // percolation is unsuccessful
}

// Function to print the grid
void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == CLOSED) {
                printf("%c ", 254); // print closed site as block character
            } else if (grid[i][j] == OPEN) {
                printf(". ");
            } else if (grid[i][j] == FULL) {
                printf("X ");
            }
        }
        printf("\n");
    }
}

int main() {
    int grid[N][N];
    initialize(grid);
    randomlyOpen(grid);
    printGrid(grid);
    if (percolate(grid)) {
        printf("\nPercolation successful!\n");
    } else {
        printf("\nPercolation unsuccessful!\n");
    }
    return 0;
}