//FormAI DATASET v1.0 Category: Sudoku solver ; Style: modular
#include <stdio.h>

// Function to print the Sudoku grid
void printGrid(int grid[9][9]){
    printf("The Sudoku Grid:\n");
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the number is safe to insert in the given cell
int isSafe(int grid[9][9],int row,int col,int num){
    // Check if the number is present in the row or column
    for(int i=0;i<9;i++){
        if(grid[row][i]==num || grid[i][col]==num){
            return 0;
        }
    }
    // Check if the number is present in the 3x3 grid
    int r = row-(row%3);
    int c = col-(col%3);
    for(int i=r;i<r+3;i++){
        for(int j=c;j<c+3;j++){
            if(grid[i][j]==num){
                return 0;
            }
        }
    }
    return 1;
}

// Function to solve the Sudoku grid using Backtracking
int solveSudoku(int grid[9][9]){
    int row, col, flag = 0;
    for(row=0;row<9;row++){
        for(col=0;col<9;col++){
            if(grid[row][col]==0){
                flag = 1;
                break; // Break from inner loop
            }
        }
        if(flag){
            break; // If the blank cell is found, break from outer loop
        }
    }
    if(!flag){
        return 1; // If no blank cell is left, solution found
    }
    for(int num=1;num<=9;num++){
        if(isSafe(grid,row,col,num)){
            grid[row][col] = num; // Fill the number in the cell if it is safe
            if(solveSudoku(grid)){
                return 1; // If solution is found, return true
            }
            grid[row][col] = 0; // If solution is not found, backtrack
        }
    }
    return 0; // If no number can be filled, backtrack
}

int main(){
    int grid[9][9] = {{5,3,0,0,7,0,0,0,0},
                      {6,0,0,1,9,5,0,0,0},
                      {0,9,8,0,0,0,0,6,0},
                      {8,0,0,0,6,0,0,0,3},
                      {4,0,0,8,0,3,0,0,1},
                      {7,0,0,0,2,0,0,0,6},
                      {0,6,0,0,0,0,2,8,0},
                      {0,0,0,4,1,9,0,0,5},
                      {0,0,0,0,8,0,0,7,9}};
    printf("Initial Sudoku Grid:\n");
    printGrid(grid);
    if(solveSudoku(grid)){
        printf("\nSolution:\n");
        printGrid(grid);
    }else{
        printf("\nNo solution exists.");
    }
    return 0;
}