//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 12 // Grid size
#define P 0.6 // Probability of each cell being open
#define OFFSET 2 // Used to center the grid in the terminal

// Function to display the grid
void displayGrid(int grid[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(grid[i][j] == 0) printf(". "); // Closed cell
            else if(grid[i][j] == 1) printf("O "); // Open cell
            else printf("X "); // Percolating cluster
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    // Initializing the grid and filling it with closed cells
    int grid[N][N];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            grid[i][j] = 0;
        }
    }

    // Opening cells with probability P
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(((double) rand() / RAND_MAX) < P) {
                grid[i][j] = 1;
            }
        }
    }

    // Initializing a temporary copy of the grid
    int tempGrid[N][N];

    // Copying the grid to the temporary grid
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            tempGrid[i][j] = grid[i][j];
        }
    }

    // Initializing a boolean flag to check if the percolation cluster has reached the bottom row
    int percolation = 0;

    // Iterating until the percolation cluster reaches the bottom row
    while(!percolation) {
        // Checking each open cell to see if it is adjacent to a percolating cluster
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(grid[i][j] == 1) {
                    if(i == 0 || i == N-1 || j == 0 || j == N-1) {
                        // Marking the cell as part of the percolating cluster if it is on the boundary
                        tempGrid[i][j] = 2;
                        percolation = 1;
                    }
                    else if((tempGrid[i-1][j] == 2) || (tempGrid[i+1][j] == 2) || (tempGrid[i][j-1] == 2) || (tempGrid[i][j+1] == 2)) {
                        // Marking the cell as part of the percolating cluster if it is adjacent to a percolating cluster cell
                        tempGrid[i][j] = 2;
                        percolation = 1;
                    }
                }
            }
        }

        // Copying the temporary grid back to the original grid
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                grid[i][j] = tempGrid[i][j];
            }
        }
    }

    // Displaying the final grid
    printf("\nPERCOLATION SIMULATOR\n");
    printf("=====================\n");
    printf("Grid size: %d x %d\n", N, N);
    printf("Probability of each cell being open: %0.2f\n", P);
    printf("\n");
    displayGrid(grid);

    return 0;
}