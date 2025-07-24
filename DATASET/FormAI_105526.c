//FormAI DATASET v1.0 Category: Chess engine ; Style: Ken Thompson
#include <stdio.h>

typedef enum {false, true} bool;
typedef enum {white, black} color;
typedef struct Piece{
    bool isPiece;
    color pieceColor;
} Piece;

#define BOARD_SIZE 8

Piece board[BOARD_SIZE][BOARD_SIZE] = {0};

void init_board(){
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            board[i][j].isPiece = false;
        }
    }
}

void print_board(){
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            printf("%c ", board[i][j].isPiece ? ((board[i][j].pieceColor==white) ? "w" : "b") : ".");
        }
        printf("\n");
    }
}

int main(){
    init_board();
    board[4][4].isPiece = true;
    board[4][4].pieceColor = white;
    board[4][3].isPiece = true;
    board[4][3].pieceColor = black;
    print_board();
    return 0;
}