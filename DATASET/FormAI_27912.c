//FormAI DATASET v1.0 Category: Game of Life ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ROWS 50
#define COLS 50

int grid[ROWS][COLS];
int newGrid[ROWS][COLS];

void fillGrid()
{
    srand(time(NULL));

    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }
}

void printGrid()
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (grid[i][j] == 1)
            {
                printf("*");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
}

int countNeighbors(int row, int col)
{
    int count = 0;
    int i, j;
    for (i = -1; i <= 1; i++)
    {
        for (j = -1; j <= 1; j++)
        {
            int r = (row + i + ROWS) % ROWS;
            int c = (col + j + COLS) % COLS;

            if (grid[r][c] == 1)
            {
                count++;
            }
        }
    }

    if (grid[row][col] == 1)
    {
        count--;
    }

    return count;
}

void updateGrid()
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            int neighbors = countNeighbors(i, j);

            if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3))
            {
                newGrid[i][j] = 0;
            }
            else if (grid[i][j] == 0 && neighbors == 3)
            {
                newGrid[i][j] = 1;
            }
            else
            {
                newGrid[i][j] = grid[i][j];
            }
        }
    }

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main()
{
    fillGrid();

    while (1)
    {
        system("clear");
        printGrid();
        updateGrid();
        usleep(100000);
    }

    return 0;
}