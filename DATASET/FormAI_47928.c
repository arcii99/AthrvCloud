//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

char board[SIZE][SIZE];

char playerSymbol = 'X';  // The symbol used by the current player
char AISymbol = 'O';  // The symbol used by the AI

// Helper function to print the board
void printBoard() {
    printf("   1   2   3\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i+1);
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("  ---+---+---\n");
        }
    }
    printf("\n");
}

// Check if a symbol has won
int checkWin(char symbol) {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        int j;
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] != symbol) break;
        }
        if (j == SIZE) return 1;
    }

    // Check columns
    for (int i = 0; i < SIZE; i++) {
        int j;
        for (j = 0; j < SIZE; j++) {
            if (board[j][i] != symbol) break;
        }
        if (j == SIZE) return 1;
    }

    // Check diagonal
    int j;
    for (j = 0; j < SIZE; j++) {
        if (board[j][j] != symbol) break;
    }
    if (j == SIZE) return 1;

    // Check anti-diagonal
    for (j = 0; j < SIZE; j++) {
        if (board[j][SIZE-j-1] != symbol) break;
    }
    if (j == SIZE) return 1;

    return 0;  // No win
}

// Check if the game is over
int isGameOver() {
    // Check for win
    if (checkWin(playerSymbol)) {
        printf("Congratulations! You win!\n");
        return 1;
    }
    if (checkWin(AISymbol)) {
        printf("Better luck next time! You lose.\n");
        return 1;
    }

    // Check for tie
    int isTie = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                isTie = 0;
                break;
            }
        }
        if (!isTie) break;
    }
    if (isTie) {
        printf("It's a tie!\n");
        return 1;
    }

    return 0;  // Game is not over
}

// Get user input for next move
void getUserInput() {
    int row, col;

    while (1) {
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        printf("Enter column (1-3): ");
        scanf("%d", &col);

        if (row < 1 || row > SIZE || col < 1 || col > SIZE) {
            printf("Invalid input! Try again.\n");
        } else if (board[row-1][col-1] != ' ') {
            printf("That square is already occupied! Try again.\n");
        } else {
            board[row-1][col-1] = playerSymbol;
            break;
        }
    }
}

// Get the best move for the AI
void getAIMove() {
    int bestScore = -10000;
    int bestRow, bestCol;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = AISymbol;
                int score = -minimax(0, 1);
                board[i][j] = ' ';
                if (score > bestScore) {
                    bestScore = score;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }
    
    printf("AI's move: (%d, %d)\n", bestRow+1, bestCol+1);
    board[bestRow][bestCol] = AISymbol;
}

// Minimax algorithm implementation
int minimax(int depth, int isMaximizing) {
    if (checkWin(playerSymbol)) {
        return -10 + depth;
    } else if (checkWin(AISymbol)) {
        return 10 - depth;
    } else if (isGameOver()) {
        return 0;
    }
    
    if (isMaximizing) {
        int bestScore = -10000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = AISymbol;
                    int score = minimax(depth+1, 0);
                    board[i][j] = ' ';
                    if (score > bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 10000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = playerSymbol;
                    int score = minimax(depth+1, 1);
                    board[i][j] = ' ';
                    if (score < bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    } 
}

// Main function
int main() {
    // Initialize the board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    printf("Welcome to Tic Tac Toe!\n");
    printf("You are %c and the AI is %c.\n\n", playerSymbol, AISymbol);

    // Game loop
    while (!isGameOver()) {
        printBoard();
        getUserInput();
        if (!isGameOver()) {
            getAIMove();
        }
    }

    printBoard();

    return 0;
}