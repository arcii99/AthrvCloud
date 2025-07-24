//FormAI DATASET v1.0 Category: Sudoku solver ; Style: innovative
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9 // for sudoku board size


void print_board(int board[SIZE][SIZE]){
    // prints the current state of sudoku board
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool is_valid(int board[SIZE][SIZE], int row, int col, int num){
    // checks if the number can be placed in given row and column safely
    for(int i=0; i<SIZE; i++){
        if(board[row][i] == num || board[i][col] == num){
            return false;
        }
    }

    // checks if the number can be placed in the subgrid safely
    int start_row = (row / 3) * 3;
    int start_col = (col / 3) * 3;

    for(int i=start_row; i<start_row + 3; i++){
        for(int j=start_col; j<start_col + 3; j++){
            if(board[i][j] == num){
                return false;
            }
        }
    }

    return true;
}

bool solve_sudoku(int board[SIZE][SIZE], int row, int col){
    // recursive function to solve sudoku

    if(row == SIZE){
        // if we have reached to last cell, sudoku is solved.
        return true;
    }

    if(col == SIZE){
        // if we reach to last column of the current row, go to next row.
        return solve_sudoku(board, row+1, 0);
    }

    if(board[row][col] != 0){
        // if the cell is already filled, move to next cell.
        return solve_sudoku(board, row, col+1);
    }

    // try to fill this cell with possible numbers.
    for(int num=1; num<=9; num++){
        if(is_valid(board, row, col, num)){
            board[row][col] = num;

            // move to next cell.
            if(solve_sudoku(board, row, col+1)){
                return true;
            }

            // if next cell is not solvable, backtrack and try next numbers in current cell.
            board[row][col] = 0;
        }
    }

    return false;
}

int main(){
    int board[SIZE][SIZE] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 0, 0, 0, 2, 0},
        {9, 0, 0, 8, 0, 0, 0, 0, 5},
        {0, 5, 0, 0, 7, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    printf("Original board:\n");
    print_board(board);

    if(solve_sudoku(board, 0, 0)){
        printf("\nSolved board:\n");
        print_board(board);
    }
    else{
        printf("\nUnable to solve the board :(\n");
    }

    return 0;
}