//FormAI DATASET v1.0 Category: Sudoku solver ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

/* The Sudoku board is stored in this 2-D array*/
int board[9][9];

/* This function will print the board on the console */
void print_board() {
    printf("Sudoku Board:\n");
    printf("------------------\n");
    for(int i=0; i<9; i++) {
        printf("| ");
        for(int j=0; j<9; j++) {
            printf("%d ", board[i][j]);
            if((j+1)%3 == 0) printf("| ");
        }
        printf("\n");
        if((i+1)%3 == 0) printf("------------------\n");
    }
}

/* This function will check if the given number is present in the given row */
int is_number_present_in_row(int num, int row) {
    for(int j=0; j<9; j++) {
        if(board[row][j] == num) return 1;
    }
    return 0;
}

/* This function will check if the given number is present in the given column */
int is_number_present_in_col(int num, int col) {
    for(int i=0; i<9; i++) {
        if(board[i][col] == num) return 1;
    }
    return 0;
}

/* This function will check if the given number is present in the given 3x3 sub-grid */
int is_number_present_in_subgrid(int num, int row, int col) {
    int start_row = (row/3)*3;
    int start_col = (col/3)*3;
    for(int i=start_row; i<start_row+3; i++) {
        for(int j=start_col; j<start_col+3; j++) {
            if(board[i][j] == num) return 1;
        }
    }
    return 0;
}

/* This function will check if it's safe to put the given number at the given row and column */
int is_number_safe(int num, int row, int col) {
    int row_check = is_number_present_in_row(num, row);
    int col_check = is_number_present_in_col(num, col);
    int subgrid_check = is_number_present_in_subgrid(num, row, col);
    return (!row_check && !col_check && !subgrid_check);
}

/* This function will find the next empty cell on the board */
int find_empty_cell(int *row, int *col) {
    for(*row=0; *row<9; (*row)++) {
        for(*col=0; *col<9; (*col)++) {
            if(board[*row][*col] == 0) return 1;
        }
    }
    return 0;
}

/* This function will solve the Sudoku board recursively */
int solve_board() {
    int row, col;
    if(!find_empty_cell(&row, &col)) return 1;  // if no more empty cell, we're done!
    for(int num=1; num<=9; num++) {
        if(is_number_safe(num, row, col)) {
            board[row][col] = num;
            if(solve_board()) return 1;
            board[row][col] = 0;  // undo the previous guess and try a new one
        }
    }
    return 0;
}

/* Main function */
int main() {
    /* prepare the board */
    board[0][0] = 0;  board[0][1] = 0;  board[0][2] = 5;  board[0][3] = 3;  board[0][4] = 0;  board[0][5] = 0;  board[0][6] = 0;  board[0][7] = 0;  board[0][8] = 0;
    board[1][0] = 8;  board[1][1] = 0;  board[1][2] = 0;  board[1][3] = 0;  board[1][4] = 0;  board[1][5] = 0;  board[1][6] = 0;  board[1][7] = 2;  board[1][8] = 0;
    board[2][0] = 0;  board[2][1] = 7;  board[2][2] = 0;  board[2][3] = 0;  board[2][4] = 1;  board[2][5] = 0;  board[2][6] = 5;  board[2][7] = 0;  board[2][8] = 0;
    board[3][0] = 4;  board[3][1] = 0;  board[3][2] = 0;  board[3][3] = 0;  board[3][4] = 0;  board[3][5] = 5;  board[3][6] = 3;  board[3][7] = 0;  board[3][8] = 0;
    board[4][0] = 0;  board[4][1] = 1;  board[4][2] = 0;  board[4][3] = 0;  board[4][4] = 7;  board[4][5] = 0;  board[4][6] = 0;  board[4][7] = 0;  board[4][8] = 6;
    board[5][0] = 0;  board[5][1] = 0;  board[5][2] = 3;  board[5][3] = 2;  board[5][4] = 0;  board[5][5] = 0;  board[5][6] = 0;  board[5][7] = 8;  board[5][8] = 0;
    board[6][0] = 0;  board[6][1] = 6;  board[6][2] = 0;  board[6][3] = 5;  board[6][4] = 0;  board[6][5] = 0;  board[6][6] = 0;  board[6][7] = 0;  board[6][8] = 9;
    board[7][0] = 0;  board[7][1] = 0;  board[7][2] = 4;  board[7][3] = 0;  board[7][4] = 0;  board[7][5] = 0;  board[7][6] = 0;  board[7][7] = 3;  board[7][8] = 0;
    board[8][0] = 0;  board[8][1] = 0;  board[8][2] = 0;  board[8][3] = 0;  board[8][4] = 0;  board[8][5] = 9;  board[8][6] = 7;  board[8][7] = 0;  board[8][8] = 0;

    /* solve the board */
    if(solve_board()) print_board();
    else printf("Error: could not solve the Sudoku!\n");

    return 0;
}