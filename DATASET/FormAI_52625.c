//FormAI DATASET v1.0 Category: Game of Life ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLS 60
#define GENERATIONS 100

int grid[ROWS][COLS];
int newGrid[ROWS][COLS];

void seedGrid() {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            grid[i][j] = rand()%2;
        }
    }
}

void printGrid() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(grid[i][j]) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int countNeighbors(int row, int col) {
    int count = 0;
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            int r = (row+i+ROWS)%ROWS;
            int c = (col+j+COLS)%COLS;
            if(grid[r][c]) {
                count++;
            }
        }
    }
    if(grid[row][col]) {
        count--;
    }
    return count;
}

void updateGrid() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int neighbors = countNeighbors(i,j);
            if(grid[i][j] && neighbors<2) {
                newGrid[i][j] = 0; // Underpopulation
            } else if(grid[i][j] && (neighbors==2 || neighbors==3)) {
                newGrid[i][j] = 1; // Survival
            } else if(grid[i][j] && neighbors>3) {
                newGrid[i][j] = 0; // Overpopulation
            } else if(!grid[i][j] && neighbors==3) {
                newGrid[i][j] = 1; // Reproduction
            } else {
                newGrid[i][j] = grid[i][j];
            }
        }
    }
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    seedGrid();
    printf("Initial Grid:\n");
    printGrid();
    for(int g=1; g<=GENERATIONS; g++) {
        printf("Generation %d\n", g);
        updateGrid();
        printGrid();
    }
    return 0;
}