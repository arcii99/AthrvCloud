//FormAI DATASET v1.0 Category: Sudoku solver ; Style: protected
#include <stdio.h>

#define BOARD_SIZE 9

void print_board(int board[BOARD_SIZE][BOARD_SIZE]){
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}

int check_row(int board[BOARD_SIZE][BOARD_SIZE], int row, int value){
    for(int i = 0; i < BOARD_SIZE; i++){
        if(board[row][i] == value){
            return 0;
        }
    }
    return 1;
}

int check_column(int board[BOARD_SIZE][BOARD_SIZE], int column, int value){
    for(int i = 0; i < BOARD_SIZE; i++){
        if(board[i][column] == value){
            return 0;
        }
    }
    return 1;
}

int check_box(int board[BOARD_SIZE][BOARD_SIZE], int row, int column, int value){
    int box_row = (row / 3) * 3;
    int box_col = (column / 3) * 3;
    for(int i = box_row; i < box_row + 3; i++){
        for(int j = box_col; j < box_col + 3; j++){
            if(board[i][j] == value){
                return 0;
            }
        }
    }
    return 1;
}

int find_empty(int board[BOARD_SIZE][BOARD_SIZE], int *row, int *column){
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j] == 0){
                *row = i;
                *column = j;
                return 1;
            }
        }
    }
    return 0;
}

int solve_sudoku(int board[BOARD_SIZE][BOARD_SIZE]){
    int row, column;
    if(find_empty(board, &row, &column) == 0){
        return 1;
    }

    for(int i = 1; i <= 9; i++){
        if(check_row(board, row, i) && check_column(board, column, i) && check_box(board, row, column, i)){
            board[row][column] = i;

            if(solve_sudoku(board)){
                return 1;
            }

            board[row][column] = 0;
        }
    }

    return 0;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    if(solve_sudoku(board)){
        printf("Solved Sudoku Puzzle:\n");
        print_board(board);
    }else{
        printf("Unsolvable Sudoku Puzzle\n");
    }

    return 0;
}