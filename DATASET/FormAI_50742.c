//FormAI DATASET v1.0 Category: Sudoku solver ; Style: sophisticated
#include<stdio.h>

int findEmpty(int grid[][9], int *row, int *col) {
    for(*row = 0; *row < 9; (*row)++) {
        for(*col = 0; *col < 9; (*col)++) {
            if(grid[*row][*col] == 0) {
                return 1;
           }
        }
    }
    return 0;
}

int checkRow(int grid[][9], int row, int num) {
    for(int col = 0; col < 9; col++) {
        if(grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

int checkCol(int grid[][9], int col, int num) {
    for(int row = 0; row < 9; row++) {
        if(grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

int checkBox(int grid[][9], int box_start_row, int box_start_col, int num) {
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            if(grid[row+box_start_row][col+box_start_col] == num) {
                return 1;
            }
        }
    }
    return 0;
}

int isValid(int grid[][9], int row, int col, int num) {
    return !checkRow(grid,row,num) && !checkCol(grid,col,num) && !checkBox(grid,row-row%3,col-col%3,num);
}

int solveSudoku(int grid[][9]){
    int row, col;

    if(!findEmpty(grid, &row, &col)) {
        return 1;
    }

    for(int num = 1; num <= 9; num++) {
        if(isValid(grid,row,col,num)) {
            grid[row][col] = num;

            if(solveSudoku(grid)) {
                return 1;
            }

            grid[row][col] = 0;
        }
    }
    return 0;
}

void printGrid(int grid[][9]) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int grid[9][9]={{0,0,0,0,0,8,0,0,0},
                    {0,2,0,7,0,0,0,4,0},
                    {0,0,0,4,0,6,2,8,0},
                    {0,1,0,0,0,0,9,0,0},
                    {7,0,0,0,4,0,0,6,0},
                    {0,0,0,0,0,0,0,0,8},
                    {3,0,0,0,0,0,7,1,0},
                    {1,0,5,0,7,9,0,0,2},
                    {6,0,0,0,0,1,0,0,0}};
    printf("Given Sudoku puzzle:\n");
    printGrid(grid);

    if(solveSudoku(grid)) {
        printf("\nSolved Sudoku puzzle:\n");
        printGrid(grid);
    }
    else {
        printf("\nInvalid Sudoku puzzle.\n");
    }
    return 0;
}