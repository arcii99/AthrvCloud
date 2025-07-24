//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Size of the grid

int grid[N][N]; // The grid
int open[N][N]; // Will contain 1 for open cells and 0 for closed cells
int filled[N][N]; // Will contain 1 for cells connected to the top and 0 for all others

// Function to initialize the grid
void initializeGrid() {
    srand(time(NULL)); // Seed the random function with time
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            grid[i][j] = 0; // Initially, all cells are blocked
            open[i][j] = 0; // Initially, no cells are open
            filled[i][j] = 0; // Initially, no cells are filled
        }
    }
}

// Function to print the grid
void printGrid() {
    for(int i=0; i<N; i++) {
        printf("|");
        for(int j=0; j<N; j++) {
            if(open[i][j] == 1) printf(" "); // Empty cell
            else if(grid[i][j] == 1) printf("*"); // Blocked cell
            else if(filled[i][j] == 1) printf("#"); // Filled cell
        }
        printf("|\n");
    }
}

// Function to open a cell in the grid
void openCell(int x, int y) {
    if(x < 0 || x >= N || y < 0 || y >= N) return; // Ignore cells outside the grid
    if(grid[x][y] == 1 || open[x][y] == 1) return; // Ignore blocked cells and cells already open
    open[x][y] = 1; // Mark cell as open
    if(x == 0) filled[x][y] = 1; // If cell is in the top row, mark it as filled
    openCell(x-1, y); // Open neighbor above
    openCell(x+1, y); // Open neighbor below
    openCell(x, y-1); // Open neighbor to the left
    openCell(x, y+1); // Open neighbor to the right
}

// Function to simulate percolation
void simulatePercolation() {
    int count = 0;
    while(1) {
        int x = rand() % N; // Random cell in the grid
        int y = rand() % N;
        if(open[x][y] == 0) { // If cell is closed
            openCell(x,y); // Open the cell
            count++;
        }
        if(filled[N-1][N-1] == 1) break; // If bottom right cell is filled, we have percolation
    }
    printf("Percolation achieved after opening %d cells.\n", count);
}

int main() {
    initializeGrid();
    simulatePercolation();
    printGrid();
    return 0;
}