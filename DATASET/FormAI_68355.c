//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // size of the grid

int grid[N][N]; // the percolation grid

void initGrid() {
    // initialize the cells randomly as open (0) or blocked (1)
    srand(time(NULL));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (rand() % 2 == 0) {
                grid[i][j] = 0; // open
            } else {
                grid[i][j] = 1; // blocked
            }
        }
    }
}

void printGrid() {
    // print the grid to the console (0=white, 1=black)
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (grid[i][j] == 0) {
                printf("\u25A1 "); // white square
            } else {
                printf("\u25A0 "); // black square
            }
        }
        printf("\n");
    }
}

int percolates() {
    // checks if the percolation system has a complete path from the top row to the bottom row or not
    int visited[N][N] = {0}; // mark the visited cells
    for (int i=0; i<N; i++) {
        if(grid[0][i] == 0 && !visited[0][i]) { // check if an open cell exists in the top row
            visited[0][i] = 1; // mark as visited
            for(int j=1; j<N; j++) { // dfs traversal from the first row
                if(grid[j][i] == 0 && !visited[j][i]) { // check if an open cell is connected
                    visited[j][i] = 1; // mark as visited
                    if(j == N-1) { // check if the last row is reached
                        return 1; // percolates
                    }
                    if(i > 0) { // visit the left cell
                        visited[j][i-1] = 1;
                    }
                    if(i < N-1) { // visit the right cell
                        visited[j][i+1] = 1;
                    }
                }
            }
        }
    }
    return 0; // does not percolate
}

int main() {
    initGrid(); // initialize the percolation grid
    printf("Initial Grid:\n");
    printGrid(); // print the initial grid
    printf("\n");

    if (percolates()) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate!\n");
    }

    return 0;
}