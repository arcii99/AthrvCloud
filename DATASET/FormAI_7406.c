//FormAI DATASET v1.0 Category: Sudoku solver ; Style: brave
#include<stdio.h>

//Function to print the Sudoku grid
void printGrid(int grid[9][9]) {
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

//Function to check if the number is valid in the given row
int isValidRow(int grid[9][9], int row, int num) {
    for(int i=0;i<9;i++) {
        if(grid[row][i] == num) {
            return 0;
        }
    }
    return 1;
}

//Function to check if the number is valid in the given column
int isValidColumn(int grid[9][9], int col, int num) {
    for(int i=0;i<9;i++) {
        if(grid[i][col] == num) {
            return 0;
        }
    }
    return 1;
}

//Function to check if the number is valid in the given 3x3 box
int isValidBox(int grid[9][9], int row, int col, int num) {
    int boxRow = row - (row % 3);
    int boxCol = col - (col % 3);
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(grid[boxRow+i][boxCol+j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

//Function to check if the number is valid in the given position
int isValidPosition(int grid[9][9], int row, int col, int num) {
    if(!isValidRow(grid, row, num) || !isValidColumn(grid, col, num) || !isValidBox(grid, row, col, num)) {
        return 0;
    }
    return 1;
}

//Function to solve the Sudoku grid
int solveSudoku(int grid[9][9], int row, int col) {
    if(row == 8 && col == 9) {
        return 1;
    }
    if(col == 9) {
        row++;
        col = 0;
    }
    if(grid[row][col] > 0) {
        return solveSudoku(grid, row, col+1);
    }
    for(int num=1;num<=9;num++) {
        if(isValidPosition(grid, row, col, num)) {
            grid[row][col] = num;
            if(solveSudoku(grid, row, col+1)) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

//Driver function
int main() {
    int grid[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    //Sample input, modify this grid to solve your own Sudoku
    int input[9][9] = {{3,0,6,5,0,8,4,0,0},
                       {5,2,0,0,0,0,0,0,0},
                       {0,8,7,0,0,0,0,3,1},
                       {0,0,3,0,0,0,0,2,0},
                       {9,0,0,8,0,0,0,0,5},
                       {0,5,0,0,0,0,6,0,0},
                       {1,3,0,0,0,0,2,5,0},
                       {0,0,0,0,0,0,0,7,4},
                       {0,0,5,2,0,6,3,0,0}};

    //Copy the input into the grid
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            grid[i][j] = input[i][j];
        }
    }

    //Let's solve the Sudoku
    if(solveSudoku(grid, 0, 0)) {
        printf("Sudoku solved successfully!\n");
        printGrid(grid);
    }
    else {
        printf("Unable to solve the given Sudoku.\n");
    }

    return 0;
}