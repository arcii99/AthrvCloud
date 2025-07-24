//FormAI DATASET v1.0 Category: Checkers Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constant for board size
#define SIZE 8

// Function to print the board
void printBoard(char **board) {
    // Print column numbers
    printf("  ");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    // Print rows with pieces
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for(int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a move is valid
bool isValidMove(char **board, int startRow, int startCol, int endRow, int endCol, char piece) {
    // Check if piece is trying to move to same spot
    if(startRow == endRow && startCol == endCol) {
        return false;
    }

    // Check if end spot is out of bounds
    if(endRow < 0 || endRow >= SIZE || endCol < 0 || endCol >= SIZE) {
        return false;
    }

    // Check if end spot is occupied by opposing piece
    if(board[endRow][endCol] != '-' && board[endRow][endCol] != piece) {
        return false;
    }

    // Check if move is diagonal
    if(abs(endRow - startRow) != abs(endCol - startCol)) {
        return false;
    }

    // Check if piece is moving too far
    if(abs(endRow - startRow) > 2) {
        return false;
    }

    // Check if piece is not moving in correct direction
    if(piece == 'x' && endRow <= startRow) {
        return false;
    }
    if(piece == 'o' && endRow >= startRow) {
        return false;
    }

    // Check if piece is jumping over another piece
    if(abs(endRow - startRow) == 2) {
        int jumpRow = (endRow + startRow) / 2;
        int jumpCol = (endCol + startCol) / 2;

        if(board[jumpRow][jumpCol] == '-' || board[jumpRow][jumpCol] == piece) {
            return false;
        }
    }

    // If all checks passed, move is valid
    return true;
}

// Function to make a move
bool makeMove(char **board, int startRow, int startCol, int endRow, int endCol, char piece) {
    // Check if move is valid
    if(!isValidMove(board, startRow, startCol, endRow, endCol, piece)) {
        return false;
    }

    // Make move
    board[endRow][endCol] = piece;
    board[startRow][startCol] = '-';

    // If piece jumped over another piece, remove it
    if(abs(endRow - startRow) == 2) {
        int jumpRow = (endRow + startRow) / 2;
        int jumpCol = (endCol + startCol) / 2;

        board[jumpRow][jumpCol] = '-';
    }

    return true;
}

int main() {
    // Initialize board
    char **board = (char**) malloc(SIZE * sizeof(char*));
    for(int i = 0; i < SIZE; i++) {
        board[i] = (char*) malloc(SIZE * sizeof(char));
        for(int j = 0; j < SIZE; j++) {
            if(i <= 2 && (i + j) % 2 == 0) {
                board[i][j] = 'x';
            } else if(i >= SIZE - 3 && (i + j) % 2 == 0) {
                board[i][j] = 'o';
            } else {
                board[i][j] = '-';
            }
        }
    }

    // Print opening message and board
    printf("Welcome to Checkers!\n");
    printBoard(board);

    // Loop for game
    char turn = 'x';
    while(true) {
        // Get move from player
        int startRow, startCol, endRow, endCol;
        while(true) {
            printf("%c's turn:\n", turn);
            printf("Enter starting row and column: ");
            scanf("%d %d", &startRow, &startCol);
            printf("Enter ending row and column: ");
            scanf("%d %d", &endRow, &endCol);

            if(isValidMove(board, startRow - 1, startCol - 1, endRow - 1, endCol - 1, turn)) {
                break;
            } else {
                printf("Invalid move. Try again.\n");
            }
        }

        // Make move
        makeMove(board, startRow - 1, startCol - 1, endRow - 1, endCol - 1, turn);

        // Print updated board
        printBoard(board);

        // Check for winner
        int countX = 0;
        int countO = 0;
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                if(board[i][j] == 'x') {
                    countX++;
                } else if(board[i][j] == 'o') {
                    countO++;
                }
            }
        }
        if(countX == 0) {
            printf("Game over! %c wins!\n", 'o');
            break;
        } else if(countO == 0) {
            printf("Game over! %c wins!\n", 'x');
            break;
        }

        // Switch turn to other player
        if(turn == 'x') {
            turn = 'o';
        } else {
            turn = 'x';
        }
    }

    return 0;
}