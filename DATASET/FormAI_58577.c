//FormAI DATASET v1.0 Category: Sudoku solver ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 9

int grid[GRID_SIZE][GRID_SIZE];

int solve();
int find_empty(int* row, int* col);
int is_valid(int num, int row, int col);
void print_grid();
void fill_grid();

/* Main program */
int main()
{
    fill_grid();

    printf("Unsolved sudoku:\n");
    print_grid();
    if (solve())
    {
        printf("Solved sudoku:\n");
        print_grid();
    }
    else
    {
        printf("Failed to solve sudoku.\n");
    }

    return 0;
}

/* Solve the sudoku recursively */
int solve()
{
    int row, col;

    /* Find the next empty cell */
    if (!find_empty(&row, &col))
    {
        return 1; /* Sudoku has been solved */
    }

    /* Try all possible values in the empty cell */
    for (int num = 1; num <= GRID_SIZE; num++)
    {
        /* Check if the value is valid */
        if (is_valid(num, row, col))
        {
            /* Set the empty cell to the valid value */
            grid[row][col] = num;

            /* Solve the rest of the sudoku recursively */
            if (solve())
            {
                return 1; /* Successfully solved sudoku */
            }

            /* Backtrack and try another value */
            grid[row][col] = 0;
        }
    }

    return 0; /* Failed to solve sudoku */
}

/* Find the next empty cell */
int find_empty(int* row, int* col)
{
    for (*row = 0; *row < GRID_SIZE; (*row)++)
    {
        for (*col = 0; *col < GRID_SIZE; (*col)++)
        {
            if (grid[*row][*col] == 0)
            {
                return 1; /* Found an empty cell */
            }
        }
    }

    return 0; /* No empty cell found */
}

/* Check if the value is valid in the cell */
int is_valid(int num, int row, int col)
{
    /* Check row */
    for (int i = 0; i < GRID_SIZE; i++)
    {
        if (grid[row][i] == num && i != col)
        {
            return 0; /* Invalid value */
        }
    }

    /* Check column */
    for (int i = 0; i < GRID_SIZE; i++)
    {
        if (grid[i][col] == num && i != row)
        {
            return 0; /* Invalid value */
        }
    }

    /* Check 3x3 box */
    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;
    for (int i = box_row; i < box_row + 3; i++)
    {
        for (int j = box_col; j < box_col + 3; j++)
        {
            if (grid[i][j] == num && i != row && j != col)
            {
                return 0; /* Invalid value */
            }
        }
    }

    return 1; /* Valid value */
}

/* Print the sudoku grid */
void print_grid()
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        if (i % 3 == 0 && i != 0)
        {
            printf("---------------------\n");
        }

        for (int j = 0; j < GRID_SIZE; j++)
        {
            if (j % 3 == 0 && j != 0)
            {
                printf("| ");
            }

            printf("%d ", grid[i][j]);
        }

        printf("\n");
    }
}

/* Fill the sudoku grid with a valid puzzle */
void fill_grid()
{
    int puzzle[GRID_SIZE][GRID_SIZE] =
    {
        {0, 0, 0, 1, 5, 0, 4, 3, 0},
        {0, 8, 0, 0, 0, 6, 0, 0, 0},
        {0, 0, 0, 3, 8, 0, 0, 7, 0},
        {6, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 4, 0, 2, 1, 0, 0, 0, 0},
        {0, 0, 2, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 8, 5, 0, 0},
        {0, 0, 0, 0, 9, 0, 0, 0, 4},
        {0, 0, 7, 0, 0, 0, 0, 1, 3}
    };

    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            grid[i][j] = puzzle[i][j];
        }
    }
}