//FormAI DATASET v1.0 Category: Sudoku solver ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
 
#define N 9
 
void print_board(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}
 
int is_valid(int board[N][N], int row, int col, int num) {
    // Check if the num is already in the row
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }
 
    // Check if the num is already in the column
    for (int i = 0; i < N; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }
 
    // Check if the num is already in the box
    int box_start_row = row - row % 3;
    int box_start_col = col - col % 3;
    for (int i = box_start_row; i < box_start_row + 3; i++) {
        for (int j = box_start_col; j < box_start_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
 
    // If the num is not already in row, column or box then it is valid
    return 1;
}
 
int solve_sudoku(int board[N][N], int row, int col) {
    // If we reached the end of the board then we successfully solved the Sudoku
    if (row == N - 1 && col == N) {
        return 1;
    }
 
    // If we reached the end of the row then move to the next row
    if (col == N) {
        row++;
        col = 0;
    }
 
    // If we found a non-zero value at a given cell then skip it
    if (board[row][col] > 0) {
        return solve_sudoku(board, row, col + 1);
    }
 
    // Try all the numbers from 1 to 9 in the given cell
    for (int num = 1; num <= 9; num++) {
        if (is_valid(board, row, col, num)) {
            board[row][col] = num;
            if (solve_sudoku(board, row, col + 1)) {
                return 1;
            }
            board[row][col] = 0;
        }
    }
 
    return 0;
}
 
int main() {
    int board[N][N] = {{8, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 3, 6, 0, 0, 0, 0, 0},
                       {0, 7, 0, 0, 9, 0, 2, 0, 0},
                       {0, 5, 0, 0, 0, 7, 0, 0, 0},
                       {0, 0, 0, 0, 4, 5, 7, 0, 0},
                       {0, 0, 0, 1, 0, 0, 0, 3, 0},
                       {0, 0, 1, 0, 0, 0, 0, 6, 8},
                       {0, 0, 8, 5, 0, 0, 0, 1, 0},
                       {0, 9, 0, 0, 0, 0, 4, 0, 0}};
 
    if (solve_sudoku(board, 0, 0)) {
        print_board(board);
    } else {
        printf("No solution exists!");
    }
 
    return 0;
}