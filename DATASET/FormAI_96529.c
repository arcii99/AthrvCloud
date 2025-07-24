//FormAI DATASET v1.0 Category: Sudoku solver ; Style: real-life
#include <stdio.h>

// The sudoku board must be defined as 2D array of integers
int board[9][9] = {{0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0}};

// Function to print the board
void print_board() {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number is valid in a certain position
int is_valid(int row, int col, int num) {
    // Check if the number is present in the row
    for(int i=0; i<9; i++) {
        if(board[row][i] == num) {
            return 0;
        }
    }
    // Check if the number is present in the column
    for(int i=0; i<9; i++) {
        if(board[i][col] == num) {
            return 0;
        }
    }
    // Check if the number is present in the 3x3 sub-grid
    int sub_row = row - row%3;
    int sub_col = col - col%3;
    for(int i=sub_row; i<sub_row+3; i++) {
        for(int j=sub_col; j<sub_col+3; j++) {
            if(board[i][j] == num) {
                return 0;
            }
        }
    }
    // If the number is not present, it is valid
    return 1;
}

// Function to solve the sudoku
int solve_sudoku(int row, int col) {
    // If the end of the board is reached, the board is solved
    if(row == 9) {
        return 1;
    }
    // If the column reaches the end of a row, move on the next row
    if(col == 9) {
        return solve_sudoku(row+1, 0);
    }
    // If the position is already filled, move on to the next column
    if(board[row][col] != 0) {
        return solve_sudoku(row, col+1);
    }
    // Check each number from 1 to 9 if it is valid in the position
    for(int num=1; num<=9; num++) {
        if(is_valid(row, col, num)) {
            // Fill in the number if it is valid
            board[row][col] = num;
            // Call the function recursively for the next position
            if(solve_sudoku(row, col+1)) {
                return 1;
            }
            // If the position cannot be filled with the number, backtrack and try a different number
            board[row][col] = 0;
        }
    }
    return 0;
}

// Driver program to test the sudoku solver
int main() {
    // Set up the initial board
    board[0][1] = 8;
    board[0][4] = 9;
    board[0][6] = 6;
    board[0][7] = 2;
    board[0][8] = 7;
    board[1][0] = 1;
    board[1][4] = 3;
    board[1][7] = 9;
    board[2][1] = 4;
    board[2][2] = 9;
    board[2][3] = 7;
    board[2][6] = 2;
    board[2][7] = 6;
    board[2][8] = 5;
    board[3][1] = 2;
    board[3][3] = 4;
    board[3][5] = 9;
    board[3][6] = 7;
    board[3][7] = 1;
    board[4][2] = 6;
    board[4][3] = 9;
    board[4][5] = 7;
    board[5][1] = 7;
    board[5][2] = 4;
    board[5][3] = 6;
    board[5][5] = 8;
    board[5][7] = 5;
    board[5][8] = 2;
    board[6][0] = 3;
    board[6][1] = 1;
    board[6][4] = 5;
    board[6][5] = 2;
    board[6][6] = 9;
    board[7][1] = 5;
    board[7][4] = 7;
    board[7][8] = 6;
    board[8][0] = 2;
    board[8][1] = 3;
    board[8][2] = 5;
    board[8][4] = 1;
    board[8][6] = 1;
    // Print the initial board
    printf("Initial board:\n");
    print_board();
    // Solve the board
    if(solve_sudoku(0, 0)) {
        // Print the solved board
        printf("Solved board:\n");
        print_board();
    } else {
        // Print an error message if the board cannot be solved
        printf("Error: board cannot be solved.\n");
    }
    return 0;
}