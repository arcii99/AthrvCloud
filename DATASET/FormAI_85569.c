//FormAI DATASET v1.0 Category: Game of Life ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 75

int grid[ROWS][COLS];

void initGrid(){
    int i, j;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            grid[i][j] = rand() % 2;
        }
    }
}

void printGrid(){
    int i, j;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            if(grid[i][j] == 1) printf("#");
            else printf(" ");
        }
        printf("\n");
    }
}

int countNeighbours(int row, int col){
    int i, j;
    int count = 0;
    for(i=-1;i<=1;i++){
        for(j=-1;j<=1;j++){
            if(i == 0 && j == 0) continue;
            if(row+i < 0 || row+i >= ROWS || col+j < 0 || col+j >= COLS) continue;
            count += grid[row+i][col+j];
        }
    }
    return count;
}

void nextGeneration(){
    int i, j, neighbours;
    int newGrid[ROWS][COLS];
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            neighbours = countNeighbours(i,j);
            if(grid[i][j] == 1){
                if(neighbours < 2 || neighbours > 3) newGrid[i][j] = 0;
                else newGrid[i][j] = 1;
            }
            else{
                if(neighbours == 3) newGrid[i][j] = 1;
                else newGrid[i][j] = 0;
            }
        }
    }
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main(){
    srand(time(NULL));
    initGrid();
    while(1){
        system("cls");
        printGrid();
        nextGeneration();
        sleep(1);
    }
    return 0;
}