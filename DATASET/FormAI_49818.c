//FormAI DATASET v1.0 Category: Checkers Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Struct for the checker pieces
typedef struct {
    int row;
    int col;
    char icon;
    int player; // 1 for player 1 and 2 for player 2
} Checker;

// Function to display the board
void displayBoard(char board[8][8]) {
    printf("   0  1  2  3  4  5  6  7\n");
    for (int row = 0; row < 8; row++) {
        printf("%d ", row);
        for (int col = 0; col < 8; col++) {
            printf("|%c ", board[row][col]);
        }
        printf("|\n");
    }
}

// Function to initialize the board with spaces and place the checker pieces in their starting positions
void initializeBoard(char board[8][8], Checker pieces[24]) {
    int pieceIndex = 0;
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if ((row % 2) == (col % 2)) {
                board[row][col] = ' ';
            } else {
                if (row < 3) {
                    board[row][col] = 'O';
                    pieces[pieceIndex++] = (Checker){row, col, 'O', 1};
                } else if (row > 4) {
                    board[row][col] = 'X';
                    pieces[pieceIndex++] = (Checker){row, col, 'X', 2};
                } else {
                    board[row][col] = ' ';
                }
            }
        }
    }
}

// Function to move a checker piece
void movePiece(char board[8][8], Checker* piece, int newRow, int newCol) {
    board[piece->row][piece->col] = ' ';
    board[newRow][newCol] = piece->icon;
    piece->row = newRow;
    piece->col = newCol;
}

int main() {
    char board[8][8];
    Checker pieces[24];

    // Initialize the board and the pieces
    initializeBoard(board, pieces);

    // Play the game loop
    int playerTurn = 1;
    int gameOver = 0;
    while (!gameOver) {
        displayBoard(board);

        // Get user input for which piece to move
        int chosenPieceIndex;
        while (1) {
            printf("Player %d's turn. Choose a piece to move (0-23): ", playerTurn);
            scanf("%d", &chosenPieceIndex);
            if (chosenPieceIndex < 0 || chosenPieceIndex > 23) {
                printf("Invalid input. Please enter a number between 0 and 23.\n");
            } else if (pieces[chosenPieceIndex].player != playerTurn) {
                printf("Invalid input. Please choose a piece that belongs to you.\n");
            } else {
                break;
            }
        }

        // Get user input for where to move the piece
        int newRow, newCol;
        while (1) {
            printf("Enter the row and column to move the piece to: ");
            scanf("%d %d", &newRow, &newCol);
            if (newRow < 0 || newRow > 7 || newCol < 0 || newCol > 7) {
                printf("Invalid input. Please enter a row and column between 0 and 7.\n");
            } else {
                break;
            }
        }

        // Move the piece
        movePiece(board, &pieces[chosenPieceIndex], newRow, newCol);

        // Switch the player's turn
        if (playerTurn == 1) {
            playerTurn = 2;
        } else {
            playerTurn = 1;
        }
    }

    return 0;
}