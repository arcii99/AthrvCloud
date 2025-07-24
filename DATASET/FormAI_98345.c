//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define GRID_SIZE 20  // size of the grid
#define THRESHOLD 0.6  // probability threshold

int grid[GRID_SIZE][GRID_SIZE]; // the grid

/* function prototypes */
void initializeGrid();
void printGrid();
bool isPercolated();
bool valid(int row, int col);

int main()
{
    srand(time(NULL));
    initializeGrid();
    printGrid();

    if (isPercolated())
    {
        printf("Percolation achieved!\n");
    }
    else
    {
        printf("Percolation not achieved.\n");
    }

    return 0;
}

/* initialize the grid with random cells */
void initializeGrid()
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if ((double)rand() / RAND_MAX > THRESHOLD)
            {
                grid[i][j] = 1;
            }
        }
    }
}

/* print the grid to the console */
void printGrid()
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if (grid[i][j] == 1)
            {
                printf("[]");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

/* check if the grid is percolated */
bool isPercolated()
{
    /* create a copy of the grid to mark cell as visited */
    int copy[GRID_SIZE][GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            copy[i][j] = grid[i][j];
        }
    }

    /* check if percolation is possible from top to bottom */
    bool visited[GRID_SIZE][GRID_SIZE] = {false};
    for (int j = 0; j < GRID_SIZE; j++)
    {
        if (grid[0][j] == 1)
        {
            visited[0][j] = true;
            copy[0][j] = 0;
        }
    }
    for (int i = 1; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if (copy[i][j] == 1 && visited[i - 1][j])
            {
                visited[i][j] = true;
                copy[i][j] = 0;

                if (i == GRID_SIZE - 1)
                {
                    return true;
                }
            }
        }
    }

    return false;
}