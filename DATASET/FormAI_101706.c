//FormAI DATASET v1.0 Category: Sudoku solver ; Style: modular
#include<stdio.h>

//Function to print the Sudoku board
void printBoard(int board[9][9]){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            printf("%d ",board[i][j]);    
        }
        printf("\n");
    }
}

//Function to check if a move is valid for a given cell
int isValid(int board[9][9], int row, int col, int num){
    //Checking if the number is already present in the same row or column
    for(int i = 0; i < 9; i++){
        if(board[row][i] == num || board[i][col] == num){
            return 0;
        }
    }
    //Checking if the number is already present in the same 3x3 box
    int subRow = (row/3)*3, subCol = (col/3)*3;
    for(int i = subRow; i < subRow+3; i++){
        for(int j = subCol; j < subCol+3; j++){
            if(board[i][j] == num){
                return 0;
            }
        }
    }
    return 1;
}

//Function to solve the Sudoku board
int solveSudoku(int board[9][9]){
    int row, col, num;
    //Finding the next empty cell
    for(row = 0; row < 9; row++){
        for(col = 0; col < 9; col++){
            if(board[row][col] == 0){
                //Checking numbers 1-9 for a valid move
                for(num = 1; num <= 9; num++){
                    if(isValid(board,row,col,num)){
                        board[row][col] = num;
                        if(solveSudoku(board)){
                            return 1;
                        }
                        board[row][col] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    int board[9][9] = {{0,0,0,7,0,0,0,0,0},
                      {1,5,0,0,0,3,4,0,0},
                      {0,0,4,0,0,0,0,0,0},
                      {0,6,0,0,1,0,0,5,0},
                      {0,0,0,0,5,0,0,0,0},
                      {0,9,0,0,7,0,0,8,0},
                      {0,0,0,0,0,0,1,0,0},
                      {0,0,7,2,0,0,0,9,8},
                      {0,0,0,0,0,0,0,0,0}};
    printf("Sudoku Board:\n");
    printBoard(board);
    if(solveSudoku(board)){
        printf("Solved Sudoku Board:\n");
        printBoard(board);
    }
    else{
        printf("Invalid Sudoku Board!\n");
    }
    return 0;
}