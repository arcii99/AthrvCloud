//FormAI DATASET v1.0 Category: Sudoku solver ; Style: post-apocalyptic
#include <stdio.h>
#define N 9

// helper function to print the Sudoku puzzle
void print(int puzzle[][N]){
    int i,j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("%d ", puzzle[i][j]);
        }
        printf("\n");
    }
}

// helper function to check if the number is already used in the row
int isUsedInRow(int puzzle[][N], int row, int num){
    int i;
    for(i=0; i<N; i++){
        if(puzzle[row][i] == num){
            return 1;
        }
    }
    return 0;
}

// helper function to check if the number is already used in the column
int isUsedInColumn(int puzzle[][N], int col, int num){
    int i;
    for(i=0; i<N; i++){
        if(puzzle[i][col] == num){
            return 1;
        }
    }
    return 0;
}

// helper function to check if the number is already used in the 3x3 grid
int isUsedInGrid(int puzzle[][N], int row, int col, int num){
    int i,j;
    int startRow = row - row%3;
    int startCol = col - col%3;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(puzzle[i+startRow][j+startCol] == num){
                return 1;
            }
        }
    }
    return 0;
}

// main solver function
int solveSudoku(int puzzle[][N], int row, int col){
    int nextRow=col==N-1? row+1 : row;
    int nextCol=col==N-1? 0 : col+1;
    int k;
    if(puzzle[row][col]!=0){
        return solveSudoku(puzzle, nextRow, nextCol);
    }
    else{
        for(k=1; k<=N; k++){
            if(!isUsedInRow(puzzle,row,k) && !isUsedInColumn(puzzle,col,k) && !isUsedInGrid(puzzle,row,col,k)){
                puzzle[row][col]=k;
                if(solveSudoku(puzzle,nextRow,nextCol)==1){
                    return 1;
                }
            }
        }
        puzzle[row][col]=0;
        return 0;
    }
}

int main(){
    int puzzle[N][N]={{8,0,0,3,4,0,0,0,0},
                      {0,0,9,7,0,2,0,0,0},
                      {2,0,0,0,0,0,0,0,0},
                      {0,4,0,8,0,0,0,5,7},
                      {0,6,0,0,0,0,0,1,0},
                      {5,2,0,0,0,3,0,8,0},
                      {0,0,0,0,0,0,0,0,9},
                      {0,0,0,6,0,8,2,0,0},
                      {0,0,0,0,7,1,0,0,4}};
    printf("Initial Puzzle:\n");
    print(puzzle);
    if(solveSudoku(puzzle,0,0)){
        printf("Solved Puzzle:\n");
        print(puzzle);
    }
    else{
        printf("No solution exists!\n");
    }
    return 0;
}