//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize variables
    int size, threshold;
    printf("Enter the size of the grid: ");
    scanf("%d", &size);
    printf("Enter the threshold: ");
    scanf("%d", &threshold);
    
    // Seed random number generator
    srand(time(0));

    // Create grid array
    int grid[size][size];

    // Initialize top row to open
    for(int i = 0; i < size; i++) {
        grid[0][i] = 1;
    }

    // Initialize rest of the grid randomly
    for(int i = 1; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(rand() % 100 < threshold) {
                grid[i][j] = 1;
            }
            else {
                grid[i][j] = 0;
            }
        }
    }

    // Print out initial grid
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(grid[i][j] == 1) {
                printf(" ");
            }
            else {
                printf("#");
            }
        }
        printf("\n");
    }

    // Percolation algorithm
    for(int i = 1; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(grid[i][j] == 1) {
                if(grid[i-1][j] == 1) {
                    grid[i][j] = 1; // Cell percolates
                }
                else if(j > 0 && grid[i-1][j-1] == 1) {
                    grid[i][j] = 1; // Cell percolates
                }
                else if(j < size-1 && grid[i-1][j+1] == 1) {
                    grid[i][j] = 1; // Cell percolates
                }
            }
        }
    }

    // Print out final grid
    printf("\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(grid[i][j] == 1) {
                printf(" ");
            }
            else {
                printf("#");
            }
        }
        printf("\n");
    }

    return 0;
}