//FormAI DATASET v1.0 Category: Sudoku solver ; Style: introspective
#include <stdio.h>

// Function to print the Sudoku board
void print_board(int board[][9])
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

// Function to check if the num can be placed in the given position
int is_valid(int board[][9], int row, int col, int num)
{
    // Check for row
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == num)
            return 0;
    }

    // Check for column
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
            return 0;
    }

    // Check for box
    int start_row = row - row % 3;
    int start_col = col - col % 3;
    for (int i = start_row; i < start_row + 3; i++)
    {
        for (int j = start_col; j < start_col + 3; j++)
        {
            if (board[i][j] == num)
                return 0;
        }
    }

    return 1;
}

// Function to solve the Sudoku board
int solve_board(int board[][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (is_valid(board, i, j, num))
                    {
                        board[i][j] = num;
                        if (solve_board(board) == 1)
                            return 1;
                        else
                            board[i][j] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int board[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                       {6, 0, 0, 1, 9, 5, 0, 0, 0},
                       {0, 9, 8, 0, 0, 0, 0, 6, 0},
                       {8, 0, 0, 0, 6, 0, 0, 0, 3},
                       {4, 0, 0, 8, 0, 3, 0, 0, 1},
                       {7, 0, 0, 0, 2, 0, 0, 0, 6},
                       {0, 6, 0, 0, 0, 0, 2, 8, 0},
                       {0, 0, 0, 4, 1, 9, 0, 0, 5},
                       {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (solve_board(board) == 1)
        print_board(board);
    else
        printf("No solution exists.\n");

    return 0;
}