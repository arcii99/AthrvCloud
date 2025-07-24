//FormAI DATASET v1.0 Category: Sudoku solver ; Style: ephemeral
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 9

int board[BOARD_SIZE][BOARD_SIZE] = {
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

void print_board() {
    printf("-----------------------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("|");
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %d ", board[i][j]);
            if ((j + 1) % 3 == 0) {
                printf("|");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0) {
            printf("-----------------------------\n");
        }
    }
}

bool is_valid(int row, int col, int num) {
    // Check row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] == num && i != col) {
            return false;
        }
    }
    // Check column
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][col] == num && i != row) {
            return false;
        }
    }
    // Check box
    int box_row = row / 3 * 3;
    int box_col = col / 3 * 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == num && i != row && j != col) {
                return false;
            }
        }
    }
    return true;
}

bool solve(int row, int col) {
    if (row >= BOARD_SIZE) {
        return true;
    }
    if (board[row][col] != 0) {
        if (col == BOARD_SIZE - 1) {
            if (solve(row + 1, 0)) {
                return true;
            }
        } else {
            if (solve(row, col + 1)) {
                return true;
            }
        }
        return false;
    } else {
        for (int i = 1; i <= 9; i++) {
            if (is_valid(row, col, i)) {
                board[row][col] = i;
                if (col == BOARD_SIZE - 1) {
                    if (solve(row + 1, 0)) {
                        return true;
                    }
                } else {
                    if (solve(row, col + 1)) {
                        return true;
                    }
                }
                board[row][col] = 0;
            }
        }
        return false;
    }
}

int main() {
    print_board();
    if (solve(0, 0)) {
        printf("\nSolution found:\n");
        print_board();
    } else {
        printf("\nNo solution found.\n");
    }
    return 0;
}