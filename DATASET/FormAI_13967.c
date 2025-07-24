//FormAI DATASET v1.0 Category: Game of Life ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLUMNS 50

// Function to initialize the grid randomly
void initGrid(int grid[][COLUMNS]) {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to check the neighbors of each cell
int countNeighbors(int grid[][COLUMNS], int x, int y) {
    int count = 0;
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            int row = (x+i+ROWS) % ROWS;
            int col = (y+j+COLUMNS) % COLUMNS;
            count += grid[row][col];
        }
    }
    count -= grid[x][y];
    return count;
}

// Function to update the grid based on the rules of Game of Life
void updateGrid(int grid[][COLUMNS]) {
    int newGrid[ROWS][COLUMNS];
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            int neighbors = countNeighbors(grid, i, j);
            if(grid[i][j] == 1) {
                if(neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = 0;
                }
                else {
                    newGrid[i][j] = 1;
                }
            }
            else {
                if(neighbors == 3) {
                    newGrid[i][j] = 1;
                }
                else {
                    newGrid[i][j] = 0;
                }
            }
        }
    }
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

// Function to print the grid in an artistic way
void printGrid(int grid[][COLUMNS]) {
    printf("\033[2J\033[1;1H"); // clears the screen
    printf("╔═%s═╗\n", "═════════════════════════════════════");
    for(int i=0; i<ROWS; i++) {
        printf("║ ");
        for(int j=0; j<COLUMNS; j++) {
            if(grid[i][j] == 1) {
                printf("\033[48;2;255;0;0m  \033[0m"); // prints a red square
            }
            else {
                printf("  ");
            }
        }
        printf(" ║\n");
    }
    printf("╚═%s═╝\n", "═════════════════════════════════════");
}

int main() {
    int grid[ROWS][COLUMNS];
    initGrid(grid);
    while(1) {
        printGrid(grid);
        updateGrid(grid);
        usleep(2000); // waits for 2000 microseconds before next update
    }
    return 0;
}