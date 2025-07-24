//FormAI DATASET v1.0 Category: Table Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void initialize(char board[SIZE][SIZE]) {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    printf("\nBoard:\n\n");

    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[SIZE][SIZE]) {
    // Check for horizontal win
    for(int i=0; i<SIZE; i++) {
        if(board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check for vertical win
    for(int i=0; i<SIZE; i++) {
        if(board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // Check for diagonal win
    if(board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }

    if(board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

void play(char board[SIZE][SIZE], char player) {
    int row, col;
    do {
        printf("Player %c: Enter row and column for your move (e.g.: 1 2): ", player);
        scanf("%d %d", &row, &col);
    } while(row<1 || row>SIZE || col<1 || col>SIZE || board[row-1][col-1] != '-');

    board[row-1][col-1] = player;
}

void playGame() {
    char board[SIZE][SIZE];
    char currentPlayer = 'X';

    initialize(board);
    printBoard(board);

    while(!checkWin(board)) {
        play(board, currentPlayer);
        printBoard(board);
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    printf("Player %c won!\n", currentPlayer);
}

int main() {
    srand(time(0));

    printf("Welcome to C Table Game!\n");
    printf("Let's get started...\n");

    char playAgain;
    do {
        playGame();

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while(playAgain == 'y' || playAgain == 'Y');

    printf("\nThank you for playing. Good bye!\n");

    return 0;
}