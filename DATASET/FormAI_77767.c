//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

void print_grid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void percolate(int grid[N][N]) {
    int open[N][N] = {0}; // stores if each site is open or not
    int full[N][N] = {0}; // stores if each site is full or not
    
    // initialize top row as full
    for (int i = 0; i < N; i++) {
        full[0][i] = 1;
    }
    
    // repeat until percolation occurs
    while (1) {
        // randomly choose an open site on the bottom row
        int randx = rand() % N;
        int randy = N - 1;
        
        // if site is already full, continue
        if (full[randy][randx] == 1) {
            continue;
        }
        
        // mark site as full and open
        open[randy][randx] = 1;
        full[randy][randx] = 1;
        
        // check if any adjacent sites are full
        if (randx > 0 && full[randy][randx-1] == 1) {
            full[randy][randx] = 1;
        }
        if (randx < N-1 && full[randy][randx+1] == 1) {
            full[randy][randx] = 1;
        }
        if (randy > 0 && full[randy-1][randx] == 1) {
            full[randy][randx] = 1;
        }
        if (full[randy+1][randx] == 1) {
            full[randy][randx] = 1;
        }
        
        // print grid to monitor progress
        print_grid(full);
        printf("\n");
        
        // check if percolation has occurred
        int percolates = 0;
        for (int i = 0; i < N; i++) {
            if (full[N-1][i] == 1) {
                percolates = 1;
                break;
            }
        }
        
        // stop if percolation has occurred
        if (percolates == 1) {
            break;
        }
    }
}

int main() {
    int grid[N][N] = {0}; // stores if each site is blocked or not
    srand(time(0)); // seed random number generator
    
    // randomly block sites
    for (int i = 0; i < N*N/2; i++) {
        int randx = rand() % N;
        int randy = rand() % N;
        grid[randy][randx] = 1;
    }
    
    // print initial grid
    printf("Initial Grid:\n");
    print_grid(grid);
    printf("\n");
    
    // simulate percolation
    percolate(grid);
    
    return 0;
}