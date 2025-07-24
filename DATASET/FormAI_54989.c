//FormAI DATASET v1.0 Category: Sudoku solver ; Style: beginner-friendly
#include <stdio.h>

void print_board(int board[9][9]) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int is_valid(int board[9][9], int row, int col, int num) {
    // Check if num is in row or column
    for(int i=0; i<9; i++) {
        if(board[row][i] == num) return 0;
        if(board[i][col] == num) return 0;
    }
    // Check if num is in current 3x3 box
    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;
    for(int i=box_row; i<box_row+3; i++) {
        for(int j=box_col; j<box_col+3; j++) {
            if(board[i][j] == num) return 0;
        }
    }
    return 1;
}

int solve(int board[9][9], int row, int col) {
    // If we've filled the whole board, return 1
    if(row == 9) return 1;
    // If we've filled the current row, move to next row
    if(col == 9) {
        return solve(board, row+1, 0);
    }
    // If current position is already filled, move to next position
    if(board[row][col] != 0) {
        return solve(board, row, col+1);
    }
    // Try to fill current position with each valid number
    for(int n=1; n<=9; n++) {
        if(is_valid(board, row, col, n)) {
            board[row][col] = n;
            if(solve(board, row, col+1)) {
                return 1;
            }
        }
    }
    // If no valid number can be filled, backtrack
    board[row][col] = 0;
    return 0;
}

int main() {
    int board[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    printf("Original board:\n");
    print_board(board);
    if(solve(board, 0, 0)) {
        printf("Solution:\n");
        print_board(board);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}