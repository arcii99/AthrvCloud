//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20 // size of the grid
#define THRESHOLD 0.6 // probability of a site being open

// function to show the grid
void show(int grid[][SIZE]) {
    system("clear"); // clear the console

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j]) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator

    int grid[SIZE][SIZE] = {0}; // initialize grid to all closed

    // open the top row
    for (int i = 0; i < SIZE; i++) {
        grid[0][i] = 1;
    }

    show(grid); // show the initial state of the grid

    // loop through all the cells in the grid
    for (int i = 1; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            double r = (double) rand() / RAND_MAX; // generate random number between 0 and 1
            if (r < THRESHOLD) { // open the cell
                grid[i][j] = 1;
            }
            show(grid); // show the updated grid
        }
    }

    return 0; // end the program
}