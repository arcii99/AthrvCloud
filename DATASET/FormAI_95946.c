//FormAI DATASET v1.0 Category: Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define BOARD_SIZE 8

typedef struct {
    int x, y;
} position;

position knight_moves[] = {{-2, -1}, {2, -1}, {-2, 1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};

int board[BOARD_SIZE][BOARD_SIZE];

int is_valid_move(position pos, int path_count) {
    return (pos.x >= 0 && pos.x < BOARD_SIZE && pos.y >= 0 && pos.y < BOARD_SIZE && board[pos.x][pos.y] == 0 && path_count < BOARD_SIZE * BOARD_SIZE);
}

void print_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n\n");
    }
    printf("\n");
}

void move_knight(position current_pos, int path_count) {
    board[current_pos.x][current_pos.y] = path_count;
    if (path_count == BOARD_SIZE * BOARD_SIZE) {
        printf("Game Over: You won!\n\n");
        print_board();
        exit(0);
    }

    int random_index = rand() % 8;
    position new_pos = {current_pos.x + knight_moves[random_index].x, current_pos.y + knight_moves[random_index].y};

    if (is_valid_move(new_pos, path_count + 1)) {
        move_knight(new_pos, path_count + 1);
    } else {
        move_knight(current_pos, path_count);
    }
}

int main() {
    srand(time(NULL));
    memset(board, 0, sizeof(board));
    position starting_pos = {rand() % BOARD_SIZE, rand() % BOARD_SIZE};
    move_knight(starting_pos, 1);
    return 0;
}