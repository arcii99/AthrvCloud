//FormAI DATASET v1.0 Category: Sudoku solver ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define size 9

// Function to print the Sudoku Grid
void print_board(int board[][size]) {
    printf("+-----+-----+-----+\n");
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            if(j%3 == 0) {
                printf("| ");
            }
            printf("%d ",board[i][j]);
        }
        if((i+1)%3 == 0) {
            printf("|\n+-----+-----+-----+\n");
        } else {
            printf("|\n");
        }
    }
}

// Function to check if the number n is valid
bool is_valid(int board[][size], int row, int col, int n) {
    // Checking if the same number exists in the same row or column
    for(int i=0;i<size;i++) {
        if(board[row][i] == n || board[i][col] == n) {
            return false;
        }
    }
    // Checking if the same number exists in the same 3x3 matrix
    int row_start = (row/3)*3;
    int col_start = (col/3)*3;
    for(int i=row_start;i<row_start+3;i++) {
        for(int j=col_start;j<col_start+3;j++) {
            if(board[i][j] == n) {
                return false;
            }
        }
    }
    return true;
}

// Function to solve the Sudoku board
bool solve_sudoku(int board[][size]) {
    int row = -1;
    int col = -1;
    bool is_complete = true;
    
    // Checking if the board is already complete or not
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            if(board[i][j] == 0) {
                row = i;
                col = j;
                is_complete = false;
                break;
            }
        }
        if(!is_complete) {
            break;
        }
    }
    
    // If the board is already complete, return true
    if(is_complete) {
        return true;
    }
    
    // Checking the possibility of number in each cell
    for(int i=1;i<=size;i++) {
        if(is_valid(board,row,col,i)) {
            board[row][col] = i;
            if(solve_sudoku(board)) {
                return true;    // If the number is valid, continue with the next empty cell
            }
            board[row][col] = 0;  // If the number is not valid, reset the cell and try the next number
        }
    }
    return false;   // If no number is valid, return false, and backtrack
}

int main() {
    int sudoku_board[size][size] = {
        {8, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 6, 0, 0, 0, 0, 0},
        {0, 7, 0, 0, 9, 0, 2, 0, 0},
        {0, 5, 0, 0, 0, 7, 0, 0, 0},
        {0, 0, 0, 0, 4, 5, 7, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 3, 0},
        {0, 0, 1, 0, 0, 0, 0, 6, 8},
        {0, 0, 8, 5, 0, 0, 0, 1, 0},
        {0, 9, 0, 0, 0, 0, 4, 0, 0}
    };

    printf("Sudoku Board:\n");
    print_board(sudoku_board);

    // Solving the Sudoku Board
    if(solve_sudoku(sudoku_board)) {
        printf("\nSolved Sudoku Board:\n");
        print_board(sudoku_board);
    } else {
        printf("\nNo Solution Found\n");
    }

    return 0;
}