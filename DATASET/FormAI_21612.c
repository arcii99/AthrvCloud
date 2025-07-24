//FormAI DATASET v1.0 Category: Chess engine ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Struct for chess pieces
typedef struct {
    char type; // 'P' for pawn, 'N' for knight, 'B' for bishop, 'R' for rook, 'Q' for queen, 'K' for king
    char color; // 'W' for white, 'B' for black
} Piece;

// Struct for chess board square
typedef struct {
    Piece piece;
    int x;
    int y;
} Square;

// Function to initialize chess board
void initBoard(Square board[8][8]) {
    // Set up white pieces
    board[0][0].piece.type = 'R';
    board[0][0].piece.color = 'W';
    board[0][1].piece.type = 'N';
    board[0][1].piece.color = 'W';
    board[0][2].piece.type = 'B';
    board[0][2].piece.color = 'W';
    board[0][3].piece.type = 'Q';
    board[0][3].piece.color = 'W';
    board[0][4].piece.type = 'K';
    board[0][4].piece.color = 'W';
    board[0][5].piece.type = 'B';
    board[0][5].piece.color = 'W';
    board[0][6].piece.type = 'N';
    board[0][6].piece.color = 'W';
    board[0][7].piece.type = 'R';
    board[0][7].piece.color = 'W';
    for (int i = 0; i < 8; i++) {
        board[1][i].piece.type = 'P';
        board[1][i].piece.color = 'W';
    }

    // Set up black pieces
    board[7][0].piece.type = 'R';
    board[7][0].piece.color = 'B';
    board[7][1].piece.type = 'N';
    board[7][1].piece.color = 'B';
    board[7][2].piece.type = 'B';
    board[7][2].piece.color = 'B';
    board[7][3].piece.type = 'Q';
    board[7][3].piece.color = 'B';
    board[7][4].piece.type = 'K';
    board[7][4].piece.color = 'B';
    board[7][5].piece.type = 'B';
    board[7][5].piece.color = 'B';
    board[7][6].piece.type = 'N';
    board[7][6].piece.color = 'B';
    board[7][7].piece.type = 'R';
    board[7][7].piece.color = 'B';
    for (int i = 0; i < 8; i++) {
        board[6][i].piece.type = 'P';
        board[6][i].piece.color = 'B';
    }

    // Initialize empty squares
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j].piece.type = ' ';
            board[i][j].piece.color = ' ';
        }
    }

    // Set coordinates for each square
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j].x = i;
            board[i][j].y = j;
        }
    }
}

// Function to print chess board
void printBoard(Square board[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c%c ", board[i][j].piece.color, board[i][j].piece.type);
        }
        printf("\n");
    }
}

// Main function
int main() {
    Square board[8][8];
    initBoard(board);
    printBoard(board);
    return 0;
}