//FormAI DATASET v1.0 Category: Sudoku solver ; Style: satisfied
#include<stdio.h>

int findEmpty(int grid[9][9], int *row, int *col){
    for (*row = 0; *row < 9; (*row)++){
        for (*col = 0; *col < 9; (*col)++){
            if (grid[*row][*col] == 0){
                return 1;
            }
        }
    }
    return 0;
}

int usedInRow(int grid[9][9], int row, int num){
    for (int col = 0; col < 9; col++){
        if (grid[row][col] == num){
            return 1;
        }
    }
    return 0;
}

int usedInCol(int grid[9][9], int col, int num){
    for (int row = 0; row < 9; row++){
        if (grid[row][col] == num){
            return 1;
        }
    }
    return 0;
}

int usedInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num){
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            if (grid[row+boxStartRow][col+boxStartCol] == num){
                return 1;
            }
        }
    }
    return 0;
}

int checkMoving(int grid[9][9], int row, int col, int num){
    return (!usedInRow(grid, row, num) && !usedInCol(grid, col, num) && !usedInBox(grid, row - row % 3 , col - col % 3, num));
}

int solveSudoku(int grid[9][9]){
    int row, col;
    if (!findEmpty(grid, &row, &col)){
        return 1;
    }
    for (int num = 1; num <= 9; num++){
        if (checkMoving(grid, row, col, num)){
            grid[row][col] = num;
            if (solveSudoku(grid)){
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

void printGrid(int grid[9][9]){
    for (int row = 0; row < 9; row++){
        for (int col = 0; col < 9; col++){
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int main(){
    int grid[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    
    if (solveSudoku(grid)){
        printGrid(grid);
    }
    else{
        printf("No solution available");
    }
    return 0;
}