//FormAI DATASET v1.0 Category: Sudoku solver ; Style: intelligent
#include <stdio.h>
#include <stdbool.h>

bool checkRow(int grid[][9], int row, int num){
    for(int col = 0; col < 9; col++){
        if(grid[row][col] == num){
            return false;
        }
    }
    return true;
}

bool checkCol(int grid[][9], int col, int num){
    for(int row = 0; row < 9; row++){
        if(grid[row][col] == num){
            return false;
        }
    }
    return true;
}

bool checkBox(int grid[][9], int startRow, int startCol, int num){
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++){
            if(grid[row+startRow][col+startCol] == num){
                return false;
            }
        }
    }
    return true;
}

bool findEmptyLocation(int grid[][9], int *row, int *col){
    for(*row = 0; *row < 9; (*row)++){
        for(*col = 0; *col < 9; (*col)++){
            if(grid[*row][*col] == 0){
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku(int grid[][9]){
    int row;
    int col;
    if(!findEmptyLocation(grid, &row, &col)){
        return true;
    }
    for(int num = 1; num <= 9; num++){
        if(checkRow(grid, row, num) && checkCol(grid, col, num) && checkBox(grid, row-row%3, col-col%3, num)){
            grid[row][col] = num;
            if(solveSudoku(grid)){
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

void printGrid(int grid[][9]){
    printf("+---+---+---+\n");
    for(int row = 0; row < 9; row++){
        printf("|");
        for(int col = 0; col < 9; col++){
            printf("%d ", grid[row][col]);
            if((col+1)%3==0){
                printf("|");
            }
        }
        printf("\n");
        if((row+1)%3==0){
            printf("+---+---+---+\n");
        }
    }
}

int main(){
    int grid[9][9] = {
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
    printf("Sudoku puzzle before solving:\n");
    printGrid(grid);
    printf("\n");
    if (solveSudoku(grid) == true){
        printf("Sudoku puzzle after solving:\n");
        printGrid(grid);
    }
    else{
        printf("Sudoku puzzle could not be solved.\n");
    }
    return 0;
}