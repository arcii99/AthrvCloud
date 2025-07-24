//FormAI DATASET v1.0 Category: Sudoku solver ; Style: decentralized
// C Sudoku Solver Example Program

#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 9 /* size of the sudoku board (9x9) */

/* function declarations */
bool is_valid_move(int board[][BOARD_SIZE], int row, int col, int num);
bool find_empty_slot(int board[][BOARD_SIZE], int *row, int *col);
bool solve_sudoku(int board[][BOARD_SIZE]);
void print_board(int board[][BOARD_SIZE]);

/**
 * Function to check if move is valid in sudoku board.
 *
 * @param board  2D array represeting sudoku board
 * @param row    row of current slot
 * @param col    column of current slot
 * @param num    number to be placed in current slot
 *
 * @return       true if move is valid, false if invalid
 */
bool is_valid_move(int board[][BOARD_SIZE], int row, int col, int num) {
    /* check row for same number */
    for(int i = 0; i < BOARD_SIZE; i++) {
        if(board[row][i] == num) {
            return false;
        }
    }

    /* check column for same number */
    for(int i = 0; i < BOARD_SIZE; i++) {
        if(board[i][col] == num) {
            return false;
        }
    }

    /* check 3x3 sub-grid for same number */
    int row_start = row - (row % 3);
    int col_start = col - (col % 3);

    for(int i = row_start; i < row_start + 3; i++) {
        for(int j = col_start; j < col_start + 3; j++) {
            if(board[i][j] == num) {
                return false;
            }
        }
    }

    /* if no duplicate found, move is valid */
    return true;
}

/**
 * Function to find empty slot in sudoku board.
 *
 * @param board  2D array represeting sudoku board
 * @param row    address of variable to hold row of empty slot
 * @param col    address of variable to hold column of empty slot
 *
 * @return       true if empty slot is found, false if board is filled
 */
bool find_empty_slot(int board[][BOARD_SIZE], int *row, int *col) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == 0) {
                *row = i;
                *col = j;
                return true;
            }
        }
    }

    /* if no empty slot is found, board is filled */
    return false;
}

/**
 * Solves the sudoku board using backtracking.
 *
 * @param board  2D array represeting sudoku board
 *
 * @return       true if board is solved, false if unsolvable
 */
bool solve_sudoku(int board[][BOARD_SIZE]) {
    int row, col;

    /* if board is filled, sudoku is solved */
    if(!find_empty_slot(board, &row, &col)) {
        return true;
    }

    /* try numbers 1-9 in current empty slot */
    for(int num = 1; num <= BOARD_SIZE; num++) {
        /* check if move is valid */
        if(is_valid_move(board, row, col, num)) {
            /* make move */
            board[row][col] = num;

            /* recursively solve the rest of the board */
            if(solve_sudoku(board)) {
                return true;
            }

            /* undo move if it leads to an unsolvable board */
            board[row][col] = 0;
        }
    }

    /* if no solution found, backtrack and try another number */
    return false;
}

/**
 * Function to print the sudoku board.
 *
 * @param board  2D array represeting sudoku board
 */
void print_board(int board[][BOARD_SIZE]) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
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

    printf("Sudoku board before solving:\n");
    print_board(board);

    if(solve_sudoku(board)) {
        printf("\nSudoku solved successfully!\n");
        printf("Sudoku board after solving:\n");
        print_board(board);
    } else {
        printf("\nSudoku is unsolvable :(\n");
    }

    return 0;
}