//FormAI DATASET v1.0 Category: Table Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialization
    int boardSize = 10;
    char board[boardSize][boardSize];
    int numOfPlayers = 2;
    char players[numOfPlayers];
    int playerTurn = 0;
    int row, col;

    // Set up players
    players[0] = 'X';
    players[1] = 'O';

    // Fill board with empty spaces
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            board[i][j] = ' ';
        }
    }

    // Play game
    while (1) {
        // Print board
        printf("  ");
        for (int i = 0; i < boardSize; i++) {
            printf("%d ", i);
        }
        printf("\n");
        for (int i = 0; i < boardSize; i++) {
            // Print row number
            printf("%d ", i);
            for (int j = 0; j < boardSize; j++) {
                printf("%c|", board[i][j]);
            }
            printf("\n");
            // Print separator
            printf("  ");
            for (int j = 0; j < boardSize; j++) {
                printf("-+");
            }
            printf("\n");
        }

        // Get user input for row and column
        printf("Player %c, enter a row: ", players[playerTurn]);
        scanf("%d", &row);
        printf("Player %c, enter a column: ", players[playerTurn]);
        scanf("%d", &col);

        // Check if input is valid and space is empty
        if (row >= 0 && row < boardSize && col >= 0 && col < boardSize && board[row][col] == ' ') {
            board[row][col] = players[playerTurn];
            // Check if player wins
            int win = 1;
            for (int i = 0; i < boardSize; i++) {
                if (board[row][i] != players[playerTurn]) {
                    win = 0;
                    break;
                }
            }
            if (win) {
                printf("Player %c wins!\n", players[playerTurn]);
                break;
            }
            win = 1;
            for (int i = 0; i < boardSize; i++) {
                if (board[i][col] != players[playerTurn]) {
                    win = 0;
                    break;
                }
            }
            if (win) {
                printf("Player %c wins!\n", players[playerTurn]);
                break;
            }
            if (row == col) {
                win = 1;
                for (int i = 0; i < boardSize; i++) {
                    if (board[i][i] != players[playerTurn]) {
                        win = 0;
                        break;
                    }
                }
                if (win) {
                    printf("Player %c wins!\n", players[playerTurn]);
                    break;
                }
            }
            if (row + col == boardSize - 1) {
                win = 1;
                for (int i = 0; i < boardSize; i++) {
                    if (board[i][boardSize - 1 - i] != players[playerTurn]) {
                        win = 0;
                        break;
                    }
                }
                if (win) {
                    printf("Player %c wins!\n", players[playerTurn]);
                    break;
                }
            }
            // Check if board is full
            int boardFull = 1;
            for (int i = 0; i < boardSize; i++) {
                for (int j = 0; j < boardSize; j++) {
                    if (board[i][j] == ' ') {
                        boardFull = 0;
                        break;
                    }
                }
                if (!boardFull) {
                    break;
                }
            }
            if (boardFull) {
                printf("Board is full! Game ends in a draw.\n");
                break;
            }
            // Switch players
            playerTurn = (playerTurn + 1) % numOfPlayers;
        } else {
            printf("Invalid input or space is already taken. Try again.\n");
        }
    }
    
    return 0;
}