//FormAI DATASET v1.0 Category: Chess engine ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the chess board size
#define BOARD_SIZE 8

// Define the player colors
#define WHITE 'W'
#define BLACK 'B'

// Define the pieces
#define EMPTY ' '
#define PAWN 'P'
#define KNIGHT 'N'
#define BISHOP 'B'
#define ROOK 'R'
#define QUEEN 'Q'
#define KING 'K'

char chessBoard[BOARD_SIZE][BOARD_SIZE];

// Initialize the board with the starting position of pieces
void initializeChessBoard() {
    int i, j;
    // Set the pieces for white players
    chessBoard[0][0] = ROOK;
    chessBoard[0][1] = KNIGHT;
    chessBoard[0][2] = BISHOP;
    chessBoard[0][3] = QUEEN;
    chessBoard[0][4] = KING;
    chessBoard[0][5] = BISHOP;
    chessBoard[0][6] = KNIGHT;
    chessBoard[0][7] = ROOK;
    for (i = 0; i < BOARD_SIZE; i++) {
        chessBoard[1][i] = PAWN;
    }
    // Set the pieces for black players
    chessBoard[7][0] = ROOK;
    chessBoard[7][1] = KNIGHT;
    chessBoard[7][2] = BISHOP;
    chessBoard[7][3] = QUEEN;
    chessBoard[7][4] = KING;
    chessBoard[7][5] = BISHOP;
    chessBoard[7][6] = KNIGHT;
    chessBoard[7][7] = ROOK;

    for (i = 0; i < BOARD_SIZE; i++) {
        chessBoard[6][i] = PAWN;
    }
    // Set the empty cells
    for (i = 2; i < 6; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            chessBoard[i][j] = EMPTY;
        }
    }
}

// Print the board in the current state
void printChessBoard() {
    int i, j;
    printf("  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf(" %c ", 'a' + i);
    }
    printf("\n");
    printf(" +");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("---+");
    }
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i + 1);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf(" %c |", chessBoard[i][j]);
        }
        printf("%d", i + 1);
        printf("\n");
        printf(" +");
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("---+");
        }
        printf("\n");
    }
    printf("  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf(" %c ", 'a' + i);
    }
    printf("\n");
}

// Check if the move is valid
bool isValidMove(int startX, int startY, int endX, int endY, char playerColor) {
    // Check if the start position is valid
    if (startX < 0 || startX >= BOARD_SIZE || startY < 0 || startY >= BOARD_SIZE || chessBoard[startX][startY] == EMPTY || chessBoard[startX][startY] == KING || (playerColor == WHITE && islower(chessBoard[startX][startY])) || (playerColor == BLACK && isupper(chessBoard[startX][startY]))) {
        return false;
    }
    // Check if the end position is valid
    if (endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE || (chessBoard[endX][endY] != EMPTY && playerColor == chessBoard[endX][endY]) || (chessBoard[startX][startY] == PAWN && endX != startX + 1 && endX != startX - 1)) {
        return false;
    }
    // Check if the move is valid for the piece
    char pieceType = chessBoard[startX][startY];
    if (pieceType == PAWN) {
        if (endY == startY && (endX == startX + 1 || endX == startX - 1)) {
            if (playerColor == WHITE && endX == startX + 1) {
                return true;
            }
            else if (playerColor == BLACK && endX == startX - 1) {
                return true;
            }
        }
        else if (endY == startY && chessBoard[endX][endY] == EMPTY) {
            if (playerColor == WHITE && endX == startX + 1) {
                return true;
            }
            else if (playerColor == BLACK && endX == startX - 1) {
                return true;
            }
        }
        else if (endX == startX + 1 || endX == startX - 1) {
            if (playerColor == WHITE && islower(chessBoard[endX][endY])) {
                return true;
            }
            else if (playerColor == BLACK && isupper(chessBoard[endX][endY])) {
                return true;
            }
        }
    }
    else if (pieceType == KNIGHT) {
        if ((endX == startX + 2 || endX == startX - 2) && (endY == startY + 1 || endY == startY - 1)) {
            if ((playerColor == WHITE && islower(chessBoard[endX][endY])) || (playerColor == BLACK && isupper(chessBoard[endX][endY]))) {
                return true;
            }
        }
        else if ((endX == startX + 1 || endX == startX - 1) && (endY == startY + 2 || endY == startY - 2)) {
            if ((playerColor == WHITE && islower(chessBoard[endX][endY])) || (playerColor == BLACK && isupper(chessBoard[endX][endY]))) {
                return true;
            }
        }
    }
    else if (pieceType == BISHOP) {
        int i;
        if (abs(endX - startX) == abs(endY - startY)) {
            int dx = (endX - startX) > 0 ? 1 : -1;
            int dy = (endY - startY) > 0 ? 1 : -1;
            int x = startX + dx;
            int y = startY + dy;
            for (i = 1; i < abs(endX - startX); i++) {
                if (chessBoard[x][y] != EMPTY) {
                    return false;
                }
                x += dx;
                y += dy;
            }
            if ((playerColor == WHITE && islower(chessBoard[endX][endY])) || (playerColor == BLACK && isupper(chessBoard[endX][endY]))) {
                return true;
            }
        }
    }
    else if (pieceType == ROOK) {
        int i;
        if (endX == startX || endY == startY) {
            int dx = (endX - startX) > 0 ? 1 : -1;
            int dy = (endY - startY) > 0 ? 1 : -1;
            int x = startX + dx;
            int y = startY + dy;
            for (i = 1; i < abs(endX - startX); i++) {
                if (chessBoard[x][y] != EMPTY) {
                    return false;
                }
                x += dx;
                y += dy;
            }
            if ((playerColor == WHITE && islower(chessBoard[endX][endY])) || (playerColor == BLACK && isupper(chessBoard[endX][endY]))) {
                return true;
            }
        }
    }
    else if (pieceType == QUEEN) {
        int i;
        if (endX == startX || endY == startY) {
            int dx = (endX - startX) > 0 ? 1 : -1;
            int dy = (endY - startY) > 0 ? 1 : -1;
            int x = startX + dx;
            int y = startY + dy;
            for (i = 1; i < abs(endX - startX); i++) {
                if (chessBoard[x][y] != EMPTY) {
                    return false;
                }
                x += dx;
                y += dy;
            }
            if ((playerColor == WHITE && islower(chessBoard[endX][endY])) || (playerColor == BLACK && isupper(chessBoard[endX][endY]))) {
                return true;
            }
        }
        else if (abs(endX - startX) == abs(endY - startY)) {
            int dx = (endX - startX) > 0 ? 1 : -1;
            int dy = (endY - startY) > 0 ? 1 : -1;
            int x = startX + dx;
            int y = startY + dy;
            for (i = 1; i < abs(endX - startX); i++) {
                if (chessBoard[x][y] != EMPTY) {
                    return false;
                }
                x += dx;
                y += dy;
            }
            if ((playerColor == WHITE && islower(chessBoard[endX][endY])) || (playerColor == BLACK && isupper(chessBoard[endX][endY]))) {
                return true;
            }
        }
    }
    else if (pieceType == KING) {
        if (abs(endX - startX) <= 1 && abs(endY - startY) <= 1) {
            if ((playerColor == WHITE && islower(chessBoard[endX][endY])) || (playerColor == BLACK && isupper(chessBoard[endX][endY]))) {
                return true;
            }
        }
    }
    return false;
}

// Check if the game is over
bool isGameOver(char playerColor) {
    int i, j;
    bool foundKing = false;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (chessBoard[i][j] == KING && ((playerColor == WHITE && isupper(chessBoard[i][j])) || (playerColor == BLACK && islower(chessBoard[i][j])))) {
                foundKing = true;
                break;
            }
        }
    }
    return !foundKing;
}

int main() {
    char currentPlayer = WHITE;
    int startX, startY, endX, endY;
    initializeChessBoard();
    while (!isGameOver(currentPlayer)) {
        printChessBoard();
        printf("It is %c's turn\n", currentPlayer);
        printf("Enter starting position (row column): ");
        scanf("%d %d", &startX, &startY);
        printf("Enter ending position (row column): ");
        scanf("%d %d", &endX, &endY);
        if (isValidMove(startX - 1, startY - 1, endX - 1, endY - 1, currentPlayer)) {
            chessBoard[endX - 1][endY - 1] = chessBoard[startX - 1][startY - 1];
            chessBoard[startX - 1][startY - 1] = EMPTY;
            currentPlayer = currentPlayer == WHITE ? BLACK : WHITE;
        }
        else {
            printf("Invalid move\n");
        }
    }
    printChessBoard();
    printf("%c player has won the game\n", currentPlayer == WHITE ? BLACK : WHITE);
    return 0;
}