//FormAI DATASET v1.0 Category: Chess engine ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum {
    EMPTY, 
    PAWN, 
    KNIGHT, 
    BISHOP, 
    ROOK, 
    QUEEN, 
    KING
} Piece;

typedef enum {
    WHITE, 
    BLACK
} Color;

typedef struct {
    Piece piece;
    Color color;
} Square;

typedef struct {
    Square board[BOARD_SIZE][BOARD_SIZE];
    Color turn;
} ChessBoard;

void initBoard(ChessBoard *board){
    int i,j;
    for(i=0;i<BOARD_SIZE;i++){
        for(j=0;j<BOARD_SIZE;j++){
            board->board[i][j].color = EMPTY;
            board->board[i][j].piece = EMPTY;
        }
    }
}

void printBoard(ChessBoard *board){
    int i,j;
    for(i=0;i<BOARD_SIZE;i++){
        for(j=0;j<BOARD_SIZE;j++){
            switch(board->board[i][j].piece){
                case PAWN:
                    printf("P");
                    break;
                case KNIGHT:
                    printf("N");
                    break;
                case BISHOP:
                    printf("B");
                    break;
                case ROOK:
                    printf("R");
                    break;
                case QUEEN:
                    printf("Q");
                    break;
                case KING:
                    printf("K");
                    break;
                default:
                    printf(".");
                    break;
            }
        }
        printf("\n");
    }
}

int main(){
    ChessBoard board;
    initBoard(&board);
    printBoard(&board);
    return 0;
}