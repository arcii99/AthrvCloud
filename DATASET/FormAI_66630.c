//FormAI DATASET v1.0 Category: Chess engine ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define BOARD_SIZE 8

//Colors of chess pieces
typedef enum { WHITE, BLACK } Color;

//Types of chess pieces
typedef enum { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } Type;

//Chess piece structure
typedef struct {
    Color color;
    Type type;
} Piece;

//Chess board structure
typedef struct {
    Piece board[BOARD_SIZE][BOARD_SIZE];
    Color turn;
    bool can_castle_kingside[2];
    bool can_castle_queenside[2];
} Board;

//Function to initialize chess board
void init_board(Board *board) {
    board->turn = WHITE;
    board->can_castle_kingside[WHITE] = true;
    board->can_castle_kingside[BLACK] = true;
    board->can_castle_queenside[WHITE] = true;
    board->can_castle_queenside[BLACK] = true;
    //Initialize pawns
    for(int i=0;i<BOARD_SIZE;i++) {
        board->board[1][i] = (Piece) { WHITE, PAWN };
        board->board[6][i] = (Piece) { BLACK, PAWN };
    }
    //Initialize knights
    board->board[0][1] = (Piece) { WHITE, KNIGHT };
    board->board[0][6] = (Piece) { WHITE, KNIGHT };
    board->board[7][1] = (Piece) { BLACK, KNIGHT };
    board->board[7][6] = (Piece) { BLACK, KNIGHT };
    //Initialize bishops
    board->board[0][2] = (Piece) { WHITE, BISHOP };
    board->board[0][5] = (Piece) { WHITE, BISHOP };
    board->board[7][2] = (Piece) { BLACK, BISHOP };
    board->board[7][5] = (Piece) { BLACK, BISHOP };
    //Initialize rooks
    board->board[0][0] = (Piece) { WHITE, ROOK };
    board->board[0][7] = (Piece) { WHITE, ROOK };
    board->board[7][0] = (Piece) { BLACK, ROOK };
    board->board[7][7] = (Piece) { BLACK, ROOK };
    //Initialize queens
    board->board[0][3] = (Piece) { WHITE, QUEEN };
    board->board[7][3] = (Piece) { BLACK, QUEEN };
    //Initialize kings
    board->board[0][4] = (Piece) { WHITE, KING };
    board->board[7][4] = (Piece) { BLACK, KING };
}

//Function to display chess board
void display_board(Board *board) {
    for(int i=0;i<BOARD_SIZE;i++) {
        for(int j=0;j<BOARD_SIZE;j++) {
            char piece_name = ' ';
            if(board->board[i][j].type == PAWN)
                piece_name = 'P';
            else if(board->board[i][j].type == KNIGHT)
                piece_name = 'N';
            else if(board->board[i][j].type == BISHOP)
                piece_name = 'B';
            else if(board->board[i][j].type == ROOK)
                piece_name = 'R';
            else if(board->board[i][j].type == QUEEN)
                piece_name = 'Q';
            else if(board->board[i][j].type == KING)
                piece_name = 'K';
            if(board->board[i][j].color == BLACK)
                piece_name = piece_name + 32; //convert to lowercase
            printf("%c ", piece_name);
        }
        printf("\n");
    }
}

//Function to move piece on chess board
void move_piece(Board *board, int from_row, int from_col, int to_row, int to_col) {
    board->board[to_row][to_col] = board->board[from_row][from_col];
    board->board[from_row][from_col] = (Piece) { 0 };
}

int main() {
    Board board;
    init_board(&board);
    display_board(&board);
    move_piece(&board, 1, 0, 2, 0);
    printf("\nAfter moving pawn:\n");
    display_board(&board);
    return 0;
}