//FormAI DATASET v1.0 Category: Sudoku solver ; Style: beginner-friendly
#include <stdio.h>

#define SIZE 9

void print_board(int board[SIZE][SIZE]) {
    // Prints the current state of the board
    printf("-------------------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("|");
        for (int j = 0; j < SIZE; j++) {
            printf(" %d", board[i][j]);
            if ((j + 1) % 3 == 0) {
                printf(" |");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0) {
            printf("-------------------------\n");
        }
    }
}

int valid(int board[SIZE][SIZE], int n, int row, int col) {
    // Check if n is a valid number to put in the cell
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == n || board[i][col] == n) {
            return 0;
        }
    }
    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == n) {
                return 0;
            }
        }
    }
    return 1;
}

int solve(int board[SIZE][SIZE], int row, int col) {
    // Recursive function to solve the board
    if (row == SIZE) {
        return 1;
    }
    if (col == SIZE) {
        return solve(board, row + 1, 0);
    }
    if (board[row][col] != 0) {
        return solve(board, row, col + 1);
    }
    for (int n = 1; n <= 9; n++) {
        if (valid(board, n, row, col)) {
            board[row][col] = n;
            if (solve(board, row, col + 1)) {
                return 1;
            }
            board[row][col] = 0;
        }
    }
    return 0;
}


int main() {
    int board[SIZE][SIZE] = { {0, 0, 0, 0, 7, 0, 0, 0, 5},
                              {0, 8, 0, 0, 0, 9, 7, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 4, 0},
                              {7, 0, 0, 2, 0, 0, 8, 0, 9},
                              {0, 9, 0, 0, 0, 0, 0, 3, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 5, 1, 0, 0, 0, 0},
                              {1, 0, 0, 0, 0, 0, 0, 0, 4},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0} };
    if (solve(board, 0, 0)) {
        print_board(board);
    } 
    else {
        printf("Could not solve the board\n");
    }
    return 0;
}