//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define N 10 // Size of the grid

// Defining the grid using a 2D array
int grid[N][N];

// Function to initialize the grid
void initialize_grid(float p) {
    srand(time(NULL));
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            float r = (float)rand() / RAND_MAX; // Generating a random number between 0 and 1
            if(r <= p) {
                grid[i][j] = 1; // Site is open
            }
            else {
                grid[i][j] = 0; // Site is blocked
            }
        }
    }
}

// Function to print the grid
void print_grid() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(grid[i][j] == 1) {
                printf("O "); // Site is open
            }
            else {
                printf("# "); // Site is blocked
            }
        }
        printf("\n");
    }
}

// Function to check if a site is connected to the top row
bool is_full(int row, int col) {
    if(row < 0 || row >= N || col < 0 || col >= N) {
        return false; // Site is out of bounds
    }
    else if(grid[row][col] == 0) {
        return false; // Site is blocked
    }
    else if(row == 0) {
        return true; // Site is connected to the top row
    }
    else {
        return is_full(row-1, col) || is_full(row, col-1) || is_full(row, col+1); // Checking if any adjacent site is connected to the top row
    }
}

// Function to check if the system percolates
bool does_percolate() {
    for(int i=0;i<N;i++) {
        if(is_full(N-1, i)) {
            return true; // Site is connected to the bottom row
        }
    }
    return false; // System does not percolate
}

int main() {
    float p = 0.6; // Probability of a site being open
    initialize_grid(p);
    print_grid();
    if(does_percolate()) {
        printf("The system percolates\n");
    }
    else {
        printf("The system does not percolate\n");
    }
    return 0;
}