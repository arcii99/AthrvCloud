//FormAI DATASET v1.0 Category: Game of Life ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int grid[ROWS][COLS];
int nextGrid[ROWS][COLS];

void initializeGrids() {
    int i, j;
    // initialize the cells randomly
    srand(time(NULL));
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    // initialize the nextGrid
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            nextGrid[i][j] = 0;
        }
    }
}

void printGrid() {
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            if(grid[i][j] == 0) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int getNeighbourCount(int row, int col) {
    int i, j;
    int count = 0;
    for(i=-1; i<=1; i++) {
        for(j=-1; j<=1; j++) {
            int r = row + i;
            int c = col + j;
            if(r >= 0 && r < ROWS && c >= 0 && c < COLS && !(i == 0 && j == 0)) {
                count += grid[r][c];
            }
        }
    }
    return count;
}

void updateGrid() {
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            int count = getNeighbourCount(i, j);
            if(grid[i][j] == 1) {
                if(count < 2 || count > 3) {
                    nextGrid[i][j] = 0; // cell dies
                } else {
                    nextGrid[i][j] = 1; // cell survives
                }
            } else {
                if(count == 3) {
                    nextGrid[i][j] = 1; // new cell born
                } else {
                    nextGrid[i][j] = 0; // cell remains dead
                }
            }
        }
    }
    // copy the nextGrid to the grid
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            grid[i][j] = nextGrid[i][j];
        }
    }
}

int main() {
    int i;
    initializeGrids();
    for(i=0; i<100; i++) {
        system("clear"); // clear the screen
        printf("Generation #%d:\n", i+1);
        printGrid();
        updateGrid();
        usleep(50000); // wait for 50ms
    }
    return 0;
}