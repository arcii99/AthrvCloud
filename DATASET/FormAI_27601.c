//FormAI DATASET v1.0 Category: Game of Life ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_X 50
#define GRID_Y 20
#define GENERATIONS 1000

// Function to initialize the grid randomly
void initializeGrid(int grid[][GRID_Y]) {
    srand(time(NULL));
    for(int i=0; i<GRID_X; i++) {
        for(int j=0; j<GRID_Y; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to print the grid
void printGrid(int grid[][GRID_Y]) {
    for(int i=0; i<GRID_Y; i++) {
        for(int j=0; j<GRID_X; j++) {
            if(grid[j][i]) {
                printf("# ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// Function to get the number of alive neighbors for a cell
int getAliveNeighbors(int grid[][GRID_Y], int x, int y) {
    int aliveNeighbors = 0;
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            if(i==0 && j==0) {
                continue;
            }
            int nx = x + i;
            int ny = y + j;
            if(nx>=0 && nx<GRID_X && ny>=0 && ny<GRID_Y && grid[nx][ny]) {
                aliveNeighbors++;
            }
        }
    }
    return aliveNeighbors;
}

// Function to update the grid to the next generation
void updateGrid(int grid[][GRID_Y]) {
    int nextGrid[GRID_X][GRID_Y];
    for(int i=0; i<GRID_X; i++) {
        for(int j=0; j<GRID_Y; j++) {
            int aliveNeighbors = getAliveNeighbors(grid, i, j);
            if(grid[i][j]) {
                if(aliveNeighbors==2 || aliveNeighbors==3) {
                    nextGrid[i][j] = 1;
                } else {
                    nextGrid[i][j] = 0;
                }
            } else {
                if(aliveNeighbors==3) {
                    nextGrid[i][j] = 1;
                } else {
                    nextGrid[i][j] = 0;
                }
            }
        }
    }
    for(int i=0; i<GRID_X; i++) {
        for(int j=0; j<GRID_Y; j++) {
            grid[i][j] = nextGrid[i][j];
        }
    }
}

int main() {
    int grid[GRID_X][GRID_Y];
    initializeGrid(grid);

    for(int i=0; i<GENERATIONS; i++) {
        system("clear");
        printf("Generation: %d\n", i+1);
        printGrid(grid);
        updateGrid(grid);
        usleep(100000);
    }

    return 0;
}