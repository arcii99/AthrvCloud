//FormAI DATASET v1.0 Category: Checkers Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Structure to represent a checker piece
typedef struct Piece {
    int player;
    int isKing;
} Piece;

// Function to initialize the board with starting pieces
void initBoard(Piece board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i < 3 && (i+j) % 2 == 0) {
                board[i][j].player = 1;
                board[i][j].isKing = 0;
            }
            else if (i > 4 && (i+j) % 2 == 0) {
                board[i][j].player = 2;
                board[i][j].isKing = 0;
            }
            else {
                board[i][j].player = 0;
                board[i][j].isKing = 0;
            }
        }
    }
}

// Function to print the current state of the board
void printBoard(Piece board[][BOARD_SIZE]) {
    printf("   0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d  ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch(board[i][j].player) {
                case 0:
                    printf(". ");
                    break;
                case 1:
                    if (board[i][j].isKing) {
                        printf("R ");
                    }
                    else {
                        printf("r ");
                    }
                    break;
                case 2:
                    if (board[i][j].isKing) {
                        printf("B ");
                    }
                    else {
                        printf("b ");
                    }
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a move is valid
int isValidMove(Piece board[][BOARD_SIZE], int row, int col, int newRow, int newCol, int player) {
    Piece piece = board[row][col];
    int direction = (player == 1) ? -1 : 1;
    int rowDiff = direction * (newRow - row);
    int colDiff = abs(newCol - col);
    if (newRow < 0 || newRow >= BOARD_SIZE || newCol < 0 || newCol >= BOARD_SIZE) {
        return 0;
    }
    if (board[newRow][newCol].player != 0) {
        return 0;
    }
    if (rowDiff == 1 && colDiff == 1) {
        // Regular move
        return 1;
    }
    else if (rowDiff == 2 && colDiff == 2) {
        // Capturing move
        Piece capturedPiece = board[row+direction][col+(newCol-col)/2];
        if (capturedPiece.player != 0 && capturedPiece.player != player) {
            return 1;
        }
    }
    return 0;
}

// Function to make a move
void makeMove(Piece board[][BOARD_SIZE], int row, int col, int newRow, int newCol) {
    Piece piece = board[row][col];
    if (abs(newRow - row) == 2) {
        // Update score if capturing move
        int direction = (piece.player == 1) ? -1 : 1;
        board[row+direction][col+(newCol-col)/2].player = 0;
    }
    board[newRow][newCol] = piece;
    board[row][col].player = 0;
    // Make piece a king if at end of board
    if ((piece.player == 1 && newRow == 0) || (piece.player == 2 && newRow == BOARD_SIZE-1)) {
        board[newRow][newCol].isKing = 1;
    }
}

int main() {
    Piece board[BOARD_SIZE][BOARD_SIZE];
    initBoard(board);
    int currentPlayer = 1;
    int player1Score = 0, player2Score = 0;
    int isGameOver = 0;

    printf("Welcome to Checkers!\n\n");

    while (!isGameOver) {
        // Print the current state of the board
        printBoard(board);

        // Get player's move
        int fromRow, fromCol, toRow, toCol;
        printf("Player %d's move (row col newRow newCol): ", currentPlayer);
        scanf("%d %d %d %d", &fromRow, &fromCol, &toRow, &toCol);

        // Check if move is valid
        if (!isValidMove(board, fromRow, fromCol, toRow, toCol, currentPlayer)) {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Make the move
        makeMove(board, fromRow, fromCol, toRow, toCol);

        // Check if a player has won
        player1Score = 0; player2Score = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j].player == 1) {
                    player1Score++;
                }
                else if (board[i][j].player == 2) {
                    player2Score++;
                }
            }
        }
        if (player1Score == 0) {
            printf("Player 2 wins!\n");
            isGameOver = 1;
        }
        else if (player2Score == 0) {
            printf("Player 1 wins!\n");
            isGameOver = 1;
        }

        // Switch to next player
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}