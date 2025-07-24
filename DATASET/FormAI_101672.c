//FormAI DATASET v1.0 Category: Game of Life ; Style: shape shifting
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 40

// Initialize the grid with a random pattern
void initGrid(bool grid[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = (rand() % 2 == 0) ? true : false;
        }
    }
}

// Print the current state of the grid
void printGrid(bool grid[ROWS][COLS]) {
    printf("+");
    for(int i = 0; i < COLS; i++) {
        printf("-");
    }
    printf("+\n");
    for(int i = 0; i < ROWS; i++) {
        printf("|");
        for(int j = 0; j < COLS; j++) {
            printf("%c", grid[i][j] ? 'O' : ' ');
        }
        printf("|\n");
    }
    printf("+");
    for(int i = 0; i < COLS; i++) {
        printf("-");
    }
    printf("+\n");
}

// Get the total number of live neighbors for a specific cell in the grid
int getLiveNeighbors(bool grid[ROWS][COLS], int row, int col) {
    int count = 0;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            if(i == 0 && j == 0)
                continue;
            int r = row + i;
            int c = col + j;
            if(r < 0 || r >= ROWS || c < 0 || c >= COLS)
                continue;
            if(grid[r][c])
                count++;
        }
    }
    return count;
}

// Update the grid based on the Game of Life rules
void updateGrid(bool grid[ROWS][COLS]) {
    bool newGrid[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int liveNeighbors = getLiveNeighbors(grid, i, j);
            if(grid[i][j]) {
                if(liveNeighbors < 2 || liveNeighbors > 3)
                    newGrid[i][j] = false;
                else
                    newGrid[i][j] = true;
            } else {
                if(liveNeighbors == 3)
                    newGrid[i][j] = true;
                else
                    newGrid[i][j] = false;
            }
        }
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    bool grid[ROWS][COLS];
    srand(time(NULL));
    initGrid(grid);
    printf("Game of Life\n");
    printf("Press Ctrl+C to exit\n");
    while(true) {
        printGrid(grid);
        updateGrid(grid);
        printf("\033[2J"); // Clear the console
        printf("\033[H"); // Move cursor to the top left corner of the console
    }
    return 0;
}