//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define ROWS 20
#define COLS 20

//Function to print the current state of the grid
void printGrid(bool grid[ROWS][COLS], int row, int col) {
    int i, j;

    for(i=0;i<row;i++) {
        for(j=0;j<col;j++) {
            if(grid[i][j]) 
                printf("O ");
            else 
                printf(". ");
        }
        printf("\n");
    }
}

//Function to check if a cell is valid
bool isAdjacent(int x, int y, int row, int col) {
    if(x>=0 && y>=0 && x<row && y<col)
        return true;

    return false;
}

//Function to check if the grid has percolated
bool isPercolated(bool grid[ROWS][COLS], int size) {
    int i;

    for(i=0;i<size;i++) {
        if(grid[size-1][i])
            return true;
    }
    
    return false;
}

//Function to percolate the grid
void percolate(bool grid[ROWS][COLS], int row, int col) {
    int i, j, x, y;
    bool newGrid[ROWS][COLS];

    while(!isPercolated(grid, row)) {
        for(i=0;i<row;i++) {
            for(j=0;j<col;j++) {
                newGrid[i][j]=grid[i][j];
                if(grid[i][j]) {
                    x=i+1, y=j;
                    if(isAdjacent(x, y, row, col) && !newGrid[x][y]) {
                        newGrid[x][y]=true;
                        if(isPercolated(newGrid, row)) {
                            printGrid(newGrid, row, col);
                            return;
                        }
                    }

                    x=i-1, y=j;
                    if(isAdjacent(x, y, row, col) && !newGrid[x][y]) {
                        newGrid[x][y]=true;
                        if(isPercolated(newGrid, row)) {
                            printGrid(newGrid, row, col);
                            return;
                        }
                    }

                    x=i, y=j+1;
                    if(isAdjacent(x, y, row, col) && !newGrid[x][y]) {
                        newGrid[x][y]=true;
                        if(isPercolated(newGrid, row)) {
                            printGrid(newGrid, row, col);
                            return;
                        }
                    }

                    x=i, y=j-1;
                    if(isAdjacent(x, y, row, col) && !newGrid[x][y]) {
                        newGrid[x][y]=true;
                        if(isPercolated(newGrid, row)) {
                            printGrid(newGrid, row, col);
                            return;
                        }
                    }
                }
            }
        }
        printGrid(newGrid, row, col);
        usleep(100000); //To give a cool animation effect
        printf("\033[H\033[J"); //Clear the screen
        memcpy(grid, newGrid, sizeof(newGrid));
    }
}

int main() {
    srand(time(NULL));
    bool grid[ROWS][COLS];

    int i, j;

    for(i=0;i<ROWS;i++) {
        for(j=0;j<COLS;j++) {
            int r=rand()%2;
            if(r==1) 
                grid[i][j]=true;
            else 
                grid[i][j]=false;
        }
    }

    printGrid(grid, ROWS, COLS);
    printf("Starting Percolation simulation...\n");
    percolate(grid, ROWS, COLS);

    return 0;
}