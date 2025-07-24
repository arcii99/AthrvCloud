//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Setting the grid size
#define N 20

// Creating the grid
int grid[N][N];

// Declaring functions
void init();
void print_grid();
void percolate();

int main() {
    // Initializing random seed
    srand(time(NULL));

    // Starting the simulation
    init();
    print_grid();
    percolate();

    return 0;
}

// Initializes the grid with random values
void init() {
    int i, j;
    double p = 0.5; // Probability of site being open

    // Loop through each row
    for (i = 0; i < N; i++) {
        // Loop through each column
        for (j = 0; j < N; j++) {
            // Generating random number between 0 and 1
            double rand_num = (double)rand() / RAND_MAX;
            // Setting the site to be open if probability is less than p
            if (rand_num < p) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }

    // Setting the top and bottom rows to be open
    for (j = 0; j < N; j++) {
        grid[0][j] = 1;
        grid[N-1][j] = 1;
    }
}

// Prints out the grid
void print_grid() {
    int i, j;

    printf("\n");
    // Loop through each row
    for (i = 0; i < N; i++) {
        // Loop through each column
        for (j = 0; j < N; j++) {
            // If site is open, print "."
            if (grid[i][j] == 1) {
                printf(". ");
            // If site is closed, print "X"
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Percolates through the grid
void percolate() {
    int i, j, k;
    // Array to keep track of which sites are connected
    int connected[N];

    // Initializing all sites to be unconnected
    for (j = 0; j < N; j++) {
        connected[j] = 0;
    }

    // Checking if any site in the top row is open and connecting it to the rest of the grid
    for (j = 0; j < N; j++) {
        if (grid[0][j] == 1) {
            connected[j] = 1;
            // Check if any neighboring sites are open and connect them
            if (j > 0 && grid[1][j-1] == 1) {
                connected[j-1] = 1;
            }
            if (j < N-1 && grid[1][j+1] == 1) {
                connected[j+1] = 1;
            }
            if (grid[1][j] == 1) {
                connected[j] = 1;
            }
        }
    }

    // Loop through each row, starting from the second row
    for (i = 1; i < N; i++) {
        // Loop through each site in the row
        for (j = 0; j < N; j++) {
            // If site is open, check if any connected site is adjacent to it
            if (grid[i][j] == 1) {
                for (k = -1; k <= 1; k++) {
                    if (j+k >= 0 && j+k < N && connected[j+k] == 1) {
                        connected[j] = 1;
                        break;
                    }
                }
            }
        }
    }

    // Checking if bottom row is connected to the top row
    int is_percolating = 0;
    for (j = 0; j < N; j++) {
        if (grid[N-1][j] == 1 && connected[j] == 1) {
            is_percolating = 1;
            break;
        }
    }

    // Printing out whether or not the grid percolates
    if (is_percolating == 1) {
        printf("The grid percolates.\n");
    } else {
        printf("The grid does not percolate.\n");
    }
}