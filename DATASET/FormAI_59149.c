//FormAI DATASET v1.0 Category: Checkers Game ; Style: complete
#include <stdio.h>

int main() {
    // Print welcome message
    printf("Welcome to Checkers Game in C!\n");

    // Initialize variables
    char board[8][8];
    int playerTurn = 1;
    int playerOneScore = 0;
    int playerTwoScore = 0;

    // Populate the board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // Check if we should place a piece
            if (i < 3 && (i+j)%2 == 0) {
                board[i][j] = 'O';
            } else if (i > 4 && (i+j)%2 == 0) {
                board[i][j] = 'X';
            } else {
                board[i][j] = ' ';
            }
        }
    }

    // Start the game loop
    while (1) {
        // Print the board
        printf("  1 2 3 4 5 6 7 8\n");
        for (int i = 0; i < 8; i++) {
            printf("%d ", i+1);
            for (int j = 0; j < 8; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        // Print the current scores
        printf("Player One Score: %d\n", playerOneScore);
        printf("Player Two Score: %d\n", playerTwoScore);

        // Get the player's move
        printf("Player %d's turn\n", playerTurn);
        printf("Enter start row: ");
        int startRow;
        scanf("%d", &startRow);
        printf("Enter start column: ");
        int startCol;
        scanf("%d", &startCol);
        printf("Enter end row: ");
        int endRow;
        scanf("%d", &endRow);
        printf("Enter end column: ");
        int endCol;
        scanf("%d", &endCol);

        // Check if the move is valid
        if (board[startRow-1][startCol-1] == 'O' && playerTurn == 1) {
            // Check if the move is a jump
            if ((startRow-endRow == 2 || startRow-endRow == -2) &&
                (startCol-endCol == 2 || startCol-endCol == -2) &&
                board[(startRow+endRow)/2-1][(startCol+endCol)/2-1] == 'X' &&
                board[endRow-1][endCol-1] == ' ') {
                board[endRow-1][endCol-1] = 'O';
                board[startRow-1][startCol-1] = ' ';
                board[(startRow+endRow)/2-1][(startCol+endCol)/2-1] = ' ';
                playerOneScore++;
            // Otherwise, check if the move is a regular move
            } else if ((startRow-endRow == 1 && abs(startCol-endCol) == 1) &&
                       board[endRow-1][endCol-1] == ' ') {
                board[endRow-1][endCol-1] = 'O';
                board[startRow-1][startCol-1] = ' ';
            } else {
                printf("Invalid Move\n");
            }
        } else if (board[startRow-1][startCol-1] == 'X' && playerTurn == 2) {
            if ((startRow-endRow == 2 || startRow-endRow == -2) &&
                (startCol-endCol == 2 || startCol-endCol == -2) &&
                board[(startRow+endRow)/2-1][(startCol+endCol)/2-1] == 'O' &&
                board[endRow-1][endCol-1] == ' ') {
                board[endRow-1][endCol-1] = 'X';
                board[startRow-1][startCol-1] = ' ';
                board[(startRow+endRow)/2-1][(startCol+endCol)/2-1] = ' ';
                playerTwoScore++;
            } else if ((endRow-startRow == 1 && abs(startCol-endCol) == 1) &&
                       board[endRow-1][endCol-1] == ' ') {
                board[endRow-1][endCol-1] = 'X';
                board[startRow-1][startCol-1] = ' ';
            } else {
                printf("Invalid Move\n");
            }
        } else {
            printf("Invalid Move\n");
        }

        // Check for game over
        if (playerOneScore == 12) {
            printf("Player One Wins!\n");
            break;
        } else if (playerTwoScore == 12) {
            printf("Player Two Wins!\n");
            break;
        }

        // Switch to the other player's turn
        playerTurn = (playerTurn == 1) ? 2 : 1;
    }

    return 0;
}