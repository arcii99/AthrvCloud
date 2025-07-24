//FormAI DATASET v1.0 Category: Sudoku solver ; Style: protected
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 9

int board[BOARD_SIZE][BOARD_SIZE];

bool canPlace(int row, int col, int num) {
    // check same row
    for(int i = 0; i < BOARD_SIZE; i++) {
        if(board[row][i] == num) {
            return false;
        }
    }

    // check same column
    for(int i = 0; i < BOARD_SIZE; i++) {
        if(board[i][col] == num) {
            return false;
        }
    }

    // check same sub-grid
    int subRow = row - (row % 3);
    int subCol = col - (col % 3);
    for(int i = subRow; i < subRow + 3; i++) {
        for(int j = subCol; j < subCol + 3; j++) {
            if(board[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solve(int row, int col) {
    if(row == BOARD_SIZE) {
        return true;
    }

    if(col == BOARD_SIZE) {
        return solve(row+1, 0);
    }

    if(board[row][col] != 0) {
        return solve(row, col+1);
    }

    for(int num = 1; num <= 9; num++) {
        if(canPlace(row, col, num)) {
            board[row][col] = num;
            if(solve(row, col+1)) {
                return true;
            }
            board[row][col] = 0;
        }
    }

    return false;
}

void printBoard() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // take user input or pre-fill board
    if(solve(0, 0)) {
        printBoard();
    } else {
        printf("No solution possible.\n");
    }

    return 0;
}