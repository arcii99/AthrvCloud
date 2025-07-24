//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Function to print the grid
void printGrid(int grid[ROWS][COLS]){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a site is open
int isOpen(int grid[ROWS][COLS], int i, int j){
    return grid[i][j] == 1;
}

// Function to check if a site is full
int isFull(int grid[ROWS][COLS], int i, int j){
    if(i<0 || i>=ROWS || j<0 || j>=COLS){
        return 0;
    }
    if(grid[i][j] == -1 || grid[i][j] == 0){
        return 0;
    }
    grid[i][j] = -1;
    return isFull(grid, i+1, j) || isFull(grid, i-1, j) || isFull(grid, i, j+1) || isFull(grid, i, j-1);
}

// Function to percolate
int percolate(int grid[ROWS][COLS]){
    for(int j=0;j<COLS;j++){
        if(isFull(grid, 0, j)){
            return 1;
        }
    }
    return 0;
}

int main(){
    int grid[ROWS][COLS];
    srand(time(NULL));
    // Initialize the grid randomly (open sites are represented with 1's)
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            if(rand()%2 == 0){
                grid[i][j] = 1;
            }else{
                grid[i][j] = 0;
            }
        }
    }
    printf("Initial Grid:\n");
    printGrid(grid);
    printf("\n");
    if(percolate(grid)){
        printf("The grid percolates!\n");
    }else{
        printf("The grid does not percolate.\n");
    }
    return 0;
}