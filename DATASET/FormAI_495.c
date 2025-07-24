//FormAI DATASET v1.0 Category: Sudoku solver ; Style: complex
#include <stdio.h>

//Function to check if a number can be filled in a particular position
int possible(int matrix[9][9], int row, int col, int num) {
    //Checking row and column
    for(int i=0; i<9; i++) {
        if(matrix[row][i] == num || matrix[i][col] == num) {
            return 0;
        }
    }
    //Checking 3x3 box
    int r = row - (row % 3);
    int c = col - (col % 3);
    for(int i=r; i<r+3; i++) {
        for(int j=c; j<c+3; j++) {
            if(matrix[i][j] == num) {
                return 0;
            }
        }
    }
    //Possible value for that position
    return 1;
}

//Function to solve the Sudoku puzzle
int solve(int matrix[9][9]) {
    int row, col;
    //Finding an empty position
    for(row=0; row<9; row++) {
        for(col=0; col<9; col++) {
            if(matrix[row][col] == 0) {
                break;
            }
        }
        if(matrix[row][col] == 0) {
            break;
        }
    }
    //If no empty position left
    if(row == 9 && col == 9) {
        return 1;
    }
    //Checking possible values for that position
    for(int num=1; num<=9; num++) {
        if(possible(matrix, row, col, num)) {
            matrix[row][col] = num;
            if(solve(matrix)) {
                return 1;
            }
            matrix[row][col] = 0;
        }
    }
    return 0;
}

//Function to print the Sudoku puzzle
void print(int matrix[9][9]) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

}

//Driver code
int main() {
    int matrix[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                        {6, 0, 0, 1, 9, 5, 0, 0, 0},
                        {0, 9, 8, 0, 0, 0, 0, 6, 0},
                        {8, 0, 0, 0, 6, 0, 0, 0, 3},
                        {4, 0, 0, 8, 0, 3, 0, 0, 1},
                        {7, 0, 0, 0, 2, 0, 0, 0, 6},
                        {0, 6, 0, 0, 0, 0, 2, 8, 0},
                        {0, 0, 0, 4, 1, 9, 0, 0, 5},
                        {0, 0, 0, 0, 8, 0, 0, 7, 9}}
                        ;

    if(solve(matrix) == 1) {
        printf("Solution:\n");
        print(matrix);
    } else {
        printf("No solution exists!\n");
    }
    return 0;
}