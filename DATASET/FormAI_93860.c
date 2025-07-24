//FormAI DATASET v1.0 Category: Game of Life ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int grid[ROWS][COLS]; // the main grid
int tempGrid[ROWS][COLS]; // temporary grid to store updated cells

// function to initialize the grid with random live or dead cells
void initializeGrid() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// function to display the grid
void printGrid() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// function to count the number of live neighbors of a cell
int countLiveNeighbors(int row, int col) {
    int count = 0;
    int i, j;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            int neighborRow = row + i;
            int neighborCol = col + j;
            if (neighborRow >= ROWS) {
                neighborRow = 0;
            } else if (neighborRow < 0) {
                neighborRow = ROWS - 1;
            }
            if (neighborCol >= COLS) {
                neighborCol = 0;
            } else if (neighborCol < 0) {
                neighborCol = COLS - 1;
            }
            count += grid[neighborRow][neighborCol];
        }
    }
    count -= grid[row][col]; // exclude the center cell
    return count;
}

// function to update the cells according to the rules of the Game of Life
void updateGrid() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            int liveNeighbors = countLiveNeighbors(i, j);
            if (grid[i][j] == 1) { // if cell is alive
                if (liveNeighbors < 2 || liveNeighbors > 3) { // underpopulation or overpopulation
                    tempGrid[i][j] = 0; // the cell dies
                } else {
                    tempGrid[i][j] = 1; // the cell survives
                }
            } else { // if cell is dead
                if (liveNeighbors == 3) { // reproduction
                    tempGrid[i][j] = 1; // a new cell is born
                } else {
                    tempGrid[i][j] = 0; // the cell remains dead
                }
            }
        }
    }
    // copy the updated cells to the main grid
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = tempGrid[i][j];
        }
    }
}

int main() {
    initializeGrid();
    printGrid();
    printf("\n");
    int i;
    for (i = 0; i < 10; i++) {
        updateGrid();
        printGrid();
        printf("\n");
    }
    return 0;
}