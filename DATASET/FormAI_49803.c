//FormAI DATASET v1.0 Category: Educational ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    srand(time(NULL)); // initialize random seed
    
    int i, j, k, n;
    int grid[10][10]; // declare a 10x10 grid
    
    // initialize the grid with random values 0 or 1
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    
    // print the initial grid
    printf("Initial Grid:\n");
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    
    // user selects the number of generations
    printf("Enter the number of generations: ");
    scanf("%d", &n);
    
    // simulate the game of life for n generations
    for(k=0; k<n; k++) {
        int next_grid[10][10];
        for(i=0; i<10; i++) {
            for(j=0; j<10; j++) {
                int neighbors = 0;
                if(i>0 && grid[i-1][j]==1) neighbors++;
                if(j>0 && grid[i][j-1]==1) neighbors++;
                if(i<9 && grid[i+1][j]==1) neighbors++;
                if(j<9 && grid[i][j+1]==1) neighbors++;
                if(i>0 && j>0 && grid[i-1][j-1]==1) neighbors++;
                if(i>0 && j<9 && grid[i-1][j+1]==1) neighbors++;
                if(i<9 && j>0 && grid[i+1][j-1]==1) neighbors++;
                if(i<9 && j<9 && grid[i+1][j+1]==1) neighbors++;
                if(grid[i][j]==1 && (neighbors<2 || neighbors>3)) {
                    next_grid[i][j] = 0;
                } else if(grid[i][j]==0 && neighbors==3) {
                    next_grid[i][j] = 1;
                } else {
                    next_grid[i][j] = grid[i][j];
                }
            }
        }
        // update the grid for the next generation
        for(i=0; i<10; i++) {
            for(j=0; j<10; j++) {
                grid[i][j] = next_grid[i][j];
            }
        }
        // print the current state of the grid
        printf("\nGeneration %d:\n", k+1);
        for(i=0; i<10; i++) {
            for(j=0; j<10; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}