//FormAI DATASET v1.0 Category: Table Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define ROWS 6
#define COLUMNS 7

// Function Prototypes
void displayBoard(char board[][COLUMNS]);
int dropPiece(char board[][COLUMNS], int col, char symbol);
int checkWinner(char board[][COLUMNS], char symbol);

// Main function
int main() {
    char board[ROWS][COLUMNS];
    char player1Symbol = 'X';
    char player2Symbol = 'O';
    int currentPlayer = 1;
    int colSelection = 0;
    int gameStatus = 0;
    int moveCount = 0;

    // Initialize the board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = '-';
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    printf("Welcome to Connect Four!\n\n");
    printf("Player 1 (X) will go first.\n");
    printf("Player 2 (O) will go second.\n\n");

    // Game loop
    while (1) {
        // Display the board
        displayBoard(board);

        // Get column selection from current player
        if (currentPlayer == 1) {
            printf("Player 1, please select a column (1-7): ");
            scanf("%d", &colSelection);
        }
        else {
            // AI player randomly selects a column
            printf("Player 2 is thinking...\n");
            colSelection = rand() % 7 + 1;
            printf("Player 2 selected column %d.\n", colSelection);
        }

        // Validate column selection
        if (colSelection < 1 || colSelection > 7) {
            printf("Invalid column selection.\n");
            continue;
        }

        // Drop the piece into the board
        int row = dropPiece(board, colSelection - 1, currentPlayer == 1 ? player1Symbol : player2Symbol);
        if (row == -1) {
            printf("Column is full. Please select another column.\n");
            continue;
        }

        // Check for winner
        gameStatus = checkWinner(board, currentPlayer == 1 ? player1Symbol : player2Symbol);
        if (gameStatus == 1) {
            displayBoard(board);
            printf("Player %d (%c) wins!\n", currentPlayer, currentPlayer == 1 ? player1Symbol : player2Symbol);
            break;
        }
        else if (gameStatus == 2) {
            displayBoard(board);
            printf("Game ended in a tie.\n");
            break;
        }

        // Switch to other player
        currentPlayer = currentPlayer == 1 ? 2 : 1;
    }

    return 0;
}

// Displays the game board
void displayBoard(char board[][COLUMNS]) {
    printf(" 1 2 3 4 5 6 7\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Drops a piece into the board
int dropPiece(char board[][COLUMNS], int col, char symbol) {
    for (int row = ROWS - 1; row >= 0; row--) {
        if (board[row][col] == '-') {
            board[row][col] = symbol;
            return row;
        }
    }
    return -1;
}

// Checks for a winner
int checkWinner(char board[][COLUMNS], char symbol) {
    // Check horizontal
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= COLUMNS - 4; j++) {
            if (board[i][j] == symbol && board[i][j+1] == symbol && board[i][j+2] == symbol && board[i][j+3] == symbol) {
                return 1;
            }
        }
    }

    // Check vertical
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] == symbol && board[i+1][j] == symbol && board[i+2][j] == symbol && board[i+3][j] == symbol) {
                return 1;
            }
        }
    }

    // Check diagonal (top left to bottom right)
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = 0; j <= COLUMNS - 4; j++) {
            if (board[i][j] == symbol && board[i+1][j+1] == symbol && board[i+2][j+2] == symbol && board[i+3][j+3] == symbol) {
                return 1;
            }
        }
    }

    // Check diagonal (bottom left to top right)
    for (int i = ROWS - 1; i >= 3; i--) {
        for (int j = 0; j <= COLUMNS - 4; j++) {
            if (board[i][j] == symbol && board[i-1][j+1] == symbol && board[i-2][j+2] == symbol && board[i-3][j+3] == symbol) {
                return 1;
            }
        }
    }

    // Check for tie
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] != '-') {
                count++;
            }
        }
    }
    if (count == ROWS * COLUMNS) {
        return 2;
    }

    return 0;
}