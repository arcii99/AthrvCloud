//FormAI DATASET v1.0 Category: Checkers Game ; Style: systematic
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 8

// Constants representing the player's pieces on the board
#define EMPTY 0
#define RED 1
#define BLACK 2

// Function declarations
void initializeBoard(int board[][BOARD_SIZE]);
void printBoard(int board[][BOARD_SIZE]);
bool isValidMove(int board[][BOARD_SIZE], int piece, int startX, int startY, int endX, int endY);
void movePiece(int board[][BOARD_SIZE], int startX, int startY, int endX, int endY);
bool isGameFinished(int board[][BOARD_SIZE]);

int main() {
    // Initialize the board and print it
    int board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);
    printf("\nWelcome to Checkers!\n\nInitial Board:\n");
    printBoard(board);

    // Turn-based gameplay loop
    int turn = RED;
    while (!isGameFinished(board)) {
        // Prompt the user for their turn
        printf("\n%s player's turn:\n", turn == RED ? "RED" : "BLACK");
        int startX, startY, endX, endY;
        printf("Enter the starting coordinates of the piece to move (ex: 3 4): ");
        scanf("%d %d", &startX, &startY);
        printf("Enter the ending coordinates of the move (ex: 2 5): ");
        scanf("%d %d", &endX, &endY);

        // If the move is invalid, prompt the user to retry
        if (!isValidMove(board, turn, startX, startY, endX, endY)) {
            printf("\nInvalid move. Please try again.\n");
            continue;
        }

        // Move the piece and print the updated board
        movePiece(board, startX, startY, endX, endY);
        printf("\nUpdated Board:\n");
        printBoard(board);

        // Swap turns
        turn = turn == RED ? BLACK : RED;
    }

    // Game is finished: announce the winner
    int redCount = 0;
    int blackCount = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == RED) {
                redCount++;
            } else if (board[i][j] == BLACK) {
                blackCount++;
            }
        }
    }
    printf("\n\nGame Over! Final Board:\n");
    printBoard(board);
    if (redCount > blackCount) {
        printf("Red wins!\n");
    } else if (blackCount > redCount) {
        printf("Black wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}

/**
 * Initialize the board with the starting setup of pieces.
 */
void initializeBoard(int board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i < 3 && (i + j) % 2 == 0) {
                board[i][j] = BLACK;
            } else if (i > 4 && (i + j) % 2 == 0) {
                board[i][j] = RED;
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

/**
 * Print the current state of the board.
 */
void printBoard(int board[][BOARD_SIZE]) {
    printf("\n  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == RED) {
                printf("R ");
            } else if (board[i][j] == BLACK) {
                printf("B ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

/**
 * Determine whether the move from the starting position to the ending position is valid.
 */
bool isValidMove(int board[][BOARD_SIZE], int piece, int startX, int startY, int endX, int endY) {
    // Make sure the piece is moving diagonally and staying on the board
    if (startX < 0 || startX >= BOARD_SIZE || startY < 0 || startY >= BOARD_SIZE ||
        endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE ||
        ((startX - endX) % 2 != 0) || ((startY - endY) % 2 != 0)) {
        return false;
    }

    // Make sure there's actually a piece at the starting position
    if (board[startX][startY] != piece) {
        return false;
    }

    // Red pieces can only move downwards and black pieces can only move upwards
    if ((piece == RED && endX >= startX) || (piece == BLACK && endX <= startX)) {
        return false;
    }

    // Regular pieces can only move one space diagonally
    if (board[startX][startY] == RED || board[startX][startY] == BLACK) {
        if (((piece == RED || piece == BLACK) && abs(startX - endX) == 1 && abs(startY - endY) == 1) &&
           board[endX][endY] == EMPTY) {
            return true;
        }
    }
    return false;
}

/**
 * Move the piece from the starting position to the ending position.
 */
void movePiece(int board[][BOARD_SIZE], int startX, int startY, int endX, int endY) {
    board[endX][endY] = board[startX][startY];
    board[startX][startY] = EMPTY;
}

/**
 * Determine whether the game is finished (i.e. one player has no pieces left).
 */
bool isGameFinished(int board[][BOARD_SIZE]) {
    bool redFound = false;
    bool blackFound = false;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == RED) {
                redFound = true;
            } else if (board[i][j] == BLACK) {
                blackFound = true;
            }
        }
    }
    return !redFound || !blackFound;
}