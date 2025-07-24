//FormAI DATASET v1.0 Category: Checkers Game ; Style: systematic
#include <stdio.h>

// Function to print the board
void printBoard(char board[8][8]) {
    printf("\n  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < 8; i++) {
        printf("%d", i);
        for (int j = 0; j < 8; j++) {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}

// Function to initialize the board with pieces
void initBoard(char board[8][8]) {
    // Initialize black pieces
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = 'B';
            } else {
                board[i][j] = ' ';
            }
        }
    }

    // Initialize white pieces
    for (int i = 5; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = 'W';
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

// Function to move a piece
void movePiece(char board[8][8], int startY, int startX, int endY, int endX) {
    if (board[endY][endX] != ' ') { // Can't move to an occupied square
        printf("Invalid move!\n");
    } else {
        board[endY][endX] = board[startY][startX]; // Move piece
        board[startY][startX] = ' '; // Remove piece from original square
    }
}

int main() {
    char board[8][8];
    initBoard(board);
    printBoard(board);

    movePiece(board, 2, 1, 3, 2);
    printBoard(board);

    movePiece(board, 5, 2, 4, 3);
    printBoard(board);

    return 0;
}