//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 9
#define COLS 9
#define BOX_ROWS 3
#define BOX_COLS 3

int board[ROWS][COLS] = {
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

bool solve_sudoku(int row, int col) {
    if (row == ROWS - 1 && col == COLS) {
        return true;
    }
    if (col == COLS) {
        row++;
        col = 0;
    }
    if (board[row][col] > 0) {
        return solve_sudoku(row, col+1);
    }
    for (int num = 1; num <= 9; num++) {
        bool valid = true;
        for (int i = 0; i < ROWS; i++) {
            if (board[i][col] == num) {
                valid = false;
                break;
            }
        }
        if (valid) {
            for (int i = 0; i < COLS; i++) {
                if (board[row][i] == num) {
                    valid = false;
                    break;
                }
            }
        }
        int box_row = row - row % BOX_ROWS;
        int box_col = col - col % BOX_COLS;
        if (valid) {
            for (int i = box_row; i < box_row + BOX_ROWS; i++) {
                for (int j = box_col; j < box_col + BOX_COLS; j++) {
                    if (board[i][j] == num) {
                        valid = false;
                        break;
                    }
                }
            }
        }
        
        if (valid) {
            board[row][col] = num;
            if (solve_sudoku(row, col+1)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

void print_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
            if ((j+1) % BOX_COLS == 0 && j < COLS - 1) {
                printf("| ");
            }
        }
        printf("\n");
        if ((i+1) % BOX_ROWS == 0 && i < ROWS - 1) {
            printf("--------------------\n");
        }
    }
}

int main() {
    printf("Original Board:\n");
    print_board();
    if (solve_sudoku(0, 0)) {
        printf("\nSolved Board:\n");
        print_board();
    } else {
        printf("\nNo solution exists for the board.\n");
    }
    return 0;
}