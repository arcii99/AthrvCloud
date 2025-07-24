//FormAI DATASET v1.0 Category: Sudoku solver ; Style: careful
#include<stdio.h>
#include<stdlib.h>

#define SIDE 9
#define UNASSIGNED 0

int isSafe(int grid[][SIDE], int row, int col, int num);
int findUnassignedLocation(int grid[][SIDE], int *row, int *col);
int solveSudoku(int grid[][SIDE]);

void printGrid(int grid[][SIDE]){
    for (int row = 0; row < SIDE; row++) {
        for (int col = 0; col < SIDE; col++){
            printf("%2d", grid[row][col]);
        }
        printf("\n");
    }
}

int main(){
    int grid[][SIDE] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
                         {5, 2, 0, 0, 0, 0, 0, 0, 0},
                         {0, 8, 7, 0, 0, 0, 0, 3, 1},
                         {0, 0, 3, 0, 0, 0, 0, 2, 0},
                         {9, 0, 0, 8, 0, 0, 0, 0, 5},
                         {0, 5, 0, 0, 0, 0, 6, 0, 0},
                         {1, 3, 0, 0, 0, 0, 2, 5, 0},
                         {0, 0, 0, 0, 0, 0, 0, 7, 4},
                         {0, 0, 5, 2, 0, 6, 3, 0, 0} };
    
    if (solveSudoku(grid) == 1)
        printGrid(grid);
    else
        printf("Unable to solve Sudoku");
        
    return 0;
}

int isSafe(int grid[][SIDE], int row, int col, int num){
    for (int x = 0; x < SIDE; x++){ 
        if (grid[row][x] == num)
            return 0;
    }
        
    for (int x = 0; x < SIDE; x++){
        if (grid[x][col] == num)
            return 0;
    }  
    
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (grid[i + boxRow][j + boxCol] == num)
                return 0;
        }
    }
    return 1;
}

int findUnassignedLocation(int grid[][SIDE], int *row, int *col){
    for (*row = 0; *row < SIDE; (*row)++){
        for (*col = 0; *col < SIDE; (*col)++){
            if (grid[*row][*col] == UNASSIGNED)
                return 1;
        }
    }
    return 0;
}

int solveSudoku(int grid[][SIDE]){ 
    int row, col;
    if (!findUnassignedLocation(grid, &row, &col))
        return 1;

    for (int num = 1; num <= 9; num++){ 
        if (isSafe(grid, row, col, num)){ 
            grid[row][col] = num; 
            if (solveSudoku(grid)) 
                return 1;
            grid[row][col] = UNASSIGNED; 
        }
    }
    return 0; 
}