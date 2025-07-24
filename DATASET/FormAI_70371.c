//FormAI DATASET v1.0 Category: Memory Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define MAX_MOVES 10

int board[BOARD_SIZE][BOARD_SIZE];

void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%3d", board[i][j]);
        }
        printf("\n");
    }
}

void shuffle() {
    srand(time(0));
    for (int i = 0; i < MAX_MOVES; i++) {
        int a = rand() % BOARD_SIZE;
        int b = rand() % BOARD_SIZE;
        int c = rand() % BOARD_SIZE;
        int d = rand() % BOARD_SIZE;
        int temp = board[a][b];
        board[a][b] = board[c][d];
        board[c][d] = temp;
    }
}

int main() {
    int num = 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = num;
            num++;
        }
    }
    shuffle();
    int moves = 0;
    while (moves < MAX_MOVES) {
        printBoard();
        printf("Enter the row and column of the number you want to flip: ");
        int row, col;
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
            board[row][col] = -board[row][col];
            moves++;
        } else {
            printf("Invalid input. Try again.\n");
        }
    }
    printBoard();
    printf("Game over!\n");
    return 0;
}