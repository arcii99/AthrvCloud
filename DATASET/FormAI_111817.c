//FormAI DATASET v1.0 Category: Sudoku solver ; Style: imaginative
#include<stdio.h>

//function to check if the number is valid in the given cell.
int valid(int puzzle[][9], int row, int col, int num) {
    int i, j, row_start, col_start;
    
    //checking the row
    for(i=0;i<9;i++) {
        if(puzzle[row][i] == num)
            return 0;
    }
    
    //checking the column
    for(i=0;i<9;i++) {
        if(puzzle[i][col] == num)
            return 0;
    }
    
    //checking the box
    row_start = (row/3)*3;
    col_start = (col/3)*3;
    
    for(i=row_start;i<row_start+3;i++) {
        for(j=col_start;j<col_start+3;j++) {
            if(puzzle[i][j] == num)
                return 0;
        }
    }
    
    //if passed all checks
    return 1;
}

//function to solve the sudoku puzzle
int solve_sudoku(int puzzle[][9], int row, int col) {
    int i, num;
    
    if(row == 8 && col == 9) {
        //when the last cell is filled
        return 1;
    }
    
    if(col == 9) {
        //when current row is filled, move to next row
        row++;
        col = 0;
    }
    
    if(puzzle[row][col] > 0) {
        //if cell is already filled, move to next cell
        return solve_sudoku(puzzle, row, col+1);
    }
    
    //trying out different numbers
    for(num=1;num<=9;num++) {
        if(valid(puzzle, row, col, num)) {
            puzzle[row][col] = num;
            
            //moving to next cell
            if(solve_sudoku(puzzle, row, col+1))
                return 1;
        }
        
        //backtracking
        puzzle[row][col] = 0;
    }
    
    return 0;
}

int main() {
    int puzzle[9][9] = {   {3, 0, 6, 5, 0, 8, 4, 0, 0},
                            {5, 2, 0, 0, 0, 0, 0, 0, 0},
                            {0, 8, 7, 0, 0, 0, 0, 3, 1},
                            {0, 0, 3, 0, 0, 0, 0, 2, 0},
                            {9, 0, 0, 8, 0, 0, 0, 0, 5},
                            {0, 5, 0, 0, 0, 0, 6, 0, 0},
                            {1, 3, 0, 0, 0, 0, 2, 5, 0},
                            {0, 0, 0, 0, 0, 0, 0, 7, 4},
                            {0, 0, 5, 2, 0, 6, 3, 0, 0}   };
    
    //displaying the puzzle before solving
    printf("Sudoku Puzzle:\n");
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            printf("%d ", puzzle[i][j]);
        }
        printf("\n");
    }
    
    //solving the puzzle
    if(solve_sudoku(puzzle, 0, 0)) {
        //displaying the solution
        printf("\nSudoku Solution:\n");
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                printf("%d ", puzzle[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("Solution does not exist.\n");
    }
    
    return 0;   
}