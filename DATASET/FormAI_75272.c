//FormAI DATASET v1.0 Category: Sudoku solver ; Style: sophisticated
#include <stdio.h>
#include <stdbool.h>

// Function to print the Sudoku board
void print_board(int board[][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number can be placed at the given position
bool is_valid(int board[][9], int row, int col, int num) {
    // Check if the number already exists in the same row or column
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // Check if the number already exists in the same 3x3 sub-grid
    int start_row = (row / 3) * 3;
    int start_col = (col / 3) * 3;
    for (int i = start_row; i < start_row+3; ++i) {
        for (int j = start_col; j < start_col+3; ++j) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

// Recursive function to solve the Sudoku board
bool solve_board(int board[][9]) {
    // Find the next empty cell
    int row = -1, col = -1;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                break;
            }
        }
        if (row != -1) {
            break;
        }
    }

    // If there are no empty cells, the board is solved
    if (row == -1 && col == -1) {
        return true;
    }

    // Try placing numbers from 1 to 9 at the empty cell
    for (int num = 1; num <= 9; ++num) {
        if (is_valid(board, row, col, num)) {
            board[row][col] = num;
            if (solve_board(board)) {
                return true;
            }
            // Backtrack if the current placement does not lead to a solution
            board[row][col] = 0;
        }
    }

    // There is no solution
    return false;
}

int main() {
    // Example Sudoku board
    int board[9][9] = {{0, 0, 9, 0, 0, 4, 1, 0, 0},
                       {7, 2, 0, 0, 5, 0, 0, 0, 0},
                       {0, 0, 0, 3, 0, 0, 0, 0, 8},
                       {0, 7, 0, 2, 0, 0, 0, 0, 4},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {9, 0, 0, 0, 0, 8, 0, 0, 0},
                       {1, 0, 0, 0, 0, 9, 0, 0, 0},
                       {0, 0, 0, 0, 3, 0, 0, 6, 2},
                       {0, 0, 6, 7, 0, 0, 3, 0, 0}};

    printf("Sudoku board:\n");
    print_board(board);

    if (solve_board(board)) {
        printf("\nSolution:\n");
        print_board(board);
    } else {
        printf("\nThere is no solution!\n");
    }

    return 0;
}