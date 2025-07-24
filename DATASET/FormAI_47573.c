//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Initialize grid with random values
void initialize(int grid[][COLS]) {
    srand(time(NULL));
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Print the grid values
void print_grid(int grid[][COLS]) {
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
}

// Check if percolation occurs
int percolates(int grid[][COLS]) {
    for(int i=0;i<ROWS;i++) {
        int connected = 0;
        for(int j=0;j<COLS;j++) {
            if(grid[i][j] == 1) {
                connected = 1;
                break;
            }
        }
        if(!connected) { // If water cannot reach bottom of grid, percolation doesn't occur
            return 0;
        }
    }
    return 1;
}

int main() {
    int grid[ROWS][COLS];
    initialize(grid);
    printf("Initial random grid:\n");
    print_grid(grid);
    if(percolates(grid)) {
        printf("\nPercolation occurred!\n");
    } else {
        printf("\nPercolation did not occur.\n");
    }
    return 0;
}