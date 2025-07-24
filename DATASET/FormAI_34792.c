//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20
#define OPEN 'O'
#define BLOCKED 'X'
#define FULL 'F'

// Initialize the grid to blocked
void initialize(char grid[][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = BLOCKED;
        }
    }
}

// Print the current state of the grid
void print(char grid[][GRID_SIZE]) {
    printf("\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// Open a random site on the grid
void open(char grid[][GRID_SIZE]) {
    int x = rand() % GRID_SIZE;
    int y = rand() % GRID_SIZE;
    grid[x][y] = OPEN;
}

// Check if this site is valid and open
int is_valid_and_open(char grid[][GRID_SIZE], int x, int y) {
    if (x < 0 || y < 0 || x >= GRID_SIZE || y >= GRID_SIZE) {
        return 0;
    }

    if (grid[x][y] != OPEN) {
        return 0;
    }

    return 1;
}

// Check if the system is percolating
int percolates(char grid[][GRID_SIZE]) {
    char temp_grid[GRID_SIZE][GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            temp_grid[i][j] = grid[i][j];
        }
    }

    // Fill up the top row with FULL
    for (int j = 0; j < GRID_SIZE; j++) {
        if (temp_grid[0][j] == OPEN) {
            temp_grid[0][j] = FULL;
        }
    }

    // Propagate FULL downward
    for (int i = 0; i < GRID_SIZE - 1; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (temp_grid[i + 1][j] == FULL) {
                if (is_valid_and_open(temp_grid, i, j - 1)) {
                    temp_grid[i][j - 1] = FULL;
                }
                if (is_valid_and_open(temp_grid, i, j + 1)) {
                    temp_grid[i][j + 1] = FULL;
                }
                if (is_valid_and_open(temp_grid, i - 1, j)) {
                    temp_grid[i - 1][j] = FULL;
                }
            }
        }
    }

    // Check if the bottom row has any FULL sites
    for (int j = 0; j < GRID_SIZE; j++) {
        if (temp_grid[GRID_SIZE - 1][j] == FULL) {
            return 1;
        }
    }

    return 0;
}

int main() {
    srand(time(NULL));
    char grid[GRID_SIZE][GRID_SIZE];
    int count = 0;
    initialize(grid);
    while (!percolates(grid)) {
        open(grid);
        count++;
        printf("\n\nStep %d:\n", count);
        print(grid);
    }
    printf("\n\nSystem percolates after %d open sites.\n", count);
    return 0;
}