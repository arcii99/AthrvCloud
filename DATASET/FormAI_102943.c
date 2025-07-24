//FormAI DATASET v1.0 Category: Game of Life ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 20
#define COLS 20

bool grid[ROWS][COLS];
bool nextGeneration[ROWS][COLS];

void initializeGrid(){
    int i, j;
    srand(time(0));
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            grid[i][j] = rand() % 2;
        }
    }
}

int countNeighbors(int row, int col){
    int i, j;
    int count = 0;
    for(i = -1; i <= 1; i++){
        for(j = -1; j <= 1; j++){
            if(i == 0 && j == 0){
                continue;
            }
            int neighborRow = row + i;
            int neighborCol = col + j;
            if(neighborRow < 0){
                neighborRow = ROWS - 1;
            }
            if(neighborRow >= ROWS){
                neighborRow = 0;
            }
            if(neighborCol < 0){
                neighborCol = COLS - 1;
            }
            if(neighborCol >= COLS){
                neighborCol = 0;
            }
            if(grid[neighborRow][neighborCol]){
                count++;
            }
        }
    }
  return count;
}

void updateGrid(){
    int i, j;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            int numNeighbors = countNeighbors(i, j);
            if(grid[i][j]){
                if(numNeighbors < 2 || numNeighbors > 3){
                    nextGeneration[i][j] = false;
                }
                else{
                    nextGeneration[i][j] = true;
                }
            }
            else{
                if(numNeighbors == 3){
                    nextGeneration[i][j] = true;
                }
                else{
                    nextGeneration[i][j] = false;
                }
            }
        }
    }
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            grid[i][j] = nextGeneration[i][j];
        }
    }
}

void printGrid(){
    int i, j;
    printf("\n");
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            if(grid[i][j]){
                printf("*");
            }
            else{
                printf("-");
            }
        }
        printf("\n");
    }
}

int main(){
    initializeGrid();
    while(1){
        printGrid();
        updateGrid();
        usleep(100000);
    }
    return 0;
}