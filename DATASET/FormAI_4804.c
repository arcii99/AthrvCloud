//FormAI DATASET v1.0 Category: Sudoku solver ; Style: real-life
#include <stdio.h>
#include <stdbool.h>

#define N 9
#define UNASSIGNED 0

bool findUnassignedLocation(int grid[N][N], int *row, int *col);
bool usedInRow(int grid[N][N], int row, int num);
bool usedInCol(int grid[N][N], int col, int num);
bool usedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num);
bool isSafe(int grid[N][N], int row, int col, int num);
bool solveSudoku(int grid[N][N]);
void printGrid(int grid[N][N]);

/*
 * Function to find an unassigned location in Sudoku grid
 * and update row and col accordingly
 */
bool findUnassignedLocation(int grid[N][N], int *row, int *col)
{
    for (*row = 0; *row < N; (*row)++)
    {
        for (*col = 0; *col < N; (*col)++)
        {
            if (grid[*row][*col] == UNASSIGNED)
            {
                return true;
            }
        }
    }

    return false;
}

/*
 * Function to check if any number is already present in 
 * given row
 */
bool usedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
    {
        if (grid[row][col] == num)
        {
            return true;
        }
    }

    return false; 
}

/*
 * Function to check if any number is already present in 
 * given column
 */
bool usedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
    {
        if (grid[row][col] == num)
        {
            return true;
        }
    }

    return false;
}

/*
 * Function to check if any number is already present in
 * given 3 x 3 box
 */
bool usedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (grid[row + boxStartRow][col + boxStartCol] == num)
            {
                return true;
            }
        }
    }

    return false;
}

/*
 * Function to check if it is safe to place `num` at `(row, col)`
*/
bool isSafe(int grid[N][N], int row, int col, int num)
{
    return !usedInRow(grid, row, num) 
           && !usedInCol(grid, col, num) 
           && !usedInBox(grid, row - row % 3, col - col % 3, num);
}

/*
 * Function to solve the Sudoku puzzle using backtracking
 */
bool solveSudoku(int grid[N][N])
{
    int row = 0, col = 0;

    // If there is no unassigned location, puzzle solved!
    if (!findUnassignedLocation(grid, &row, &col))
    {
        return true;
    }

    // Consider digits 1 to 9 and try to fill in the cell recursively
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;

            // If successful, return true
            if (solveSudoku(grid))
            {
                return true;
            }

            // Otherwise, reset the cell and try again
            grid[row][col] = UNASSIGNED;
        }
    }

    // This triggers backtracking to the previous call
    return false;
}

/*
 * Function to print the Sudoku grid
 */
void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int main()
{
    int grid[N][N] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Some cells are already assigned in the Sudoku puzzle
    int initialGrid[N][N] = {{5, 0, 0, 0, 0, 2, 0, 0, 0},
                             {0, 0, 2, 0, 0, 0, 0, 1, 0},
                             {0, 0, 0, 0, 0, 0, 7, 0, 6},
                             {7, 4, 0, 0, 5, 0, 0, 0, 9},
                             {0, 0, 0, 7, 0, 0, 0, 0, 4},
                             {0, 0, 0, 4, 0, 0, 5, 0, 0},
                             {8, 0, 0, 9, 0, 0, 0, 0, 7},
                             {0, 0, 0, 0, 0, 0, 0, 6, 0},
                             {1, 0, 0, 0, 0, 0, 0, 5, 3}};

    // Copy the initial Sudoku puzzle to our grid
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            grid[row][col] = initialGrid[row][col];
        }
    }

    // Print the initial Sudoku puzzle
    printf("Initial Sudoku puzzle:\n");
    printGrid(grid);
    printf("\n");

    // Solve the Sudoku puzzle and print the solution
    if (solveSudoku(grid))
    {
        printf("Solved Sudoku puzzle:\n");
        printGrid(grid);
    }
    else
    {
        printf("No solution exists for the given Sudoku puzzle.\n");
    }

    return 0;
}