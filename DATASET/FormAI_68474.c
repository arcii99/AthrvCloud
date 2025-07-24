//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 30

int percolation(int grid[MAXSIZE][MAXSIZE], int n) {
    // initialize top and bottom as not connected to begin with
    int top[MAXSIZE*MAXSIZE], bottom[MAXSIZE*MAXSIZE];
    for (int i=0; i<n*n; i++) {
        top[i] = 0;
        bottom[i] = 0;
    }

    // connect top to top row and bottom to bottom row
    for (int j=0; j<n; j++) {
        top[j] = 1;
        bottom[n*(n-1) + j] = 1;
    }

    // use union-find algorithm to connect nodes
    for (int i=0; i<n*n; i++) {
        if (grid[i/n][i%n] == 0) {
            continue;
        }
        // check if node has top and/or bottom connections
        int top_conn = 0;
        int bottom_conn = 0;
        if (i < n) {
            top_conn = 1;
        }
        if (i >= n*(n-1)) {
            bottom_conn = 1;
        }
        // check if neighboring nodes are connected
        if (i%n != 0 && grid[i/n][(i-1)%n] == 1) {
            if (top[(i-1)] == 1 || bottom[(i-1)] == 1) {
                top_conn = 1;
                bottom_conn = 1;
            }
        }
        if (i%n != n-1 && grid[i/n][(i+1)%n] == 1) {
            if (top[(i+1)] == 1 || bottom[(i+1)] == 1) {
                top_conn = 1;
                bottom_conn = 1;
            }
        }
        if (i/n != 0 && grid[(i/n)-1][i%n] == 1) {
            if (top[(i-n)] == 1 || bottom[(i-n)] == 1) {
                top_conn = 1;
                bottom_conn = 1;
            }
        }
        if (i/n != n-1 && grid[(i/n)+1][i%n] == 1) {
            if (top[(i+n)] == 1 || bottom[(i+n)] == 1) {
                top_conn = 1;
                bottom_conn = 1;
            }
        }
        // connect nodes if at least one connection is found
        if (top_conn == 1 || bottom_conn == 1) {
            top[i] = 1;
            bottom[i] = 1;
            for (int j=0; j<n*n; j++) {
                if (top[j] == 1 && bottom[j] == 1) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

void print_grid(int grid[MAXSIZE][MAXSIZE], int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int n = 10;
    int grid[MAXSIZE][MAXSIZE];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            // randomly generate open or closed position
            int r = rand() % 2;
            grid[i][j] = r;
        }
    }

    printf("Initial grid:\n");
    print_grid(grid, n);

    if (percolation(grid, n) == 1) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate.\n");
    }

    return 0;
}