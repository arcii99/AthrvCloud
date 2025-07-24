//FormAI DATASET v1.0 Category: Checkers Game ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define RED 'R'
#define BLACK 'B'
#define KING 'K'

typedef struct position {
    int row;
    int column;
} Position;

typedef struct piece {
    char type;
    int isKing;
} Piece;

Piece board[BOARD_SIZE][BOARD_SIZE]; // Initialize empty board

void initializeBoard() {
    int i, j;

    printf("Initializing board...\n");

    // Initialize all board pieces
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 != 0) { // Only place pieces on dark squares
                if (i < 3) {
                    board[i][j].type = BLACK;
                    board[i][j].isKing = 0;
                } else if (i > 4) {
                    board[i][j].type = RED;
                    board[i][j].isKing = 0;
                } else {
                    board[i][j].type = ' ';
                    board[i][j].isKing = 0;
                }
            } else {
                board[i][j].type = ' ';
                board[i][j].isKing = 0;
            }
        }
    }
}

void printBoard() {
    int i, j;

    printf("   0  1  2  3  4  5  6  7\n");
    printf("  +-----------------------+\n");

    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i);

        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].type == ' ') {
                printf("   |");
            } else {
                if (board[i][j].isKing) {
                    printf(" %c |", toupper(board[i][j].type));
                } else {
                    printf(" %c |", board[i][j].type);
                }
            }
        }

        printf(" %d\n", i);
        printf("  +-----------------------+\n");
    }

    printf("   0  1  2  3  4  5  6  7\n");
}

int main() {
    int turn = 0; // Red goes first
    initializeBoard();
    printBoard();

    while (1) { // Keep playing until either player wins
        char playerColor = (turn % 2 == 0) ? RED : BLACK;
        printf("%c's turn.\n", playerColor);

        printf("Enter coordinates of piece to move: ");
        Position fromPos;
        scanf("%d %d", &fromPos.row, &fromPos.column);

        printf("Enter coordinates of square to move to: ");
        Position toPos;
        scanf("%d %d", &toPos.row, &toPos.column);

        // Make sure entered coordinates are valid
        if (fromPos.row < 0 || fromPos.row >= BOARD_SIZE || fromPos.column < 0 || fromPos.column >= BOARD_SIZE ||
            toPos.row < 0 || toPos.row >= BOARD_SIZE || toPos.column < 0 || toPos.column >= BOARD_SIZE) {
            printf("Invalid position entered.\n");
            continue;
        }

        // Make sure player is moving their own piece
        if (board[fromPos.row][fromPos.column].type == ' ' || board[fromPos.row][fromPos.column].type != playerColor) {
            printf("You can only move your own pieces.\n");
            continue;
        }

        // Make sure player is not moving to an occupied space
        if (board[toPos.row][toPos.column].type != ' ') {
            printf("You cannot move to an occupied space.\n");
            continue;
        }

        // Make sure move is valid
        if (playerColor == RED) {
            if (toPos.row == fromPos.row - 1 && (toPos.column == fromPos.column - 1 || toPos.column == fromPos.column + 1)) {
                board[toPos.row][toPos.column] = board[fromPos.row][fromPos.column];
                board[fromPos.row][fromPos.column] = (Piece) { ' ', 0 };
            } else if (toPos.row == fromPos.row - 2 && (toPos.column == fromPos.column - 2 || toPos.column == fromPos.column + 2)) {
                int capturedPieceRow = (toPos.row + fromPos.row) / 2;
                int capturedPieceColumn = (toPos.column + fromPos.column) / 2;

                if (board[capturedPieceRow][capturedPieceColumn].type == BLACK) {
                    board[toPos.row][toPos.column] = board[fromPos.row][fromPos.column];
                    board[fromPos.row][fromPos.column] = (Piece) { ' ', 0 };
                    board[capturedPieceRow][capturedPieceColumn] = (Piece) { ' ', 0 };
                } else {
                    printf("Invalid move.\n");
                    continue;
                }
            } else {
                printf("Invalid move.\n");
                continue;
            }
        } else if (playerColor == BLACK) {
            if (toPos.row == fromPos.row + 1 && (toPos.column == fromPos.column - 1 || toPos.column == fromPos.column + 1)) {
                board[toPos.row][toPos.column] = board[fromPos.row][fromPos.column];
                board[fromPos.row][fromPos.column] = (Piece) { ' ', 0 };
            } else if (toPos.row == fromPos.row + 2 && (toPos.column == fromPos.column - 2 || toPos.column == fromPos.column + 2)) {
                int capturedPieceRow = (toPos.row + fromPos.row) / 2;
                int capturedPieceColumn = (toPos.column + fromPos.column) / 2;

                if (board[capturedPieceRow][capturedPieceColumn].type == RED) {
                    board[toPos.row][toPos.column] = board[fromPos.row][fromPos.column];
                    board[fromPos.row][fromPos.column] = (Piece) { ' ', 0 };
                    board[capturedPieceRow][capturedPieceColumn] = (Piece) { ' ', 0 };
                } else {
                    printf("Invalid move.\n");
                    continue;
                }
            } else {
                printf("Invalid move.\n");
                continue;
            }
        }

        printBoard();
        turn++; // Switch turns
    }

    return 0;
}