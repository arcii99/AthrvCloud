//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20   // size of grid
#define P 0.5  // probability of opening a site

// helper function to determine whether a site is open or not
int is_open(int row, int col, int *grid) {
    return *(grid + row * N + col);
}

// helper function to open a site
void open(int row, int col, int *grid) {
    *(grid + row * N + col) = 1;
}

// helper function to print the grid
void print_grid(int *grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (*(grid + i * N + j) == 0) {
                printf(". ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }
}

// function to run the percolation simulation
void simulate_percolation() {
    // allocate memory for the grid
    int *grid = malloc(N * N * sizeof(int));
    if (grid == NULL) {
        printf("Error: Unable to allocate memory for grid\n");
        exit(1);
    }

    // initialize the grid to be all closed
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(grid + i * N + j) = 0;
        }
    }

    // seed the random number generator
    srand(time(NULL));

    // open sites with probability P
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((double)rand() / RAND_MAX < P) {
                open(i, j, grid);
            }
        }
    }

    // check if top and bottom of grid are connected
    int top_connected = 0;
    for (int j = 0; j < N; j++) {
        if (is_open(0, j, grid)) {
            top_connected = 1;
            break;
        }
    }
    int bottom_connected = 0;
    for (int j = 0; j < N; j++) {
        if (is_open(N-1, j, grid)) {
            bottom_connected = 1;
            break;
        }
    }

    // print the grid and whether it percolates or not
    printf("Simulation Complete!\n");
    print_grid(grid);
    if (top_connected && bottom_connected) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    // free memory for grid
    free(grid);
}

// main function
int main() {
    simulate_percolation();
    return 0;
}