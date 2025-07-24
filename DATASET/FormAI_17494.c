//FormAI DATASET v1.0 Category: Sudoku solver ; Style: complex
#include <stdio.h>
#include <stdbool.h>

#define UNASSIGNED 0
#define N 9

bool isRowSafe(int grid[N][N], int row, int num){
    for(int col = 0; col < N; col++){
        if(grid[row][col] == num){
            return false;
        }
    }
    return true;
}

bool isColSafe(int grid[N][N], int col, int num){
    for(int row = 0; row < N; row++){
        if(grid[row][col] == num){
            return false;
        }
    }
    return true;
}

bool isBoxSafe(int grid[N][N], int row, int col, int num){
    int boxRowStart = row - row % 3;
    int boxColStart = col - col % 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grid[i + boxRowStart][j + boxColStart] == num){
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int grid[N][N], int row, int col, int num){
    return isRowSafe(grid, row, num)
        && isColSafe(grid, col, num)
        && isBoxSafe(grid, row, col, num);
}

bool findUnassignedLocation(int grid[N][N], int* row, int* col){
    for(*row = 0; *row < N; (*row)++){
        for(*col = 0; *col < N; (*col)++){
            if(grid[*row][*col] == UNASSIGNED){
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku(int grid[N][N]){
    int row, col;
    if(!findUnassignedLocation(grid, &row, &col)){
        return true;
    }
    for(int num = 1; num <= 9; num++){
        if(isSafe(grid, row, col, num)){
            grid[row][col] = num;
            if(solveSudoku(grid)){
                return true;
            }
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}

void printGrid(int grid[N][N]){
    for(int row = 0; row < N; row++){
        for(int col = 0; col < N; col++){
            printf("%2d ", grid[row][col]);
        }
        printf("\n");
    }
}

int main(){
    int grid[N][N] = {
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
    if(solveSudoku(grid) == true){
        printGrid(grid);
    }
    else{
        printf("No solution exists");
    }
    return 0;
}