//FormAI DATASET v1.0 Category: Sudoku solver ; Style: careful
#include <stdio.h>
#include <stdbool.h>

// Function to print the Sudoku grid
void print_grid(int grid[9][9]){
    for (int row = 0; row < 9; row++){
        for (int col = 0; col < 9; col++){
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to check if the given value is safe to put at the given cell
bool is_safe(int grid[9][9], int row, int col, int num){
    // Check for row
    for(int i=0; i<9; i++){
        if(grid[row][i] == num){
            return false;
        }
    }
    
    // Check for column
    for(int i=0; i<9; i++){
        if(grid[i][col] == num){
            return false;
        }
    }
    
    // Check for 3x3 box
    int box_row = row - row%3;
    int box_col = col - col%3;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (grid[i+box_row][j+box_col] == num){
                return false;
            }
        }
    }
    
    // Return true if the value is safe for the given cell
    return true;
}

// Function to solve the Sudoku grid recursively
bool solve_sudoku(int grid[9][9]){
    int row, col;
    bool is_empty = false;
    // Check for empty cells in the grid
    for (row = 0; row < 9; row++){
        for (col = 0; col < 9; col++){
            if (grid[row][col] == 0){
                is_empty = true;
                break;
            }
        }
        if (is_empty == true){
            break;
        }
    }
    // If all cells are filled, return true
    if (is_empty == false){
        return true;
    }
    // Try all possible numbers for the empty cell
    for (int num = 1; num <= 9; num++){
        if (is_safe(grid, row, col, num)){
            grid[row][col] = num;
            // Recursive call to solve the grid
            if (solve_sudoku(grid)){
                return true;
            }
            grid[row][col] = 0;
        }
    }
    // Return false if no value can be placed on the empty cell
    return false;
}

int main(){
    int grid[9][9] = {{3, 0, 0, 0, 8, 0, 4, 0, 0},
                      {0, 0, 0, 7, 0, 0, 0, 0, 0},
                      {1, 0, 0, 4, 0, 0, 0, 0, 0},
                      {0, 0, 0, 5, 0, 0, 9, 0, 0},
                      {0, 0, 9, 0, 2, 0, 0, 0, 0},
                      {0, 4, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 8, 0},
                      {0, 0, 0, 0, 0, 0, 3, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    
    // Solve the Sudoku grid
    if (solve_sudoku(grid) == true){
        printf("Sudoku grid solved successfully:\n");
        print_grid(grid);
    }
    else{
        printf("Sudoku grid cannot be solved\n");
    }
    return 0;
}