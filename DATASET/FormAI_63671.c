//FormAI DATASET v1.0 Category: Sudoku solver ; Style: happy
#include <stdio.h>

#define BOARD_SIZE 9

int board[BOARD_SIZE][BOARD_SIZE];

void print_board() {
    // implementation omitted
}

int is_valid(int row, int col, int val) {
    // implementation omitted
}

int solve(int row, int col) {
    if (row == BOARD_SIZE) {
        return 1; // puzzle solved
    }
    if (board[row][col] != 0) {
        // this cell is already filled, so move to the next one
        if (col == BOARD_SIZE - 1) {
            return solve(row + 1, 0);
        } else {
            return solve(row, col + 1);
        }
    }
    for (int val = 1; val <= 9; val++) {
        if (is_valid(row, col, val)) {
            board[row][col] = val;
            if (col == BOARD_SIZE - 1) {
                if (solve(row + 1, 0)) {
                    return 1;
                }
            } else {
                if (solve(row, col + 1)) {
                    return 1;
                }
            }
            board[row][col] = 0; // undo assignment
        }
    }
    return 0; // puzzle unsolvable
}

int main() {
    // read or generate puzzle
    if (solve(0, 0)) {
        print_board();
    } else {
        printf("Puzzle unsolvable\n");
    }
    return 0;
}