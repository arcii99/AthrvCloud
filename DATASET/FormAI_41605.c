//FormAI DATASET v1.0 Category: Sudoku solver ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#define SIZE 9

int isSudokuSolved(int board[SIZE][SIZE]);
int isPossible(int board[SIZE][SIZE], int row, int col, int num);
void printBoard(int board[SIZE][SIZE]);
int solveSudoku(int board[SIZE][SIZE]);

int main(){
    int board[SIZE][SIZE] ={
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
    printf("Sudoku board to be solved: \n");
    printBoard(board);
    if(solveSudoku(board)){
        printf("Sudoku board solved successfully: \n");
        printBoard(board);
    } else{
        printf("Sudoku board could not be solved!");
    }
    return 0;
}

// Function to check whether the given Sudoku board is solved or not
int isSudokuSolved(int board[SIZE][SIZE]){
    int row, col;
    for(row=0;row<SIZE;row++){
        for(col=0;col<SIZE;col++){
            if(board[row][col]==0){
                return 0;
            }
        }
    }
    return 1;
}

// Function to check whether it is possible to place the given number at the given row and column or not
int isPossible(int board[SIZE][SIZE], int row, int col, int num){
    int i, j, rowStart, colStart;
    for(i=0;i<SIZE;i++){
        if(board[row][i]==num){
            return 0;
        }
        if(board[i][col]==num){
            return 0;
        }
    }
    rowStart = (row/3)*3;
    colStart = (col/3)*3;
    for(i=rowStart;i<rowStart+3;i++){
        for(j=colStart;j<colStart+3;j++){
            if(board[i][j]==num){
                return 0;
            }
        }
    }
    return 1;
}

// Function to print the Sudoku board
void printBoard(int board[SIZE][SIZE]){
    int row, col;
    for(row=0;row<SIZE;row++){
        for(col=0;col<SIZE;col++){
            printf("%d ",board[row][col]);
        }
        printf("\n");
    }
}

// Function to solve the given Sudoku puzzle
int solveSudoku(int board[SIZE][SIZE]){
    int row, col, num;
    if(isSudokuSolved(board)){
        return 1;
    }
    for(row=0;row<SIZE;row++){
        for(col=0;col<SIZE;col++){
            if(board[row][col]==0){
                for(num=1;num<=SIZE;num++){
                    if(isPossible(board,row,col,num)){
                        board[row][col] = num;
                        if(solveSudoku(board)){
                            return 1;
                        } else{
                            board[row][col] = 0;
                        }
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}