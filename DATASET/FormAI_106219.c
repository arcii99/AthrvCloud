//FormAI DATASET v1.0 Category: Checkers Game ; Style: ephemeral
#include <stdio.h>

#define BOARD_SIZE 8

typedef enum { EMPTY, RED, RED_KING, BLACK, BLACK_KING } piece_t;

void init_board(piece_t board[BOARD_SIZE][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (row % 2 != col % 2) {
                if (row < 3) {
                    board[row][col] = BLACK;
                } else if (row > 4) {
                    board[row][col] = RED;
                } else {
                    board[row][col] = EMPTY;
                }
            } else {
                board[row][col] = EMPTY;
            }
        }
    }
}

void print_board(piece_t board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n   ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf(" %c ", 'A' + col);
    }
    printf("\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf(" %d ", row + 1);
        for (int col = 0; col < BOARD_SIZE; col++) {
            char ch;
            switch (board[row][col]) {
                case EMPTY:
                    ch = '_';
                    break;
                case RED:
                    ch = 'r';
                    break;
                case RED_KING:
                    ch = 'R';
                    break;
                case BLACK:
                    ch = 'b';
                    break;
                case BLACK_KING:
                    ch = 'B';
                    break;
                default:
                    ch = '?'; // error state
            }
            printf("|%c|", ch);
        }
        printf(" %d", row + 1);
        printf("\n");
    }
    printf("   ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf(" %c ", 'A' + col);
    }
    printf("\n");
}

int main() {
    piece_t board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    print_board(board);
    return 0;
}