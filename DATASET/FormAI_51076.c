//FormAI DATASET v1.0 Category: Game of Life ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 20

int grid[ROWS][COLS];
int newGrid[ROWS][COLS];

void initGrid() // Initialize the grid with random values
{
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void printGrid() // Print the grid
{
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", grid[i][j] ? 'x' : ' ');
        }
        printf("\n");
    }
}

int countNeighbors(int i, int j) // Count the neighboring cells that are alive
{
    int count = 0;
    int x, y;
    for (x = i - 1; x <= i + 1; x++) {
        for (y = j - 1; y <= j + 1; y++) {
            if (x == i && y == j) continue; // Skip the cell itself
            if (x < 0 || y < 0 || x >= ROWS || y >= COLS) continue; // Skip the cells outside the grid
            if (grid[x][y]) count++;
        }
    }
    return count;
}

void updateGrid() // Update the grid according to the rules of the Game of Life
{
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(i, j);
            if (grid[i][j] && (neighbors < 2 || neighbors > 3)) {
                newGrid[i][j] = 0; // Cell dies
            } else if (!grid[i][j] && neighbors == 3) {
                newGrid[i][j] = 1; // Cell is born
            } else {
                newGrid[i][j] = grid[i][j]; // Cell stays the same
            }
        }
    }
    // Copy the new grid to the old grid
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main()
{
    initGrid();
    while (1) {
        system("clear"); // Clear the screen
        printGrid();
        updateGrid();
    }
    return 0;
}