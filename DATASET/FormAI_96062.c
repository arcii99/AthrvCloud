//FormAI DATASET v1.0 Category: Sudoku solver ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9

bool is_valid_move(int board[SIZE][SIZE], int row, int col, int num)
{
    int i, j;
    // Check row
    for (i = 0; i < SIZE; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }
    // Check column
    for (i = 0; i < SIZE; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }
    // Check box
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (i = box_row; i < box_row + 3; i++) {
        for (j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solve_sudoku(int board[SIZE][SIZE])
{
    int row, col, num;
    // Find an empty spot
    bool found = false;
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board[row][col] == 0) {
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    // If there are no empty spots, the game is solved
    if (!found) {
        return true;
    }
    // Try all possible numbers in the empty spot until one is valid
    for (num = 1; num <= 9; num++) {
        if (is_valid_move(board, row, col, num)) {
            board[row][col] = num;
            // Continue solving the rest of the board recursively
            if (solve_sudoku(board)) {
                return true;
            }
            // Undo the move if it doesn't lead to a solution
            board[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    // Initialize the Sudoku board
    int board[SIZE][SIZE] = {
        {0, 0, 3, 0, 2, 0, 6, 0, 0},
        {9, 0, 0, 3, 0, 5, 0, 0, 1},
        {0, 0, 1, 8, 0, 6, 4, 0, 0},
        {0, 0, 8, 1, 0, 2, 9, 0, 0},
        {7, 0, 0, 0, 0, 0, 0, 0, 8},
        {0, 0, 6, 7, 0, 8, 2, 0, 0},
        {0, 0, 2, 6, 0, 9, 5, 0, 0},
        {8, 0, 0, 2, 0, 3, 0, 0, 9},
        {0, 0, 5, 0, 1, 0, 3, 0, 0}
    };

    printf("Original Sudoku board:\n");
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Solve the Sudoku board
    if (solve_sudoku(board)) {
        printf("Solved Sudoku board:\n");
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution found for the given Sudoku board.\n");
    }

    return 0;
}