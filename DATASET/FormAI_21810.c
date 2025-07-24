//FormAI DATASET v1.0 Category: Sudoku solver ; Style: minimalist
#include <stdio.h>

int puzzle[9][9]; // the sudoku puzzle to be solved

int is_valid(int row, int col, int num){

    // check for validity of number "num" whether it can be placed at specified location (row, col)

    for (int i = 0; i < 9; i++){
        if (puzzle[row][i] == num) return 0; // check row
        if (puzzle[i][col] == num) return 0; // check column
        if (puzzle[(row/3)*3 + i/3][(col/3)*3 + i%3] == num) return 0; // check box
    }

    return 1;
}

int solve(int row, int col){

    // solve the sudoku puzzle using backtracking algorithm

    if (row == 9) return 1; // if all rows are completed, return true to terminate

    if (col == 9) return solve(row+1, 0); // if all columns of the current row are completed, move to next row

    if (puzzle[row][col] != 0) return solve(row, col+1); // if the location already has a number, move to next column

    for (int i = 1; i <= 9; i++){ // check for all possible numbers 1 to 9

        if (is_valid(row, col, i)){ // if the number is valid to be placed at current location

            puzzle[row][col] = i; // assign the valid number to the current location

            if (solve(row, col+1)) return 1; // if the solution found, return true to terminate

            puzzle[row][col] = 0; // backtrack as the solution not found with current number
        }
    }

    return 0; // solution not found
}

void print_puzzle(){

    // function to print sudoku puzzle

    printf("-------------------------\n");

    for (int i = 0; i < 9; i++){

        printf("| ");

        for (int j = 0; j < 9; j++){
            printf("%d ", puzzle[i][j]);
            if ((j+1) % 3 == 0) printf("| ");
        }

        printf("\n");

        if ((i+1) % 3 == 0){
            printf("-------------------------\n");
        }

    }

    printf("\n");
}

int main(){

    // initialize the sudoku puzzle to be solved
    int unsolved_puzzle[9][9] = {
            {0, 0, 0, 0, 7, 0, 0, 4, 9},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 2, 0, 9, 0, 0, 0, 0, 0},
            {2, 0, 0, 0, 0, 8, 0, 0, 0},
            {5, 0, 9, 0, 0, 0, 0, 6, 0},
            {0, 0, 0, 0, 6, 0, 0, 0, 0},
            {0, 9, 7, 0, 0, 4, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 7},
            {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // copy the unsolved puzzle to puzzle array
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            puzzle[i][j] = unsolved_puzzle[i][j];
        }
    }

    printf("Unsolved Puzzle:\n");
    print_puzzle();

    if (solve(0, 0)){ // solve the sudoku puzzle

        printf("Solved Puzzle:\n");
        print_puzzle();

    } else {

        printf("Puzzle could not be solved!\n");
    }

    return 0;
}