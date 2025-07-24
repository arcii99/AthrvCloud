//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // grid size

void initialize(int *grid, int p) {
    srand(time(NULL));
    for (int i = 0; i < N*N; i++) {
        int r = rand() % 100;
        if (r < p) {
            grid[i] = 1;   // site open
        } else {
            grid[i] = 0;   // site closed
        }
    }
}

void percolate(int *grid) {
    int open[N*N];
    for (int i = 0; i < N*N; i++) {
        open[i] = 0;  // all sites initially closed
    }
    for (int i = 0; i < N; i++) {
        if (grid[i] == 1) {
            open[i] = 1;  // site open
        }
    }
    int changed = 1;
    while (changed) {
        changed = 0;
        for (int i = 0; i < N*N; i++) {            
            if (open[i] == 1 && grid[i] == 1) {
                if (i%N != 0 && grid[i-1] == 1 && open[i-1] == 0) {  // left
                    open[i-1] = 1;
                    changed = 1;
                }
                if (i%N != N-1 && grid[i+1] == 1 && open[i+1] == 0) {  // right
                    open[i+1] = 1;
                    changed = 1;
                }
                if (i > N-1 && grid[i-N] == 1 && open[i-N] == 0) {  // up
                    open[i-N] = 1;
                    changed = 1;
                }
                if (i < N*(N-1) && grid[i+N] == 1 && open[i+N] == 0) {  // down
                    open[i+N] = 1;
                    changed = 1;
                }
            }
        }
    }
    if (open[N*(N-1)] == 1) {  // bottom site open
        printf("Percolates!\n");
    } else {
        printf("Does not percolate.\n");
    }
}

int main() {
    int grid[N*N];
    int p = 60;  // probability of site being open
    initialize(grid, p);
    percolate(grid);
    return 0;
}