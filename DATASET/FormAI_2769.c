//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // grid size
#define P 0.6 // probability of site being open

int grid[N][N] = {0}; // 0: blocked, 1: open, 2: connected to top, 3: connected to bottom

void init() {
    // initialize grid with open or blocked sites based on probability P
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((double) rand() / RAND_MAX < P) {
                grid[i][j] = 1;
            }
        }
    }
}

void update(int i, int j) {
    // update connectivity status of open site (i,j) and its neighbors
    if (grid[i][j] == 1) {
        if (i == 0) {
            grid[i][j] = 2; // connected to top
        } else if (i == N-1) {
            grid[i][j] = 3; // connected to bottom
        }
        if (i > 0 && grid[i-1][j] > 1) { // check top
            grid[i][j] = grid[i-1][j];
        }
        if (i < N-1 && grid[i+1][j] > 1) { // check bottom
            grid[i][j] = grid[i+1][j];
        }
        if (j > 0 && grid[i][j-1] > 1) { // check left
            grid[i][j] = grid[i][j-1];
        }
        if (j < N-1 && grid[i][j+1] > 1) { // check right
            grid[i][j] = grid[i][j+1];
        }
    }
}

void percolate() {
    // percolate through the grid to determine if there is a path from top to bottom
    int connected[N+2] = {0}; // virtual sites at top and bottom
    int top_site = N*N;
    int bottom_site = N*N+1;
    for (int j = 0; j < N; j++) {
        if (grid[0][j] > 0) {
            connected[grid[0][j]] |= 1; // connect to top
        }
        if (grid[N-1][j] > 0) {
            connected[grid[N-1][j]] |= 2; // connect to bottom
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int site = i*N+j;
            if (grid[i][j] > 0) {
                update(i, j);
                if (i == 0) {
                    connected[grid[i][j]] |= 1;
                } else if (i == N-1) {
                    connected[grid[i][j]] |= 2;
                }
            }
        }
    }
    if (connected[1] & 2) { // top and bottom are connected
        printf("Percolation has occurred!\n");
    } else {
        printf("Percolation has not occurred.\n");
    }
}

void display() {
    // display grid with connectivity status
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    init();
    display();
    percolate();
    return 0;
}