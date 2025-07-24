//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // size of the grid
#define P 0.5 // probability of a site becoming open

int grid[SIZE][SIZE]; // grid to represent the lattice
int open[SIZE][SIZE] = {0}; // grid to keep track of open sites

void printGrid() {
    printf("\n");
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(grid[i][j] == 1) {
                printf("*");
            } else if(open[i][j] == 1) {
                printf(" ");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int isOpen(int row, int col) {
    if(row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return 0;
    }
    return open[row][col];
}

void openSite(int row, int col) {
    if(row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return;
    }
    if(open[row][col] == 1 || grid[row][col] == 1) {
        return;
    }
    open[row][col] = 1;
    if(isOpen(row-1, col)) {
        openSite(row-1, col);
    }
    if(isOpen(row+1, col)) {
        openSite(row+1, col);
    }
    if(isOpen(row, col-1)) {
        openSite(row, col-1);
    }
    if(isOpen(row, col+1)) {
        openSite(row, col+1);
    }
}

int percolates() {
    for(int i=0; i<SIZE; i++) {
        if(open[0][i] == 1) {
            openSite(0,i);
        }
    }
    for(int i=0; i<SIZE; i++) {
        if(open[SIZE-1][i] == 1 && open[SIZE-2][i] == 1) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    //Initialize grid with randomly placed sites
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(((double) rand() / (RAND_MAX)) < P) {
                grid[i][j] = 1;
            }
        }
    }
    printGrid();
    if(percolates()) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }
    return 0;
}