//FormAI DATASET v1.0 Category: Checkers Game ; Style: ultraprecise
#include <stdio.h>

int main(void) {

    // Define the board and set all spaces to empty
    char board[8][8];
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            board[row][col] = '-';
        }
    }

    // Set the starting positions for the red and black pieces
    // Red pieces
    board[0][1] = 'r';
    board[0][3] = 'r';
    board[0][5] = 'r';
    board[0][7] = 'r';
    board[1][0] = 'r';
    board[1][2] = 'r';
    board[1][4] = 'r';
    board[1][6] = 'r';
    board[2][1] = 'r';
    board[2][3] = 'r';
    board[2][5] = 'r';
    board[2][7] = 'r';

    // Black pieces
    board[5][0] = 'b';
    board[5][2] = 'b';
    board[5][4] = 'b';
    board[5][6] = 'b';
    board[6][1] = 'b';
    board[6][3] = 'b';
    board[6][5] = 'b';
    board[6][7] = 'b';
    board[7][0] = 'b';
    board[7][2] = 'b';
    board[7][4] = 'b';
    board[7][6] = 'b';

    // Print the starting board
    printf("Current Board:\n");
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }

    // Main game loop
    int turn = 0; // 0 for red, 1 for black
    int exit = 0; // Set to 1 when a player wins or quits
    int numBlackPieces = 12;
    int numRedPieces = 12;
    while (exit == 0) {

        // Determine which player's turn it is
        char currentPlayer;
        if (turn == 0) {
            currentPlayer = 'r';
        }
        else {
            currentPlayer = 'b';
        }

        // Get the move from the player
        int startRow, startCol, endRow, endCol;
        printf("%c's turn: Enter the row and column of the piece you want to move, then the row and column of where you want to move it.\n", currentPlayer);
        scanf("%d %d %d %d", &startRow, &startCol, &endRow, &endCol);

        // Check if the move is valid and make the move if it is
        if (board[startRow][startCol] == currentPlayer && board[endRow][endCol] == '-') {

            if (currentPlayer == 'r') {
                if (startRow - endRow == 1 && abs(startCol - endCol) == 1) {
                    board[startRow][startCol] = '-';
                    board[endRow][endCol] = 'r';
                }
                else if (startRow - endRow == 2 && abs(startCol - endCol) == 2) {
                    int jumpedRow = startRow - 1;
                    int jumpedCol = (startCol + endCol) / 2;
                    if (board[jumpedRow][jumpedCol] == 'b') {
                        board[startRow][startCol] = '-';
                        board[jumpedRow][jumpedCol] = '-';
                        board[endRow][endCol] = 'r';
                        numBlackPieces--;
                    }
                    else {
                        printf("Invalid move: you can only jump over your opponent's piece.\n");
                    }
                }
                else {
                    printf("Invalid move: you can only move one space diagonally or jump over your opponent's piece.\n");
                }
            }
            else { // Current player is black
                if (endRow - startRow == 1 && abs(startCol - endCol) == 1) {
                    board[startRow][startCol] = '-';
                    board[endRow][endCol] = 'b';
                }
                else if (endRow - startRow == 2 && abs(startCol - endCol) == 2) {
                    int jumpedRow = startRow + 1;
                    int jumpedCol = (startCol + endCol) / 2;
                    if (board[jumpedRow][jumpedCol] == 'r') {
                        board[startRow][startCol] = '-';
                        board[jumpedRow][jumpedCol] = '-';
                        board[endRow][endCol] = 'b';
                        numRedPieces--;
                    }
                    else {
                        printf("Invalid move: you can only jump over your opponent's piece.\n");
                    }
                }
                else {
                    printf("Invalid move: you can only move one space diagonally or jump over your opponent's piece.\n");
                }
            }

            // Check if the current player has won
            if (numRedPieces == 0) {
                printf("Black wins!\n");
                exit = 1;
            }
            else if (numBlackPieces == 0) {
                printf("Red wins!\n");
                exit = 1;
            }

            // Print the updated board
            printf("\nCurrent Board:\n");
            for (int row = 0; row < 8; row++) {
                for (int col = 0; col < 8; col++) {
                    printf("%c ", board[row][col]);
                }
                printf("\n");
            }

            // Switch to the other player's turn
            turn = 1 - turn;

        }
        else {
            printf("Invalid move: you can only move your own piece to an empty space.\n");
        }
    }

    return 0;
}