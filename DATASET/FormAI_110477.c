//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define grid size and probability of cell being open
#define SIZE 20
#define PROBABILITY 0.6

// define grid cell structure
typedef struct {
    int row;
    int col;
    int open;
    int connected;
} cell;

// create 2D grid of cells
cell grid[SIZE][SIZE];

// declare function prototypes
void initializeGrid();
void printGrid();
void percolate();

// main function
int main() {
    // initialize random number generator
    srand(time(NULL));
    // initialize grid
    initializeGrid();
    // print original grid
    printf("Original Grid:\n");
    printGrid();
    // simulate percolation
    percolate();
    // print final grid
    printf("Final Grid:\n");
    printGrid();
    return 0;
}

// function to initialize grid
void initializeGrid() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            grid[i][j].row = i;
            grid[i][j].col = j;
            grid[i][j].open = (rand() < PROBABILITY * RAND_MAX) ? 1 : 0;
            grid[i][j].connected = 0;
        }
    }
}

// function to print grid
void printGrid() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", (grid[i][j].open) ? 'O' : 'X');
        }
        printf("\n");
    }
}

// function to percolate
void percolate() {
    int i, j, k, l, flag;
    // check if top and bottom are connected
    for (i = 0, flag = 0; i < SIZE && !flag; i++) {
        for (j = 0; j < SIZE; j++) {
            if (grid[i][j].open && grid[i][j].row == 0) {
                for (k = 0; k < SIZE; k++) {
                    for (l = 0; l < SIZE; l++) {
                        if (grid[k][l].open && grid[k][l].row == SIZE-1) {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag) break;
                }
                if (flag) break;
            }
        }
    }
    // if top and bottom are not connected, try to percolate
    if (!flag) {
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (grid[i][j].open) {
                    // check for neighbors
                    if (i > 0 && grid[i-1][j].open) {
                        grid[i][j].connected = 1;
                        grid[i-1][j].connected = 1;
                    }
                    if (i < SIZE-1 && grid[i+1][j].open) {
                        grid[i][j].connected = 1;
                        grid[i+1][j].connected = 1;
                    }
                    if (j > 0 && grid[i][j-1].open) {
                        grid[i][j].connected = 1;
                        grid[i][j-1].connected = 1;
                    }
                    if (j < SIZE-1 && grid[i][j+1].open) {
                        grid[i][j].connected = 1;
                        grid[i][j+1].connected = 1;
                    }
                }
            }
        }
        // check if top and bottom are connected
        for (i = 0, flag = 0; i < SIZE && !flag; i++) {
            for (j = 0; j < SIZE; j++) {
                if (grid[i][j].open && grid[i][j].row == 0) {
                    for (k = 0; k < SIZE; k++) {
                        for (l = 0; l < SIZE; l++) {
                            if (grid[k][l].open && grid[k][l].row == SIZE-1) {
                                flag = 1;
                                break;
                            }
                        }
                        if (flag) break;
                    }
                    if (flag) break;
                }
            }
        }
        // if top and bottom are still not connected, retry percolation
        if (!flag) {
            percolate();
        }
    }
}