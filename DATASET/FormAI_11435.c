//FormAI DATASET v1.0 Category: Game of Life ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

int grid[ROWS][COLS];

// Fill the grid with random alive cells
void initGrid() {
    srand(time(NULL));
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            grid[row][col] = rand() < RAND_MAX / 2 ? 1 : 0;
        }
    }
}

// Print the grid
void printGrid() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("%c", grid[row][col] ? '#' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

// Count the number of alive neighbors for a given cell
int countNeighbors(int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int r = row + i;
            int c = col + j;
            if (r >= 0 && r < ROWS && c >= 0 && c < COLS && !(i == 0 && j == 0)) {
                count += grid[r][c];
            }
        }
    }
    return count;
}

// Update the grid based on the rules of the Game of Life
void updateGrid() {
    int newGrid[ROWS][COLS];
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            int neighbors = countNeighbors(row, col);
            if (grid[row][col]) {
                if (neighbors < 2 || neighbors > 3) {
                    newGrid[row][col] = 0; // Die of loneliness or overpopulation
                } else {
                    newGrid[row][col] = 1; // Happy and alive
                }
            } else {
                if (neighbors == 3) {
                    newGrid[row][col] = 1; // Born from the dead
                } else {
                    newGrid[row][col] = 0; // Still dead
                }
            }
        }
    }
    // Copy the new grid into the old grid
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            grid[row][col] = newGrid[row][col];
        }
    }
}

int main() {
    initGrid();
    for (int i = 0; i < 100; i++) {
        printf("Generation %d:\n", i);
        printGrid();
        updateGrid();
    }
    return 0;
}