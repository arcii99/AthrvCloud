//FormAI DATASET v1.0 Category: Sudoku solver ; Style: retro
#include <stdio.h>

void print_board(int board[][9]){
    int i, j;
    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int find_empty_spot(int board[][9], int *row, int *col){
    for(*row=0; *row<9; (*row)++){
        for(*col=0; *col<9; (*col)++){
            if(board[*row][*col] == 0){
                return 1;
            }
        }
    }
    return 0;
}

int check_row(int board[][9], int row, int num){
    int i;
    for(i=0; i<9; i++){
        if(board[row][i] == num){
            return 0;
        }
    }
    return 1;
}

int check_col(int board[][9], int col, int num){
    int i;
    for(i=0; i<9; i++){
        if(board[i][col] == num){
            return 0;
        }
    }
    return 1;
}

int check_box(int board[][9], int box_row, int box_col, int num){
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(board[box_row+i][box_col+j] == num){
                return 0;
            }
        }
    }
    return 1;
}

int check_move(int board[][9], int row, int col, int num){
    int box_row = row - (row%3);
    int box_col = col - (col%3);
    return check_row(board, row, num) && check_col(board, col, num) && check_box(board, box_row, box_col, num);
}

int solve_sudoku(int board[][9]){
    int row, col;

    if(!find_empty_spot(board, &row, &col)){
        return 1;
    }

    int num;
    for(num=1; num<=9; num++){
        if(check_move(board, row, col, num)){
            board[row][col] = num;
            if(solve_sudoku(board)){
                return 1;
            }
            board[row][col] = 0;
        }
    }

    return 0;
}

void main(){
    int board[9][9] = {
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
        printf("Solved!\n");
        print_board(board);
    } else {
        printf("Unsolvable board\n");
    }
}