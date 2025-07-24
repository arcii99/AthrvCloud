//FormAI DATASET v1.0 Category: Sudoku solver ; Style: expert-level
#include <stdio.h>

//function to print the sudoku board
void print_board(int board[9][9]) {
    printf("___________________\n");
    for(int i=0; i<9; i++) {
        printf("|");
        for(int j=0; j<9; j++) {
            if(board[i][j] == 0) printf(" . ");
            else printf(" %d ", board[i][j]);
            if((j+1)%3 == 0) printf("|");
        }
        printf("\n");
        if((i+1)%3 == 0) printf("___________________\n");
    }
}

//function to check if a number can be placed in a particular cell
int can_place(int board[9][9], int row, int col, int num) {
    //checking the row and column
    for(int i=0; i<9; i++) {
        if(board[row][i] == num || board[i][col] == num) return 0;
    }
    //checking the box
    int r = row - row%3;
    int c = col - col%3;
    for(int i=r; i<r+3; i++) {
        for(int j=c; j<c+3; j++) {
            if(board[i][j] == num) return 0;
        }
    }
    //if the number can be placed
    return 1;
}

//function to solve the sudoku
int solve(int board[9][9], int row, int col) {
    //if the column is reached at the end of the row
    if(col == 9) {
        row = row + 1;
        col = 0;
    }
    //if the row is reached at the end
    if(row == 9) {
        return 1;
    }
    //if the cell is already filled
    if(board[row][col] != 0) {
        return solve(board, row, col+1);
    }
    //for unfilled cell
    for(int i=1; i<=9; i++) {
        if(can_place(board, row, col, i)) {
            board[row][col] = i;
            if(solve(board, row, col+1)) {
                return 1;
            }
            board[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    int board[9][9] = {{0, 0, 0, 0, 8, 0, 0, 0, 0},
                       {0, 6, 0, 0, 0, 1, 2, 9, 0},
                       {0, 4, 0, 0, 7, 2, 0, 0, 5},
                       {0, 3, 0, 0, 0, 0, 0, 2, 0},
                       {8, 0, 0, 0, 4, 0, 0, 0, 3},
                       {0, 7, 0, 0, 0, 0, 0, 5, 0},
                       {6, 0, 0, 5, 1, 0, 0, 4, 0},
                       {0, 8, 3, 7, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 9, 0, 0, 0, 0}};

    printf("Before solving:\n");
    print_board(board);

    if(solve(board, 0, 0)) {
        printf("\nAfter solving:\n");
        print_board(board);
    } else {
        printf("\nNo solution found.\n");
    }

    return 0;
}