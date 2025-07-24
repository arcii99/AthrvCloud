//FormAI DATASET v1.0 Category: Game of Life ; Style: introspective
#include <stdio.h>

/*
The Game of Life is a popular cellular automaton that
was devised by British mathematician John Horton Conway in 1970.

Each cell lives or dies depending on its eight neighbours.
The rules are as follows:
  1) Any live cell with fewer than two live neighbours dies,
   as if caused by underpopulation.
  2) Any live cell with two or three live neighbours lives
   on to the next generation.
  3) Any live cell with more than three live neighbours dies,
   as if by overpopulation.
  4) Any dead cell with exactly three live neighbours becomes a live cell,
   as if by reproduction.

In this program, we will create a random grid and apply the rules to simulate
the generation of new grids based on the previous state. We will display the
grid after each generation to visualize the changes.
*/

#define HEIGHT 10
#define WIDTH 20

// Function to initialize random grid
void initialize_grid(int grid[][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to print grid to console
void print_grid(int grid[][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            printf(grid[i][j] ? "*" : " ");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to count live neighbors
int count_neighbors(int grid[][WIDTH], int row, int col)
{
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            if (i < 0 || i >= HEIGHT || j < 0 || j >= WIDTH)
            {
                continue;
            }
            if (i == row && j == col)
            {
                continue;
            }
            if (grid[i][j])
            {
                count++;
            }
        }
    }
    return count;
}

// Function to simulate one generation
void simulate_generation(int grid[][WIDTH])
{
    int new_grid[HEIGHT][WIDTH] = {0};
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            int count = count_neighbors(grid, i, j);
            if (grid[i][j])
            {
                if (count < 2 || count > 3)
                {
                    new_grid[i][j] = 0;
                }
                else
                {
                    new_grid[i][j] = 1;
                }
            }
            else
            {
                if (count == 3)
                {
                    new_grid[i][j] = 1;
                }
                else
                {
                    new_grid[i][j] = 0;
                }
            }
        }
    }
    memcpy(grid, new_grid, sizeof(new_grid));
}

// Main function
int main()
{
    int grid[HEIGHT][WIDTH] = {0};
    initialize_grid(grid);
    print_grid(grid);
    for (int i = 0; i < 10; i++)
    {
        simulate_generation(grid);
        print_grid(grid);
    }
    return 0;
}