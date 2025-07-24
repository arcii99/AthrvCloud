//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Claude Shannon
#include<stdio.h> 

int possible(int sudoku[][9],int row, int col, int num) // checks if the number is a possible solution
{ 
    int row_start = (row/3)*3; // upper left boundaries of corresponding 3x3 box
    int col_start = (col/3)*3; 
  
    for (int i=0; i<9; i++) 
    { 
        if (sudoku[row][i] == num) // checks row
            return 0; 

        if (sudoku[i][col] == num) // checks column
            return 0; 

        if (sudoku[row_start + (i%3)][col_start + (i/3)] == num) // checks 3x3 box
            return 0; 
    } 
    return 1; 
} 

int solve_sudoku(int sudoku[][9], int row, int col) // solves the sudoku recursively
{ 
    if (row == 8 && col == 9) 
        return 1; // completed the sudoku successfully 
    if (col == 9) 
    { 
        row++; 
        col = 0; 
    } 

    if (sudoku[row][col] > 0) 
        return solve_sudoku(sudoku, row, col+1); // goes to the next column

    for(int num=1; num<=9; num++) // tries to insert the number 1-9 to an empty cell
    { 
        if(possible(sudoku,row,col,num)==1) // checks if it's a possible solution
        { 
            sudoku[row][col] = num; 
            if (solve_sudoku(sudoku, row, col+1)) 
                return 1; 
        } 
        sudoku[row][col] = 0; //backtrack 
    } 
    return 0; 
} 

void print_grid(int sudoku[][9]) // prints the solved sudoku grid
{ 
    for (int row=0; row<9; row++) 
    { 
        for (int col=0; col<9; col++) 
            printf("%d ",sudoku[row][col]); 
        printf("\n"); 
    } 
} 

int main() 
{ 
    int sudoku[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0}, // input the empty sudoku grid
                       {6, 0, 0, 1, 9, 5, 0, 0, 0}, 
                       {0, 9, 8, 0, 0, 0, 0, 6, 0}, 
                       {8, 0, 0, 0, 6, 0, 0, 0, 3}, 
                       {4, 0, 0, 8, 0, 3, 0, 0, 1}, 
                       {7, 0, 0, 0, 2, 0, 0, 0, 6}, 
                       {0, 6, 0, 0, 0, 0, 2, 8, 0}, 
                       {0, 0, 0, 4, 1, 9, 0, 0, 5}, 
                       {0, 0, 0, 0, 8, 0, 0, 7, 9}}; 
    
    if (solve_sudoku(sudoku, 0, 0) == 1) // solves the sudoku using the recursive function
        print_grid(sudoku); // prints the solved sudoku grid
    else
        printf("No solution exists"); 
  
    return 0; 
}