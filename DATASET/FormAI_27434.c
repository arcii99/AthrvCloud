//FormAI DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int row, col, choice, counter = 0;
    char board[3][3];

    // Initialize the game board
    for(row = 0; row < 3; row++) {
        for(col = 0; col < 3; col++) {
            board[row][col] = ' ';
        }
    }

    printf("Tic Tac Toe game\n");
    printf("Player 1 (X) - Player 2 (O)\n\n");
    printf("   1   2   3 \n");
    printf("1  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("  ---+---+---\n");
    printf("2  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("  ---+---+---\n");
    printf("3  %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);

    // Let's play!
    while(counter < 9) {
        // Player 1's turn
        do {
            printf("Player 1, please enter your move (row column): ");
            scanf("%d %d", &row, &col);
        } while(board[row-1][col-1] != ' ');

        board[row-1][col-1] = 'X';
        printf("\n   1   2   3 \n");
        printf("1  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
        printf("  ---+---+---\n");
        printf("2  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
        printf("  ---+---+---\n");
        printf("3  %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);

        counter++;

        // Check for winner
        if((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') ||
           (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') ||
           (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') ||
           (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') ||
           (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') ||
           (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') ||
           (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
           (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')) {

            printf("Player 1 wins!\n");
            return 0;

        } else if(counter == 9) {
            printf("It's a draw!\n");
            return 0;
        }

        // Player 2's turn
        do {
            printf("Player 2, please enter your move (row column): ");
            scanf("%d %d", &row, &col);
        } while(board[row-1][col-1] != ' ');

        board[row-1][col-1] = 'O';
        printf("\n   1   2   3 \n");
        printf("1  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
        printf("  ---+---+---\n");
        printf("2  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
        printf("  ---+---+---\n");
        printf("3  %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);

        counter++;

        // Check for winner
        if((board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') ||
           (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') ||
           (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') ||
           (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') ||
           (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') ||
           (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') ||
           (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') ||
           (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')) {

            printf("Player 2 wins!\n");
            return 0;

        }
    }

    return 0;
}