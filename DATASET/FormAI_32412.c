//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to initialize the game board
void initializeBoard(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

// function to print the game board
void printBoard(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// function to check if there is a winner
char checkWinner(char board[][3]) {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    // check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != '-' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }
    // check diagonals
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    // no winner
    return '-';
}

// function to get the user move
void getUserMove(char board[][3], int *row, int *col) {
    do {
        printf("Enter row (1-3): ");
        scanf("%d", row);
        printf("Enter column (1-3): ");
        scanf("%d", col);
        (*row)--;
        (*col)--;
    } while (*row < 0 || *row > 2 || *col < 0 || *col > 2 || board[*row][*col] != '-');
}

// function to get the computer move
void getComputerMove(char board[][3], int *row, int *col) {
    do {
        *row = rand() % 3;
        *col = rand() % 3;
    } while (board[*row][*col] != '-');
}

int main() {
    char board[3][3];
    initializeBoard(board);
    srand(time(NULL));
    int row, col;
    char winner = '-';
    while (winner == '-') {
        printf("\nPlayer 1 (X):\n");
        getUserMove(board, &row, &col);
        board[row][col] = 'X';
        printBoard(board);
        winner = checkWinner(board);
        if (winner != '-') {
            break;
        }
        printf("\nPlayer 2 (O):\n");
        getComputerMove(board, &row, &col);
        board[row][col] = 'O';
        printBoard(board);
        winner = checkWinner(board);
    }
    if (winner == 'X') {
        printf("\nPlayer 1 wins!\n");
    } else if (winner == 'O') {
        printf("\nPlayer 2 wins!\n");
    } else {
        printf("\nDraw!\n");
    }
    return 0;
}