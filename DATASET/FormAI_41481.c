//FormAI DATASET v1.0 Category: Chess engine ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Constants to represent the chess board size
#define BOARD_SIZE 8
#define WHITE_PAWN 'P'
#define WHITE_KNIGHT 'N'
#define WHITE_BISHOP 'B'
#define WHITE_ROOK 'R'
#define WHITE_QUEEN 'Q'
#define WHITE_KING 'K'
#define BLACK_PAWN 'p'
#define BLACK_KNIGHT 'n'
#define BLACK_BISHOP 'b'
#define BLACK_ROOK 'r'
#define BLACK_QUEEN 'q'
#define BLACK_KING 'k'
#define EMPTY_CELL '.'

// Function to initialize the chess board
void init_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for(i=0; i<BOARD_SIZE; i++) {
        for(j=0; j<BOARD_SIZE; j++) {
            if (i==0 || i==BOARD_SIZE-1) {
                // Place the back row of pieces for black and white
                switch(j) {
                    case 0: board[i][j] = WHITE_ROOK; break;
                    case 1: board[i][j] = WHITE_KNIGHT; break;
                    case 2: board[i][j] = WHITE_BISHOP; break;
                    case 3: board[i][j] = WHITE_QUEEN; break;
                    case 4: board[i][j] = WHITE_KING; break;
                    case 5: board[i][j] = WHITE_BISHOP; break;
                    case 6: board[i][j] = WHITE_KNIGHT; break;
                    case 7: board[i][j] = WHITE_ROOK; break;
                }
            } else if (i==1 || i==BOARD_SIZE-2) {
                // Place the rows of pawns for black and white
                board[i][j] = (i==1)? WHITE_PAWN : BLACK_PAWN;
            } else {
                // Place empty cells after the initial rows
                board[i][j] = EMPTY_CELL;
            }
        }
    }
}

// Function to print the current state of the chess board
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for(i=0; i<BOARD_SIZE; i++) {
        for(j=0; j<BOARD_SIZE; j++) {
            printf("|%c", board[i][j]);
        }
        printf("|\n");
    }
}

// Main function to run the chess engine
int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    print_board(board);
    return 0;
}