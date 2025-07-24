//FormAI DATASET v1.0 Category: Sudoku solver ; Style: interoperable
#include <stdio.h>

// function to print the sudoku grid
void print_board(int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// function to check if a value can be placed in a cell
int is_valid(int board[9][9], int row, int col, int val) {
    // check if value is already present in row or column
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == val || board[i][col] == val) {
            return 0;
        }
    }
    // check if value is already present in 3x3 box
    int box_row = row - (row % 3);
    int box_col = col - (col % 3);
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == val) {
                return 0;
            }
        }
    }
    return 1;
}

// function to solve the sudoku grid recursively
int solve_board(int board[9][9]) {
    int row, col, is_complete = 1;
    // check if board is complete
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                is_complete = 0;
                break;
            }
        }
        if (is_complete == 0) {
            break;
        }
    }
    // if board is complete, return success
    if (is_complete) {
        return 1;
    }
    // try values from 1 to 9 in the empty cell
    for (int i = 1; i <= 9; i++) {
        if (is_valid(board, row, col, i)) {
            board[row][col] = i;
            if (solve_board(board)) {
                return 1;
            }
            board[row][col] = 0;
        }
    }
    // if no value can be placed, backtrack
    return 0;
}

int main() {
    int board[9][9] = { // initialize sudoku grid
        {3, 0, 0, 0, 0, 0, 0, 0, 0},
        {5, 0, 0, 0, 0, 9, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 0, 0},
        {0, 0, 5, 0, 0, 0, 6, 0, 9},
        {0, 0, 0, 3, 4, 0, 0, 0, 0},
        {0, 0, 9, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 2, 0},
        {0, 0, 0, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 7, 0, 0, 0}
    };
    printf("Initial board:\n");
    print_board(board);
    if (solve_board(board)) { // solve sudoku grid
        printf("\nSolved board:\n");
        print_board(board);
    } else { // if no solution is found
        printf("No solution found.\n");
    }
    return 0;
}