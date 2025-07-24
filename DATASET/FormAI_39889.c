//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BOARD_HEIGHT 24
#define BOARD_WIDTH 80
#define MAX_ENEMIES 18

struct enemy {
    int x;
    int y;
    bool active;
};

void display_board(char board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i=0;i<BOARD_HEIGHT;i++) {
        for (int j=0;j<BOARD_WIDTH;j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void generate_random_enemy(struct enemy* enemies) {
    int rand_x = rand() % BOARD_WIDTH;
    int rand_y = rand() % 6;
    int index = -1;
    for (int i=0;i<MAX_ENEMIES;i++) {
        if (!enemies[i].active) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return;
    }
    enemies[index].x = rand_x;
    enemies[index].y = rand_y;
    enemies[index].active = true;
}

void move_enemies(char board[BOARD_HEIGHT][BOARD_WIDTH], struct enemy* enemies) {
    for (int i=0;i<MAX_ENEMIES;i++) {
        if (enemies[i].active) {
            board[enemies[i].y][enemies[i].x] = ' ';
            enemies[i].y++;
            if (enemies[i].y >= BOARD_HEIGHT-2) {
                enemies[i].active = false;
            } else {
                board[enemies[i].y][enemies[i].x] = 'E';
            }
        }
    }
}

void fire_bullet(char board[BOARD_HEIGHT][BOARD_WIDTH], int* player_x, int* player_y) {
    board[*player_y-1][*player_x] = '^';
}

void move_bullet(char board[BOARD_HEIGHT][BOARD_WIDTH], int* bullet_x, int* bullet_y, struct enemy* enemies, int* score) {
    if (board[*bullet_y-1][*bullet_x] == 'E') {
        for (int i=0;i<MAX_ENEMIES;i++) {
            if (enemies[i].active && enemies[i].x == *bullet_x && enemies[i].y == *bullet_y-1) {
                enemies[i].active = false;
                *score += 10;
            }
        }
        board[*bullet_y-1][*bullet_x] = ' ';
        *bullet_x = -1;
        *bullet_y = -1;
        return;
    }
    if (*bullet_y == 0) {
        board[*bullet_y][*bullet_x] = ' ';
        *bullet_x = -1;
        *bullet_y = -1;
        return;
    }
    board[*bullet_y-1][*bullet_x] = '^';
    board[*bullet_y][*bullet_x] = ' ';
    (*bullet_y)--;
}

void* move_player(void* arg) {
    char board[BOARD_HEIGHT][BOARD_WIDTH];
    int index = *((int*) arg);
    int player_x = BOARD_WIDTH / 2;
    int player_y = BOARD_HEIGHT - 2;
    int bullet_x = -1;
    int bullet_y = -1;
    int score = 0;
    struct enemy enemies[MAX_ENEMIES];
    for (int i=0;i<MAX_ENEMIES;i++) {
        enemies[i].active = false;
    }
    while (true) {
        system("clear");
        for (int i=0;i<BOARD_HEIGHT;i++) {
            for (int j=0;j<BOARD_WIDTH;j++) {
                if (i == player_y && j == player_x) {
                    board[i][j] = 'P';
                } else if (i == BOARD_HEIGHT-1) {
                    board[i][j] = '-';
                } else if (j == 0 || j == BOARD_WIDTH-1) {
                    board[i][j] = '|';
                } else {
                    board[i][j] = ' ';
                }
            }
        }
        for (int i=0;i<MAX_ENEMIES;i++) {
            if (enemies[i].active) {
                board[enemies[i].y][enemies[i].x] = 'E';
            }
        }
        if (bullet_y != -1) {
            move_bullet(board, &bullet_x, &bullet_y, enemies, &score);
        }
        printf("SCORE: %d\n", score);
        display_board(board);
        int ch = getchar();
        if (ch == 'a' && player_x > 1) {
            player_x--;
        } else if (ch == 'd' && player_x < BOARD_WIDTH-2) {
            player_x++;
        } else if (ch == 'w' && bullet_y == -1) {
            bullet_x = player_x;
            bullet_y = player_y-1;
            fire_bullet(board, &player_x, &player_y);
        } else if (ch == 'q') {
            printf("GAME OVER\n");
            exit(0);
        }
        generate_random_enemy(enemies);
        move_enemies(board, enemies);
    }
}

int main() {
    pthread_t t1, t2, t3, t4;
    int p1 = 1;
    int p2 = 2;
    int p3 = 3;
    int p4 = 4;
    srand(time(NULL));
    pthread_create(&t1, NULL, move_player, (void*) &p1);
    pthread_create(&t2, NULL, move_player, (void*) &p2);
    pthread_create(&t3, NULL, move_player, (void*) &p3);
    pthread_create(&t4, NULL, move_player, (void*) &p4);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    return 0;
}