//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayBoard(char board[3][3]) {
    printf("  %c | %c | %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("----+---+----\n");
    printf("  %c | %c | %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("----+---+----\n");
    printf("  %c | %c | %c  \n", board[2][0], board[2][1], board[2][2]);
}

int validMove(char board[3][3], int i, int j) {
    return (i >= 0 && i < 3 && j >= 0 && j < 3 && board[i][j] == ' ');
}

int gameOver(char board[3][3]) {
    int i, j;

    // check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    // check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }
    // check diagonals
    if (board[1][1] != ' ' &&
        ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
         (board[0][2] == board[1][1] && board[1][1] == board[2][0]))) {
        return 1;
    }
    // check for tie
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 2;
}

void computerMove(char board[3][3]) {
    int i, j;

    // generate random move
    do {
        i = rand() % 3;
        j = rand() % 3;
    } while (!validMove(board, i, j));

    board[i][j] = 'O';
    printf("Computer moves:\n");
    displayBoard(board);

    if (gameOver(board) == 1) {
        printf("Computer wins!\n");
    } else if (gameOver(board) == 2) {
        printf("It's a tie!\n");
    } else {
        playerMove(board);
    }
}

void playerMove(char board[3][3]) {
    int i, j;

    printf("Enter your move (row, column): ");
    scanf("%d%d", &i, &j);

    if (!validMove(board, i, j)) {
        printf("Invalid move, try again.\n");
        playerMove(board);
    } else {
        board[i][j] = 'X';
        displayBoard(board);

        if (gameOver(board) == 1) {
            printf("You win!\n");
        } else if (gameOver(board) == 2) {
            printf("It's a tie!\n");
        } else {
            computerMove(board);
        }
    }
}

int main() {
    char board[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}};

    srand(time(NULL));
    displayBoard(board);
    playerMove(board);
    return 0;
}