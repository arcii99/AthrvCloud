//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // the size of the grid

int grid[SIZE][SIZE]; // the grid

/**
 * A recursive function to percolate through the grid
 */
void percolate(int row, int col) {
    if (row < 0 || col < 0 || row >= SIZE || col >= SIZE || grid[row][col] == 0) {
        return;
    }
    
    // mark the current cell as empty
    grid[row][col] = 0;
    
    // percolate to the four adjacent cells
    percolate(row - 1, col);
    percolate(row + 1, col);
    percolate(row, col - 1);
    percolate(row, col + 1);
}

int main() {
    srand(time(NULL)); // seed the random number generator
    
    // initialize the grid with some random values
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (rand() % 2 == 0) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
    
    // print the initial grid
    printf("Initial grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    
    // percolate through the first row
    for (int j = 0; j < SIZE; j++) {
        if (grid[0][j] == 1) {
            percolate(0, j);
        }
    }
    
    // print the final grid
    printf("Final grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}