//FormAI DATASET v1.0 Category: Chess AI ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Define the chess board size
#define BOARD_SIZE 8

//Define piece types
typedef enum {EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING} pieceType_t;

//Define the pieces structure
typedef struct {
    pieceType_t type;   //the type of the piece
    bool isWhite;       //whether the piece is white or black
} piece_t;

//Define the chess board
piece_t board[BOARD_SIZE][BOARD_SIZE];

//Define the function to initialize the board
void initializeBoard() {
    //initialize the pawns
    for(int i=0; i<BOARD_SIZE; i++) {
        board[1][i].type = PAWN;
        board[1][i].isWhite = false;
        
        board[6][i].type = PAWN;
        board[6][i].isWhite = true;
    }
    
    //initialize the knights
    board[0][1].type = KNIGHT;
    board[0][1].isWhite = false;
    
    board[0][6].type = KNIGHT;
    board[0][6].isWhite = false;
    
    board[7][1].type = KNIGHT;
    board[7][1].isWhite = true;
    
    board[7][6].type = KNIGHT;
    board[7][6].isWhite = true;
    
    //initialize the bishops
    board[0][2].type = BISHOP;
    board[0][2].isWhite = false;
    
    board[0][5].type = BISHOP;
    board[0][5].isWhite = false;
    
    board[7][2].type = BISHOP;
    board[7][2].isWhite = true;
    
    board[7][5].type = BISHOP;
    board[7][5].isWhite = true;
    
    //initialize the rooks
    board[0][0].type = ROOK;
    board[0][0].isWhite = false;
    
    board[0][7].type = ROOK;
    board[0][7].isWhite = false;
    
    board[7][0].type = ROOK;
    board[7][0].isWhite = true;
    
    board[7][7].type = ROOK;
    board[7][7].isWhite = true;
    
    //initialize the queens
    board[0][3].type = QUEEN;
    board[0][3].isWhite = false;
    
    board[7][3].type = QUEEN;
    board[7][3].isWhite = true;
    
    //initialize the kings
    board[0][4].type = KING;
    board[0][4].isWhite = false;
    
    board[7][4].type = KING;
    board[7][4].isWhite = true;
}

//Define the function to print the board
void printBoard() {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            switch(board[i][j].type) {
                case EMPTY:
                    printf("-");
                    break;
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
            }
            
            if(board[i][j].isWhite)
                printf("w ");
            else
                printf("b ");
        }
        printf("\n");
    }
}

int main() {
    initializeBoard();
    printBoard();
    return 0;
}