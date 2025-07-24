//FormAI DATASET v1.0 Category: Chess engine ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define board size
#define BOARD_SIZE 8

// Define piece values
#define KING_VALUE 100
#define QUEEN_VALUE 9
#define ROOK_VALUE 5
#define BISHOP_VALUE 3
#define KNIGHT_VALUE 3
#define PAWN_VALUE 1

// Define piece types
#define EMPTY 0
#define KING 1
#define QUEEN 2
#define ROOK 3
#define BISHOP 4
#define KNIGHT 5
#define PAWN 6

// Define color values
#define WHITE 0
#define BLACK 1

// Define struct for chess piece
typedef struct {
    int type;
    int value;
    int color;
} Piece;

// Define 2D array to hold chess board
Piece board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the starting chess board
void initialize_board() {
    // Initialize pawns
    for(int i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = (Piece) {PAWN, PAWN_VALUE, BLACK};
        board[6][i] = (Piece) {PAWN, PAWN_VALUE, WHITE};
    }
    
    // Initialize rooks
    board[0][0] = (Piece) {ROOK, ROOK_VALUE, BLACK};
    board[0][7] = (Piece) {ROOK, ROOK_VALUE, BLACK};
    board[7][0] = (Piece) {ROOK, ROOK_VALUE, WHITE};
    board[7][7] = (Piece) {ROOK, ROOK_VALUE, WHITE};
    
    // Initialize knights
    board[0][1] = (Piece) {KNIGHT, KNIGHT_VALUE, BLACK};
    board[0][6] = (Piece) {KNIGHT, KNIGHT_VALUE, BLACK};
    board[7][1] = (Piece) {KNIGHT, KNIGHT_VALUE, WHITE};
    board[7][6] = (Piece) {KNIGHT, KNIGHT_VALUE, WHITE};
    
    // Initialize bishops
    board[0][2] = (Piece) {BISHOP, BISHOP_VALUE, BLACK};
    board[0][5] = (Piece) {BISHOP, BISHOP_VALUE, BLACK};
    board[7][2] = (Piece) {BISHOP, BISHOP_VALUE, WHITE};
    board[7][5] = (Piece) {BISHOP, BISHOP_VALUE, WHITE};
    
    // Initialize queens
    board[0][3] = (Piece) {QUEEN, QUEEN_VALUE, BLACK};
    board[7][3] = (Piece) {QUEEN, QUEEN_VALUE, WHITE};
    
    // Initialize kings
    board[0][4] = (Piece) {KING, KING_VALUE, BLACK};
    board[7][4] = (Piece) {KING, KING_VALUE, WHITE};
}

// Function to print the chess board
void print_board() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j].type == EMPTY) {
                printf(" - ");
            }
            else {
                switch(board[i][j].type) {
                    case KING:
                        printf(" K ");
                        break;
                    case QUEEN:
                        printf(" Q ");
                        break;
                    case ROOK:
                        printf(" R ");
                        break;
                    case BISHOP:
                        printf(" B ");
                        break;
                    case KNIGHT:
                        printf(" N ");
                        break;
                    case PAWN:
                        printf(" P ");
                        break;
                }
            }
        }
        printf("\n");
    }
}

int main() {
    // Initialize the chess board
    initialize_board();
    
    // Print the initial board
    printf("Initial board:\n");
    print_board();
    
    return 0;
}