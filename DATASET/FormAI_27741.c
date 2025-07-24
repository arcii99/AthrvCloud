//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 20 // size of the grid
#define P 0.6 // probability that a cell is open


// define a structure for each cell
typedef struct {
    bool isOpen;
    bool isFull;
} cell;

// define a function to initialize the grid
void initializeGrid(cell grid[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            grid[i][j].isOpen = false;
            grid[i][j].isFull = false;
        }
    }
}

// define a function to populate the grid with open cells
void populateGrid(cell grid[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            double r = (double)rand() / (RAND_MAX);
            if(r < P){
                grid[i][j].isOpen = true;
            }
        }
    }
}

// define a function to check if a cell is valid and open
bool isValidCell(cell grid[N][N], int row, int col){
    if(row<0 || row>=N || col<0 || col>=N){
        return false;
    }
    if(!grid[row][col].isOpen){
        return false;
    }
    return true;
}

// define a recursive function to check if a cell is full
void fillCell(cell grid[N][N], int row, int col){

    grid[row][col].isFull = true;

    // recursively fill the neighboring cells if they are valid and not full
    if(isValidCell(grid, row-1, col) && !grid[row-1][col].isFull){
        fillCell(grid, row-1, col);
    }
    if(isValidCell(grid, row+1, col) && !grid[row+1][col].isFull){
        fillCell(grid, row+1, col);
    }
    if(isValidCell(grid, row, col-1) && !grid[row][col-1].isFull){
        fillCell(grid, row, col-1);
    }
    if(isValidCell(grid, row, col+1) && !grid[row][col+1].isFull){
        fillCell(grid, row, col+1);
    }
}

// define a function to check if there is a path between the top and bottom of the grid
bool percolates(cell grid[N][N]){

    // initialize the top row to be full
    for(int i=0;i<N;i++){
        if(grid[0][i].isOpen){
            fillCell(grid, 0, i);
        }
    }

    // check if any cell in the bottom row is full
    for(int i=0;i<N;i++){
        if(grid[N-1][i].isFull){
            return true;
        }
    }
    return false;
}

int main(){

    srand(time(NULL)); // seed the random number generator

    cell grid[N][N];
    initializeGrid(grid); // initialize the grid
    populateGrid(grid); // populate the grid with open cells

    printf("Original Grid:\n");
    // print the original grid
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j].isOpen){
                printf(" ");
            }
            else{
                printf("#");
            }
        }
        printf("\n");
    }

    bool result = percolates(grid);
    if(result){
        printf("\nThe grid percolates!\n");
    }
    else{
        printf("\nThe grid does not percolate.\n");
    }

    printf("\nFinal Grid:\n");
    // print the final grid with filled cells
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j].isOpen){
                if(grid[i][j].isFull){
                    printf("*");
                }
                else{
                    printf(" ");
                }
            }
            else{
                printf("#");
            }
        }
        printf("\n");
    }
    
    return 0;
}