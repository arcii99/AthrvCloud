//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10   // size of grid (SIZE x SIZE)

int grid[SIZE][SIZE];   // initialize grid

void printGrid() {
    printf("Current Grid State:\n");
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int percolates() {
    int top[SIZE] = {0};   // initialize top row to 0
    int bottom[SIZE] = {0};  // initialize bottom row to 0

    // check top row
    for(int j = 0; j < SIZE; j++) {
        if(grid[0][j] == 1) {
            top[j] = 1;
        }
    }

    // check bottom row
    for(int j = 0; j < SIZE; j++) {
        if(grid[SIZE-1][j] == 1) {
            bottom[j] = 1;
        }
    }

    // check if there is a path from top to bottom
    for(int i = 0; i < SIZE; i++) {
        if(top[i] == 1) {
            for(int j = 0; j < SIZE; j++) {
                if(bottom[j] == 1) {
                    if(grid[i][j] == 1) {
                        printf("Percolation achieved!\n");
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}

int main() {
    srand(time(NULL));   // seed random number generator with current time

    // initialize grid randomly with 0 or 1
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            int r = rand() % 2;
            grid[i][j] = r;
        }
    }

    printGrid();   // print initial grid

    while(!percolates()) {
        // randomly choose a cell to be opened
        int i = rand() % SIZE;
        int j = rand() % SIZE;

        // check if cell is already open
        if(grid[i][j] == 0) {
            grid[i][j] = 1;
        }
    }

    printGrid();   // print final grid

    return 0;
}