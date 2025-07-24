//FormAI DATASET v1.0 Category: Game of Life ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 20
#define COLS 20

// define cell states for verification
#define DEAD 0
#define ALIVE 1

// function to print the game grid
void printGrid(int grid[][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(grid[i][j]) {
                printf("O");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("-------------\n");
}

// function to count living neighbors
int countNeighbors(int grid[][COLS], int x, int y) {
    int count = 0;
    // count top neighboring cell
    if(x > 0 && grid[x-1][y] == ALIVE) {
        count++;
    }
    // count bottom neighboring cell
    if(x < ROWS-1 && grid[x+1][y] == ALIVE) {
        count++;
    }
    // count left neighboring cell
    if(y > 0 && grid[x][y-1] == ALIVE) {
        count++;
    }
    // count right neighboring cell
    if(y < COLS-1 && grid[x][y+1] == ALIVE) {
        count++;
    }
    // count top-left neighboring cell
    if(x > 0 && y > 0 && grid[x-1][y-1] == ALIVE) {
        count++;
    }
    // count top-right neighboring cell
    if(x > 0 && y < COLS-1 && grid[x-1][y+1] == ALIVE) {
        count++;
    }
    // count bottom-left neighboring cell
    if(x < ROWS-1 && y > 0 && grid[x+1][y-1] == ALIVE) {
        count++;
    }
    // count bottom-right neighboring cell
    if(x < ROWS-1 && y < COLS-1 && grid[x+1][y+1] == ALIVE) {
        count++;
    }
    return count;
}

// main function
int main() {
    // initialize random seed
    srand(time(NULL));
    // initialize grid with random cell states
    int grid[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    // print initial grid
    printGrid(grid);
    // perform 100 iterations of game
    for(int i = 0; i < 100; i++) {
        // create new grid to track changes
        int newGrid[ROWS][COLS];
        // copy cell states from old grid to new grid
        for(int x = 0; x < ROWS; x++) {
            for(int y = 0; y < COLS; y++) {
                newGrid[x][y] = grid[x][y];
            }
        }
        // apply game rules to each cell
        for(int x = 0; x < ROWS; x++) {
            for(int y = 0; y < COLS; y++) {
                // count living neighbors
                int count = countNeighbors(grid, x, y);
                // apply rules to determine new state
                if(grid[x][y] == ALIVE) {
                    if(count < 2 || count > 3) {
                        newGrid[x][y] = DEAD;
                    }
                } else {
                    if(count == 3) {
                        newGrid[x][y] = ALIVE;
                    }
                }
            }
        }
        // update old grid with new grid
        for(int x = 0; x < ROWS; x++) {
            for(int y = 0; y < COLS; y++) {
                grid[x][y] = newGrid[x][y];
            }
        }
        // print new grid
        printGrid(grid);
    }
    return 0;
}