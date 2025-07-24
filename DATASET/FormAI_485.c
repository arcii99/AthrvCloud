//FormAI DATASET v1.0 Category: Checkers Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

void print_board(char board[][BOARD_SIZE]) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("  ");
    for (char col = 'a'; col <= 'h'; col++) printf("%c ", col);
    printf("\n");
}

void initialize_board(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0 && i < 3) {
                board[i][j] = 'b'; //black checker
            } else if ((i + j) % 2 == 0 && i > 4) {
                board[i][j] = 'w'; //white checker
            } else {
                board[i][j] = ' '; //empty square
            }
        }
    }
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    print_board(board);
    return 0;
}