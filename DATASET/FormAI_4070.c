//FormAI DATASET v1.0 Category: Chess engine ; Style: brave
#include <stdio.h>
#include <stdlib.h>

//define the chess board size
#define BOARD_SIZE 8

//define the move struct
typedef struct move_t{
    int fromRow;
    int fromCol;
    int toRow;
    int toCol;
} Move;

// define the board struct
typedef struct board_t{
    char squares[BOARD_SIZE][BOARD_SIZE];
} Board;

// function to print the board
void printBoard(Board board){
    int i, j;
    printf("\n");
    for(i = 0; i < BOARD_SIZE; i++){
        for(j = 0; j < BOARD_SIZE; j++){
            printf(" %c ", board.squares[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// function to initialize the board
void initBoard(Board *board){
    int i, j;
    
    //initialize the pawns
    for(i = 0; i < BOARD_SIZE; i++){
        board->squares[1][i] = 'P';
        board->squares[6][i] = 'p';
    }
    
    //initialize the rest of the pieces
    board->squares[0][0] = 'R';
    board->squares[0][7] = 'R';
    board->squares[7][0] = 'r';
    board->squares[7][7] = 'r';
    board->squares[0][1] = 'N';
    board->squares[0][6] = 'N';
    board->squares[7][1] = 'n';
    board->squares[7][6] = 'n';
    board->squares[0][2] = 'B';
    board->squares[0][5] = 'B';
    board->squares[7][2] = 'b';
    board->squares[7][5] = 'b';
    board->squares[0][3] = 'Q';
    board->squares[7][3] = 'q';
    board->squares[0][4] = 'K';
    board->squares[7][4] = 'k';
    
    //initialize the empty squares
    for(i = 2; i < 6; i++){
        for(j = 0; j < BOARD_SIZE; j++){
            board->squares[i][j] = ' ';
        }
    }
}

// function to check if a move is legal
int isLegalMove(Board board, Move move){
    //TODO: add code to check if move is legal
    return 1;
}

// function to make a move
void makeMove(Board *board, Move move){
    board->squares[move.toRow][move.toCol] = board->squares[move.fromRow][move.fromCol];
    board->squares[move.fromRow][move.fromCol] = ' ';
}

int main(){
    Board board;
    initBoard(&board);
    printBoard(board);
    
    //TODO: add code to get moves from player and make them 
    
    return 0;
}