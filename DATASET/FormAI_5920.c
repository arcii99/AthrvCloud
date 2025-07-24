//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void percolate(int grid[ROWS][COLS])
{
    int current_row = 0;
    int current_col = rand() % COLS;
    grid[current_row][current_col] = 2;

    while (current_row < ROWS - 1)
    {
        int next_row = current_row + 1;

        if (current_col > 0 && grid[next_row][current_col - 1] == 1)
        {
            current_col--;
        }
        else if (current_col < COLS - 1 && grid[next_row][current_col + 1] == 1)
        {
            current_col++;
        }

        grid[next_row][current_col] = 2;
        current_row = next_row;
    }
}

void print_grid(int grid[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (grid[i][j] == 0)
            {
                printf(". ");
            }
            else if (grid[i][j] == 1)
            {
                printf("# ");
            }
            else if (grid[i][j] == 2)
            {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int grid[ROWS][COLS] = {{0}};
    srand(time(NULL));

    for (int i = 0; i < COLS; i++)
    {
        grid[ROWS - 1][i] = 1;
    }

    percolate(grid);
    print_grid(grid);

    return 0;
}