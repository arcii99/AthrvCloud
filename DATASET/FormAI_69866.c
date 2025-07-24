//FormAI DATASET v1.0 Category: Sudoku solver ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>

#define EMPTY 0
#define SIZE 9

void print_board(int board[SIZE][SIZE]) {  // Prints the Sudoku board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%2d", board[i][j]);
        }
        printf("\n");
    }
}

bool find_empty(int board[SIZE][SIZE], int *i, int *j) {  // Finds empty cell in the board
    for (*i = 0; *i < SIZE; (*i)++) {
        for (*j = 0; *j < SIZE; (*j)++) {
            if (board[*i][*j] == EMPTY) {
                return true;
            }
        }
    }
    return false;
}

bool is_possible(int board[SIZE][SIZE], int i, int j, int num) {  // Checks if a number is possible in a cell
    int row_start = (i / 3) * 3;
    int col_start = (j / 3) * 3;

    for (int k = 0; k < SIZE; k++) {
        if (board[i][k] == num || board[k][j] == num) {
            return false;
        }
    }

    for (int row = row_start; row < row_start + 3; row++) {
        for (int col = col_start; col < col_start + 3; col++) {
            if (board[row][col] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solve_board(int board[SIZE][SIZE]) {  // Solves the Sudoku board using backtracking
    int i = 0, j = 0;
    if (!find_empty(board, &i, &j)) {
        return true;
    }

    for (int num = 1; num <= SIZE; num++) {
        if (is_possible(board, i, j, num)) {
            board[i][j] = num;
            if (solve_board(board)) {
                return true;
            }
            board[i][j] = EMPTY;
        }
    }

    return false;
}

int main() {
    int board[SIZE][SIZE] = {
        {8, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 6, 0, 0, 0, 0, 0},
        {0, 7, 0, 0, 9, 0, 2, 0, 0},
        {0, 5, 0, 0, 0, 7, 0, 0, 0},
        {0, 0, 0, 0, 4, 5, 7, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 3, 0},
        {0, 0, 1, 0, 0, 0, 0, 6, 8},
        {0, 0, 8, 5, 0, 0, 0, 1, 0},
        {0, 9, 0, 0, 0, 0, 4, 0, 0},
    };

    printf("Sudoku board before solving:\n");
    print_board(board);

    if (solve_board(board)) {
        printf("\nSudoku board after solving:\n");
        print_board(board);
    }
    else {
        printf("\nNo solution exists.\n");
    }

    return 0;
}