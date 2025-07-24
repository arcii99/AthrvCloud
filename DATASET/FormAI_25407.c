//FormAI DATASET v1.0 Category: Sudoku solver ; Style: complete
#include<stdio.h>

#define N 9

int find_empty(int grid[N][N], int *row, int *col);
int is_safe(int grid[N][N], int row, int col, int num);
int solve_sudoku(int grid[N][N]);
void print_grid(int grid[N][N]);

int main()
{
    int grid[N][N] = {{0, 5, 3, 0, 0, 0, 6, 2, 0},
                      {0, 0, 6, 9, 8, 0, 0, 7, 0},
                      {0, 0, 0, 0, 0, 7, 1, 0, 8},
                      {8, 0, 0, 0, 0, 0, 0, 0, 5},
                      {0, 6, 0, 0, 0, 0, 0, 8, 0},
                      {3, 0, 0, 0, 0, 0, 0, 0, 4},
                      {9, 0, 0, 8, 0, 0, 0, 0, 0},
                      {0, 1, 0, 0, 0, 4, 8, 0, 0},
                      {0, 7, 4, 5, 0, 0, 0, 0, 0}};

    if(solve_sudoku(grid))
        print_grid(grid);
    else
        printf("No solution exists for the given Sudoku.");

    return 0;
}

/* The find_empty() function finds the next empty cell in which
 * we need to fill a number. If the function finds an empty cell,
 * then it returns 1 along with the position of the empty cell in
 * row and column, otherwise it returns 0. */

int find_empty(int grid[N][N], int *row, int *col)
{
    for (*row = 0; *row < N; (*row)++)
        for (*col = 0; *col < N; (*col)++)
            if (grid[*row][*col] == 0)
                return 1;
    return 0; // There is no empty cell left
}

/* The is_safe() function checks whether it is safe to fill
 * the cell with a number "num" or not. */

int is_safe(int grid[N][N], int row, int col, int num)
{
    int i, j;

    // Row and column check
    for (i = 0; i < N; i++)
        if (grid[row][i] == num || grid[i][col] == num)
            return 0;

    // Box check
    int row_start = (row / 3) * 3, col_start = (col / 3) * 3;
    for (i = row_start; i < row_start + 3; i++)
        for (j = col_start; j < col_start + 3; j++)
            if (grid[i][j] == num)
                return 0;

    return 1; // Safe to fill in the cell with the given number
}

/* The solve_sudoku() function calls the find_empty() function
 * to find the next empty cell in the grid. If there is no empty
 * cell left, we exit the recursion and return 1 indicating that
 * the Sudoku has been solved successfully. */

int solve_sudoku(int grid[N][N])
{
    int row, col;

    if (!find_empty(grid, &row, &col)) // Sudoku has been solved successfully
        return 1;

    for (int num = 1; num <= N; num++) // Try filling the empty cell with numbers from 1 to 9
    {
        if (is_safe(grid, row, col, num))
        {
            grid[row][col] = num;

            if (solve_sudoku(grid))
                return 1;

            grid[row][col] = 0; // The number num doesn't lead to a solution. So, backtrack.
        }
    }

    return 0; // No number from 1 to 9 is safe to fill the empty cell. So, backtrack.
}

/* The print_grid() function prints the solved Sudoku grid. */

void print_grid(int grid[N][N])
{
    printf("\n\n The solved Sudoku grid is as follows:\n\n");

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", grid[i][j]);
        printf("\n");
    }
}