//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // size of grid

// function prototypes
void initialize(int grid[N][N]);
void printGrid(int grid[N][N]);
void percolate(int grid[N][N]);

int main() {
    // seed for random number generator
    srand(time(NULL));
    
    int grid[N][N];
    
    // initialize the grid
    initialize(grid);
    
    // print the initial grid
    printf("Initial configuration:\n");
    printGrid(grid);
    
    // simulate percolation
    percolate(grid);
    
    // print the final grid
    printf("\nFinal configuration:\n");
    printGrid(grid);
    
    return 0;
}

// initialize the grid with random values
void initialize(int grid[N][N]) {
    int i, j;
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            int randVal = rand() % 101;
            if(randVal < 50) {
                grid[i][j] = 0; // blocked site
            } else {
                grid[i][j] = 1; // open site
            }
        }
    }
}

// print the grid
void printGrid(int grid[N][N]) {
    int i, j;
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(grid[i][j] == 0) {
                printf("X "); // blocked site
            } else {
                printf("- "); // open site
            }
        }
        printf("\n");
    }
}

// simulate percolation
void percolate(int grid[N][N]) {
    int i, j;
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(grid[i][j] == 1) { // open site
                if(i==0) {
                    grid[i][j] = 2; // full site
                } else {
                    if(j==0) {
                        if(grid[i-1][j] == 2) {
                            grid[i][j] = 2; // full site
                        }
                    } else if(j==N-1) {
                        if(grid[i-1][j] == 2) {
                            grid[i][j] = 2; // full site
                        }
                    } else {
                        if(grid[i-1][j] == 2 || grid[i][j-1] == 2 || grid[i][j+1] == 2) {
                            grid[i][j] = 2; // full site
                        }
                    }
                }
            }
        }
    }
}