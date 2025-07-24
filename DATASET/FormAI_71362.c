//FormAI DATASET v1.0 Category: Checkers Game ; Style: complete
#include <stdio.h>

#define BOARD_SIZE 8

enum Piece { NONE = '.', WHITE = 'w', BLACK = 'b' };

void print_board(enum Piece board[BOARD_SIZE][BOARD_SIZE]) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    enum Piece board[BOARD_SIZE][BOARD_SIZE] = {
        { NONE, BLACK, NONE, BLACK, NONE, BLACK, NONE, BLACK},
        { BLACK, NONE, BLACK, NONE, BLACK, NONE, BLACK, NONE},
        { NONE, BLACK, NONE, BLACK, NONE, BLACK, NONE, BLACK},
        { NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE},
        { NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE},
        { WHITE, NONE, WHITE, NONE, WHITE, NONE, WHITE, NONE},
        { NONE, WHITE, NONE, WHITE, NONE, WHITE, NONE, WHITE},
        { WHITE, NONE, WHITE, NONE, WHITE, NONE, WHITE, NONE},
    };
    print_board(board);
    return 0;
}