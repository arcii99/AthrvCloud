//FormAI DATASET v1.0 Category: Checkers Game ; Style: safe
#include <stdio.h>
#define BOARD_SIZE 8

typedef enum { EMPTY, RED, BLACK, RED_KING, BLACK_KING } piece;

void initialize_board(piece board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
            if ((i + j) % 2 != 0) {
                if (i < 3) {
                    board[i][j] = BLACK;
                } else if (i > 4) {
                    board[i][j] = RED;
                }
            }
        }
    }
}

void print_board(piece board[][BOARD_SIZE]) {
    printf("      0   1   2   3   4   5   6   7\n");
    printf("    +---+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("  %d |", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case EMPTY:
                    printf("   |");
                    break;
                case RED:
                    printf(" R |");
                    break;
                case BLACK:
                    printf(" B |");
                    break;
                case RED_KING:
                    printf("RK |");
                    break;
                case BLACK_KING:
                    printf("BK |");
                    break;
                default:
                    break;
            }
        }
        printf("\n");
        printf("    +---+---+---+---+---+---+---+---+\n");
    }
}

int main() {
    piece board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    print_board(board);
    return 0;
}