//FormAI DATASET v1.0 Category: Game of Life ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int grid[ROWS][COLS];
int temp_grid[ROWS][COLS];

void generateGrid(){
    srand(time(NULL));
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            grid[i][j] = rand() % 2;
        }
    }
}

void printGrid(){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            if(grid[i][j] == 0){
                printf("-");
            }
            else{
                printf("*");
            }
        }
        printf("\n");
    }
}

int countLiveNeighbors(int x, int y){
    int count = 0;
    for(int i=x-1;i<=x+1;i++){
        for(int j=y-1;j<=y+1;j++){
            if((i >= 0 && i < ROWS) && (j >= 0 && j < COLS) && !(i == x && j == y)){
                count += grid[i][j];
            }
        }
    }
    return count;
}

void simulateOneGeneration(){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            int liveNeighbors = countLiveNeighbors(i, j);
            if(grid[i][j] == 1 && liveNeighbors < 2){
                // Underpopulation
                temp_grid[i][j] = 0;
            }
            else if(grid[i][j] == 1 && (liveNeighbors == 2 || liveNeighbors == 3)){
                // Survive
                temp_grid[i][j] = 1;
            }
            else if(grid[i][j] == 1 && liveNeighbors > 3){
                // Overpopulation
                temp_grid[i][j] = 0;
            }
            else if(grid[i][j] == 0 && liveNeighbors == 3){
                // Reproduction
                temp_grid[i][j] = 1;
            }
            else{
                temp_grid[i][j] = grid[i][j];
            }
        }
    }
    // Copy temp grid to actual grid
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            grid[i][j] = temp_grid[i][j];
        }
    }
}

int main(){
    generateGrid();
    printf("Initial Grid:\n");
    printGrid();

    for(int i=0;i<5;i++){
        simulateOneGeneration();
        printf("Generation %d:\n", i+1);
        printGrid();
    }

    return 0;
}