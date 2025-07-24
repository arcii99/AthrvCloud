//FormAI DATASET v1.0 Category: Sudoku solver ; Style: paranoid
#include<stdio.h>

//function to check if value n can be placed at (row, col)
int isPossible(int sudoku[9][9], int row, int col, int n){
    for (int i=0; i<9; i++){ //checking row and column
        if (sudoku[row][i] == n || sudoku[i][col] == n){
            return 0;
        }
    }
    //checking the square
    int rowStart = (row/3) * 3;
    int colStart = (col/3) * 3;
    for (int i=rowStart; i<rowStart+3; i++){
        for (int j=colStart; j<colStart+3; j++){
            if (sudoku[i][j] == n){
                return 0;
            }
        }
    }
    return 1;
}

//function to solve sudoku puzzle using backtracking
int solveSudoku(int sudoku[9][9]){
    int row, col;
    int empty = 0;
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            if (sudoku[i][j] == 0){ //checking for empty cell
                row = i;
                col = j;
                empty = 1;
                break;
            }
        }
        if (empty == 1){
            break;
        }
    }
    if (empty == 0){ //no empty cell left, sudoku is solved
        return 1;
    }
    //trying different numbers for the empty cell
    for (int i=1; i<=9; i++){
        if (isPossible(sudoku, row, col, i)){
            sudoku[row][col] = i;
            if (solveSudoku(sudoku)){
                return 1;
            }
            sudoku[row][col] = 0; //backtracking
        }
    }
    return 0; //this path does not lead to solution
}

//function to print the sudoku puzzle
void printSudoku(int sudoku[9][9]){
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int sudoku[9][9] = { //example sudoku
        {5, 0, 0, 0, 3, 0, 0, 0, 0},
        {0, 0, 6, 0, 0, 0, 0, 9, 8},
        {0, 0, 0, 0, 0, 7, 0, 0, 5},
        {6, 0, 0, 0, 0, 0, 0, 0, 7},
        {0, 9, 0, 3, 0, 0, 0, 0, 0},
        {8, 0, 1, 7, 0, 0, 0, 0, 4},
        {0, 0, 0, 0, 2, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 6, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0}
    };
    printf("Sudoku before solving:\n");
    printSudoku(sudoku);
    solveSudoku(sudoku);
    printf("\nSudoku after solving:\n");
    printSudoku(sudoku);
    return 0;
}