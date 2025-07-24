//FormAI DATASET v1.0 Category: Sudoku solver ; Style: introspective
#include <stdio.h>

int board[9][9]; //the sudoku board

//function to print the board
void print_board() {
    printf("---------------------\n");
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            printf("%d ", board[i][j]);
            if((j+1)%3 == 0) printf("| ");
        }
        printf("\n");
        if((i+1)%3 == 0) printf("---------------------\n");
    }
}

//function to check if a number can be placed at a certain cell
int is_valid(int num, int row, int col) {
    //check if the number already exists in the same row or column
    for(int i=0; i<9; i++) {
        if(board[row][i] == num || board[i][col] == num) {
            return 0;
        }
    }
    //check if the number already exists in the same 3x3 block
    int row_start = (row/3)*3;
    int col_start = (col/3)*3;
    for(int i=row_start; i<row_start+3; i++) {
        for(int j=col_start; j<col_start+3; j++) {
            if(board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

//recursive function to solve the sudoku puzzle
int solve(int row, int col) {
    //base case: if the row crosses the board, the puzzle is solved
    if(row == 9) {
        return 1;
    }
    //if the current cell already has a number, move to the next cell
    if(board[row][col] != 0) {
        if(col == 8) {
            if(solve(row+1, 0)) return 1;
        } else {
            if(solve(row, col+1)) return 1;
        }
        return 0;
    }
    //try placing numbers (1-9) in the current cell until a valid number is found
    for(int i=1; i<=9; i++) {
        if(is_valid(i, row, col)) {
            board[row][col] = i;
            if(col == 8) {
                if(solve(row+1, 0)) return 1;
            } else {
                if(solve(row, col+1)) return 1;
            }
            board[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    //initialize the board with zeros
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            board[i][j] = 0;
        }
    }

    //sample sudoku board
    board[0][2] = 4; board[0][4] = 5; board[0][5] = 3; board[0][6] = 7;
    board[1][0] = 1; board[1][3] = 5; board[1][5] = 4; board[1][8] = 6;
    board[2][2] = 9; board[2][3] = 7; board[2][6] = 1; board[2][7] = 8;
    board[3][1] = 8; board[3][2] = 6; board[3][3] = 4; board[3][4] = 2; board[3][5] = 7;
    board[4][2] = 1; board[4][3] = 9; board[4][5] = 5; board[4][6] = 4; board[4][7] = 6;
    board[5][2] = 7; board[5][3] = 2; board[5][4] = 6; board[5][5] = 8; board[5][6] = 3;
    board[6][1] = 2; board[6][6] = 5; board[6][7] = 3; board[6][8] = 1;
    board[7][0] = 5; board[7][3] = 3; board[7][5] = 9; board[7][8] = 4;
    board[8][2] = 3; board[8][3] = 8; board[8][4] = 1; board[8][6] = 2;

    printf("Original board:\n");
    print_board();

    if(solve(0,0)) {
        printf("Solution found:\n");
        print_board();
    } else {
        printf("No solution found.\n");
    }

    return 0;
}