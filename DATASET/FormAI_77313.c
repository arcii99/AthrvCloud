//FormAI DATASET v1.0 Category: Game of Life ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define GENERATIONS 20

void printGrid(int grid[ROWS][COLS]);

void initGrid(int grid[ROWS][COLS]){
    srand(time(NULL)); // seed the random number generator
    // populate the grid randomly with 0's and 1's
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            grid[i][j] = rand()%2;
        }
    }
}

int getNeighbourCount(int grid[ROWS][COLS], int x, int y){
    int count = 0;
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i==0 && j==0) continue; // skip the cell itself
            int row = (x+i+ROWS)%ROWS; // handle edge cases by wrapping
            int col = (y+j+COLS)%COLS;
            count += grid[row][col];
        }
    }
    return count;
}

void updateGrid(int grid[ROWS][COLS]){
    int newGrid[ROWS][COLS];
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            int count = getNeighbourCount(grid, i, j);
            if(grid[i][j] == 0 && count == 3){
                newGrid[i][j] = 1; // dead cell with 3 neighbours comes to life
            }
            else if(grid[i][j] == 1 && (count < 2 || count > 3)){
                newGrid[i][j] = 0; // living cell with less than 2 or more than 3 neighbours dies
            }
            else{
                newGrid[i][j] = grid[i][j]; // cell remains the same
            }
        }
    }
    // copy the new grid over to the old grid
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            grid[i][j] = newGrid[i][j];
        }
    }
}

void printGrid(int grid[ROWS][COLS]){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(grid[i][j]){
                printf("o ");
            }
            else{
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main(){
    int grid[ROWS][COLS];
    initGrid(grid);
    for(int i=0; i<GENERATIONS; i++){
        printf("Generation: %d\n", i);
        printGrid(grid);
        updateGrid(grid);
    }
    return 0;
}