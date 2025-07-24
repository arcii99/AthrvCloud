//FormAI DATASET v1.0 Category: Checkers Game ; Style: Ada Lovelace
#include <stdio.h>

#define BOARD_SIZE 8
#define EMPTY ' '
#define BLACK 'B'
#define WHITE 'W'
#define BLACK_KING 'K'
#define WHITE_KING 'Q'

int board[BOARD_SIZE][BOARD_SIZE] = {
    {0, -1, 0, -1, 0, -1, 0, -1},
    {-1, 0, -1, 0, -1, 0, -1, 0},
    {0, -1, 0, -1, 0, -1, 0, -1},
    {EMPTY, 0, EMPTY, 0, EMPTY, 0, EMPTY, 0},
    {0, EMPTY, 0, EMPTY, 0, EMPTY, 0, EMPTY},
    {WHITE, 0, WHITE, 0, WHITE, 0, WHITE, 0},
    {0, WHITE, 0, WHITE, 0, WHITE, 0, WHITE},
    {WHITE, 0, WHITE, 0, WHITE, 0, WHITE, 0}
};

void print_board() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}

int main() {
    print_board();
    return 0;
}