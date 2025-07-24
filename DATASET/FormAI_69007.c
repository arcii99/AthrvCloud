//FormAI DATASET v1.0 Category: Chess engine ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ROWS 8
#define COLUMNS 8

// Structure to store the state of the chess board
typedef struct {
    char board[ROWS][COLUMNS];
    int whiteKingRow;
    int whiteKingColumn;
    int blackKingRow;
    int blackKingColumn;
    bool whiteToMove;
    bool whiteKingSafe;
    bool blackKingSafe;
} ChessBoard;

// Initializes the chess board
void initChessBoard(ChessBoard *chessBoard) {
    // Set up the initial chess board configuration
    char chessBoardConfig[ROWS][COLUMNS] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
     };

    // Copy the initial chess board configuration to the game board
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            chessBoard->board[row][column] = chessBoardConfig[row][column];
            if (chessBoardConfig[row][column] == 'K') {
                chessBoard->whiteKingRow = row;
                chessBoard->whiteKingColumn = column;
            } else if (chessBoardConfig[row][column] == 'k') {
                chessBoard->blackKingRow = row;
                chessBoard->blackKingColumn = column;
            }
        }
    }
    chessBoard->whiteToMove = true;
    chessBoard->whiteKingSafe = true;
    chessBoard->blackKingSafe = true;
}

// Displays the chess board on the console
void displayChessBoard(ChessBoard *chessBoard) {
    printf("\n  a b c d e f g h\n");
    for (int row = 0; row < ROWS; row++) {
        printf("%d ", row + 1);
        for (int column = 0; column < COLUMNS; column++) {
            printf("%c ", chessBoard->board[row][column]);
        }
        printf("%d\n", row + 1);
    }
    printf("  a b c d e f g h\n");
}

int main() {
    ChessBoard chessBoard;
    initChessBoard(&chessBoard);
    displayChessBoard(&chessBoard);
    return 0;
}