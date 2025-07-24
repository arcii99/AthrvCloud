//FormAI DATASET v1.0 Category: Game of Life ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 20
#define COLS 40

#define ALIVE '*'
#define DEAD ' '

int grid[ROWS][COLS];
int newGrid[ROWS][COLS];

int neighbors(int x, int y);
void clearGrids();
void printGrid();
void setRandom();

int main()
{
    srand(time(NULL)); // seed random number generator

    clearGrids();
    setRandom();

    for (int i = 0; i < 100; i++) { // run for 100 iterations
        clearGrids();
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                int n = neighbors(row, col);
                if (grid[row][col] == 1) { // cell is alive
                    if (n < 2 || n > 3)
                        newGrid[row][col] = 0; // dies from under/over-population
                    else
                        newGrid[row][col] = 1; // lives
                }
                else { // cell is dead
                    if (n == 3)
                        newGrid[row][col] = 1; // becomes alive from reproduction
                    else
                        newGrid[row][col] = 0; // stays dead
                }
            }
        }
        memcpy(grid, newGrid, sizeof(grid)); // copy new grid to old grid
        printGrid();
        getchar(); // pause before next iteration
    }

    return 0;
}

int neighbors(int x, int y)
{
    int count = 0;
    for (int row = x - 1; row <= x + 1; row++) {
        for (int col = y - 1; col <= y + 1; col++) {
            if (row >= 0 && row < ROWS && col >= 0 && col < COLS && !(row == x && col == y)) {
                if (grid[row][col] == 1)
                    count++;
            }
        }
    }
    return count;
}

void clearGrids()
{
    memset(grid, 0, sizeof(grid));
    memset(newGrid, 0, sizeof(newGrid));
}

void printGrid()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (grid[row][col] == 1)
                putchar(ALIVE);
            else
                putchar(DEAD);
        }
        putchar('\n');
    }
}

void setRandom()
{
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (rand() % 2 == 1)
                grid[row][col] = 1;
            else
                grid[row][col] = 0;
        }
    }
}