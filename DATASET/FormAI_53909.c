//FormAI DATASET v1.0 Category: Sudoku solver ; Style: thoughtful
#include <stdio.h>

#define N 9

void print_board(int board[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int is_possible(int board[N][N], int row, int col, int num) {
    // Check for row and column conflict 
    for(int i = 0; i < N; i++) {
        if(board[row][i] == num || board[i][col] == num) {
            return 0;
        }
    }
    
    //Check for block conflict
    int block_row = (row / 3) * 3;
    int block_col = (col / 3) * 3;
    
    for(int i = block_row; i < block_row + 3; i++) {
        for(int j = block_col; j < block_col + 3; j++) {
            if(board[i][j] == num) {
                return 0;
            }
        }
    }
    
    return 1;
}

int solve_sudoku(int board[N][N], int row, int col) {
    //If reached end of the board, print and return 1
    if(row == N) {
        print_board(board);
        return 1;
    }
    
    //If reached end of row, move to next row
    if(col == N) {
        return solve_sudoku(board, row + 1, 0);
    }
    
    //If already filled in, just move to next column
    if(board[row][col] != 0) {
        return solve_sudoku(board, row, col + 1);
    }
    
    //Try every possible number
    for(int num = 1; num <= N; num++) {
        if(is_possible(board, row, col, num)) {
            board[row][col] = num;
            
            //If solution is found, return true
            if(solve_sudoku(board, row, col + 1)) {
                return 1;
            }
            
            //Otherwise, reset the attempted number and try the next one
            board[row][col] = 0;
        }
    }
    
    //If no solution possible, return false
    return 0;
}

int main() {
    int board[N][N] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    
    solve_sudoku(board, 0, 0);
    
    return 0;
}