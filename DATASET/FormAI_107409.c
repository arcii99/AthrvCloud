//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10   /* size of the grid */
#define P 0.6  /* probability of opening a site */

int grid[N][N];  /* the grid */
int open[N][N];  /* keep track of open sites */

/* function to initialize the grid */
void init_grid() {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            grid[i][j] = 0;
            open[i][j] = 0;
        }
    }
}

/* function to randomly open sites */
void open_sites() {
    int i, j;
    double r;

    srand(time(NULL));
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            r = (double) rand() / (RAND_MAX + 1.0);
            if (r < P) {
                open[i][j] = 1;
            }
        }
    }
}

/* function to print the grid */
void print_grid() {
    int i, j;

    printf("  ");
    for (i = 0; i < N; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 0; i < N; i++) {
        printf("%d ", i);
        for (j = 0; j < N; j++) {
            if (open[i][j]) {
                printf("* ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

/* recursive function to check if (i,j) is connected to the top */
int is_connected(int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= N) {
        return 0;
    }
    if (!open[i][j]) {
        return 0;
    }
    if (i == 0) {
        return 1;
    }
    open[i][j] = 0;
    if (is_connected(i-1, j) || is_connected(i+1, j) ||
        is_connected(i, j-1) || is_connected(i, j+1)) {
        return 1;
    }
    return 0;
}

/* function to check if the grid percolates */
int percolates() {
    int i;

    for (i = 0; i < N; i++) {
        if (is_connected(N-1, i)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    init_grid();
    open_sites();
    print_grid();
    if (percolates()) {
        printf("Percolates\n");
    } else {
        printf("Does not percolate\n");
    }
    return 0;
}