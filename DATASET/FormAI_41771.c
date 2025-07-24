//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

int grid[ROW][COL]; // grid for storing the site values
int open[ROW][COL]; // grid for storing the open/closed status of sites

// function to set all sites in grid to closed
void initialize() {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            grid[i][j] = 0;
            open[i][j] = 0;
        }
    }
}

// function to print the current state of the grid
void printGrid() {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%d ", open[i][j]);
        }
        printf("\n");
    }
}

// function to generate a random site in the grid
void generateSite(int *x, int *y) {
    *x = rand() % ROW;
    *y = rand() % COL;
}

// function to check if a site is already open
int isOpen(int x, int y) {
    return open[x][y];
}

// function for percolation through neighboring sites
void percolate(int x, int y) {
    if (x < 0 || x >= ROW || y < 0 || y >= COL) return; // check if site is out of bounds
    if (isOpen(x, y)) return; // check if site is already open
    
    open[x][y] = 1; // open the current site
    
    // percolate through neighboring sites
    percolate(x+1, y);
    percolate(x-1, y);
    percolate(x, y+1);
    percolate(x, y-1);
}

int main() {
    srand(time(NULL)); // seed for random number generator
    initialize(); // initialize grid
    int x, y;
    
    // generate random open sites until there is percolation
    while (1) {
        generateSite(&x, &y);
        open[x][y] = 1;
        if (x == 0) percolate(x, y); // check for percolation
        if (open[0][0]) break; // break loop if percolation is successful
    }
    
    printf("Percolation achieved!\n");
    printGrid(); //display the final grid
    return 0;
}