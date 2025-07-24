//FormAI DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define the grid dimensions
#define ROWS 20
#define COLS 50

// function prototypes
void initializeGrid(int grid[ROWS][COLS]);
void printGrid(int grid[ROWS][COLS]);

int main() {
    srand(time(NULL)); // initialize the random seed based on the current time
    int grid[ROWS][COLS];
    initializeGrid(grid); // initialize grid with random live cells
    
    while(1) { // loop indefinitely
        system("clear"); // clear the console screen
        printGrid(grid); // print the current grid to console
        usleep(100000); // wait for 100 milliseconds (updated 10 times per second)
        
        // update the grid based on the Game of Life rules
        int newGrid[ROWS][COLS];
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                // count the number of live neighbors
                int liveNeighbors = 0;
                for(int x=-1; x<=1; x++) {
                    for(int y=-1; y<=1; y++) {
                        if(i+x>=0 && i+x<ROWS && j+y>=0 && j+y<COLS) { // check if neighbor is within bounds
                            liveNeighbors += grid[i+x][j+y];
                        }
                    }
                }
                liveNeighbors -= grid[i][j]; // subtract self (don't count self as neighbor)
                
                // determine if cell is alive, dead, or reborn based on live neighbor count
                if(grid[i][j] == 1 && (liveNeighbors == 2 || liveNeighbors == 3)) {
                    newGrid[i][j] = 1; // cell stays alive
                }
                else if(grid[i][j] == 0 && liveNeighbors == 3) {
                    newGrid[i][j] = 1; // cell is reborn
                }
                else {
                    newGrid[i][j] = 0; // cell dies
                }
            }
        }
        // assign new grid to current grid
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                grid[i][j] = newGrid[i][j];
            }
        }
    }
    return 0;
}

void initializeGrid(int grid[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            grid[i][j] = rand() % 2; // assign random live (1) or dead (0) value to each cell
        }
    }
}

void printGrid(int grid[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(grid[i][j] == 1) {
                printf("*"); // live cell
            }
            else {
                printf("."); // dead cell
            }
        }
        printf("\n"); // move to next row
    }
}