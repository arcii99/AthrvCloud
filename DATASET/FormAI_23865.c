//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10             // size of the grid
#define P 0.5            // probability of a site being open
#define PERCOLATION '*'
#define OPEN ' '

char grid[N][N];         // the grid for the percolation

void initGrid()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = OPEN;
        }
    }
}

void printGrid() 
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

bool isOpen(int i, int j) 
{
    return grid[i][j] == PERCOLATION || grid[i][j] == OPEN;
}

bool isFull(int i, int j) 
{
    if (i < 0 || j < 0 || i >= N || j >= N) return false;
    if (isOpen(i, j)) return false;
    grid[i][j] = PERCOLATION;
    isFull(i+1, j);  // check down
    isFull(i-1, j);  // check up
    isFull(i, j+1);  // check right
    isFull(i, j-1);  // check left
    return true;
}

bool percolates() 
{
    for (int j = 0; j < N; j++) {
        if (isFull(0, j)) {
            return true;
        }
    }
    return false;
}

int main()
{
    srand(time(NULL));   // seed random number generator
    initGrid();           // initialize grid with all sites closed

    // randomly open sites
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((float) rand() / (float) RAND_MAX < P) grid[i][j] = PERCOLATION;
        }
    }

    printGrid();
    if (percolates()) {
        printf("Water percolates through the grid.\n");
    } else {
        printf("Water does not percolate through the grid.\n");
    }

    return 0;
}