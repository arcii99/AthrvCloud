//FormAI DATASET v1.0 Category: Sudoku solver ; Style: protected
#include<stdio.h>
#include<stdbool.h>

#define N 9

bool isPossible(int matrix[N][N], int row, int col, int num){
    //check row and column
    for(int i=0; i<N; i++){
        if(matrix[row][i] == num || matrix[i][col] == num){
            return false;
        }
    }
    //check the 3x3 sub-grid
    int sub_row = row - row%3;
    int sub_col = col - col%3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(matrix[sub_row+i][sub_col+j] == num){
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int matrix[N][N], int row, int col){
    if(row == N-1 && col == N){
        return true;
    }
    if(col == N){
        row++;
        col = 0;
    }
    if(matrix[row][col] > 0){
        return solveSudoku(matrix, row, col+1);
    }
    for(int num=1; num<=N; num++){
        if(isPossible(matrix, row, col, num)){
            matrix[row][col] = num;
            if(solveSudoku(matrix, row, col+1)){
                return true;
            }
            matrix[row][col] = 0;
        }
    }
    return false;
}

void printSudoku(int matrix[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int matrix[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                        {5, 2, 0, 0, 0, 0, 0, 0, 0},
                        {0, 8, 7, 0, 0, 0, 0, 3, 1},
                        {0, 0, 3, 0, 0, 0, 0, 2, 0},
                        {9, 0, 0, 8, 0, 0, 0, 0, 5},
                        {0, 5, 0, 0, 0, 0, 6, 0, 0},
                        {1, 3, 0, 0, 0, 0, 2, 5, 0},
                        {0, 0, 0, 0, 0, 0, 0, 7, 4},
                        {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    
    if(solveSudoku(matrix, 0, 0)){
        printSudoku(matrix);
    }
    else{
        printf("Sudoku cannot be solved!");
    }
    return 0;
}