//FormAI DATASET v1.0 Category: Checkers Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 8

typedef enum { EMPTY, RED, BLACK } Piece;

typedef struct {
    Piece piece;
    int x;
    int y;
} Square;

Square board[ROWS][COLS];

void init_board() {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i < 3 && (i + j) % 2 == 0) {
                board[i][j].piece = BLACK;
            } else if (i > 4 && (i + j) % 2 == 0) {
                board[i][j].piece = RED;
            } else {
                board[i][j].piece = EMPTY;
            }

            board[i][j].x = i;
            board[i][j].y = j;
        }
    }
}

void print_board() {
    int i, j;

    printf("   A B C D E F G H\n");
    printf("  -----------------\n");

    for (i = 0; i < ROWS; i++) {
        printf("%d |", i + 1);

        for (j = 0; j < COLS; j++) {
            switch (board[i][j].piece) {
            case EMPTY:
                printf("  ");
                break;
            case RED:
                printf("R ");
                break;
            case BLACK:
                printf("B ");
                break;
            }
        }

        printf("|\n");
    }

    printf("  -----------------\n");
}

void play_game() {
    init_board();
    print_board();
    /* Start the game */
}

int main() {
    play_game();

    return 0;
}