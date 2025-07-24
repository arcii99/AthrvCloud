//FormAI DATASET v1.0 Category: Game of Life ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 30

// function to print the current generation's grid
void print_grid(int grid[][COLS])
{
    printf("\nCurrent Generation:\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
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
    printf("\n");
}

// function to initialize the grid randomly
void init_grid(int grid[][COLS])
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int rand_num = rand() % 2;
            grid[i][j] = rand_num;
        }
    }
}

// function to count the number of alive neighbors
int count_alive_neighbors(int grid[][COLS], int row, int col)
{
    int count = 0;
    for (int i = row-1; i <= row+1; i++)
    {
        for (int j = col-1; j <= col+1; j++)
        {
            if (i >= 0 && i < ROWS && j >=0 && j < COLS && grid[i][j] == 1)
            {
                count++;
            }
        }
    }
    if (grid[row][col] == 1) // removing self from count
    {
        count--;
    }
    return count;
}

// function to update the grid to the next generation
void update_grid(int grid[][COLS])
{
    int new_grid[ROWS][COLS] = {0};

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int alive_neighbors = count_alive_neighbors(grid, i, j);
            if (grid[i][j] == 1 && alive_neighbors < 2) // isolate the cell
            {
                new_grid[i][j] = 0;
            }
            else if (grid[i][j] == 1 && alive_neighbors > 3) // overpopulation
            {
                new_grid[i][j] = 0;
            }
            else if (grid[i][j] == 0 && alive_neighbors == 3) // reproduction
            {
                new_grid[i][j] = 1;
            }
            else
            {
                new_grid[i][j] = grid[i][j]; // no change
            }
        }
    }

    // copying the new grid back to the original grid
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j] = new_grid[i][j];
        }
    }
}

// main function
int main()
{
    int grid[ROWS][COLS] = {0};
    init_grid(grid); // initializing the grid
    print_grid(grid); // printing the initial grid

    // loop to update the grid for each generation
    for (int i = 1; i <= 10; i++) // simulating 10 generations
    {
        update_grid(grid); // updating the grid for the next generation
        print_grid(grid); // printing the updated grid
    }

    return 0;
}