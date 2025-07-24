//FormAI DATASET v1.0 Category: Chess engine ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

// Structure for each chess piece.
typedef struct {
    char symbol;
    int row;
    int col;
} ChessPiece;

// Function to initialize the chess board and pieces.
void initializeBoard(ChessPiece *pieces) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        pieces[i].symbol = 'P';
        pieces[i].row = 1;
        pieces[i].col = i;
    }
    for(int i = BOARD_SIZE; i < 2*BOARD_SIZE; i++) {
        pieces[i].symbol = 'K';
        if(i == BOARD_SIZE) {
            pieces[i].row = 0;
            pieces[i].col = 1;
        }
        else {
            pieces[i].row = 0;
            pieces[i].col = BOARD_SIZE - 2;
        }
    }
    printf("Wow! The chess board is now initialized with pieces!\n");
}

// Function to print the chess board.
void printBoard(ChessPiece *pieces) {
    char board[BOARD_SIZE][BOARD_SIZE];
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
    for(int i = 0; i < 2*BOARD_SIZE; i++) {
        int row = pieces[i].row;
        int col = pieces[i].col;
        board[row][col] = pieces[i].symbol;
    }
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("Bravo! The chess board is now printed with pieces!\n");
}

// Function to move a chess piece.
void movePiece(ChessPiece *pieces, char symbol, int row, int col) {
    bool pieceFound = false;
    for(int i = 0; i < 2*BOARD_SIZE; i++) {
        if(pieces[i].symbol == symbol && pieces[i].row == row && pieces[i].col == col) {
            pieces[i].row++;
            pieces[i].col++;
            printf("Amazing! The %c piece is now moved to row %d and column %d.\n", symbol, pieces[i].row, pieces[i].col);
            pieceFound = true;
            break;
        }
    }
    if(!pieceFound) {
        printf("Oh no! Could not find the %c piece on the specified row and column.\n", symbol);
    }
}

int main() {
    ChessPiece pieces[2*BOARD_SIZE];
    // Initialize the board and pieces.
    initializeBoard(pieces);
    // Print the board with pieces.
    printBoard(pieces);
    // Move a piece.
    movePiece(pieces, 'P', 2, 1);
    // Print the board with pieces after the move.
    printBoard(pieces);
    return 0;
}