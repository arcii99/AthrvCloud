//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: artistic
// C Percolation Simulator
// By: Your Name Here

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int grid[N * N]; // Grid

// Function prototypes
void initGrid();
void printGrid();
int find(int);
void unionGrid(int, int);

int main() {
    srand(time(NULL)); // Seed random number generator
    
    int p = 60; // Percolation threshold
    int openSiteCount = 0; // Number of open sites
    int percolates = 0; // Flag to check if system percolates
    
    initGrid(); // Initialize grid
    
    // Open sites until system percolates
    while (!percolates) {
        // Add random site to open list
        int site = rand() % (N * N);
        if (!grid[site]) {
            grid[site] = 1; // Open site
            openSiteCount++;
        }
        
        // Connect to adjacent open sites
        int row = site / N;
        int col = site % N;
        if (row > 0 && grid[(row - 1) * N + col]) {
            unionGrid(site, (row - 1) * N + col); // Connect to top site
        }
        if (row < N - 1 && grid[(row + 1) * N + col]) {
            unionGrid(site, (row + 1) * N + col); // Connect to bottom site
        }
        if (col > 0 && grid[row * N + col - 1]) {
            unionGrid(site, row * N + col - 1); // Connect to left site
        }
        if (col < N - 1 && grid[row * N + col + 1]) {
            unionGrid(site, row * N + col + 1); // Connect to right site
        }
        
        // Check if system percolates
        for (int i = 0; i < N; i++) {
            if (grid[i] && find(i) < N) {
                percolates = 1;
                break;
            }
        }
    }
    
    printGrid(); // Print final grid
    
    printf("Percolation threshold: %d%%\n", (int)((float)openSiteCount / (float)(N * N) * 100)); // Print percolation threshold
    
    return 0;
}

// Initialize grid with closed sites
void initGrid() {
    for (int i = 0; i < N * N; i++) {
        grid[i] = 0;
    }
}

// Print grid with open sites and connections
void printGrid() {
    for (int i = 0; i < N * N; i++) {
        if (grid[i]) {
            printf("1 ");
        } else {
            printf("0 ");
        }
        
        if ((i + 1) % N == 0) {
            printf("\n");
        }
    }
}

// Find root of component containing site
int find(int site) {
    while (site != grid[site]) {
        site = grid[site];
    }
    return site;
}

// Connect two components
void unionGrid(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);
    if (rootP == rootQ) {
        return;
    }
    grid[rootP] = rootQ;
}