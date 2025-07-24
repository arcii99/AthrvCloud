//FormAI DATASET v1.0 Category: Sudoku solver ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define ROWS 9
#define COLS 9
#define EMPTY 0

int is_valid(int grid[ROWS][COLS], int row, int col, int num);
void print_grid(int grid[ROWS][COLS]);
int find_empty_location(int grid[ROWS][COLS], int *row, int *col);
int solve_sudoku(int grid[ROWS][COLS]);

int main()
{
    int grid[ROWS][COLS] = {{1, 0, 0, 0, 0, 7, 0, 9, 0},
                            {0, 3, 0, 0, 2, 0, 0, 0, 8},
                            {0, 0, 9, 6, 0, 0, 5, 0, 0},
                            {0, 0, 5, 3, 0, 0, 9, 0, 0},
                            {0, 1, 0, 0, 8, 0, 0, 0, 2},
                            {6, 0, 0, 0, 0, 4, 0, 0, 0},
                            {3, 0, 0, 0, 0, 0, 0, 1, 0},
                            {0, 4, 0, 0, 0, 0, 0, 0, 7},
                            {0, 0, 7, 0, 0, 0, 3, 0, 0}};

    if (solve_sudoku(grid) == 1)
        print_grid(grid);
    else
        printf("No solution exists\n");

    return 0;
}

int is_valid(int grid[ROWS][COLS], int row, int col, int num)
{
    int i, j;
    for (i = 0; i < ROWS; i++)
        if (grid[row][i] == num)
            return 0;

    for (i = 0; i < COLS; i++)
        if (grid[i][col] == num)
            return 0;

    int box_row = row - row % 3;
    int box_col = col - col % 3;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (grid[i + box_row][j + box_col] == num)
                return 0;

    return 1;
}

void print_grid(int grid[ROWS][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int find_empty_location(int grid[ROWS][COLS], int *row, int *col)
{
    for (*row = 0; *row < ROWS; (*row)++)
        for (*col = 0; *col < COLS; (*col)++)
            if (grid[*row][*col] == EMPTY)
                return 1;
    return 0;
}

int solve_sudoku(int grid[ROWS][COLS])
{
    int row, col;

    if (!find_empty_location(grid, &row, &col))
        return 1;

    int num;

    for (num = 1; num <= 9; num++)
    {
        if (is_valid(grid, row, col, num))
        {
            grid[row][col] = num;
            if (solve_sudoku(grid))
                return 1;
            grid[row][col] = EMPTY;
        }
    }
    return 0;
}