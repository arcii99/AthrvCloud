//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// size of the grid
#define GRID_SIZE 10

// probability of a site being open
#define PROBABILITY 0.6

// structure to represent a site in the grid
typedef struct Site {
    bool isOpen;
    bool isFull;
} Site;

// main grid
Site grid[GRID_SIZE][GRID_SIZE];

// function to initialize the grid
void initializeGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            float r = (float) rand() / RAND_MAX;
            if (r < PROBABILITY) {
                grid[i][j].isOpen = true;
            } else {
                grid[i][j].isOpen = false;
            }
            grid[i][j].isFull = false;
        }
    }
}

// function to check if the site is valid and open
bool isValidAndOpen(int x, int y) {
    if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE) {
        return false;
    }
    if (!grid[x][y].isOpen) {
        return false;
    }
    return true;
}

// function to check if a site is full
bool isFull(int x, int y) {
    if (!isValidAndOpen(x, y)) {
        return false;
    }
    if (grid[x][y].isFull) {
        return true;
    }
    // mark the site as full
    grid[x][y].isFull = true;
    // check if any of the neighboring sites are full
    bool isFullSite = isFull(x - 1, y) || isFull(x + 1, y) || isFull(x, y - 1) || isFull(x, y + 1);
    if (isFullSite) {
        return true;
    }
    return false;
}

// function to run percolation simulation
bool percolates() {
    // check if the top row sites are full
    for (int j = 0; j < GRID_SIZE; j++) {
        if (isFull(0, j)) {
            return true;
        }
    }
    return false;
}

// function to print the grid
void printGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j].isOpen && !grid[i][j].isFull) {
                printf("0 ");
            } else {
                printf("1 ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));  // seed the random number generator
    initializeGrid();
    printf("Initial Grid:\n");
    printGrid();
    printf("\n");
    if (percolates()) {
        printf("Percolates!\n");
    } else {
        printf("Does not percolate!\n");
    }
    return 0;
}