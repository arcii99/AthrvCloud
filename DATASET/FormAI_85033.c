//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20 // size of grid
#define WATER_FILL_PROB 40 // probability of water filling cells
#define MAX_ITERATIONS 1000 // max number of iterations
#define SLEEP_TIME 100000 // time to sleep between iterations in microseconds

// function to print the grid
void printGrid(int grid[GRID_SIZE][GRID_SIZE]) {
    for(int i=0; i<GRID_SIZE; i++) {
        for(int j=0; j<GRID_SIZE; j++) {
            switch(grid[i][j]) {
                case 0:
                    printf("_ ");
                    break;
                case 1:
                    printf("~ ");
                    break;
                case 2:
                    printf("░░");
                    break;
                case 3:
                    printf("▓▓");
                    break;
                case 4:
                    printf("██");
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

// function to check if the cell is at the border of the grid
int isBorderCell(int x, int y) {
    if(x==0 || x==GRID_SIZE-1 || y==0 || y==GRID_SIZE-1) {
        return 1;
    } else {
        return 0;
    }
}

// function to check if the cell has water neighboring cells
int hasWaterNeighbour(int grid[GRID_SIZE][GRID_SIZE], int x, int y) {
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            if(grid[x+i][y+j]==1) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE];

    // set all cells to empty
    for(int i=0; i<GRID_SIZE; i++) {
        for(int j=0; j<GRID_SIZE; j++) {
            grid[i][j] = 0;
        }
    }

    // fill border cells with solid ground
    for(int i=0; i<GRID_SIZE; i++) {
        grid[i][0] = 4;
        grid[i][GRID_SIZE-1] = 4;
    }
    for(int j=0; j<GRID_SIZE; j++) {
        grid[0][j] = 4;
        grid[GRID_SIZE-1][j] = 4;
    }

    // fill random cells with water
    srand(time(0));
    for(int i=1; i<GRID_SIZE-1; i++) {
        for(int j=1; j<GRID_SIZE-1; j++) {
            if(rand()%100 < WATER_FILL_PROB) {
                grid[i][j] = 1;
            }
        }
    }

    // simulate water percolation
    int iteration = 0;
    int percolates = 0;
    while(iteration < MAX_ITERATIONS && !percolates) {
        for(int i=1; i<GRID_SIZE-1; i++) {
            for(int j=1; j<GRID_SIZE-1; j++) {
                if(grid[i][j]==1 && (isBorderCell(i,j) || hasWaterNeighbour(grid,i,j))) {
                    grid[i][j] = 2; // mark cell as flowing
                    if(isBorderCell(i,j)) {
                        percolates = 1; // grid has percolated, stop simulation
                    }
                }
            }
        }
        
        // print current state of grid
        printf("Iteration %d:\n", iteration+1);
        printGrid(grid);
        usleep(SLEEP_TIME); // sleep to see the animation

        for(int i=1; i<GRID_SIZE-1; i++) {
            for(int j=1; j<GRID_SIZE-1; j++) {
                if(grid[i][j]==2) {
                    grid[i][j] = 3; // mark cell as solid
                }
            }
        }

        iteration++;
    }

    // print final state of grid
    printf("Final state:\n");
    printGrid(grid);

    // print if grid percolates or not
    if(percolates) {
        printf("The grid has percolated!");
    } else {
        printf("The grid has not percolated!");
    }

    return 0;
}