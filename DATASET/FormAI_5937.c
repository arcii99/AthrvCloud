//FormAI DATASET v1.0 Category: Game of Life ; Style: romantic
#include<stdio.h>
#include<stdlib.h>

// define size of the grid
#define ROW 10
#define COL 10

// function to initialize grid with random values
void initGrid(int grid[][COL]) {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// function to print the grid
void printGrid(int grid[][COL]) {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            printf("%c ", grid[i][j] ? '*' : ' ');
        }
        printf("\n");
    }
    printf("\n");
}

// function to count number of living neighbors
int countNeighbors(int grid[][COL], int x, int y) {
    int count = 0;
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            int row = (x+i+ROW) % ROW;
            int col = (y+j+COL) % COL;
            count += grid[row][col];
        }
    }
    count -= grid[x][y];
    return count;
}

// function to update the grid based on the rules of the game
void updateGrid(int grid[][COL]) {
    int newGrid[ROW][COL];
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            int neighbors = countNeighbors(grid, i, j);
            if(grid[i][j] == 1 && neighbors < 2) {
                newGrid[i][j] = 0; // dies of loneliness
            }
            else if(grid[i][j] == 1 && neighbors > 3) {
                newGrid[i][j] = 0; // dies of overcrowding
            }
            else if(grid[i][j] == 0 && neighbors == 3) {
                newGrid[i][j] = 1; // new cell born
            }
            else {
                newGrid[i][j] = grid[i][j]; // cell remains the same
            }
        }
    }
    // update original grid
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    int grid[ROW][COL];
    initGrid(grid);
    printGrid(grid);
    while(1) {
        updateGrid(grid);
        printGrid(grid);
    }
    return 0;
}