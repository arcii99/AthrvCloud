//FormAI DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 60

void print_grid(char grid[ROWS][COLS])
{
    system("clear"); // Clear the console window
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

void init_grid(char grid[ROWS][COLS])
{
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            float random = (float)rand() / RAND_MAX; // Generate a random number between 0 and 1
            if (random < 0.2)
            {
                grid[i][j] = '#'; // Fill the cell with a hash symbol if random number is less than 0.2
            }
            else
            {
                grid[i][j] = ' '; // Leave the cell empty otherwise
            }
        }
    }
}

int count_neighbors(char grid[ROWS][COLS], int row, int col)
{
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS && !(i == row && j == col))
            {
                if (grid[i][j] == '#')
                {
                    count++; // Increment the count if the neighbor is alive
                }
            }
        }
    }
    return count;
}

void update_grid(char grid[ROWS][COLS])
{
    char new_grid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int neighbors = count_neighbors(grid, i, j);
            if (grid[i][j] == '#' && (neighbors < 2 || neighbors > 3))
            {
                new_grid[i][j] = ' '; // Kill the cell if it has less than 2 or more than 3 neighbors
            }
            else if (grid[i][j] == ' ' && neighbors == 3)
            {
                new_grid[i][j] = '#'; // Bring a cell to life if it has exactly 3 neighbors
            }
            else
            {
                new_grid[i][j] = grid[i][j]; // Leave the cell alive if it has 2 or 3 neighbors
            }
        }
    }
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j] = new_grid[i][j]; // Update the original grid with the new grid
        }
    }
}

int main()
{
    char grid[ROWS][COLS];
    init_grid(grid);
    while (1)
    {
        print_grid(grid);
        update_grid(grid);
        usleep(100000); // Delay the update by 100 milliseconds
    }
    return 0;
}