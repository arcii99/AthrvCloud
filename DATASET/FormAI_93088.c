//FormAI DATASET v1.0 Category: Sudoku solver ; Style: portable
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

void print_board(int board[][SIZE]);
bool find_empty(int board[][SIZE], int *row, int *col);
bool is_valid(int board[][SIZE], int row, int col, int num);
bool solve_board(int board[][SIZE]);

int main()
{
    int board[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};
      
    if (solve_board(board))
    {
        printf("Solution:\n");
        print_board(board);
    }
    else
    {
        printf("No solution exists.\n");
    }
    return 0;
}

void print_board(int board[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool find_empty(int board[][SIZE], int *row, int *col)
{
    for (*row = 0; *row < SIZE; (*row)++)
    {
        for (*col = 0; *col < SIZE; (*col)++)
        {
            if (board[*row][*col] == 0)
                return true;
        }
    }
    return false;
}

bool is_valid(int board[][SIZE], int row, int col, int num)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (board[row][i] == num)
            return false;
        if (board[i][col] == num)
            return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
            return false;
    }
    return true;
}

bool solve_board(int board[][SIZE])
{
    int row, col;
    if (!find_empty(board, &row, &col))
        return true;

    for (int num = 1; num <= 9; num++)
    {
        if (is_valid(board, row, col, num))
        {
            board[row][col] = num;

            if (solve_board(board))
                return true;

            board[row][col] = 0;
        }
    }
    return false;
}