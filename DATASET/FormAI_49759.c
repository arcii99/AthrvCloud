//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define BOARD_SIZE 3
#define MAX_DEPTH 9 // Maximum depth of the Minimax algorithm

// Function prototypes
void displayBoard(char board[][BOARD_SIZE]);
int evaluate(char board[][BOARD_SIZE]);
int minimax(char board[][BOARD_SIZE], int depth, bool isMaximizer);
int getBestMove(char board[][BOARD_SIZE]);
bool isGameOver(char board[][BOARD_SIZE]);
void playerMove(char board[][BOARD_SIZE]);
void computerMove(char board[][BOARD_SIZE]);

// Main function
int main(void) {
    char board[BOARD_SIZE][BOARD_SIZE] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    srand(time(NULL)); // Set the seed for the random number generator

    printf("*****Tic Tac Toe*****\n");
    printf("Player 1: X\nPlayer 2: O\n");
    printf("Player 1 goes first.\n\n");
    displayBoard(board);

    // Game loop
    while (!isGameOver(board)) {
        playerMove(board);
        if (isGameOver(board)) {
            break;
        }
        computerMove(board);
    }

    // Determine winner
    int score = evaluate(board);
    if (score == 0) {
        printf("Tie game!\n");
    } else if (score > 0) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }

    return 0;
}

// Displays the tic-tac-toe board
void displayBoard(char board[][BOARD_SIZE]) {
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Evaluates the tic-tac-toe board and returns a score
int evaluate(char board[][BOARD_SIZE]) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X') {
                return 10;
            } else if (board[i][0] == 'O') {
                return -10;
            }
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            if (board[0][j] == 'X') {
                return 10;
            } else if (board[0][j] == 'O') {
                return -10;
            }
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X') {
            return 10;
        } else if (board[0][0] == 'O') {
            return -10;
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X') {
            return 10;
        } else if (board[0][2] == 'O') {
            return -10;
        }
    }

    // If no winner
    return 0;
}

// Uses the Minimax algorithm to determine the best move for the computer
int minimax(char board[][BOARD_SIZE], int depth, bool isMaximizer) {
    int score = evaluate(board);

    // Base case: terminal node or the maximum depth has been reached
    if (score == 10) {
        return score - depth;
    } else if (score == -10) {
        return score + depth;
    } else if (isGameOver(board)) {
        return 0;
    } else if (depth == MAX_DEPTH) {
        return 0;
    }

    // Recursive case
    if (isMaximizer) {
        int bestScore = -1000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    int tempScore = minimax(board, depth + 1, false);
                    board[i][j] = ' ';
                    if (tempScore > bestScore) {
                        bestScore = tempScore;
                    }
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int tempScore = minimax(board, depth + 1, true);
                    board[i][j] = ' ';
                    if (tempScore < bestScore) {
                        bestScore = tempScore;
                    }
                }
            }
        }
        return bestScore;
    }
}

// Returns the best move for the computer
int getBestMove(char board[][BOARD_SIZE]) {
    int bestScore = -1000;
    int bestMove = -1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'X';
                int tempScore = minimax(board, 0, false);
                board[i][j] = ' ';
                if (tempScore > bestScore) {
                    bestScore = tempScore;
                    bestMove = i * BOARD_SIZE + j;
                }
            }
        }
    }
    return bestMove;
}

// Returns true if the game is over, false otherwise
bool isGameOver(char board[][BOARD_SIZE]) {
    // Check for winner
    if (evaluate(board) != 0) {
        return true;
    }

    // Check for tie game
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Allows the player to make a move
void playerMove(char board[][BOARD_SIZE]) {
    int row, col;
    printf("Player 1 enter row and column number to place X (separated by space): ");
    scanf("%d %d", &row, &col);

    if (board[row-1][col-1] == ' ') {
        board[row-1][col-1] = 'O';
    } else {
        printf("That cell is already occupied. Please try again.\n");
        playerMove(board);
    }

    displayBoard(board);
}

// Allows the computer to make a move
void computerMove(char board[][BOARD_SIZE]) {
    printf("Player 2 is thinking...\n");
    int bestMove = getBestMove(board);
    int row = bestMove / BOARD_SIZE;
    int col = bestMove % BOARD_SIZE;
    board[row][col] = 'X';

    displayBoard(board);
}