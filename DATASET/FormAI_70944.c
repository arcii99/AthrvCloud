//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10 // size of percolation grid

// global variables
bool percolates = false;
int count = 0;
int grid[N][N];
int opened[N][N];

void open(int row, int col) {
    // set the site at (row, col) to be open
    opened[row][col] = 1;
    count++;
        
    // check if the site at (row, col) is connected to the top or bottom
    if (row == 0) {
        grid[row][col] = 2;
    }
    if (row == N-1) {
        grid[row][col] = 3;
    }
    
    // connect neighboring open sites
    if (row-1 >= 0 && opened[row-1][col] == 1) {
        grid[row][col] = grid[row][col] | grid[row-1][col];
        grid[row-1][col] = grid[row][col];
    }
    if (row+1 < N && opened[row+1][col] == 1) {
        grid[row][col] = grid[row][col] | grid[row+1][col];
        grid[row+1][col] = grid[row][col];
    }
    if (col-1 >= 0 && opened[row][col-1] == 1) {
        grid[row][col] = grid[row][col] | grid[row][col-1];
        grid[row][col-1] = grid[row][col];
    }
    if (col+1 < N && opened[row][col+1] == 1) {
        grid[row][col] = grid[row][col] | grid[row][col+1];
        grid[row][col+1] = grid[row][col];
    }
    
    // check if the percolation system percolates
    if (row == N-1 && (grid[row][col] == 2 || grid[row][col] == 3)) {
        percolates = true;
    }
}

int main() {
    srand(time(NULL));
    
    // initialize percolation grid and open random sites
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = 1;
            opened[i][j] = 0;
        }
    }
    while (!percolates) {
        int row = rand() % N;
        int col = rand() % N;
        if (opened[row][col] == 0) {
            open(row, col);
        }
    }
    
    // print the percolation grid and number of open sites
    printf("Percolation Grid:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("Number of Open Sites: %d\n", count);
    
    return 0;
}