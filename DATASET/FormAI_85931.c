//FormAI DATASET v1.0 Category: Sudoku solver ; Style: puzzling
#include <stdio.h>

// Sudoku puzzle
int puzzle[9][9] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// Prints the Sudoku puzzle
void print_puzzle() {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++)
            printf("%d ", puzzle[i][j]);
        printf("\n");
    }
}

// Checks if a value is valid to be placed in a cell
int is_valid(int row, int col, int value) {
    
    // Check if the value already exists in the same row or column
    for(int i=0; i<9; i++) {
        if(puzzle[row][i]==value || puzzle[i][col]==value)
            return 0;
    }
    
    // Check if the value already exists in the same 3x3 box
    int x = (row/3)*3;
    int y = (col/3)*3;
    for(int i=x; i<x+3; i++) {
        for(int j=y; j<y+3; j++) {
            if(puzzle[i][j]==value)
                return 0;
        }
    }
    
    // If the value is valid for the cell, return true
    return 1;
}

// Recursive function to solve the Sudoku puzzle
int solve_puzzle(int row, int col) {
    
    // If the row and column are both 9, the Sudoku puzzle is solved
    if(row==9 && col==0)
        return 1;
    
    // If the column is 9, move to the next row
    if(col == 9) {
        row++;
        col = 0;
    }
    
    // If the cell is already filled, move to the next cell
    if(puzzle[row][col] != 0) 
        return solve_puzzle(row, col+1);
    
    // Check all possible values for the cell
    for(int i=1; i<=9; i++) {
        if(is_valid(row, col, i)) {
            puzzle[row][col] = i;
            if(solve_puzzle(row, col+1))
                return 1;
        }
    }
    
    // If no value is valid for the cell, backtrack by setting the cell to 0
    puzzle[row][col] = 0;
    return 0;
}

int main() {
    
    // Initialize the Sudoku puzzle
    puzzle[0][0] = 5;
    puzzle[0][1] = 3;
    puzzle[0][4] = 7;
    puzzle[1][0] = 6;
    puzzle[1][3] = 1;
    puzzle[1][4] = 9;
    puzzle[1][5] = 5;
    puzzle[2][1] = 9;
    puzzle[2][2] = 8;
    puzzle[2][7] = 6;
    puzzle[3][0] = 8;
    puzzle[3][4] = 6;
    puzzle[3][8] = 3;
    puzzle[4][0] = 4;
    puzzle[4][3] = 8;
    puzzle[4][5] = 3;
    puzzle[4][8] = 1;
    puzzle[5][0] = 7;
    puzzle[5][4] = 2;
    puzzle[5][8] = 6;
    puzzle[6][1] = 6;
    puzzle[6][6] = 2;
    puzzle[6][7] = 8;
    puzzle[7][3] = 4;
    puzzle[7][4] = 1;
    puzzle[7][5] = 9;
    puzzle[7][8] = 5;  
    puzzle[8][4] = 8;
    puzzle[8][7] = 7;
    puzzle[8][8] = 9;
    
    // Print the unsolved Sudoku puzzle
    printf("Unsolved Sudoku puzzle:\n");
    print_puzzle();
    
    // Solve the Sudoku puzzle
    if(solve_puzzle(0, 0)) {
        // Print the solved Sudoku puzzle
        printf("Solved Sudoku puzzle:\n");
        print_puzzle();
    } else {
        printf("Cannot solve the Sudoku puzzle.");
    }
    
    return 0;
}