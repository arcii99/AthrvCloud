//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>

#define UNASSIGNED 0
#define N 9

int isSafe(int board[N][N], int row, int col, int num);
int findUnassignedLocation(int board[N][N], int *row, int *col);
int solveSudoku(int board[N][N]);

int main()
{
    int board[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                       {5, 2, 0, 0, 0, 0, 0, 0, 0},
                       {0, 8, 7, 0, 0, 0, 0, 3, 1},
                       {0, 0, 3, 0, 0, 0, 0, 2, 0},
                       {9, 0, 0, 8, 0, 0, 0, 0, 5},
                       {0, 5, 0, 0, 0, 0, 6, 0, 0},
                       {1, 3, 0, 0, 0, 0, 2, 5, 0},
                       {0, 0, 0, 0, 0, 0, 0, 7, 4},
                       {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    
    if (solveSudoku(board) == 1){
        printf("Solution:\n");
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                printf("%d ",board[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("No solution exists");
    }
    return 0;
}

int isSafe(int board[N][N], int row, int col, int num){
    // Check row
    for (int i = 0; i < N; i++){
        if (board[row][i] == num){
            return 0;
        }
    }
    
    // Check column
    for (int i = 0; i < N; i++){
        if (board[i][col] == num){
            return 0;
        }
    }
    
    // Check box
    int sqrtN = 3;
    int boxRow = row - row % sqrtN;
    int boxCol = col - col % sqrtN;
    for (int i = 0; i < sqrtN; i++){
        for (int j = 0; j < sqrtN; j++){
            if (board[i + boxRow][j + boxCol] == num){
                return 0;
            }
        }
    }
    
    return 1;
}

int findUnassignedLocation(int board[N][N], int *row, int *col){
    for (*row = 0; *row < N; (*row)++){
        for (*col = 0; *col < N; (*col)++){
            if(board[*row][*col] == UNASSIGNED){
                return 1;
            }
        }
    }
    return 0;
}

int solveSudoku(int board[N][N]){
    int row, col;
    
    if(!findUnassignedLocation(board, &row, &col)){
        return 1;
    }
    
    for(int num=1; num<=N; num++){
        if(isSafe(board,row,col,num)){
            board[row][col] = num;
            if(solveSudoku(board)){
                return 1;
            }
            board[row][col] = UNASSIGNED;
        }
    }
    
    return 0;
}