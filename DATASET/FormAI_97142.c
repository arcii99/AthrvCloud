//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Linus Torvalds
/* Linux-style Sudoku Solver Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ROWS 9
#define COLS 9

typedef struct cell {
    int value;
    bool locked;
} Cell;

Cell board[ROWS][COLS];

int find_empty_cell(int *row, int *col) {
    for (*row = 0; *row < ROWS; ++*row) {
        for (*col = 0; *col < COLS; ++*col) {
            if (board[*row][*col].value == 0) {
                return 1;
            }
        }
    }
    return 0;
}

bool is_valid_value(int row, int col, int value) {
    int i, j;
    // Check row and column
    for (i = 0; i < ROWS; ++i) {
        if (board[i][col].value == value ||
            board[row][i].value == value) {
            return false;
        }
    }
    // Check 3x3 box
    int box_row = row - (row % 3);
    int box_col = col - (col % 3);
    for (i = box_row; i < box_row + 3; ++i) {
        for (j = box_col; j < box_col + 3; ++j) {
            if (board[i][j].value == value) {
                return false;
            }
        }
    }
    return true;
}

bool solve_sudoku() {
    int row, col;
    if (!find_empty_cell(&row, &col)) {
        return true;
    }
    int i;
    for (i = 1; i <= 9; ++i) {
        if (is_valid_value(row, col, i)) {
            board[row][col].value = i;
            if (solve_sudoku()) {
                return true;
            }
            board[row][col].value = 0;
        }
    }
    return false;
}

void print_board() {
    int i, j;
    printf(" -------------------------\n");
    for (i = 0; i < ROWS; ++i) {
        printf("| ");
        for (j = 0; j < COLS; ++j) {
            printf("%d ", board[i][j].value);
            if ((j + 1) % 3 == 0) {
                printf("| ");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0) {
            printf(" -------------------------\n");
        }
    }
}

int main() {
    int i, j;
    // Initialize board
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            board[i][j].value = 0;
            board[i][j].locked = false;
        }
    }
    // Set up example puzzle
    board[0][0].value = 5;
    board[0][1].value = 3;
    board[0][4].value = 7;
    board[1][0].value = 6;
    board[1][3].value = 1;
    board[1][4].value = 9;
    board[1][5].value = 5;
    board[2][1].value = 9;
    board[2][2].value = 8;
    board[2][7].value = 6;
    board[3][0].value = 8;
    board[3][4].value = 6;
    board[3][8].value = 3;
    board[4][0].value = 4;
    board[4][3].value = 8;
    board[4][5].value = 3;
    board[4][8].value = 1;
    board[5][0].value = 7;
    board[5][4].value = 2;
    board[5][8].value = 6;
    board[6][1].value = 6;
    board[6][6].value = 2;
    board[6][7].value = 8;
    board[7][3].value = 4;
    board[7][4].value = 1;
    board[7][5].value = 9;
    board[7][8].value = 5;
    board[8][4].value = 8;
    board[8][7].value = 7;
    board[8][8].value = 9;

    printf("Original board:\n");
    print_board();
    printf("\n");

    if (solve_sudoku()) {
        printf("Solution:\n");
        print_board();
    } else {
        printf("Unable to solve Sudoku puzzle\n");
    }

    return 0;
}