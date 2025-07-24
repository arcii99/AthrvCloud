//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdbool.h>

// A function to display the Sudoku puzzle grid
void displayGrid(int grid[9][9]){
    printf("   --- --- ---   --- --- ---   --- --- ---\n");
    for(int row=0; row<9; row++){
        printf("  |");
        for(int col=0; col<9; col++){
            if(grid[row][col]==0){
                printf("   ");
            } else {
                printf(" %d ",grid[row][col]);
            }
            if((col+1)%3==0){
                printf("|");
            }
        }
        printf("\n");
        if((row+1)%3==0){
            printf("   --- --- ---   --- --- ---   --- --- ---\n");
        }
    }
}

// A function to check if a digit is in the row
bool inRow(int grid[9][9], int row, int digit){
    for(int col=0; col<9; col++){
        if(grid[row][col] == digit){
            return true;
        }
    }
    return false;
}

// A function to check if a digit is in the column
bool inCol(int grid[9][9], int col, int digit){
    for(int row=0; row<9; row++){
        if(grid[row][col] == digit){
            return true;
        }
    }
    return false;
}

// A function to check if a digit is in the 3x3 box
bool inBox(int grid[9][9], int startRow, int startCol, int digit){
    for(int row=0; row<3; row++){
        for(int col=0; col<3; col++){
            if(grid[row+startRow][col+startCol] == digit){
                return true;
            }
        }
    }
    return false;
}

// A function to check if a digit can be placed in cell
bool canPlace(int grid[9][9], int row, int col, int digit){
    if(!inRow(grid, row, digit) && !inCol(grid, col, digit) && !inBox(grid, row-row%3, col-col%3, digit)){
        return true;
    }
    return false;
}

// A function to find the next unassigned cell
bool findUnassigned(int grid[9][9], int* row, int* col){
    for(*row=0; *row<9; (*row)++){
        for(*col=0; *col<9; (*col)++){
            if(grid[*row][*col]==0){
                return true;
            }
        }
    }
    return false;
}

// The main function to solve the Sudoku puzzle
bool solveSudoku(int grid[9][9]){
    int row, col;
    if(!findUnassigned(grid, &row, &col)) {
        return true;
    }
    for(int digit=1; digit<=9; digit++){
        if(canPlace(grid, row, col, digit)){
            grid[row][col] = digit;
            if(solveSudoku(grid)){
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

// The Romeo and Juliet style code for the Sudoku solver program
int main(){
    printf("Romeo: Oh, Juliet. I am in despair. My mind is in such a chaos I cannot bear.\n");
    printf("Juliet: My dear Romeo, what troubles your mind with such a deep care?\n");
    printf("Romeo: It is this Sudoku puzzle, Juliet. It has defeated my every try and dare.\n");
    int grid[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                      {6, 0, 0, 1, 9, 5, 0, 0, 0},
                      {0, 9, 8, 0, 0, 0, 0, 6, 0},
                      {8, 0, 0, 0, 6, 0, 0, 0, 3},
                      {4, 0, 0, 8, 0, 3, 0, 0, 1},
                      {7, 0, 0, 0, 2, 0, 0, 0, 6},
                      {0, 6, 0, 0, 0, 0, 2, 8, 0},
                      {0, 0, 0, 4, 1, 9, 0, 0, 5},
                      {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    printf("Romeo: This is the puzzle board I cannot fix. It gives me constant angry kicks.\n");
    displayGrid(grid);
    if(solveSudoku(grid)){
        printf("Juliet: Romeo, the solution is here. Your puzzle vanquished, without any fear.\n");
        displayGrid(grid);
        printf("Romeo: Oh, Juliet. Your words so profound. I am in awe, my love, my one true sound.\n");
    } 
    return 0;
}