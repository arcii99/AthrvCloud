//FormAI DATASET v1.0 Category: Checkers Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]);
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    print_board(board);
    return 0;
}

void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;

    // Set all squares to empty
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }

    // Place black pieces
    for (i = 0; i < 3; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 1) {
                board[i][j] = 'b';
            }
        }
    }

    // Place red pieces
    for (i = 5; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 1) {
                board[i][j] = 'r';
            }
        }
    }
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;

    printf("  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    printf("  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("- ");
    }
    printf("\n");

    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("%d\n", i);

        printf(" ");
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("- ");
        }
        printf("\n");
    }

    printf("  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
}