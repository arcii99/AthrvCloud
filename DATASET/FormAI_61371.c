//FormAI DATASET v1.0 Category: Sudoku solver ; Style: rigorous
#include<stdio.h>
#define N 9

// Function to check if a number can be placed 
// at a certain row, column position or not
int canPlace(int grid[N][N], int row, int col, int num){
    for(int i=0;i<N;i++){
        if(grid[row][i]==num||grid[i][col]==num)
            return 0; // not possible to place number
    }
    // check 3x3 box
    int box_row=(row/3)*3;    
    int box_col=(col/3)*3;
    for(int i=box_row;i<box_row+3;i++){
        for(int j=box_col;j<box_col+3;j++){
            if(grid[i][j]==num)
                return 0;
        }
    }
    return 1; // number can be placed
}

// Recursively solve the Sudoku puzzle 
int sudokuUtil(int grid[N][N], int row, int col){
    if(row==N-1 && col==N) // reached the end of grid
        return 1;
        
    if(col==N){ // reached the end of column
        row++;
        col=0;
    }
    
    if(grid[row][col]>0) // if already filled move forward
        return sudokuUtil(grid, row, col+1); 
    
    // else try all possibilities
    for(int i=1;i<=N;i++){
        if(canPlace(grid,row,col,i)){
            grid[row][col]=i;
            if(sudokuUtil(grid,row,col+1))
                return 1; // solution found
            grid[row][col]=0; // backtrack
        }
    }
    return 0; // no solution possible
}

// Solve the Sudoku problem using recursive utility function
void solveSudoku(int grid[N][N]){
    if(sudokuUtil(grid,0,0)){
        printf("Sudoku Solved: \n");
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                printf("%d ",grid[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("No solution exists.");
}

int main(){
    int sudoku[N][N]={
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 0, 0, 0, 2, 0},
        {9, 0, 0, 8, 0, 0, 0, 0, 5},
        {0, 5, 0, 0, 0, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };
    
    printf("Original Sudoku: \n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",sudoku[i][j]);
        }
        printf("\n");
    }
    
    solveSudoku(sudoku);
    
    return 0;
}