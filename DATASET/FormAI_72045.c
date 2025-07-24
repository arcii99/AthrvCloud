//FormAI DATASET v1.0 Category: Sudoku solver ; Style: brave
#include <stdio.h>

// Function to check if a given value is safe in the current cell
int isSafe(int puzzle[9][9], int row, int col, int num)
{
    // Check if the value is already present in the current row or column
    for (int i = 0; i < 9; i++)
    {
        if (puzzle[row][i] == num || puzzle[i][col] == num)
        {
            return 0;
        }
    }

    // Check if the value is already present in the current 3x3 box
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (int i = boxRow; i < boxRow + 3; i++)
    {
        for (int j = boxCol; j < boxCol + 3; j++)
        {
            if (puzzle[i][j] == num)
            {
                return 0;
            }
        }
    }

    // If the value is safe in the current cell, return true
    return 1;
}

// Function to print the Sudoku puzzle
void printPuzzle(int puzzle[9][9])
{
    printf("\n-----------------\n");
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", puzzle[i][j]);
            if (j % 3 == 2)
            {
                printf("| ");
            }
        }
        printf("\n");
        if (i % 3 == 2)
        {
            printf("-----------------\n");
        }
    }
}

// Function to solve the Sudoku puzzle
int solveSudoku(int puzzle[9][9], int row, int col)
{
    // If we have reached the last cell, we have completed the puzzle
    if (row == 8 && col == 9)
    {
        return 1;
    }

    // If we have completed a row, move to the next row
    if (col == 9)
    {
        row++;
        col = 0;
    }

    // If the current cell is not empty, move to the next cell
    if (puzzle[row][col] != 0)
    {
        return solveSudoku(puzzle, row, col + 1);
    }

    // Try all numbers from 1 to 9 in the current cell
    for (int i = 1; i <= 9; i++)
    {
        if (isSafe(puzzle, row, col, i))
        {
            puzzle[row][col] = i;

            // If we can solve the puzzle using this number, return true
            if (solveSudoku(puzzle, row, col + 1))
            {
                return 1;
            }
        }
    }

    // If no number works, backtrack and return false
    puzzle[row][col] = 0;
    return 0;
}

int main()
{
    int puzzle[9][9] = {{0, 6, 0, 1, 0, 4, 0, 5, 0},
                        {0, 0, 8, 3, 0, 5, 6, 0, 0},
                        {2, 0, 0, 0, 0, 0, 0, 0, 1},
                        {8, 0, 0, 4, 0, 7, 0, 0, 6},
                        {0, 0, 6, 0, 0, 0, 3, 0, 0},
                        {7, 0, 0, 9, 0, 1, 0, 0, 4},
                        {5, 0, 0, 0, 0, 0, 0, 0, 2},
                        {0, 0, 7, 2, 0, 6, 9, 0, 0},
                        {0, 4, 0, 5, 0, 8, 0, 7, 0}};

    if (solveSudoku(puzzle, 0, 0))
    {
        printPuzzle(puzzle);
    }
    else
    {
        printf("No solution found.\n");
    }

    return 0;
}