//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: careful
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10 // size of grid
#define PROBABILITY 0.6 // probability of site being open

// define the grid
int grid[GRID_SIZE][GRID_SIZE]; 

// function to randomly generate grid
void generate_grid() {
    srand(time(NULL)); // seed random number generator with current time
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            float r = (float)rand() / RAND_MAX; // generate random float between 0 and 1
            if(r < PROBABILITY) {
                grid[i][j] = 1; // open site
            } else {
                grid[i][j] = 0; // blocked site
            }
        }
    }
}

// function to print the grid
void print_grid() {
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            if(grid[i][j] == 1) {
                printf("O "); // open site
            } else {
                printf("X "); // blocked site
            }
        }
        printf("\n");
    }
}

// function to check if site is open
bool is_open(int row, int col) {
    if(row < 0 || col < 0 || row >= GRID_SIZE || col >= GRID_SIZE) {
        return false; // site is out of bounds
    }
    return (grid[row][col] == 1); // site is open
}

// function to check if a site is full (connected to top)
bool is_full(int row, int col) {
    if(row < 0 || col < 0 || row >= GRID_SIZE || col >= GRID_SIZE) {
        return false; // site is out of bounds
    }
    if(grid[row][col] == 0) {
        return false; // site is blocked
    }
    if(row == 0) {
        return true; // site is connected to top
    }
    return (is_full(row-1, col) || is_full(row, col-1) || is_full(row, col+1)); // check neighboring sites
}

// function to check if the system percolates
bool percolates() {
    for(int i = 0; i < GRID_SIZE; i++) {
        if(is_full(GRID_SIZE-1, i)) {
            return true; // system percolates
        }
    }
    return false; // system does not percolate
}

int main() {
    generate_grid(); // randomly generate grid
    print_grid(); // print grid
    if(percolates()) { 
        printf("The system percolates!\n"); // system percolates
    } else { 
        printf("The system does not percolate.\n"); // system does not percolate
    }
    return 0;
}