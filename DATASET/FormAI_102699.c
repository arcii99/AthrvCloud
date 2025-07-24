//FormAI DATASET v1.0 Category: Chess engine ; Style: systematic
#include <stdio.h>

// Define constants for the size of the chess board
#define BOARD_SIZE 8
#define EMPTY_SQUARE 0
#define WHITE_PAWN 1
#define WHITE_KING 2
#define WHITE_QUEEN 3
#define WHITE_ROOK 4
#define WHITE_BISHOP 5
#define WHITE_KNIGHT 6
#define BLACK_PAWN -1
#define BLACK_KING -2
#define BLACK_QUEEN -3
#define BLACK_ROOK -4
#define BLACK_BISHOP -5
#define BLACK_KNIGHT -6

// Define the type representing the chess board
typedef int Board[BOARD_SIZE][BOARD_SIZE];

// Function to print the chess board to the console
void print_board(Board board) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            switch(board[i][j]) {
                case EMPTY_SQUARE: printf("."); break;
                case WHITE_PAWN: printf("P"); break;
                case WHITE_KING: printf("K"); break;
                case WHITE_QUEEN: printf("Q"); break;
                case WHITE_ROOK: printf("R"); break;
                case WHITE_BISHOP: printf("B"); break;
                case WHITE_KNIGHT: printf("N"); break;
                case BLACK_PAWN: printf("p"); break;
                case BLACK_KING: printf("k"); break;
                case BLACK_QUEEN: printf("q"); break;
                case BLACK_ROOK: printf("r"); break;
                case BLACK_BISHOP: printf("b"); break;
                case BLACK_KNIGHT: printf("n"); break;
            }
        }
        printf("\n");
    }
}

// Function to initialize the board to a starting position
void init_board(Board board) {
    // Set up the pieces for the white side
    board[0][0] = WHITE_ROOK;
    board[0][1] = WHITE_KNIGHT;
    board[0][2] = WHITE_BISHOP;
    board[0][3] = WHITE_QUEEN;
    board[0][4] = WHITE_KING;
    board[0][5] = WHITE_BISHOP;
    board[0][6] = WHITE_KNIGHT;
    board[0][7] = WHITE_ROOK;
    for(int i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = WHITE_PAWN;
    }

    // Set up the pieces for the black side
    board[7][0] = BLACK_ROOK;
    board[7][1] = BLACK_KNIGHT;
    board[7][2] = BLACK_BISHOP;
    board[7][3] = BLACK_QUEEN;
    board[7][4] = BLACK_KING;
    board[7][5] = BLACK_BISHOP;
    board[7][6] = BLACK_KNIGHT;
    board[7][7] = BLACK_ROOK;
    for(int i = 0; i < BOARD_SIZE; i++) {
        board[6][i] = BLACK_PAWN;
    }

    // Set the rest of the squares to empty
    for(int i = 2; i < 6; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY_SQUARE;
        }
    }
}

// This program initializes a chess board and then prints it to the console
int main() {
    Board board;
    init_board(board);
    print_board(board);
    return 0;
}