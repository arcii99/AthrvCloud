//FormAI DATASET v1.0 Category: Sudoku solver ; Style: light-weight
#include<stdio.h>

void printSudokuBoard(int board[][9]){
    for (int row = 0; row < 9; row++){
        for (int col = 0; col < 9; col++){
            printf("%d ",board[row][col]);
        }
        printf("\n");
    }
}

int canPlaceNumber(int board[][9], int row, int col, int num){
    // Check in the row
    for (int i = 0; i < 9; i++){
        if (board[row][i] == num){
            return 0;
        }
    }

    // Check in the column
    for (int i = 0; i < 9; i++){
        if (board[i][col] == num){
            return 0;
        }
    }

    // Check in the box
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (int i = boxRow; i < boxRow + 3; i++){
        for (int j = boxCol; j < boxCol + 3; j++){
            if (board[i][j] == num){
                return 0;
            }
        }
    }

    return 1;
}

int solveSudoku(int board[][9], int row, int col){
    if (row == 9){
        return 1;
    }

    if (col == 9){
        return solveSudoku(board, row + 1, 0);
    }

    if (board[row][col] != 0){
        return solveSudoku(board, row, col + 1);
    }

    for (int num = 1; num <= 9; num++){
        if (canPlaceNumber(board, row, col, num) == 1){
            board[row][col] = num;
            if (solveSudoku(board, row, col + 1) == 1){
                return 1;
            }
            board[row][col] = 0;
        }
    }

    return 0;
}

int main(){
    int board[9][9] = {
        {0, 0, 0, 0, 0, 0, 2, 0, 0},
        {0, 8, 0, 0, 0, 7, 0, 9, 0},
        {6, 0, 2, 0, 0, 0, 5, 0, 0},
        {0, 7, 0, 0, 6, 0, 0, 0, 0},
        {0, 0, 0, 9, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 2, 0, 0, 4, 0},
        {0, 0, 5, 0, 0, 0, 6, 0, 3},
        {0, 9, 0, 4, 0, 0, 0, 7, 0},
        {0, 0, 6, 0, 0, 0, 0, 0, 0}
    };

    if (solveSudoku(board, 0, 0) == 1){
        printSudokuBoard(board);
    }
    else{
        printf("Could not solve the sudoku.\n");
    }

    return 0;
}