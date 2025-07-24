//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // size of grid
#define P 0.6 // probability of a site being open
#define EMPTY 0 // site is blocked
#define FULL 1 // site is open

void print_grid(int grid[N][N]) {
    printf("\n");
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (grid[i][j] == EMPTY) printf("X "); // blocked site
            else printf("O "); // open site
        }
        printf("\n");
    }
}

int connected(int a, int b) {
    // check if two sites are connected
    return ((a + 1 == b) || (a - 1 == b) || (a + N == b) || (a - N == b));
}

void percolate(int grid[N][N]) {
    // create virtual top and bottom sites
    int virtual_top = N*N;
    int virtual_bottom = N*N + 1;

    // initialize UFDS data structure
    int ufds[N*N + 2];
    for (int i=0; i<N*N + 2; i++) {
        ufds[i] = i;
    }

    // connect top row to virtual top site
    for (int i=0; i<N; i++) {
        if (grid[0][i] == FULL) {
            ufds[i] = virtual_top;
        }
    }

    // connect bottom row to virtual bottom site
    for (int i=0; i<N; i++) {
        if (grid[N-1][i] == FULL) {
            ufds[(N-1)*N + i] = virtual_bottom;
        }
    }

    // connect sites within grid
    for (int i=0; i<N*N; i++) {
        int row = i / N;
        int col = i % N;

        if (grid[row][col] == FULL) {
            // connect to neighboring sites
            if (row > 0 && grid[row-1][col] == FULL && !connected(ufds[i], ufds[i-N])) {
                ufds[ufds[i-N]] = ufds[i];
            }
            if (row < N-1 && grid[row+1][col] == FULL && !connected(ufds[i], ufds[i+N])) {
                ufds[ufds[i+N]] = ufds[i];
            }
            if (col > 0 && grid[row][col-1] == FULL && !connected(ufds[i], ufds[i-1])) {
                ufds[ufds[i-1]] = ufds[i];
            }
            if (col < N-1 && grid[row][col+1] == FULL && !connected(ufds[i], ufds[i+1])) {
                ufds[ufds[i+1]] = ufds[i];
            }

            // connect to virtual top/bottom sites
            if (ufds[i] < N && !connected(ufds[i], virtual_top)) {
                ufds[ufds[i]] = ufds[virtual_top];
            }
            if (ufds[i] >= (N-1)*N && !connected(ufds[i], virtual_bottom)) {
                ufds[ufds[i]] = ufds[virtual_bottom];
            }
        }
    }

    // check if percolation occurred
    if (ufds[virtual_top] == ufds[virtual_bottom]) printf("\nPercolation occurred!\n");
    else printf("\nPercolation did not occur.\n");
}

int main() {
    int grid[N][N];

    // initialize grid with blocked sites
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            grid[i][j] = EMPTY;
        }
    }

    // randomly open sites
    srand(time(NULL));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if ((double) rand() / (double) RAND_MAX < P) {
                grid[i][j] = FULL;
            }
        }
    }

    printf("Initial Grid:");
    print_grid(grid);

    // perform percolation simulation
    percolate(grid);

    printf("\nFinal Grid:");
    print_grid(grid);

    return 0;
}