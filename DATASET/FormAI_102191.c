//FormAI DATASET v1.0 Category: Game of Life ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Size of the grid
#define ROWS 20
#define COLS 20

// Function to randomly initialize the grid
void initGrid(int grid[][COLS]){
    int i, j;
    srand(time(NULL)); // Seed the random number generator

    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            grid[i][j] = rand() % 2; // Randomly initialize each cell to 0 or 1
        }
    }
}

// Function to print the grid
void printGrid(int grid[][COLS]){
    int i, j;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            if(grid[i][j] == 0){
                printf(".");
            }else{
                printf("*");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to count the number of living neighbors of cell (i,j)
int countNeighbors(int grid[][COLS], int i, int j){
    int count = 0;
    int row, col;

    // Loop through all 8 neighbors (except for the center cell)
    for(row=i-1;row<=i+1;row++){
        for(col=j-1;col<=j+1;col++){
            if(row>=0 && row<ROWS && col>=0 && col<COLS && !(row==i && col==j)){
                count += grid[row][col];
            }
        }
    }

    return count;
}

// Function to update the grid for the next generation
void updateGrid(int grid[][COLS]){
    int i, j;
    int neighbors;
    int nextGrid[ROWS][COLS]; // Keep track of the next generation

    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            neighbors = countNeighbors(grid, i, j);

            // Apply the rules of the Game of Life
            if(grid[i][j] == 0 && neighbors == 3){
                nextGrid[i][j] = 1;
            }else if(grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)){
                nextGrid[i][j] = 0;
            }else{
                nextGrid[i][j] = grid[i][j];
            }
        }
    }

    // Copy the next generation back into the original grid
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            grid[i][j] = nextGrid[i][j];
        }
    }
}

int main(){
    int grid[ROWS][COLS];

    initGrid(grid);

    while(1){ // Loop forever, printing and updating the grid
        printGrid(grid);
        updateGrid(grid);
        usleep(100000); // Sleep for 100000 microseconds (0.1 seconds)
    }

    return 0;
}