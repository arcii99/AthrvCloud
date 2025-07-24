//FormAI DATASET v1.0 Category: Chess engine ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 /*Declaring variables*/
struct chess_board {
    char board[8][8];
    int black_pieces;
    int white_pieces;
};

/*Declaring functions*/
void reset_board(struct chess_board *board);
void print_board(struct chess_board *board);
void move_piece(struct chess_board *board, char *from_pos, char *to_pos);

/*Resetting the chessboard*/
void reset_board(struct chess_board *board) {
    int i,j;
    char empty = '-';
    
    /*Initializing all pieces to empty*/
    for(i=0; i<8; i++) {
        for(j=0; j<8; j++) {
            board->board[i][j] = empty;
        }
    }
    
    /*Placing black pieces*/
    board->board[0][0] = 'r';
    board->board[0][1] = 'n';
    board->board[0][2] = 'b';
    board->board[0][3] = 'k';
    board->board[0][4] = 'q';
    board->board[0][5] = 'b';
    board->board[0][6] = 'n';
    board->board[0][7] = 'r';
    board->board[1][0] = 'p';
    board->board[1][1] = 'p';
    board->board[1][2] = 'p';
    board->board[1][3] = 'p';
    board->board[1][4] = 'p';
    board->board[1][5] = 'p';
    board->board[1][6] = 'p';
    board->board[1][7] = 'p';
    board->black_pieces = 16;

    /*Placing white pieces*/
    board->board[7][0] = 'R';
    board->board[7][1] = 'N';
    board->board[7][2] = 'B';
    board->board[7][3] = 'K';
    board->board[7][4] = 'Q';
    board->board[7][5] = 'B';
    board->board[7][6] = 'N';
    board->board[7][7] = 'R';
    board->board[6][0] = 'P';
    board->board[6][1] = 'P';
    board->board[6][2] = 'P';
    board->board[6][3] = 'P';
    board->board[6][4] = 'P';
    board->board[6][5] = 'P';
    board->board[6][6] = 'P';
    board->board[6][7] = 'P';
    board->white_pieces = 16;

    return;
}

/*Printing the chessboard*/
void print_board(struct chess_board *board) {
    int i,j;
    
    for(i=0; i<8; i++) {
        for(j=0; j<8; j++) {
            printf("%c",board->board[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    return;
}

/*Moving a chess piece*/
void move_piece(struct chess_board *board, char *from_pos, char *to_pos) {

    int from_x, from_y, to_x, to_y;
    char piece;
    
    /*Determining the piece to move from the original position*/
    from_x = from_pos[0] - 'a';
    from_y = 8 - (from_pos[1] - '0');
    piece = board->board[from_y][from_x];

    /*Moving the piece to the new position*/
    to_x = to_pos[0] - 'a';
    to_y = 8 - (to_pos[1] - '0');
    board->board[from_y][from_x] = '-';
    board->board[to_y][to_x] = piece;

    return;
}

int main() {

    struct chess_board board;
    
    /*Resetting the board*/
    reset_board(&board);
    /*Printing the initial board*/
    print_board(&board);
    
    /*Moving the piece at b2 to b4*/
    char *from = "b2";
    char *to = "b4";
    move_piece(&board, from, to);
    /*Printing the board after moving the piece*/
    print_board(&board);
    
    return 0;
}