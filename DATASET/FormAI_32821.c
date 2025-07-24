//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

typedef struct {
    int x, y;
} Point;

void print_board(char board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    Point player_pos = {0, 0};
    char board[ROWS][COLS];

    // initialize board with walls
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) {
                board[i][j] = '#';
            } else {
                board[i][j] = '.';
            }
        }
    }

    // randomly place player and treasure
    board[player_pos.y][player_pos.x] = '@';
    Point treasure_pos = {rand() % (COLS - 2) + 1, rand() % (ROWS - 2) + 1};
    board[treasure_pos.y][treasure_pos.x] = '$';

    print_board(board);

    return 0;
}