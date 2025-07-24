//FormAI DATASET v1.0 Category: Game of Life ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 30
#define COLS 60

// Function prototypes
void initGrid(char grid[ROWS][COLS]);
void printGrid(char grid[ROWS][COLS]);
void updateGrid(char grid[ROWS][COLS]);

int main() {
    char grid[ROWS][COLS];

    // Initialize the grid
    initGrid(grid);

    // Main game loop
    while(1) {
        printf("\033[H\033[J"); // Clear the screen
        printGrid(grid);
        updateGrid(grid);
        usleep(100000); // Sleep for 0.1 seconds
    }

    return 0;
}

// Initialize the grid randomly
void initGrid(char grid[ROWS][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2 ? 'X' : ' ';
        }
    }
}

// Print the grid to the console
void printGrid(char grid[ROWS][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

// Update the grid based on the Game of Life rules
void updateGrid(char grid[ROWS][COLS]) {
    int i, j, count;
    char newGrid[ROWS][COLS];

    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            // Count the number of live neighbors
            count = 0;
            if(grid[(i-1+ROWS)%ROWS][(j-1+COLS)%COLS] == 'X') count++;
            if(grid[(i-1+ROWS)%ROWS][j] == 'X') count++;
            if(grid[(i-1+ROWS)%ROWS][(j+1)%COLS] == 'X') count++;
            if(grid[i][(j-1+COLS)%COLS] == 'X') count++;
            if(grid[i][(j+1)%COLS] == 'X') count++;
            if(grid[(i+1)%ROWS][(j-1+COLS)%COLS] == 'X') count++;
            if(grid[(i+1)%ROWS][j] == 'X') count++;
            if(grid[(i+1)%ROWS][(j+1)%COLS] == 'X') count++;

            // Apply the Game of Life rules
            if(grid[i][j] == 'X') {
                if(count < 2 || count > 3) {
                    newGrid[i][j] = ' ';
                } else {
                    newGrid[i][j] = 'X';
                }
            } else {
                if(count == 3) {
                    newGrid[i][j] = 'X';
                } else {
                    newGrid[i][j] = ' ';
                }
            }
        }
    }

    // Copy the new grid over to the old grid
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}