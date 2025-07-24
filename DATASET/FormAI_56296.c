//FormAI DATASET v1.0 Category: Sudoku solver ; Style: authentic
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

void printBoard(int board[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        if(i % 3 == 0 && i != 0){
            printf("-----------------------\n");
        }
        for(int j = 0; j < SIZE; j++){
            if(j % 3 == 0 && j != 0){
                printf("| ");
            }
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool isPossible(int board[SIZE][SIZE], int row, int col, int num){
    for(int i = 0; i < SIZE; i++){
        if(board[row][i] == num){
            return false;
        }
    }
    for(int j = 0; j < SIZE; j++){
        if(board[j][col] == num){
            return false;
        }
    }
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for(int i = boxRow; i < boxRow + 3; i++){
        for(int j = boxCol; j < boxCol + 3; j++){
            if(board[i][j] == num){
                return false;
            }
        }
    }
    return true;
}

bool findEmpty(int board[SIZE][SIZE], int* row, int* col){
    for(*row = 0; *row < SIZE; (*row)++){
        for(*col = 0; *col < SIZE; (*col)++){
            if(board[*row][*col] == 0){
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku(int board[SIZE][SIZE]){
    int row, col;
    if(!findEmpty(board, &row, &col)){
        return true;
    }
    for(int num = 1; num <= 9; num++){
        if(isPossible(board, row, col, num)){
            board[row][col] = num;
            if(solveSudoku(board)){
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

int main(){
    int board[SIZE][SIZE] = {
        {0, 0, 5, 3, 0, 0, 0, 0, 0},
        {8, 0, 0, 0, 0, 0, 0, 2, 0},
        {0, 7, 0, 0, 1, 0, 5, 0, 0},
        {4, 0, 0, 0, 0, 5, 3, 0, 0},
        {0, 1, 0, 0, 7, 0, 0, 0, 6},
        {0, 0, 3, 2, 0, 0, 0, 8, 0},
        {0, 6, 0, 5, 0, 0, 0, 0, 9},
        {0, 0, 4, 0, 0, 0, 0, 3, 0},
        {0, 0, 0, 0, 0, 9, 7, 0, 0}
    };
    
    printf("Sudoku puzzle:\n");
    printBoard(board);
    printf("\n");
    
    if (solveSudoku(board)){
        printf("Solution:\n");
        printBoard(board);
    }
    else{
        printf("Sudoku puzzle has no solution.\n");
    }
    
    return 0;
}