//FormAI DATASET v1.0 Category: Game of Life ; Style: active
#include <stdio.h>

#define ROWS 20
#define COLS 60

void printGrid(int grid[ROWS][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("%c", grid[row][col] ? '*' : '-');
        }
        printf("\n");
    }
}

int countNeighbors(int grid[ROWS][COLS], int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS && (i != row || j != col)) {
                count += (grid[i][j]) ? 1 : 0;
            }
        }
    }
    return count;
}

void updateGrid(int grid[ROWS][COLS]) {
    int newGrid[ROWS][COLS];
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            int neighbors = countNeighbors(grid, row, col);
            if (grid[row][col]) {
                // cell is alive
                if (neighbors < 2 || neighbors > 3) {
                    // underpopulation or overpopulation
                    newGrid[row][col] = 0;  // cell dies
                } else {
                    // just right, cell survives
                    newGrid[row][col] = 1;
                }
            } else {
                // cell is dead
                if (neighbors == 3) {
                    // reproduction
                    newGrid[row][col] = 1;  // cell comes to life
                } else {
                    // cell stays dead
                    newGrid[row][col] = 0;
                }
            }
        }
    }
    // copy newGrid to grid
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            grid[row][col] = newGrid[row][col];
        }
    }
}

int main() {
    int grid[ROWS][COLS] = {{0}};  // initialize to 0
    // add glider
    grid[1][2] = 1;
    grid[2][3] = 1;
    grid[3][1] = grid[3][2] = grid[3][3] = 1;

    for (int i = 0; i < 100; i++) {  // run for 100 generations
        system("clear");  // clear console
        printGrid(grid);
        updateGrid(grid);
        usleep(100000);  // delay 100ms
    }

    return 0;
}