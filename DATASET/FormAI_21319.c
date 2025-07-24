//FormAI DATASET v1.0 Category: Sudoku solver ; Style: happy
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

bool solveSudoku(int[][SIZE], int, int);
bool isSafe(int[][SIZE], int, int, int);
void printBoard(int[][SIZE]);

int main()
{
    printf("Welcome! I am a happy Sudoku solver!\n");

    int board[SIZE][SIZE] =
    {
        {8, 0, 0, 4, 0, 6, 0, 0, 7},
        {0, 0, 0, 0, 0, 0, 4, 0, 0},
        {0, 1, 0, 0, 0, 0, 6, 5, 0},
        {5, 0, 9, 0, 3, 0, 7, 8, 0},
        {0, 0, 0, 0, 7, 0, 0, 0, 0},
        {0, 4, 8, 0, 2, 0, 1, 0, 3},
        {0, 5, 2, 0, 0, 0, 0, 9, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0},
        {3, 0, 0, 9, 0, 2, 0, 0, 5}
    };

    printf("Here's the puzzle:\n");
    printBoard(board);

    if (solveSudoku(board, 0, 0))
    {
        printf("Yay! Here's the solved puzzle:\n");
        printBoard(board);
    }
    else
    {
        printf("Oops! Something went wrong! Could not solve the puzzle.\n");
    }

    return 0;
}

/*  Solves Sudoku board using recursive backtracking */
bool solveSudoku(int board[][SIZE], int row, int col)
{
    if (row == SIZE)
    {
        return true;
    }
    if (col == SIZE)
    {
        return solveSudoku(board, row + 1, 0);
    }
    if (board[row][col] != 0)
    {
        return solveSudoku(board, row, col + 1);
    }

    for (int num = 1; num <= SIZE; num++)
    {
        if (isSafe(board, row, col, num))
        {
            board[row][col] = num;

            if (solveSudoku(board, row, col + 1))
            {
                return true;
            }

            board[row][col] = 0;
        }
    }

    return false;
}

/*  Checks if a number is safe to be placed in a given position */
bool isSafe(int board[][SIZE], int row, int col, int num)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (board[row][i] == num || board[i][col] == num)
        {
            return false;
        }
    }

    int boxRow = row - row % 3;
    int boxCol = col - col % 3;

    for (int i = boxRow; i < boxRow + 3; i++)
    {
        for (int j = boxCol; j < boxCol + 3; j++)
        {
            if (board[i][j] == num)
            {
                return false;
            }
        }
    }

    return true;
}

/*  Prints Sudoku board */
void printBoard(int board[][SIZE])
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}