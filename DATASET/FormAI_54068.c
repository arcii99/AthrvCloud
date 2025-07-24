//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: invasive
#include <stdio.h> // include standard input/output library 
#include <stdlib.h> // include standard library for memory allocation
#include <time.h> // include time library for using random numbers

#define N 20 // define the size of the grid
#define VACANT 0 // define the vacant site
#define BLOCKED 1 // define the blocked site
#define OPEN 2 // define the open site

// function to check if the site is vacant or not
int is_vacant(int i, int j, int grid[N][N]) {
    return (grid[i][j] == VACANT);
}

// function to check if the site percolates
int does_percolate(int grid[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        if (grid[0][i] == OPEN) { // check for open sites in the top row
            for (j = 0; j < N; j++) {
                if (grid[N-1][j] == OPEN) { // check for open sites in the bottom row
                    return 1; // percolation occurs if there exists a path from top to bottom
                }
            }
        }
    }
    return 0; // percolation does not occur
}

// function to generate random numbers
int rand_int(int n) {
    return rand() % n;
}

// function to create a random grid
void random_grid(int grid[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (rand_int(N) < N/2) { // randomly assign blocked and open sites
                grid[i][j] = BLOCKED;
            } else {
                grid[i][j] = VACANT;
            }
        }
    }
}

// function to display the grid
void display_grid(int grid[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (grid[i][j] == BLOCKED) {
                printf("#");
            } else if (grid[i][j] == VACANT) {
                printf(".");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// function that percolates the grid
void percolate_grid(int grid[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (is_vacant(i, j, grid) && does_percolate(grid)) { // check if the random site is vacant and if there exists a path from top to bottom
                grid[i][j] = OPEN; // open the site if it percolates
            }
        }
    }
}

int main() {
    srand(time(0)); // seed random number generator
    int grid[N][N]; // declare the grid
    random_grid(grid); // create a random grid
    printf("Initial Grid:\n");
    display_grid(grid); // display the initial grid
    percolate_grid(grid); // percolate the grid
    printf("Percolated Grid:\n");
    display_grid(grid); // display the percolated grid
    return 0; // exit the program
}