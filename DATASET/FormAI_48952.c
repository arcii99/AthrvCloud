//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10 // Size of the grid
#define p 0.5 // Probability of site being open

bool grid[N][N]; // Grid of sites
bool opened[N][N]; // Grid of opened sites

void initialize() {
    srand(time(NULL)); // Initialize random generator
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if((double) rand() / (double) RAND_MAX <= p) {
                grid[i][j] = true; // Site is open
            } else {
                grid[i][j] = false; // Site is closed
            }
            opened[i][j] = false; // Site is not opened yet
        }
    }
}

void printGrid() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(grid[i][j]) {
                printf(" "); // Space for open site
            } else {
                printf("#"); // Hash for closed site
            }
        }
        printf("\n");
    }
}

bool isOpen(int i, int j) {
    return grid[i][j];
}

bool isFull(int i, int j) {
    if(i<0 || i>=N || j<0 || j>=N) {
        return false; // Outside of grid
    }
    if(!isOpen(i, j) || opened[i][j]) {
        return false; // Site is closed or already opened
    }
    opened[i][j] = true; // Mark site as opened
    if(i==0) {
        return true; // Site is connected to top
    }
    return isFull(i-1,j) || isFull(i+1,j) || isFull(i,j-1) || isFull(i,j+1);
}

bool percolates() {
    for(int j=0; j<N; j++) {
        if(isFull(N-1,j)) {
            return true; // Site is connected to bottom
        }
    }
    return false; // Site is not connected to bottom
}

int main() {
    initialize();
    printf("Initial grid:\n");
    printGrid();
    printf("\nThe grid percolates: %s\n", percolates() ? "YES" : "NO");
    return 0;
}