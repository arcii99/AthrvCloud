//FormAI DATASET v1.0 Category: Sudoku solver ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int row;
    int column;
    int box;
} Cell;

void print_board(Cell board[][9]);
void solve_board(Cell board[][9]);
int find_next_empty(Cell board[][9], int* row, int* col);
int is_valid(Cell board[][9], int row, int col, int val);

int main() {
    Cell board[9][9];

    // initialize board with some values
    board[0][1].value = 2;
    board[0][3].value = 4;
    board[0][7].value = 5;
    board[1][0].value = 3;
    board[1][1].value = 6;
    board[1][5].value = 1;
    board[2][2].value = 7;
    board[2][8].value = 6;
    board[3][2].value = 1;
    board[3][3].value = 9;
    board[3][4].value = 5;
    board[3][7].value = 8;
    board[4][0].value = 4;
    board[4][2].value = 5;
    board[4][5].value = 8;
    board[4][8].value = 1;
    board[5][1].value = 7;
    board[5][4].value = 3;
    board[5][5].value = 4;
    board[5][6].value = 2;
    board[6][0].value = 5;
    board[6][6].value = 3;
    board[6][8].value = 4;
    board[7][3].value = 8;
    board[7][7].value = 1;
    board[7][8].value = 7;
    board[8][1].value = 1;
    board[8][5].value = 9;
    board[8][7].value = 6;

    printf("Initial board:\n");
    print_board(board);

    solve_board(board);

    printf("Solved board:\n");
    print_board(board);

    return 0;
}

// prints the current state of the board
void print_board(Cell board[][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", board[i][j].value);
            if ((j + 1) % 3 == 0 && j < 8) printf("| ");
        }
        printf("\n");
        if ((i + 1) % 3 == 0 && i < 8) printf("---------------------\n");
    }
    printf("\n");
}

// solves the sudoku board using recursion
void solve_board(Cell board[][9]) {
    int row, col;
    if (!find_next_empty(board, &row, &col)) return; // board is filled, base case

    for (int val = 1; val <= 9; val++) {
        if (is_valid(board, row, col, val)) {
            board[row][col].value = val;
            solve_board(board);
            if (!find_next_empty(board, &row, &col)) return; // board is filled, base case
            board[row][col].value = 0; // undo previous move
        }
    }
}

// finds the next empty cell in the board
int find_next_empty(Cell board[][9], int* row, int* col) {
    for (*row = 0; *row < 9; (*row)++) {
        for (*col = 0; *col < 9; (*col)++) {
            if (board[*row][*col].value == 0) {
                return 1; // cell is empty
            }
        }
    }
    return 0; // board is filled
}

// checks if a given move is valid
int is_valid(Cell board[][9], int row, int col, int val) {
    // check row constraints
    for (int j = 0; j < 9; j++) {
        if (board[row][j].value == val) return 0;
    }

    // check column constraints
    for (int i = 0; i < 9; i++) {
        if (board[i][col].value == val) return 0;
    }

    // check box constraints
    int row_start = row / 3 * 3;
    int col_start = col / 3 * 3;
    for (int i = row_start; i < row_start + 3; i++) {
        for (int j = col_start; j < col_start + 3; j++) {
            if (board[i][j].value == val) {
                return 0;
            }
        }
    }

    return 1; // move is valid
}