//FormAI DATASET v1.0 Category: Table Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void displayBoard(char board[ROWS][COLS]) {
    printf("\n");
    printf("\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkWinner(char board[ROWS][COLS]) {
    int i;
    // check rows
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            if (board[i][0] == 'X') {
                return 1; // X wins
            } else if (board[i][0] == 'O') {
                return 2; // O wins
            }
        }
    }
    // check columns
    for (i = 0; i < COLS; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            if (board[0][i] == 'X') {
                return 1; // X wins
            } else if (board[0][i] == 'O') {
                return 2; // O wins
            }
        }
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        if (board[0][0] == 'X') {
            return 1; // X wins
        } else if (board[0][0] == 'O') {
            return 2; // O wins
        }
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        if (board[0][2] == 'X') {
            return 1; // X wins
        } else if (board[0][2] == 'O') {
            return 2; // O wins
        }
    }
    // check for a tie
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] != '1' && board[i][1] != '2' && board[i][2] != '3' &&
            board[i][0] != '4' && board[i][1] != '5' && board[i][2] != '6' &&
            board[i][0] != '7' && board[i][1] != '8' && board[i][2] != '9') {
            return 0; // tie
        }
    }
    // game not over yet
    return -1;
}

void playGame() {
    char board[ROWS][COLS] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    int turn = 1; // 1 for X, 2 for O
    int move;
    int row, col;
    int winner = -1;

    while (winner == -1) {
        displayBoard(board);
        if (turn == 1) {
            printf("Player X, enter a number (1-9) for your move: ");
        } else {
            printf("Player O, enter a number (1-9) for your move: ");
        }
        scanf("%d", &move);

        // validate move
        while (move < 1 || move > 9) {
            printf("Invalid move. Please enter a number between 1 and 9: ");
            scanf("%d", &move);
        }

        row = (move-1) / ROWS;
        col = (move-1) % COLS;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("That space is already taken. Please choose another.\n");
            continue;
        }

        if (turn == 1) {
            board[row][col] = 'X';
            turn = 2;
        } else {
            board[row][col] = 'O';
            turn = 1;
        }

        winner = checkWinner(board);
    }

    displayBoard(board);
    if (winner == 0) {
        printf("The game is a tie!\n");
    } else if (winner == 1) {
        printf("Congratulations! Player X wins!\n");
    } else if (winner == 2) {
        printf("Congratulations! Player O wins!\n");
    }
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");
    printf("=======================\n");

    int playAgain = 1;
    while (playAgain) {
        playGame();

        printf("Do you want to play again? (1 for yes, 0 for no): ");
        scanf("%d", &playAgain);
    }

    printf("Thanks for playing!\n");

    return 0;
}