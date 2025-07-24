//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20 // size of the grid
#define p 0.6 // probability of sites being open

int grid[N][N]; // 2D grid
int count = 0; // keeps track of number of open sites

void print_grid() {
    printf("\n");
    printf(" ");
    for(int i=0; i<N; i++) {
        printf("_");
    }
    printf(" \n");
    for(int i=0; i<N; i++) {
        printf("|");
        for(int j=0; j<N; j++) {
            if(grid[i][j] == 0) {
                printf(" ");
            } else if(grid[i][j] == 1) {
                printf("*");
            }
        }
        printf("|");
        printf("\n");
    }
    printf(" ");
    for(int i=0; i<N; i++) {
        printf("_");
    }
    printf(" \n");
}

void percolate(int i, int j) {
    if(grid[i][j] == 1) {
        return;
    }
    grid[i][j] = 1;
    count++;
    if(i > 0 && grid[i-1][j] == 0) {
        percolate(i-1, j);
    }
    if(i < N-1 && grid[i+1][j] == 0) {
        percolate(i+1, j);
    }
    if(j > 0 && grid[i][j-1] == 0) {
        percolate(i, j-1);
    }
    if(j < N-1 && grid[i][j+1] == 0) {
        percolate(i, j+1);
    }
}

int main() {
    srand(time(NULL)); // seed random number generator
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if((double)rand()/RAND_MAX <= p) { // randomly open a site
                grid[i][j] = 0;
            } else {
                grid[i][j] = -1;
            }
        }
    }
    print_grid();
    for(int j=0; j<N; j++) {
        if(grid[0][j] == 0) { // check if top row site is open
            percolate(0, j);
        }
    }
    printf("\n");
    if(count > 0) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }
    print_grid();
    return 0;
}