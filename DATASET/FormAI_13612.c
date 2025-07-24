//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_MARKER 'X'
#define COMPUTER_MARKER 'O'

// function to print the board
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j]);
            if (j != BOARD_SIZE - 1) {
                printf(" | ");
            }
        }
        printf("\n");
        if (i != BOARD_SIZE - 1) {
            printf("---------\n");
        }
    }
    printf("\n");
}

// function to check if there's a winner
int checkWinner(char board[BOARD_SIZE][BOARD_SIZE]) {
    // check horizontally
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
    }

    // check vertically
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }

    // check diagonally
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return 1;
    }

    return 0;
}

// function to check if the board is full
int isBoardFull(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

// function to get the computer's move
void getComputerMove(char board[BOARD_SIZE][BOARD_SIZE], int* row, int* col) {
    // check if there's a move to win
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = COMPUTER_MARKER;
                if (checkWinner(board)) {
                    *row = i;
                    *col = j;
                    return;
                } else {
                    board[i][j] = ' ';
                }
            }
        }
    }

    // check if there's a move to block the player
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = PLAYER_MARKER;
                if (checkWinner(board)) {
                    *row = i;
                    *col = j;
                    board[i][j] = COMPUTER_MARKER;
                    return;
                } else {
                    board[i][j] = ' ';
                }
            }
        }
    }

    // if no move to win or block, random choice
    do {
        *row = rand() % BOARD_SIZE;
        *col = rand() % BOARD_SIZE;
    } while (board[*row][*col] != ' ');
    board[*row][*col] = COMPUTER_MARKER;
}

int main() {
    srand(time(NULL)); // seed for rand() function

    int row, col;
    char board[BOARD_SIZE][BOARD_SIZE];

    // initialize board with empty spaces
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // print romantic welcome message
    printf("Hello, my dear! I have prepared a game of Tic Tac Toe for us to play. Are you ready?\n");

    // main game loop
    while (1) {
        printBoard(board);

        // get player's move
        printf("Please enter the row and column (separated by space) where you want to place your marker '%c': ", PLAYER_MARKER);
        scanf("%d %d", &row, &col);
        while (board[row][col] != ' ') {
            printf("Sorry, that spot is taken. Please choose another one: ");
            scanf("%d %d", &row, &col);
        }
        board[row][col] = PLAYER_MARKER;

        // check if player has won
        if (checkWinner(board)) {
            printBoard(board);
            printf("Congratulations, my love! You have won!\n");
            break;
        }

        // check if board is full
        if (isBoardFull(board)) {
            printBoard(board);
            printf("Aww, it's a tie game! But don't worry, we can play again later.\n");
            break;
        }

        // get computer's move
        printf("Let me think of a move...\n");
        getComputerMove(board, &row, &col);
        printf("I have chosen row %d column %d to place my marker '%c'\n", row, col, COMPUTER_MARKER);

        // check if computer has won
        if (checkWinner(board)) {
            printBoard(board);
            printf("Oh no, my love! I have won this time. But don't be sad, we can play again later.\n");
            break;
        }
    }

    return 0;
}