//FormAI DATASET v1.0 Category: Game of Life ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 50

// Function to initialize the grid randomly
void initGrid(int grid[][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            grid[i][j] = rand()%2;
        }
    }
}

// Function to print the grid
void printGrid(int grid[][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%c ", grid[i][j] ? '.' : ' ');
        }
        printf("\n");
    }
    printf("\n");
}

// Function to count the number of live neighbors of a cell
int countNeighbors(int grid[][COLS], int row, int col) {
    int count = 0;
    for(int i=row-1; i<=row+1; i++) {
        for(int j=col-1; j<=col+1; j++) {
            if(i>=0 && i<ROWS && j>=0 && j<COLS && grid[i][j]) {
                count++;
            }
        }
    }
    return count - grid[row][col];
}

// Function to update the grid according to the rules of the Game of Life
void updateGrid(int oldGrid[][COLS], int newGrid[][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int neighbors = countNeighbors(oldGrid, i, j);
            if(oldGrid[i][j]) { // cell is alive
                if(neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = 0; // cell dies
                } else {
                    newGrid[i][j] = 1; // cell lives
                }
            } else { // cell is dead
                if(neighbors == 3) {
                    newGrid[i][j] = 1; // cell is born
                } else {
                    newGrid[i][j] = 0; // cell stays dead
                }
            }
        }
    }
}

int main() {
    printf("Welcome to the Game of Life, Mr. Holmes.\n");
    printf("The game is about to begin...\n");

    int oldGrid[ROWS][COLS], newGrid[ROWS][COLS];
    initGrid(oldGrid);
    printGrid(oldGrid);

    int generation = 1;
    while(1) {
        printf("Generation %d:\n", generation);
        updateGrid(oldGrid, newGrid);
        printGrid(newGrid);

        // Check if the grid is stable (no changes between generations)
        int stable = 1;
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                if(oldGrid[i][j] != newGrid[i][j]) {
                    stable = 0;
                    break;
                }
            }
            if(!stable) {
                break;
            }
        }
        if(stable) {
            printf("The Game of Life has come to a stable state.\n");
            break;
        }

        // Copy the new grid into the old grid for the next iteration
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                oldGrid[i][j] = newGrid[i][j];
            }
        }

        generation++;
    }

    printf("The game is over, Mr. Holmes. It lasted for %d generations.\n", generation-1);

    return 0;
}