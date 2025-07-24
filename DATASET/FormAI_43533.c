//FormAI DATASET v1.0 Category: Sudoku solver ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>

// Function to print the solved Sudoku board
void printSolution(int board[9][9]){
    for(int row=0; row<9; row++){
        for(int col=0; col<9; col++){
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

// Function to find the next empty cell
bool findEmptyCell(int board[9][9], int *row, int *col){
    for(*row = 0; *row < 9; (*row)++){
        for(*col = 0; *col < 9; (*col)++) {
            if(board[*row][*col] == 0){
                return true;
            }
        }
    }
    return false;
}

// Function to check if the number can be placed at the given position
bool isSafe(int board[9][9], int row, int col, int num){
    // Check if the number is already present in the row
    for(int i=0; i<9; i++){
        if(board[row][i] == num){
            return false;
        }
    }

    // Check if the number is already present in the column
    for(int i=0; i<9; i++){
        if(board[i][col] == num){
            return false;
        }
    }

    // Check if the number is already present in the 3x3 sub-grid
    int subGridRow = row - row%3;
    int subGridCol = col - col%3;
    for(int i=subGridRow; i<subGridRow+3; i++){
        for(int j=subGridCol; j<subGridCol+3; j++){
            if(board[i][j] == num){
                return false;
            }
        }
    }

    // If number is not present in the row, column, or sub-grid, then it can be placed at the given position
    return true;
}

// Function to solve the Sudoku board
bool solveSudoku(int board[9][9]){
    int row, col;
    if(!findEmptyCell(board, &row, &col)){
        // If all cells are filled, then the Sudoku board is solved
        return true;
    }

    // Try different numbers in the empty cell
    for(int num=1; num<=9; num++){
        if(isSafe(board, row, col, num)){
            // If the number can be placed at the given position, then update the board
            board[row][col] = num;

            // Recursively solve the remaining part of the board
            if(solveSudoku(board)){
                return true;
            }

            // If the remaining part of the board can't be solved with the current number, then reset the cell to 0
            board[row][col] = 0;
        }
    }

    // If none of the numbers can be placed at the given position, then the board can't be solved
    return false;
}

int main(){
    int board[9][9] = {{0, 0, 3, 0, 2, 0, 6, 0, 0},
                       {9, 0, 0, 3, 0, 5, 0, 0, 1},
                       {0, 0, 1, 8, 0, 6, 4, 0, 0},
                       {0, 0, 8, 1, 0, 2, 9, 0, 0},
                       {7, 0, 0, 0, 0, 0, 0, 0, 8},
                       {0, 0, 6, 7, 0, 8, 2, 0, 0},
                       {0, 0, 2, 6, 0, 9, 5, 0, 0},
                       {8, 0, 0, 2, 0, 3, 0, 0, 9},
                       {0, 0, 5, 0, 1, 0, 3, 0, 0}};

    if(solveSudoku(board)){
        printf("Sudoku board solution:\n");
        printSolution(board);
    } else {
        printf("Sudoku board can't be solved!\n");
    }

    return 0;
}