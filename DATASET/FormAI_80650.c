//FormAI DATASET v1.0 Category: Sudoku solver ; Style: irregular
#include <stdio.h>

// Function to print the sudoku board
void print_board(int board[][9]){
    printf("--------------------\n");
    for(int i=0;i<9;i++){
        printf("| ");
        for(int j=0;j<9;j++){
            printf("%d ", board[i][j]);
            if((j+1)%3 ==0){
                printf("| ");
            }
        }
        printf("\n");
        if((i+1)%3 ==0){
            printf("--------------------\n");
        }
    }
}

// Function to check if the value can be placed at given position
int is_valid(int board[][9], int row, int col, int val){
    int i, j;

    // Check row
    for(i=0; i<9; i++){
        if(board[row][i] == val){
            return 0;
        }
    }

    // Check column
    for(i=0; i<9; i++){
        if(board[i][col] == val){
            return 0;
        }
    }

    // Check subgrid
    int row_start = (row/3)*3;
    int col_start = (col/3)*3;
    for(i=row_start; i<(row_start+3); i++){
        for(j=col_start; j<(col_start+3); j++){
            if(board[i][j] == val){
                return 0;
            }
        }
    }

    // If value can be placed, return 1
    return 1;
}

// Function to solve the sudoku board
int solve_sudoku(int board[][9], int row, int col){
    // If last row and last column, return 1 as sudoku is solved
    if(row == 8 && col == 9){
        return 1;
    }
    // If last column, move to next row
    if(col == 9){
        row++;
        col = 0;
    }
    // If value already present, move to next column
    if(board[row][col] > 0){
        return solve_sudoku(board, row, col+1);
    }
    // Try values from 1 to 9
    for(int i=1; i<=9; i++){
        // If value can be placed at given position
        if(is_valid(board, row, col, i)){
            // Assign value at given position
            board[row][col] = i;
            // Move to next column
            if(solve_sudoku(board, row, col+1)){
                return 1;
            }
        }
        // If value cannot be placed, reset the position to 0
        board[row][col] = 0;
    }
    // If sudoku cannot be solved, return 0
    return 0;
}

int main(){
    int board[9][9] = {
        {0,0,0,0,0,5,0,8,0},
        {2,0,0,0,4,0,0,0,7},
        {0,8,0,0,1,6,0,0,0},
        {0,1,0,5,0,0,0,0,0},
        {0,9,5,7,0,0,0,0,6},
        {0,0,0,9,0,0,0,0,1},
        {7,0,0,0,0,0,0,6,0},
        {4,0,3,2,0,0,7,1,0},
        {0,0,8,0,0,0,0,0,3}
    };
    // Print initial board
    printf("Initial Sudoku:\n");
    print_board(board);
    // Try solving sudoku
    if(solve_sudoku(board, 0, 0)){
        // Print solved sudoku board
        printf("Solved Sudoku:\n");
        print_board(board);
    }
    // If sudoku cannot be solved
    else{
        printf("Sudoku cannot be solved.\n");
    }
    return 0;
}