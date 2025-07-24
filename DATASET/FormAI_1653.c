//FormAI DATASET v1.0 Category: Game of Life ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 60

void displayGrid(int grid[ROWS][COLS]) {
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int countNeighbors(int grid[ROWS][COLS], int row, int col) {
    int count = 0;
    for (int i=-1; i<=1; i++) {
        for (int j=-1; j<=1; j++) {
            int neighbor_row = row+i;
            int neighbor_col = col+j;
            if ((neighbor_row >= 0) && (neighbor_row < ROWS) && (neighbor_col >= 0) && (neighbor_col < COLS)) {
                count += grid[neighbor_row][neighbor_col];
            }
        }
    }
    count -= grid[row][col];
    return count;
}

void generateNext(int grid[ROWS][COLS]) {
    int next[ROWS][COLS];
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            int neighbors = countNeighbors(grid, i, j);
            if (grid[i][j] == 1) {
                if (neighbors < 2) {
                    next[i][j] = 0;
                } else if (neighbors > 3) {
                    next[i][j] = 0;
                } else {
                    next[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    next[i][j] = 1;
                } else {
                    next[i][j] = 0;
                }
            }
        }
    }
    // Copy the next state back to the original grid
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            grid[i][j] = next[i][j];
        }
    }
}

int main(void) {
    // Initialize grid with random values
    int grid[ROWS][COLS];
    srand(time(NULL));
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    
    // Simulate game of life
    for (int i=0; i<100; i++) {
        system("clear"); // Clear the console (works only on Unix-like systems)
        displayGrid(grid);
        generateNext(grid);
        printf("Generation: %d\n", i+1);
        usleep(200000); // Wait for 200 milliseconds
    }
    
    return 0;
}