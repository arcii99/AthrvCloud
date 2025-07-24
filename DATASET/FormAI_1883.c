//FormAI DATASET v1.0 Category: Sudoku solver ; Style: systematic
#include <stdio.h>

// Function to check if num is valid at position r, c
int isValid(int board[9][9], int r, int c, int num)
{
    // Check row and column for the same num
    for (int i = 0; i < 9; i++)
        if (board[i][c] == num || board[r][i] == num)
            return 0;

    // Check small 3x3 grid for the same num
    int rowStart = (r / 3) * 3;
    int colStart = (c / 3) * 3;
    for (int i = rowStart; i < rowStart + 3; i++)
        for (int j = colStart; j < colStart + 3; j++)
            if (board[i][j] == num)
                return 0;

    // If num is valid at position r, c
    return 1;
}

// Function to solve Sudoku board using backtracking
int solveSudoku(int board[9][9], int row, int col)
{
    // Base case: if all columns of all rows are filled, then solveSudoku completes successfully
    if (row == 9)
        return 1;

    // If all columns are filled, move to the next row
    if (col == 9)
        return solveSudoku(board, row + 1, 0);

    // If the current position is not empty
    if (board[row][col] != 0)
        return solveSudoku(board, row, col + 1);

    // Try different numbers in the current empty position
    for (int num = 1; num <= 9; num++)
    {
        // Check if this num is valid for this position
        if (isValid(board, row, col, num) == 1)
        {
            // Place the num at this position
            board[row][col] = num;

            // Recursively solve the rest of the board
            if (solveSudoku(board, row, col + 1) == 1)
                return 1;

            // If solving the rest of the board was unsuccessful,
            // backtrack and try the next num
            board[row][col] = 0;
        }
    }

    // If no num is valid for this position, backtrack and try the next position
    return 0;
}

// Function to print Sudoku board
void printSudoku(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Initialize sample Sudoku board
    int board[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                       {5, 2, 0, 0, 0, 0, 0, 0, 0},
                       {0, 8, 7, 0, 0, 0, 0, 3, 1},
                       {0, 0, 3, 0, 0, 0, 0, 2, 0},
                       {9, 0, 0, 8, 0, 0, 0, 0, 5},
                       {0, 5, 0, 0, 0, 0, 6, 0, 0},
                       {1, 3, 0, 0, 0, 0, 2, 5, 0},
                       {0, 0, 0, 0, 0, 0, 0, 7, 4},
                       {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    // Solve Sudoku board
    if (solveSudoku(board, 0, 0) == 1)
    {
        printf("Solution found!\n");
        printSudoku(board);
    }
    else
    {
        printf("No solution found.\n");
    }

    return 0;
}