//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int grid[ROWS][COLS];
int filled[ROWS][COLS] = {0};

void printGrid() {
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (grid[i][j] == 1) {
                printf("X ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void fill(int row, int col) {
    if (filled[row][col] == 1) {
        return;
    }
  
    filled[row][col] = 1;

    if (row-1 >= 0 && grid[row-1][col] == 1) {
        fill(row-1, col);
    }

    if (row+1 < ROWS && grid[row+1][col] == 1) {
        fill(row+1, col);
    }

    if (col-1 >= 0 && grid[row][col-1] == 1) {
        fill(row, col-1);
    }

    if (col+1 < COLS && grid[row][col+1] == 1) {
        fill(row, col+1);
    }
}

int main() {
    srand(time(NULL));
  
    // initialize grid with random values
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (rand() % 2 == 0) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }

    printf("Initial grid:\n");
    printGrid();
  
    // fill top row with water
    for (int i=0; i<COLS; i++) {
        if (grid[0][i] == 0) {
            grid[0][i] = 1;
        }
    }
  
    // simulate water spreading
    for (int i=0; i<COLS; i++) {
        if (grid[0][i] == 1 && filled[0][i] == 0) {
            fill(0, i);
        }
    }

    printf("\nFinal grid:\n");
    printGrid();
  
    return 0;
}