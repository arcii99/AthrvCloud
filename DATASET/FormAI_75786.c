//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 10
#define ENEMY_COUNT 10

typedef struct {
    int x;
    int y;
} position_t;

position_t player_pos = { BOARD_WIDTH / 2, BOARD_HEIGHT - 1 };
position_t enemy_pos[ENEMY_COUNT];

void initialize_board(bool board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = false;
        }
    }
}

void print_board(bool board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (player_pos.x == j && player_pos.y == i) {
                printf("P");
            } else {
                bool enemy_detected = false;
                for (int k = 0; k < ENEMY_COUNT; k++) {
                    if (enemy_pos[k].x == j && enemy_pos[k].y == i) {
                        printf("E");
                        enemy_detected = true;
                        break;
                    }
                }
                if (!enemy_detected) {
                    printf("-");
                }
            }
        }
        printf("\n");
    }
}

bool check_collision(position_t pos, bool board[BOARD_HEIGHT][BOARD_WIDTH]) {
    if (pos.x < 0 || pos.x >= BOARD_WIDTH || pos.y < 0 || pos.y >= BOARD_HEIGHT) {
        return true;
    }
    if (board[pos.y][pos.x]) {
        return true;
    }
    return false;
}

void move_player(bool board[BOARD_HEIGHT][BOARD_WIDTH], int direction) {
    position_t new_pos = { player_pos.x + direction, player_pos.y };
    if (!check_collision(new_pos, board)) {
        board[player_pos.y][player_pos.x] = false;
        player_pos = new_pos;
        board[player_pos.y][player_pos.x] = true;
    }
}

void move_enemies(bool board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < ENEMY_COUNT; i++) {
        int direction = rand() % 3 - 1;
        position_t new_pos = { enemy_pos[i].x + direction, enemy_pos[i].y + 1 };
        if (!check_collision(new_pos, board)) {
            board[enemy_pos[i].y][enemy_pos[i].x] = false;
            enemy_pos[i] = new_pos;
            board[enemy_pos[i].y][enemy_pos[i].x] = true;
        }
    }
}

int main() {
    bool board[BOARD_HEIGHT][BOARD_WIDTH];
    initialize_board(board);

    srand(time(NULL));
    for (int i = 0; i < ENEMY_COUNT; i++) {
        position_t enemy = { rand() % BOARD_WIDTH, rand() % BOARD_HEIGHT };
        while (check_collision(enemy, board)) {
            enemy.x = rand() % BOARD_WIDTH;
            enemy.y = rand() % BOARD_HEIGHT;
        }
        enemy_pos[i] = enemy;
        board[enemy.y][enemy.x] = true;
    }
    board[player_pos.y][player_pos.x] = true;

    while (true) {
        print_board(board);
        printf("Enter left[l], right[r] or quit[q]: ");
        char input = getchar();
        getchar();
        if (input == 'q') {
            break;
        } else if (input == 'l') {
            move_player(board, -1);
        } else if (input == 'r') {
            move_player(board, 1);
        } else {
            printf("Invalid input\n");
        }
        move_enemies(board);
    }

    return 0;
}