//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20 // grid size

void print_grid(int grid[N][N]) {
    printf("\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(grid[i][j] == 0) {
                printf(". ");
            }
            else {
                printf("o ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// function to randomly fill the grid with open sites
void random_grid(int grid[N][N], float p_open) {
    srand(time(NULL)); // seed random number generator
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            float r = (float)rand()/(float)RAND_MAX; // generate random number between 0 and 1
            if(r < p_open) {
                grid[i][j] = 1; // open site
            }
            else {
                grid[i][j] = 0; // closed site
            }
        }
    }
}

// function to check if the system has percolated
int check_percolation(int grid[N][N]) {
    for(int i=0; i<N; i++) {
        if(grid[0][i] == 1) { // check first row
            for(int j=0; j<N; j++) {
                if(grid[N-1][j] == 1) { // check last row
                    return 1; // percolation found
                }
            }
        }
    }
    return 0; // no percolation found
}

// main function
int main() {
    int grid[N][N];
    float p_open = 0.6; // probability of open site
    random_grid(grid, p_open); // randomly fill the grid
    print_grid(grid); // print the initial grid
    int percolated = check_percolation(grid); // check if the system has percolated
    printf("System percolation: %d\n", percolated);
    return 0;
}