//FormAI DATASET v1.0 Category: Game of Life ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define GRID_ROWS 20
#define GRID_COLS 30

enum CellState {
    DEAD = 0,
    ALIVE
};

void update_grid(enum CellState curr_grid[GRID_ROWS][GRID_COLS], enum CellState new_grid[GRID_ROWS][GRID_COLS])
{
    int i, j;
    int alive_neighbors = 0;

    for (i = 0; i < GRID_ROWS; ++i)
    {
        for (j = 0; j < GRID_COLS; ++j)
        {
            alive_neighbors = 0;

            if (i > 0 && curr_grid[i - 1][j] == ALIVE)
                ++alive_neighbors;
            if (i < GRID_ROWS - 1 && curr_grid[i + 1][j] == ALIVE)
                ++alive_neighbors;
            if (j > 0 && curr_grid[i][j - 1] == ALIVE)
                ++alive_neighbors;
            if (j < GRID_COLS - 1 && curr_grid[i][j + 1] == ALIVE)
                ++alive_neighbors;
            if (i > 0 && j > 0 && curr_grid[i - 1][j - 1] == ALIVE)
                ++alive_neighbors;
            if (i > 0 && j < GRID_COLS - 1 && curr_grid[i - 1][j + 1] == ALIVE)
                ++alive_neighbors;
            if (i < GRID_ROWS - 1 && j > 0 && curr_grid[i + 1][j - 1] == ALIVE)
                ++alive_neighbors;
            if (i < GRID_ROWS - 1 && j < GRID_COLS - 1 && curr_grid[i + 1][j + 1] == ALIVE)
                ++alive_neighbors;

            if (curr_grid[i][j] == ALIVE)
            {
                if (alive_neighbors == 2 || alive_neighbors == 3)
                    new_grid[i][j] = ALIVE;
                else
                    new_grid[i][j] = DEAD;
            }
            else
            {
                if (alive_neighbors == 3)
                    new_grid[i][j] = ALIVE;
                else
                    new_grid[i][j] = DEAD;
            }
        }
    }

    for (i = 0; i < GRID_ROWS; ++i)
    {
        for (j = 0; j < GRID_COLS; ++j)
        {
            curr_grid[i][j] = new_grid[i][j];
        }
    }
}

void print_grid(enum CellState curr_grid[GRID_ROWS][GRID_COLS])
{
    int i, j;

    for (i = 0; i < GRID_ROWS; ++i)
    {
        for (j = 0; j < GRID_COLS; ++j)
        {
            if (curr_grid[i][j] == ALIVE)
                printf("*");
            else
                printf("-");

            if (j == GRID_COLS - 1)
                printf("\n");
        }
    }

    printf("\n");
}

int main()
{
    enum CellState curr_grid[GRID_ROWS][GRID_COLS];
    enum CellState new_grid[GRID_ROWS][GRID_COLS];

    srand(time(NULL));

    int i, j, r;

    for (i = 0; i < GRID_ROWS; ++i)
    {
        for (j = 0; j < GRID_COLS; ++j)
        {
            r = rand() % 2;
            if (r == 0)
                curr_grid[i][j] = DEAD;
            else
                curr_grid[i][j] = ALIVE;

            new_grid[i][j] = curr_grid[i][j];
        }
    }

    int generation = 0;
    while (generation < 1000)
    {
        printf("Generation %d:\n", generation);
        print_grid(curr_grid);
        update_grid(curr_grid, new_grid);
        ++generation;
    }

    return 0;
}