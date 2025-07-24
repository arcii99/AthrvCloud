//FormAI DATASET v1.0 Category: Checkers Game ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

// function to initialize the checker board
void init_board(char board[][SIZE]) {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if((i+j) % 2 == 0) {
                if(i < 3)
                    board[i][j] = 'b';
                else if(i > 4)
                    board[i][j] = 'w';
                else
                    board[i][j] = 'e'; // empty cell
            } else {
                board[i][j] = ' '; // invalid cell
            }
        }
    }
}

// function to display the checker board
void display_board(char board[][SIZE]) {
    printf("    ");
    for(int i=0; i<SIZE; i++)
        printf("%c  ", 'a'+i);
    printf("\n");
    for(int i=0; i<SIZE; i++) {
        printf("   +");
        for(int j=0; j<SIZE; j++)
            printf("--+");
        printf("\n");
        printf("%2d |", i+1);
        for(int j=0; j<SIZE; j++)
            printf("%c |", board[i][j]);
        printf(" %2d\n", i+1);
    }
    printf("   +");
    for(int j=0; j<SIZE; j++)
        printf("--+");
    printf("\n");
    printf("    ");
    for(int i=0; i<SIZE; i++)
        printf("%c  ", 'a'+i);
    printf("\n");
}

// function to check whether a move is valid or not
int is_valid_move(char board[][SIZE], int row, int col, int nrow, int ncol, char turn) {
    // check if the target cell is empty
    if(board[nrow][ncol] != 'e')
        return 0;
    // check for a regular move for a normal piece
    if(abs(ncol-col) == 1 && (nrow-row) == (turn=='w'?-1:1) && board[row][col] == turn)
        return 1;
    // check for a regular move for a king piece
    if(abs(ncol-col) == 1 && abs(nrow-row) == 1 && board[row][col] == turn+'K')
        return 1;
    // check for a capture move for a normal piece
    if(abs(ncol-col) == 2 && (nrow-row) == (turn=='w'?-2:2) && board[row][col] == turn) {
        int mid_row = (nrow+row)/2;
        int mid_col = (ncol+col)/2;
        if(board[mid_row][mid_col] == ((turn=='w')?'b':'w') || board[mid_row][mid_col] == ((turn=='w')?'B':'W'))
            return 1;
    }
    // check for a capture move for a king piece
    if(abs(ncol-col) == 2 && abs(nrow-row) == 2 && board[row][col] == turn+'K') {
        int mid_row = (nrow+row)/2;
        int mid_col = (ncol+col)/2;
        if(board[mid_row][mid_col] == ((turn=='w')?'b':'w') || board[mid_row][mid_col] == ((turn=='w')?'B':'W'))
            return 1;
    }
    return 0;
}

// function to make a move on the checker board
int make_move(char board[][SIZE], int row, int col, int nrow, int ncol, char turn) {
    // check if the move is valid
    if(!is_valid_move(board, row, col, nrow, ncol, turn))
        return 0;
    // make the move
    board[nrow][ncol] = board[row][col];
    board[row][col] = 'e';
    // check for a capture move
    if(abs(ncol-col) == 2) {
        int mid_row = (nrow+row)/2;
        int mid_col = (ncol+col)/2;
        board[mid_row][mid_col] = 'e';
    }
    // convert a normal piece to a king
    if(board[nrow][ncol] == 'w' && nrow == 0)
        board[nrow][ncol] = 'W';
    if(board[nrow][ncol] == 'b' && nrow == SIZE-1)
        board[nrow][ncol] = 'B';
    return 1;
}

// function to check whether a player has any valid moves left
int has_valid_moves_left(char board[][SIZE], char turn) {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(board[i][j] == turn || board[i][j] == turn+'K') {
                if(is_valid_move(board, i, j, i-1, j+1, turn) ||
                   is_valid_move(board, i, j, i-1, j-1, turn) ||
                   is_valid_move(board, i, j, i+1, j+1, turn) ||
                   is_valid_move(board, i, j, i+1, j-1, turn))
                    return 1;
            }
        }
    }
    return 0;
}

// main function
int main() {
    char board[SIZE][SIZE];
    char turn = 'w';
    int row, col, nrow, ncol;
    init_board(board);
    while(has_valid_moves_left(board, turn)) {
        display_board(board);
        printf("Player %c's turn:\n", turn);
        printf("Enter the row and column of the piece you want to move: ");
        scanf("%d%d", &row, &col);
        printf("Enter the row and column of the position you want to move to: ");
        scanf("%d%d", &nrow, &ncol);
        if(make_move(board, row-1, col-'a', nrow-1, ncol-'a', turn)) {
            if(turn == 'w')
                turn = 'b';
            else
                turn = 'w';
        } else {
            printf("Invalid move!\n");
        }
    }
    display_board(board);
    printf("Player %c wins!\n", (turn=='w')?'b':'w');
    return 0;
}