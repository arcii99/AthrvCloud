//FormAI DATASET v1.0 Category: Chess engine ; Style: minimalist
#include <stdio.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

void emptyBoard() {
    for (int x = 0; x < BOARD_SIZE; x++) {
        for (int y = 0; y < BOARD_SIZE; y++) {
            board[x][y] = ' ';
        }
    }
}

void printBoard() {
    printf("  0 1 2 3 4 5 6 7\n");
    printf("-----------------\n");
    for (int x = 0; x < BOARD_SIZE; x++) {
        printf("%d|", x);
        for (int y = 0; y < BOARD_SIZE; y++) {
            printf("%c|", board[x][y]);
        }
        printf("\n");
        printf("-----------------\n");
    }
}

int main() {
    emptyBoard();
    printBoard();
    return 0;
}