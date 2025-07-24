//FormAI DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 50
#define GENERATIONS 100

/*
 * Utility function to print the grid
 */
void printGrid(int grid[][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j] ? 'X' : '-');
        }
        printf("\n");
    }
}

/*
 * Utility function to initialize the grid with random values
 */
void initializeGrid(int grid[][COLS])
{
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

/*
 * Utility function to count the number of live neighbors
 */
int getLiveNeighbors(int grid[][COLS], int row, int col)
{
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            // Skip the current cell
            if (i == row && j == col) {
                continue;
            }
            // Handle edge cases
            if (i < 0 || i >= ROWS || j < 0 || j >= COLS) {
                continue;
            }
            // Increment the count if the neighbor is live
            if (grid[i][j]) {
                count++;
            }
        }
    }
    return count;
}

/*
 * Utility function to apply rules of the Game of Life and update the grid
 */
void playGame(int grid[][COLS])
{
    int nextGrid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int liveNeighbors = getLiveNeighbors(grid, i, j);
            // If a cell is alive
            if (grid[i][j]) {
                // Rule 1: Any live cell with fewer than two live neighbors dies, as if by underpopulation.
                if (liveNeighbors < 2) {
                    nextGrid[i][j] = 0;
                }
                // Rule 2: Any live cell with two or three live neighbors lives on to the next generation.
                else if (liveNeighbors == 2 || liveNeighbors == 3) {
                    nextGrid[i][j] = 1;
                }
                // Rule 3: Any live cell with more than three live neighbors dies, as if by overpopulation.
                else if (liveNeighbors > 3) {
                    nextGrid[i][j] = 0;
                }
            }
            // If a cell is dead
            else {
                // Rule 4: Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                if (liveNeighbors == 3) {
                    nextGrid[i][j] = 1;
                }
            }
        }
    }
    // Copy the next grid back to the original grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = nextGrid[i][j];
        }
    }
}

int main()
{
    int grid[ROWS][COLS];
    initializeGrid(grid);
    for (int i = 0; i < GENERATIONS; i++) {
        printf("Generation %d:\n", i + 1);
        printGrid(grid);
        playGame(grid);
    }
    return 0;
}