//FormAI DATASET v1.0 Category: Checkers Game ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>

void printBoard(int board[8][8]);
void initializeBoard(int board[8][8]);
void updateBoard(int board[8][8], int move[4]);
int checkValidMove(int board[8][8], int move[4]);

int main() {
    int board[8][8];
    initializeBoard(board);
    printBoard(board);
    int player = 1;
    int gameOver = 0;
    int move[4];
    while (!gameOver) {
        printf("Player %d, enter your move coordinates: ", player);
        scanf("%d %d %d %d", &move[0], &move[1], &move[2], &move[3]);
        int valid = checkValidMove(board, move);
        while (!valid) {
            printf("Invalid move. Try again: ");
            scanf("%d %d %d %d", &move[0], &move[1], &move[2], &move[3]);
            valid = checkValidMove(board, move);
        }
        updateBoard(board, move);
        printBoard(board);
        player = (player == 1) ? 2 : 1;
        // Game over conditions
        // Code for game over conditions
    }
    printf("Game over!");
    return 0;
}

void initializeBoard(int board[8][8]) {
    // Code for initializing the board
}

void printBoard(int board[8][8]) {
    // Code for printing the board
}

void updateBoard(int board[8][8], int move[4]) {
    // Code for updating the board after a move
}

int checkValidMove(int board[8][8], int move[4]) {
    // Code for checking if a move is valid
}