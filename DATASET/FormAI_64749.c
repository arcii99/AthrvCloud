//FormAI DATASET v1.0 Category: Game of Life ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void printGrid(int grid[ROWS][COLS])
{
    printf("Current Generation:\n");
    for(int row = 0; row < ROWS; row++)
    {
        for(int col = 0; col < COLS; col++)
        {
            if(grid[row][col] == 1)
                printf("* ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

int countNeighbors(int grid[ROWS][COLS], int row, int col)
{
    int sum = 0;
    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            int newRow = row + i;
            int newCol = col + j;
            if(newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS)
            {
                sum += grid[newRow][newCol];
            }
        }
    }
    sum -= grid[row][col];
    return sum;
}

void applyRules(int grid[ROWS][COLS])
{
    int newGrid[ROWS][COLS];
    for(int row = 0; row < ROWS; row++)
    {
        for(int col = 0; col < COLS; col++)
        {
            int neighbors = countNeighbors(grid, row, col);
            if(grid[row][col] == 1)
            {
                if(neighbors < 2 || neighbors > 3)
                    newGrid[row][col] = 0;
                else
                    newGrid[row][col] = 1;
            }
            else
            {
                if(neighbors == 3)
                    newGrid[row][col] = 1;
                else
                    newGrid[row][col] = 0;
            }
        }
    }
    for(int row = 0; row < ROWS; row++)
    {
        for(int col = 0; col < COLS; col++)
        {
            grid[row][col] = newGrid[row][col];
        }
    }
}

int main()
{
    int grid[ROWS][COLS] = {0};

    // Randomly set some cells to 1
    srand(time(NULL));
    for(int i = 0; i < 25; i++)
    {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        grid[row][col] = 1;
    }

    printGrid(grid);

    for(int generation = 1; generation <= 10; generation++)
    {
        applyRules(grid);
        printf("Generation %d:\n", generation);
        printGrid(grid);
    }

    return 0;
}