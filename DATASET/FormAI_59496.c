//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define GRID_SIZE 10

typedef struct {
    bool isOpen;
    bool isFull;
} Site;

Site grid[GRID_SIZE][GRID_SIZE];

void initializeGrid() {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            grid[i][j].isOpen = false;
            grid[i][j].isFull = false;
        }
    }
}

bool isBlocked(int row, int col) {
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE) {
        return true;
    }
    return !grid[row][col].isOpen;
}

void percolate() {
    int i, j;
    for (j = 0; j < GRID_SIZE; j++) {
        if (grid[0][j].isOpen) {
            grid[0][j].isFull = true;
        }
    }
    bool changed;
    do {
        changed = false;
        for (i = 1; i < GRID_SIZE; i++) {
            for (j = 0; j < GRID_SIZE; j++) {
                if (grid[i][j].isOpen && !grid[i][j].isFull) {
                    if (isBlocked(i - 1, j) && isBlocked(i, j - 1) && isBlocked(i, j + 1)) {
                        grid[i][j].isFull = false;
                    }
                    else {
                        grid[i][j].isFull = true;
                        changed = true;
                    }
                }
            }
        }
    } while (changed);
}

void openSite(int row, int col) {
    grid[row][col].isOpen = true;
}

int main() {
    initializeGrid();
    openSite(0, 1);
    openSite(1, 1);
    openSite(2, 1);
    openSite(3, 1);
    percolate();
    if (grid[GRID_SIZE - 1][1].isFull) {
        printf("The system percolates\n");
    }
    else {
        printf("The system does not percolate\n");
    }
    return 0;
}