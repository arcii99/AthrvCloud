//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // size of the grid
#define P 0.6 // probability of a site being open

// defining the grid
int grid[N][N];

// initializing all the sites as closed
void initialize() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            grid[i][j] = 0;
        }
    }
}

// populating the grid with open or closed sites randomly 
void generateGrid() {
    srand(time(NULL)); // seeding random number generator with current time
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            float r = (float) rand()/(float) RAND_MAX; // generating a random float number between 0 and 1
            if(r <= P) {
                grid[i][j] = 1; // site is open
            } else {
                grid[i][j] = 0; // site is closed
            }
        }
    }
}

// checking if the site is open
int isOpen(int row, int col) {
    if(row < 0 || row >= N || col < 0 || col >= N) { // if the site is outside the grid, return false
        return 0;
    }
    return grid[row][col]; // the site is open if grid[row][col] is 1, otherwise it is closed
}

// checking if a site is connected to the top row
int isFull(int row, int col) {
    if(row < 0 || row >= N || col < 0 || col >= N) { // if the site is outside the grid, return false
        return 0;
    }
    if(row == 0) { // if the site is in the top row, it is connected to the top
        return 1;
    }
    if(!isOpen(row, col)) { // if the site is closed, it is not connected to the top
        return 0;
    }
    // check if any of the neighbors are connected to the top
    return isFull(row-1, col) || isFull(row, col-1) || isFull(row, col+1);
}

// checking if the system percolates (at least one site in the bottom row is connected to the top)
int percolates() {
    for(int j=0; j<N; j++) {
        if(isFull(N-1, j)) {
            return 1;
        }
    }
    return 0;
}

// printing the grid
void printGrid() {
    printf("\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(grid[i][j] == 1) {
                printf("O ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int main() {
    initialize();
    generateGrid();
    printGrid();
    if(percolates()) {
        printf("\nThe system percolates!\n");
    } else {
        printf("\nThe system does not percolate!\n");
    }
    return 0;
}