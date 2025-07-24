//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10

// Array to store status of each cell in the grid
bool grid[N][N];

// Initialize grid with randomly open or closed sites
void initializeGrid() {
    srand(time(0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Check if cell at (i, j) is open or closed
bool isOpen(int i, int j) {
    return grid[i][j];
}

// Check if cell at (i, j) is connected to top row
bool isFull(int i, int j) {
    if (i == 0) {
        return true;
    } else if (!isOpen(i, j)) {
        return false;
    } else {
        return isFull(i-1, j) || (j != 0 && isFull(i, j-1)) || (j != N-1 && isFull(i, j+1));
    }
}

// Check if grid system percolates
bool percolates() {
    for (int j = 0; j < N; j++) {
        if (isFull(N-1, j)) {
            return true;
        }
    }
    return false;
}

// Prints the grid system
void printGrid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j]) {
                printf("O ");
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    initializeGrid();
    printGrid();

    if (percolates()) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    return 0;
}