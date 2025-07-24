//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 //Size of the grid
#define NUM_ITERATIONS 100 //Number of iterations to run the simulation
#define OPEN_SITE_THRESHOLD 0.6 //Threshold for opening a site
#define BARRIER 1 //Value for a barrier site
#define OPEN 0 //Value for an open site

void printGrid(int grid[N][N]) {
    printf("\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(grid[i][j] == BARRIER) {
                printf("X ");
            } else {
                printf("%d ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

void initializeGrid(int grid[N][N]) {
    srand(time(NULL));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if((float)rand()/(float)RAND_MAX < OPEN_SITE_THRESHOLD) {
                grid[i][j] = OPEN;
            } else {
                grid[i][j] = BARRIER;
            }
        }
    }
}

void percolate(int grid[N][N]) {
    int topRowOpened = 0;
    int bottomRowOpened = 0;
    for(int i = 0; i < N; i++) {
        if(grid[0][i] == OPEN) {
            topRowOpened = 1;
        }
        if(grid[N-1][i] == OPEN) {
            bottomRowOpened = 1;
        }
    }
    if(topRowOpened && bottomRowOpened) {
        printf("\n***The grid percolates!***\n");
        printGrid(grid);
        exit(0);
    }
}

void simulate(int grid[N][N]) {
    for(int i = 0; i < NUM_ITERATIONS; i++) {
        int x = rand() % N;
        int y = rand() % N;
        if(grid[x][y] == BARRIER) {
            grid[x][y] = OPEN;
            percolate(grid);
        }
    }
    printf("\n***The grid does not percolate***\n");
    printGrid(grid);
}

int main() {
    int grid[N][N];
    initializeGrid(grid);
    printGrid(grid);
    simulate(grid);
    return 0;
}