//FormAI DATASET v1.0 Category: Sudoku solver ; Style: light-weight
#include <stdio.h>

// Function to check if a number can be placed in a particular cell
int is_valid(int board[][9], int row, int col, int num)
{
    // Check if the same number is not present in the same row and column
    for (int i = 0; i < 9; i++)
        if (board[row][i] == num || board[i][col] == num)
            return 0;

    // Check if the same number is not present in the same 3x3 box
    int start_row = (row / 3) * 3;
    int start_col = (col / 3) * 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[start_row + i][start_col + j] == num)
                return 0;

    return 1;
}

// Function to solve the sudoku puzzle using backtracking
int solve_sudoku(int board[][9], int row, int col)
{
    // If we have reached the end of the board, we have solved the puzzle
    if (row == 9)
        return 1;

    // If we have reached the end of a row, move to the next row
    if (col == 9)
        return solve_sudoku(board, row + 1, 0);

    // If the cell is already filled, move to the next cell
    if (board[row][col] != 0)
        return solve_sudoku(board, row, col + 1);

    // Try to place numbers 1-9 in the cell
    for (int num = 1; num <= 9; num++)
    {
        if (is_valid(board, row, col, num))
        {
            // Place the number in the cell
            board[row][col] = num;

            // Recursively try to solve the rest of the puzzle
            if (solve_sudoku(board, row, col + 1))
                return 1;

            // If we cannot solve the puzzle with this number in the cell, remove it
            board[row][col] = 0;
        }
    }

    // If we cannot solve the puzzle at this point, backtrack
    return 0;
}

// Function to print the board
void print_board(int board[][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

int main()
{
    // Initialize the sudoku puzzle
    int board[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Solve the puzzle
    if (solve_sudoku(board, 0, 0))
        print_board(board);
    else
        printf("No solution found.");

    return 0;
}