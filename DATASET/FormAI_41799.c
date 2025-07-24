//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 6
#define MAX_MOVES 10

char board[BOARD_SIZE][BOARD_SIZE];

typedef struct {
    int x;
    int y;
} Position;

int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

Position get_random_position() {
    Position pos;
    pos.x = generate_random_number(0, BOARD_SIZE - 1);
    pos.y = generate_random_number(0, BOARD_SIZE - 1);
    return pos;
}

void prepare_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

void print_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int make_move(Position pos) {
    if (board[pos.x][pos.y] == '.') {
        board[pos.x][pos.y] = 'X';
        return 1;
    }
    return 0;
}

int main() {
    srand(time(0));
    prepare_board();
    int moves_left = MAX_MOVES;
    while (moves_left > 0) {
        Position pos = get_random_position();
        if (make_move(pos)) {
            moves_left--;
        }
        print_board();
        printf("Moves Left: %d\n", moves_left);
        printf("Enter any key to continue...");
        getchar();
    }
    return 0;
}