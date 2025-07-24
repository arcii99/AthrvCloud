//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // size of grid
#define THRESHOLD 0.6 // threshold for percolation

// program to simulate percolation in a 2D grid
// cells have either value 0 (blocked) or 1 (open)
// percolation happens when the top row and bottom row are connected
// through open cells

int grid[SIZE][SIZE]; // 2D grid to store blocked (0) or open (1) cells

// function to initialize the grid randomly
void initialize_grid() {
    srand(time(NULL)); // seed random number generator with current time
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            float r = (float) rand() / RAND_MAX; // generate a random float between 0 and 1
            if(r < THRESHOLD) {
                grid[i][j] = 1; // cell is open
            } else {
                grid[i][j] = 0; // cell is blocked
            }
        }
    }
}

// function to print the grid
void print_grid() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// function to check if the top row and bottom row are connected
int percolates() {
    int top_row[SIZE], bottom_row[SIZE];
    // copy top row
    for(int j = 0; j < SIZE; j++) {
        top_row[j] = grid[0][j];
    }
    // copy bottom row
    for(int j = 0; j < SIZE; j++) {
        bottom_row[j] = grid[SIZE-1][j];
    }
    // check if any open cells in top row are connected to any open cells in bottom row
    for(int j = 0; j < SIZE; j++) {
        if(top_row[j] == 1) { // if cell in top row is open
            for(int k = 0; k < SIZE; k++) {
                if(bottom_row[k] == 1) { // if cell in bottom row is open
                    if(j == k) { // if cells are in the same column, they are connected
                        return 1; // percolation has occurred
                    }
                }
            }
        }
    }
    return 0; // no percolation
}

int main() {
    initialize_grid();
    printf("Initial grid:\n");
    print_grid();
    if(percolates()) {
        printf("Percolation has occurred.\n");
    } else {
        printf("Percolation has not occurred.\n");
    }
    return 0;
}