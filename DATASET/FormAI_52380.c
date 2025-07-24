//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define GRID_SIZE 9
#define UNASSIGNED 0

void print_grid(int grid[][GRID_SIZE]);
bool find_unassigned(int grid[][GRID_SIZE], int *row, int *col);
bool is_safe(int grid[][GRID_SIZE], int row, int col, int num);
bool solve_sudoku(int grid[][GRID_SIZE]);

int main()
{
    int grid[GRID_SIZE][GRID_SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solve_sudoku(grid) == true)
    {
        printf("Solution:\n");
        print_grid(grid);
    }
    else
    {
        printf("No solution exists.\n");
    }

    return 0;
}

void print_grid(int grid[][GRID_SIZE])
{
    for (int row = 0; row < GRID_SIZE; row++)
    {
        for (int col = 0; col < GRID_SIZE; col++)
        {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

bool find_unassigned(int grid[][GRID_SIZE], int *row, int *col)
{
    for (*row = 0; *row < GRID_SIZE; (*row)++)
    {
        for (*col = 0; *col < GRID_SIZE; (*col)++)
        {
            if (grid[*row][*col] == UNASSIGNED)
            {
                return true;
            }
        }
    }
    return false;
}

bool is_safe(int grid[][GRID_SIZE], int row, int col, int num)
{
    // Check row
    for (int col_index = 0; col_index < GRID_SIZE; col_index++)
    {
        if (grid[row][col_index] == num)
        {
            return false;
        }
    }

    // Check column
    for (int row_index = 0; row_index < GRID_SIZE; row_index++)
    {
        if (grid[row_index][col] == num)
        {
            return false;
        }
    }

    // Check box
    int box_start_row = row - row % 3;
    int box_start_col = col - col % 3;
    for (int i = box_start_row; i < box_start_row + 3; i++)
    {
        for (int j = box_start_col; j < box_start_col + 3; j++)
        {
            if (grid[i][j] == num)
            {
                return false;
            }
        }
    }

    return true;
}

bool solve_sudoku(int grid[][GRID_SIZE])
{
    int row, col;

    if (!find_unassigned(grid, &row, &col))
    {
        return true;
    }

    for (int num = 1; num <= 9; num++)
    {
        if (is_safe(grid, row, col, num))
        {
            grid[row][col] = num;

            if (solve_sudoku(grid))
            {
                return true;
            }

            grid[row][col] = UNASSIGNED;
        }
    }

    return false;
}