//FormAI DATASET v1.0 Category: Sudoku solver ; Style: expert-level
#include <stdio.h>
#include <stdbool.h>

// Constants
#define BOARD_SIZE 9
#define EMPTY 0

// Helper functions
bool find_empty_cell(int board[][BOARD_SIZE], int *row, int *col);
bool check_row(int board[][BOARD_SIZE], int row, int num);
bool check_col(int board[][BOARD_SIZE], int col, int num);
bool check_box(int board[][BOARD_SIZE], int start_row, int start_col, int num);
bool is_safe(int board[][BOARD_SIZE], int row, int col, int num);
bool solve_sudoku(int board[][BOARD_SIZE]);
void print_board(int board[][BOARD_SIZE]);

// Find the next empty cell in the board
bool find_empty_cell(int board[][BOARD_SIZE], int *row, int *col)
{
    for (*row = 0; *row < BOARD_SIZE; (*row)++)
    {
        for (*col = 0; *col < BOARD_SIZE; (*col)++)
        {
            if (board[*row][*col] == EMPTY)
            {
                return true;
            }
        }
    }
    return false;
}

// Check if the given number is already present in the row
bool check_row(int board[][BOARD_SIZE], int row, int num)
{
    for (int col = 0; col < BOARD_SIZE; col++)
    {
        if (board[row][col] == num)
        {
            return true;
        }
    }
    return false;
}

// Check if the given number is already present in the column
bool check_col(int board[][BOARD_SIZE], int col, int num)
{
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        if (board[row][col] == num)
        {
            return true;
        }
    }
    return false;
}

// Check if the given number is already present in the 3x3 box
bool check_box(int board[][BOARD_SIZE], int start_row, int start_col, int num)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (board[row + start_row][col + start_col] == num)
            {
                return true;
            }
        }
    }
    return false;
}

// Check if the given number can be placed in the given cell
bool is_safe(int board[][BOARD_SIZE], int row, int col, int num)
{
    return (!check_row(board, row, num) &&
            !check_col(board, col, num) &&
            !check_box(board, row - row % 3, col - col % 3, num));
}

// Solve the sudoku board recursively using backtracking
bool solve_sudoku(int board[][BOARD_SIZE])
{
    int row, col;

    if (!find_empty_cell(board, &row, &col))
    {
        // No empty cell left, puzzle solved!
        return true;
    }

    for (int num = 1; num <= 9; num++)
    {
        if (is_safe(board, row, col, num))
        {
            board[row][col] = num;

            if (solve_sudoku(board))
            {
                // Puzzle solved!
                return true;
            }

            board[row][col] = EMPTY; // Backtrack and try another number
        }
    }

    // No number can be placed in this cell, backtrack to previous cell
    return false;
}

// Print the board
void print_board(int board[][BOARD_SIZE])
{
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

// Driver program
int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {
        {7, 8, 0, 4, 0, 0, 1, 2, 0},
        {6, 0, 0, 0, 7, 5, 0, 0, 9},
        {0, 0, 0, 6, 0, 1, 0, 7, 8},
        {0, 0, 7, 0, 4, 0, 2, 6, 0},
        {0, 0, 1, 0, 5, 0, 9, 3, 0},
        {9, 0, 4, 0, 6, 0, 0, 0, 5},
        {0, 7, 0, 3, 0, 0, 0, 1, 2},
        {1, 2, 0, 0, 0, 7, 4, 0, 0},
        {0, 4, 9, 2, 0, 6, 0, 0, 7}
    };

    if (solve_sudoku(board))
    {
        printf("Solved:\n");
        print_board(board);
    }
    else
    {
        printf("Not solvable!");
    }

    return 0;
}