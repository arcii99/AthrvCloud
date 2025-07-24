//FormAI DATASET v1.0 Category: Sudoku solver ; Style: satisfied
#include<stdio.h>

void printSudoku(int grid[9][9]) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int checkRow(int grid[9][9], int row, int num) {
    for(int i=0; i<9; i++) {
        if(grid[row][i] == num)
            return 1;
    }
    return 0;
}

int checkCol(int grid[9][9], int col, int num) {
    for(int i=0; i<9; i++) {
        if(grid[i][col] == num)
            return 1;
    }
    return 0;
}

int checkBox(int grid[9][9], int row, int col, int num) {
    int boxStartRow = row - row % 3;
    int boxStartCol = col - col % 3;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(grid[i+boxStartRow][j+boxStartCol] == num)
                return 1;
        }
    }
    return 0;
}

int isSafe(int grid[9][9], int row, int col, int num) {
    return (!checkRow(grid, row, num)
            && !checkCol(grid, col, num)
            && !checkBox(grid, row, col, num));
}

int findEmptyCell(int grid[9][9], int* row, int* col) {
    for(*row=0; *row<9; (*row)++) {
        for(*col=0; *col<9; (*col)++) {
            if(grid[*row][*col] == 0)
                return 1;
        }
    }
    
    return 0;
}

int solveSudoku(int grid[9][9]) {
    int row, col;
    
    if(!findEmptyCell(grid, &row, &col))
        return 1;
        
    for(int num=1; num<=9; num++) {
        if(isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            
            if(solveSudoku(grid))
                return 1;
                
            grid[row][col] = 0;
        }
    }
    
    return 0;
}

int main() {
    int grid[9][9] = { { 0, 3, 0, 0, 4, 0, 9, 0, 5 },
                       { 4, 0, 0, 8, 7, 0, 1, 0, 0 },
                       { 0, 0, 5, 0, 0, 0, 0, 6, 7 },
                       { 0, 0, 2, 0, 0, 4, 3, 0, 9 },
                       { 0, 0, 0, 0, 0, 8, 4, 1, 0 },
                       { 0, 0, 1, 0, 5, 0, 7, 0, 0 },
                       { 5, 4, 3, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 8, 0, 0, 5, 6, 0, 3 },
                       { 0, 0, 0, 9, 0, 0, 0, 7, 0 } };
    
    printf("Sudoku before solving:\n");
    printSudoku(grid);
    
    if(solveSudoku(grid)) {
        printf("\nSudoku after solving:\n");
        printSudoku(grid);
    }
    else {
        printf("\nInvalid Sudoku");
    }
    
    return 0;
}