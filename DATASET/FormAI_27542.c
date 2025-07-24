//FormAI DATASET v1.0 Category: Game of Life ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 10
#define COLS 10

void initializeGrid(int grid[ROWS][COLS]) {
    for(int row = 0; row < ROWS; ++row) {
        for(int col = 0; col < COLS; ++col) {
            grid[row][col] = rand() % 2;
        }
    }
}

void printGrid(int grid[ROWS][COLS]) {
    printf("\n");
    for(int row = 0; row < ROWS; ++row) {
        for(int col = 0; col < COLS; ++col) {
            printf("%c", (grid[row][col] == 1 ? '#' : ' '));
        }
        printf("\n");
    }
}

void calculateNextGeneration(int grid[ROWS][COLS]) {
    int tempGrid[ROWS][COLS];

    for(int row = 0; row < ROWS; ++row) {
        for(int col = 0; col < COLS; ++col) {
            int neighbours = 0;

            for(int i = -1; i <= 1; ++i) {
                for(int j = -1; j <= 1; ++j) {
                    int rowToCheck = row + i;
                    int colToCheck = col + j;

                    if(rowToCheck < 0 || colToCheck < 0 || rowToCheck >= ROWS || colToCheck >= COLS) continue;
                    if(i == 0 && j == 0) continue;

                    neighbours += grid[rowToCheck][colToCheck];
                }
            }

            if(grid[row][col] == 1) {
                if(neighbours < 2 || neighbours > 3) {
                    tempGrid[row][col] = 0;
                } else {
                    tempGrid[row][col] = 1;
                }
            } else {
                if(neighbours == 3) {
                    tempGrid[row][col] = 1;
                } else {
                    tempGrid[row][col] = 0;
                }
            }
        }
    }

    for(int row = 0; row < ROWS; ++row) {
        for(int col = 0; col < COLS; ++col) {
            grid[row][col] = tempGrid[row][col];
        }
    }
}

int main() {
    int grid[ROWS][COLS];

    srand(time(NULL));
    initializeGrid(grid);

    while(1) {
        printGrid(grid);
        calculateNextGeneration(grid);
        usleep(300 * 1000);
        system("clear");
    }

    return 0;
}