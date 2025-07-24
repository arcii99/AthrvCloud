//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Tic Tac Toe Board Array
char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

/**
 * Check if the game is draw.
 * Return true if draw, else false.
 */
bool isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

/**
 * Check if the game is won by either player.
 * Return player character (X or O) if game is won, else return 0.
 */
char isWon() {
    // Check for rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check for columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }

    // Check for diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return 0;
}

/**
 * Evaluate score for each possible game scenario
 * based on current board state using minimax algorithm.
 * Return the score.
 */
int evaluate(char player) {
    char opponent = (player == 'X') ? 'O' : 'X';
    char winner = isWon();
    if (winner == player) {
        return 10;
    } else if (winner == opponent) {
        return -10;
    } else if (isDraw()) {
        return 0;
    }

    // Recursive function call to evaluate all possible game moves
    int best = (player == 'X') ? -1000 : 1000;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player;
                int score = evaluate(opponent);
                board[i][j] = ' ';

                if (player == 'X') {
                    if (score > best) {
                        best = score;
                    }
                } else {
                    if (score < best) {
                        best = score;
                    }
                }
            }
        }
    }

    return best;
}

/**
 * Make the best move for given player using minimax algorithm.
 * Update the board and return true if valid move, else return false.
 */
bool makeMove(char player) {
    char opponent = (player == 'X') ? 'O' : 'X';
    int bestScore = (player == 'X') ? -1000 : 1000;
    int bestRow = -1, bestCol = -1;

    // Iterate over all empty cells to find the best move
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player;
                int score = evaluate(opponent);
                board[i][j] = ' ';

                if (player == 'X') {
                    if (score > bestScore) {
                        bestScore = score;
                        bestRow = i;
                        bestCol = j;
                    }
                } else {
                    if (score < bestScore) {
                        bestScore = score;
                        bestRow = i;
                        bestCol = j;
                    }
                }
            }
        }
    }

    // Update the board with the best move
    if (bestRow != -1 && bestCol != -1) {
        board[bestRow][bestCol] = player;
        return true;
    } else {
        return false;
    }
}

/**
 * Print current board state
 */
void printBoard() {
    printf("-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}

/**
 * Main function to play the game
 */
int main() {
    printf("Welcome to Tic Tac Toe with Minimax Algorithm!\n");
    printf("You are X and the computer is O.\n\n");

    char player = 'X';
    bool done = false;

    while (!done) {
        printBoard();

        if (player == 'X') {
            // User input
            int row, col;
            printf("Enter row (0 to 2) and column (0 to 2) separated by a space: ");
            scanf("%d %d", &row, &col);

            if (board[row][col] == ' ') {
                board[row][col] = player;
            } else {
                printf("Invalid move!\n");
                continue;
            }
        } else {
            // AI move
            printf("Computer is thinking...\n");
            if (!makeMove(player)) {
                done = true;
            }
        }

        // Check if game is over
        char winner = isWon();
        if (winner != 0) {
            printf("Game over. %c won!\n", winner);
            done = true;
        } else if (isDraw()) {
            printf("Game over. It's a draw!\n");
            done = true;
        }

        // Switch player turn
        player = (player == 'X') ? 'O' : 'X';
    }

    printBoard();

    return 0;
}