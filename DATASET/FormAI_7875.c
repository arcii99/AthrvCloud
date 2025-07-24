//FormAI DATASET v1.0 Category: Sudoku solver ; Style: innovative
#include <stdio.h>

int board[9][9];

void printBoard() {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int isValid(int row, int col, int num) {
    // check if num exists in row or col
    for(int i=0; i<9; i++) {
        if(board[row][i] == num || board[i][col] == num) {
            return 0; // invalid
        }
    }

    // check if num exists in 3x3 grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for(int i=startRow; i<startRow+3; i++) {
        for(int j=startCol; j<startCol+3; j++) {
            if(board[i][j] == num) {
                return 0; // invalid
            }
        }
    }
    return 1; // valid
}

int solve(int row, int col) {
    int nextRow = row;
    int nextCol = col+1;
    if(nextCol == 9) {
        nextRow++;
        nextCol=0;
    }
    if(row == 8 && col == 8) {
        // last cell
        return board[row][col]; 
    }
    if(board[row][col] != 0) {
        // cell already has a value
        return solve(nextRow, nextCol);
    }
    for(int i=1; i<=9; i++) {
        if(isValid(row, col, i)) {
            board[row][col] = i;
            int result = solve(nextRow, nextCol);
            if(result != 0) {
                return result;
            }
        }
    }
    board[row][col] = 0; // backtracking
    return 0;
}

int main() {
    // sample board
    board[0][1] = 5;
    board[0][4] = 6;
    board[0][7] = 1;
    board[1][0] = 4;
    board[1][1] = 7;
    board[1][6] = 5;
    board[2][3] = 3;
    board[2][5] = 9;
    board[2][8] = 2;
    board[3][0] = 3;
    board[3][2] = 8;
    board[3][4] = 5;
    board[3][6] = 7;
    board[4][3] = 6;
    board[4][5] = 2;
    board[5][2] = 5;
    board[5][4] = 3;
    board[5][6] = 6;
    board[5][8] = 8;
    board[6][0] = 6;
    board[6][3] = 9;
    board[6][5] = 8;
    board[6][8] = 3;
    board[7][2] = 9;
    board[7][7] = 6;
    board[7][8] = 7;
    board[8][1] = 6;
    board[8][4] = 1;
    board[8][7] = 2;

    printf("Initial Board:\n");
    printBoard();

    int result = solve(0, 0);

    printf("\nSolution:\n");
    printBoard();

    return 0;
}