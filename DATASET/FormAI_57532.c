//FormAI DATASET v1.0 Category: Game of Life ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// initialize the grid with random values
void initializeGrid(int grid[][10]) {
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            grid[i][j] = rand()%2;
        }
    }
}

// display the current state of the grid
void printGrid(int grid[][10]) {
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            if(grid[i][j] == 1) printf("X");
            else printf("-");
        }
        printf("\n");
    }
    printf("\n");
}

// find the number of live neighbors of a given cell
int countLiveNeighbors(int grid[][10], int row, int col) {
    int count = 0;
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            int r = row+i;
            int c = col+j;
            if(r >= 0 && r < 10 && c >= 0 && c < 10) {
                count += grid[r][c];
            }
        }
    }
    count -= grid[row][col];
    return count;
}

// update the grid based on the rules of the Game of Life
void updateGrid(int grid[][10]) {
    int newGrid[10][10];
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            int liveNeighbors = countLiveNeighbors(grid, i, j);
            if(grid[i][j] == 1) {
                if(liveNeighbors < 2) newGrid[i][j] = 0;
                else if(liveNeighbors <= 3) newGrid[i][j] = 1;
                else newGrid[i][j] = 0;
            }
            else {
                if(liveNeighbors == 3) newGrid[i][j] = 1;
                else newGrid[i][j] = 0;
            }
        }
    }
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

// main function to run the Game of Life
int main() {
    int grid[10][10];
    srand(time(NULL));
    initializeGrid(grid);
    printf("Initial state: \n");
    printGrid(grid);
    for(int i=0; i<10; i++) {
        updateGrid(grid);
        printf("State after step %d: \n", i+1);
        printGrid(grid);
    }
    return 0;
}