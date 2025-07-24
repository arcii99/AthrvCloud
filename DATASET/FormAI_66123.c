//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Function to print the tic-tac-toe board
void printBoard(char board[3][3]) {
    printf("-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}

// Function to check if a given player has won the game
int checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

// Function to get the best move for the AI
int getBestMove(char board[3][3]) {
    int bestMove = -1;
    int bestScore = -1000;
    for (int i = 0; i < 9; i++) {
        if (board[i/3][i%3] == '-') {
            board[i/3][i%3] = 'O';
            int score = minimax(board, 0, 0);
            board[i/3][i%3] = '-';
            if (score > bestScore) {
                bestScore = score;
                bestMove = i;
            }
        }
    }
    return bestMove;
}

// Function to get the worst move for the AI
int getWorstMove(char board[3][3]) {
    int worstMove = -1;
    int worstScore = 1000;
    for (int i = 0; i < 9; i++) {
        if (board[i/3][i%3] == '-') {
            board[i/3][i%3] = 'X';
            int score = minimax(board, 0, 0);
            board[i/3][i%3] = '-';
            if (score < worstScore) {
                worstScore = score;
                worstMove = i;
            }
        }
    }
    return worstMove;
}

// Recursive function to implement the minimax algorithm
int minimax(char board[3][3], int depth, int isMaximizing) {
    if (checkWin(board, 'O')) {
        return 10;
    }
    if (checkWin(board, 'X')) {
        return -10;
    }
    if (depth == 9) {
        return 0;
    }
    if (isMaximizing) {
        int bestScore = -1000;
        for (int i = 0; i < 9; i++) {
            if (board[i/3][i%3] == '-') {
                board[i/3][i%3] = 'O';
                int score = minimax(board, depth+1, 0);
                board[i/3][i%3] = '-';
                if (score > bestScore) {
                    bestScore = score;
                }
            }
        }
        return bestScore;
    }
    else {
        int worstScore = 1000;
        for (int i = 0; i < 9; i++) {
            if (board[i/3][i%3] == '-') {
                board[i/3][i%3] = 'X';
                int score = minimax(board, depth+1, 1);
                board[i/3][i%3] = '-';
                if (score < worstScore) {
                    worstScore = score;
                }
            }
        }
        return worstScore;
    }
}

// Main function to play the game
int main() {
    char board[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
    int turn = 1;
    while (1) {
        if (turn == 1) {
            printBoard(board);
            int move;
            printf("Enter move (0-8): ");
            scanf("%d", &move);
            if (board[move/3][move%3] != '-') {
                printf("Invalid move!\n");
                continue;
            }
            board[move/3][move%3] = 'X';
            if (checkWin(board, 'X')) {
                printf("You won!\n");
                printBoard(board);
                break;
            }
            if (checkWin(board, 'O')) {
                printf("AI won!\n");
                printBoard(board);
                break;
            }
            turn = 2;
        }
        else {
            int move = getBestMove(board);
            board[move/3][move%3] = 'O';
            if (checkWin(board, 'X')) {
                printf("You won!\n");
                printBoard(board);
                break;
            }
            if (checkWin(board, 'O')) {
                printf("AI won!\n");
                printBoard(board);
                break;
            }
            turn = 1;
        }
        if (turn == 1) {
            int move = getWorstMove(board);
            board[move/3][move%3] = 'X';
            if (checkWin(board, 'X')) {
                printf("You won!\n");
                printBoard(board);
                break;
            }
            if (checkWin(board, 'O')) {
                printf("AI won!\n");
                printBoard(board);
                break;
            }
        }
    }
    return 0;
}