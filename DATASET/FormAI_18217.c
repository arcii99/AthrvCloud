//FormAI DATASET v1.0 Category: Checkers Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Constants representing the colors of checkers pieces
#define BLACK 'B'
#define WHITE 'W'

// Constants representing the size of the board
#define ROWS 8
#define COLS 8

// Function to initialize the board with checkers pieces
void initializeBoard(char board[ROWS][COLS]) {
    int i, j;
    // Fill the first three rows with black pieces
    for (i = 0; i < 3; i++) {
        for (j = 0; j < COLS; j++) {
            if ((i+j) % 2 == 1) {
                board[i][j] = BLACK;
            } else {
                board[i][j] = ' ';
            }
        }
    }
    // Fill the last three rows with white pieces
    for (i = ROWS-1; i >= ROWS-3; i--) {
        for (j = 0; j < COLS; j++) {
            if ((i+j) % 2 == 1) {
                board[i][j] = WHITE;
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

// Function to print the board with row and column labels
void printBoard(char board[ROWS][COLS]) {
    int i, j;
    printf("  ");
    for (i = 1; i <= ROWS; i++) {
        printf(" %d", i);
    }
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        printf("%c ", 'A' + i);
        for (j = 0; j < COLS; j++) {
            printf("|%c", board[i][j]);
        }
        printf("| %c\n", 'A' + i);
    }
    printf("  ");
    for (i = 1; i <= ROWS; i++) {
        printf(" %d", i);
    }
    printf("\n");
}

// Function to check if a move is valid for a given color
int isValidMove(char board[ROWS][COLS], int fromRow, int fromCol, int toRow, int toCol, char color) {
    char opponentColor;
    if (color == BLACK) {
        opponentColor = WHITE;
    } else {
        opponentColor = BLACK;
    }
    // Check that the move is within the board bounds
    if (toRow < 0 || toRow >= ROWS || toCol < 0 || toCol >= COLS) {
        return 0;
    }
    // Check that the end position is empty
    if (board[toRow][toCol] != ' ') {
        return 0;
    }
    // Check that the start position contains a checker of the correct color
    if (board[fromRow][fromCol] != color && board[fromRow][fromCol] != color+32) {
        return 0;
    }
    // Check that the move is diagonal (can only move forwards or backwards one row and one column at a time)
    if (abs(toRow - fromRow) != 1 || abs(toCol - fromCol) != 1) {
        return 0;
    }
    // Check that regular checkers only move forward
    if (board[fromRow][fromCol] == color && toRow <= fromRow) {
        return 0;
    }
    // Check that the move captures an opponent checker if possible
    if (abs(toRow - fromRow) == 2 && abs(toCol - fromCol) == 2) {
        int capturedRow = (fromRow + toRow) / 2;
        int capturedCol = (fromCol + toCol) / 2;
        if (board[capturedRow][capturedCol] != opponentColor && board[capturedRow][capturedCol] != opponentColor+32) {
            return 0;
        }
        return 2;
    }
    return 1;
}

// Function to make a move for a given color
int makeMove(char board[ROWS][COLS], int fromRow, int fromCol, int toRow, int toCol, char color) {
    int valid = isValidMove(board, fromRow, fromCol, toRow, toCol, color);
    if (valid == 0) {
        printf("Invalid move\n");
    } else {
        board[fromRow][fromCol] = ' ';
        board[toRow][toCol] = color;
        if (valid == 2) { // Capture move
            int capturedRow = (fromRow + toRow) / 2;
            int capturedCol = (fromCol + toCol) / 2;
            board[capturedRow][capturedCol] = ' ';
        }
        return 1;
    }
    return 0;
}

// Function to check if the game is over (if one player has no more pieces)
char checkGameOver(char board[ROWS][COLS]) {
    int i, j;
    int blackPieces = 0;
    int whitePieces = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == BLACK || board[i][j] == BLACK+32) {
                blackPieces++;
            } else if (board[i][j] == WHITE || board[i][j] == WHITE+32) {
                whitePieces++;
            }
        }
    }
    if (blackPieces == 0) {
        return WHITE;
    } else if (whitePieces == 0) {
        return BLACK;
    } else {
        return ' ';
    }
}

// Main function to play the game
int main() {
    char board[ROWS][COLS];
    initializeBoard(board);
    char currentPlayer = BLACK;
    while (1) {
        printBoard(board);
        printf("%c's turn\n", currentPlayer);
        char fromInput[3];
        char toInput[3];
        printf("Enter the checker you want to move (e.g. A3): ");
        scanf("%s", fromInput);
        printf("Enter the position you want to move it to (e.g. B4): ");
        scanf("%s", toInput);
        int fromRow = fromInput[0] - 'A';
        int fromCol = fromInput[1] - '1';
        int toRow = toInput[0] - 'A';
        int toCol = toInput[1] - '1';
        if (makeMove(board, fromRow, fromCol, toRow, toCol, currentPlayer)) {
            char winner = checkGameOver(board);
            if (winner != ' ') {
                printf("%c wins!\n", winner);
                return 0;
            }
            if (currentPlayer == BLACK) {
                currentPlayer = WHITE;
            } else {
                currentPlayer = BLACK;
            }
        }
    }
    return 0;
}