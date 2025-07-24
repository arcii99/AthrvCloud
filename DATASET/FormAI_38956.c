//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 //Change this value to adjust the grid size
#define THRESHOLD 0.6 //Change this value to adjust the percolation threshold

int grid[SIZE][SIZE]; //Initialize grid with all zeros

void printGrid() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(grid[i][j] == 1) printf("\u25A0 "); //print black square for full cells
            else printf("\u25A1 "); //print white square for empty cells
        }
        printf("\n");
    }
}

int isConnected(int x1, int y1, int x2, int y2) {
    return (grid[x1][y1] == 1 && grid[x2][y2] == 1);
}

int isPercolating() {
    for(int i = 0; i < SIZE; i++) {
        if(isConnected(0, i, SIZE-1, i)) return 1; //check bottom row for percolation
    }
    return 0;
}

int main() {
    srand(time(0)); //seed the random number generator with current time
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if((double)rand()/(double)RAND_MAX < THRESHOLD) grid[i][j] = 1; //with a given probability, fill the cell
            else grid[i][j] = 0; //otherwise leave it empty
        }
    }
    printGrid();
    if(isPercolating()) printf("The system percolates!");
    else printf("The system doesn't percolate.");
    return 0;
}