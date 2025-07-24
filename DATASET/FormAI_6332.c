//FormAI DATASET v1.0 Category: Checkers Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

void setupBoard() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if((i + j) % 2 == 0) {
                if(i < 3) {
                    board[i][j] = 'O';
                } else if(i > 4) {
                    board[i][j] = 'X';
                } else {
                    board[i][j] = ' ';
                }
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

void printBoard() {
    printf("  1 2 3 4 5 6 7 8\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    setupBoard();
    printBoard();
    return 0;
}