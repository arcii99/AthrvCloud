//FormAI DATASET v1.0 Category: Game of Life ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

// function to print the current state of the grid
void print_grid(int grid[ROWS][COLS]) { 
    printf("\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(grid[i][j] == 1) {
                printf("X");
            }
            else {
                printf("-");
            }
        }
        printf("\n");
    }
}

// function to count the number of live neighbors around a cell
int count_neighbors(int grid[ROWS][COLS], int row, int col) {
    int count = 0;
    for(int i = row-1; i <= row+1; i++) {
        for(int j = col-1; j <= col+1; j++) {
            if(i >= 0 && i < ROWS && j >= 0 && j < COLS) {
                if(i != row || j != col) {
                    if(grid[i][j] == 1) {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    // initialize the grid with zeros
    int grid[ROWS][COLS] = {0};

    // initialize the random number generator
    srand(time(NULL));

    // randomly set some cells to be alive initially
    for(int i = 0; i < ROWS*COLS/4; i++) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        grid[row][col] = 1;
    }

    // print the initial state of the grid
    print_grid(grid);

    // simulate the game of life for 10 generations
    for(int gen = 1; gen <= 10; gen++) { 
        // create a new copy of the grid for the next generation
        int new_grid[ROWS][COLS];

        // loop over every cell in the grid and update its state
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                int state = grid[i][j];
                int neighbors = count_neighbors(grid, i, j);
                if(state == 1 && neighbors < 2) {
                    new_grid[i][j] = 0; // cell dies of loneliness
                }
                else if(state == 1 && neighbors > 3) {
                    new_grid[i][j] = 0; // cell dies of overcrowding
                }
                else if(state == 0 && neighbors == 3) {
                    new_grid[i][j] = 1; // cell is born
                }
                else {
                    new_grid[i][j] = state; // cell stays the same
                }
            }
        }

        // copy the new grid over to the old grid for the next generation
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }

        // print the current state of the grid
        print_grid(grid);
    }

    return 0;
}