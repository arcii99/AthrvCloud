//FormAI DATASET v1.0 Category: Sudoku solver ; Style: puzzling
#include <stdio.h>

#define SIZE 9  // The size of the Sudoku board

// Function to print the Sudoku board
void print_board(int board[SIZE][SIZE]) {
    printf("-------------------\n");

    for (int i = 0; i < SIZE; i++) {
        printf("| ");

        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }

        printf("|\n");
    }

    printf("-------------------\n");
}

// Function to check if a number can be placed in a given row and column
int is_valid(int board[SIZE][SIZE], int row, int col, int num) {
    // Check row
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }

    // Check column
    for (int i = 0; i < SIZE; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }

    // Check box
    int box_row = row - row % 3;
    int box_col = col - col % 3;

    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to solve the Sudoku board recursively
int solve_board(int board[SIZE][SIZE], int row, int col) {
    if (row == SIZE) {
        return 1;
    }

    if (col == SIZE) {
        return solve_board(board, row + 1, 0);
    }

    if (board[row][col] != 0) {
        return solve_board(board, row, col + 1);
    }

    for (int num = 1; num <= SIZE; num++) {
        if (is_valid(board, row, col, num)) {
            board[row][col] = num;

            if (solve_board(board, row, col + 1)) {
                return 1;
            }

            board[row][col] = 0;
        }
    }

    return 0;
}

int main() {
    int board[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    printf("Sudoku board before solving:\n");
    print_board(board);

    if (solve_board(board, 0, 0)) {
        printf("Sudoku board after solving:\n");
        print_board(board);
    } else {
        printf("No solution found!\n");
    }

    return 0;
}