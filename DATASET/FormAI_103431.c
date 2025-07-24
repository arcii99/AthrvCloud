//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 25

int grid[GRID_SIZE][GRID_SIZE];

void fillPercolationGrid() {
    int i, j;
    srand(time(NULL));
    for(i = 0; i < GRID_SIZE; i++) {
        for(j = 0; j < GRID_SIZE; j++) {
            if( rand() % 2 == 0 ) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
}

void printPercolationGrid() {
    int i, j;

    printf("+" );
    for(j = 0; j < GRID_SIZE; j++) {
        printf("--+");
    }
    printf("\n");

    for(i = 0; i < GRID_SIZE; i++) {
        printf("|" );
        for(j = 0; j < GRID_SIZE; j++) {
            if(grid[i][j] == 1) {
                printf(" #|" );
            } else {
                printf("  |" );
            }
        }
        printf("\n+" );
        for(j = 0; j < GRID_SIZE; j++) {
            printf("--+");
        }
        printf("\n");
    }
}

int percolates() {
    int i = GRID_SIZE - 1;
    int j;
    for(j = 0; j < GRID_SIZE; j++ ) {
        if( grid[i][j] == 1 ) {
            return 1;
        }
    }

    return 0;
}

int main() {
    fillPercolationGrid();
    printPercolationGrid();
    if(percolates()) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate!\n");
    }
    return 0;
}