//FormAI DATASET v1.0 Category: Sudoku solver ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>

// Helper function to print the sudoku grid at any given point
void printGrid(int grid[9][9]){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Helper function to check if it is safe to place a value at a given (row, col) position
bool isSafe(int grid[9][9], int row, int col, int val){
    // Check if the value already exists in the same row
    for(int i=0; i<9; i++){
        if(grid[row][i] == val){
            return false;
        }
    }
    
    // Check if the value already exists in the same column
    for(int i=0; i<9; i++){
        if(grid[i][col] == val){
            return false;
        }
    }
    
    // Check if the value already exists in the same 3x3 sub-grid
    int sub_row = row - (row % 3);
    int sub_col = col - (col % 3);
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(grid[sub_row+i][sub_col+j] == val){
                return false;
            }
        }
    }
    
    return true;
}

// The main solve function
bool solveSudoku(int grid[9][9]){
    int row, col;
    bool found_unassigned = false;
    
    // Check if there are any unassigned cells left
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(grid[i][j] == 0){
                found_unassigned = true;
                row = i;
                col = j;
                break;
            }
        }
        if(found_unassigned){
            break;
        }
    }
    
    // If all cells are assigned, we have solved it!
    if(!found_unassigned){
        return true;
    }
    
    // Try all possible values for the current unassigned cell
    for(int val=1; val<=9; val++){
        if(isSafe(grid, row, col, val)){
            // Assign the value and recursively solve the grid
            grid[row][col] = val;
            if(solveSudoku(grid)){
                return true;
            }
            // If the recursive solve failed, backtrack and try again with a different value
            grid[row][col] = 0;
        }
    }
    
    return false;
}

int main(){
    int grid[9][9] = {
        {0, 0, 8, 7, 0, 3, 9, 0, 0},
        {0, 5, 0, 0, 0, 6, 0, 0, 0},
        {0, 0, 0, 9, 5, 0, 0, 3, 0},
        {0, 0, 0, 0, 2, 0, 3, 8, 0},
        {4, 0, 0, 6, 0, 8, 0, 0, 5},
        {0, 6, 9, 0, 3, 0, 0, 0, 0},
        {0, 7, 0, 0, 6, 4, 0, 0, 0},
        {0, 0, 0, 3, 0, 0, 0, 7, 0},
        {0, 0, 3, 2, 0, 5, 1, 0, 0}
    };
    
    printf("Input sudoku grid:\n");
    printGrid(grid);
    printf("\n");
    
    if(solveSudoku(grid)){
        printf("Solved sudoku grid:\n");
        printGrid(grid);
    }
    else{
        printf("Unable to solve sudoku grid.\n");
    }
    
    return 0;
}