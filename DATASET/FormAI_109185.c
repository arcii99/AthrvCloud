//FormAI DATASET v1.0 Category: Game of Life ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

void initialize(int grid[ROWS][COLS]) {
    // Set all cells to dead (0)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = 0;
        }
    }
    // Randomly set some cells to alive (1)
    srand(time(NULL));
    for (int i = 0; i < ROWS*COLS/4; i++) {
        int x = rand() % ROWS;
        int y = rand() % COLS;
        grid[x][y] = 1;
    }
}

void printGrid(int grid[ROWS][COLS]) {
    // Print the grid to the console
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 0) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int countNeighbors(int grid[ROWS][COLS], int row, int col) {
    // Count the number of alive neighbors around a given cell
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int nr = row + i;
            int nc = col + j;
            if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && !(i == 0 && j == 0)) {
                count += grid[nr][nc];
            }
        }
    }
    return count;
}

void update(int grid[ROWS][COLS]) {
    // Update the grid based on the rules of the game
    int newGrid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(grid, i, j);
            if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                newGrid[i][j] = 0;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                newGrid[i][j] = 1;
            } else {
                newGrid[i][j] = grid[i][j];
            }
        }
    }
    // Copy the new grid back to the original grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    int grid[ROWS][COLS];
    initialize(grid);
    while (1) {
        printGrid(grid);
        update(grid);
        // Clear the console before printing the next generation
        system("clear");
    }
    return 0;
}