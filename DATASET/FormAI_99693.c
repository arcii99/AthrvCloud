//FormAI DATASET v1.0 Category: Chess AI ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

// Piece values
#define PAWN_VALUE 1
#define KNIGHT_VALUE 3
#define BISHOP_VALUE 3
#define ROOK_VALUE 5
#define QUEEN_VALUE 9
#define KING_VALUE 100

// Piece colors
#define WHITE_PIECE 0
#define BLACK_PIECE 1

// Board representation
char board[BOARD_SIZE][BOARD_SIZE] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

// Determines if a position is on the board
bool onBoard(int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
}

// Determines if a piece is of a certain color
bool isColor(char piece, int color) {
    if (piece >= 'A' && piece <= 'Z') {
        return color == WHITE_PIECE;
    } else if (piece >= 'a' && piece <= 'z') {
        return color == BLACK_PIECE;
    }
    return false;
}

// Returns the value of a given piece
int getPieceValue(char piece) {
    switch(piece) {
        case 'P':
        case 'p':
            return PAWN_VALUE;
        case 'N':
        case 'n':
            return KNIGHT_VALUE;
        case 'B':
        case 'b':
            return BISHOP_VALUE;
        case 'R':
        case 'r':
            return ROOK_VALUE;
        case 'Q':
        case 'q':
            return QUEEN_VALUE;
        case 'K':
        case 'k':
            return KING_VALUE;
        default:
            return 0;
    }
}

// Evaluates the board and returns the score for a given color
int evaluateBoard(int color) {
    int score = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            char piece = board[i][j];
            if (isColor(piece, color)) {
                score += getPieceValue(piece);
            } else if (isColor(piece, 1 - color)) {
                score -= getPieceValue(piece);
            }
        }
    }
    return score;
}

// Prints the board
void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Evaluate the board for white
    int whiteScore = evaluateBoard(WHITE_PIECE);
    printf("White score: %d\n", whiteScore);
    
    // Evaluate the board for black
    int blackScore = evaluateBoard(BLACK_PIECE);
    printf("Black score: %d\n", blackScore);
    
    // Print the board
    printBoard();
    
    return 0;
}