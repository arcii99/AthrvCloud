//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24
#define BULLET_SPEED 3
#define POSSIBLE_MOVES 2
#define PLAYER_SYMBOL 'A'
#define ENEMY_SYMBOL 'X'
#define BULLET_SYMBOL '|'

char screen[SCREEN_HEIGHT][SCREEN_WIDTH];
int player_x, player_y;
int enemy_x, enemy_y;
int bullet_x, bullet_y;

int score = 0;
bool game_over = false;

int kbhit(void);
void move_player(int x);
void move_bullet();
void display();
void create_enemy();
void init_screen();

int main() {
    srand(time(NULL));
    init_screen();
    create_enemy();
    while (!game_over) {
        display();
        int move = kbhit();
        if (move != -1) {
            if (move == 0) move_player(-POSSIBLE_MOVES);
            else if (move == 1) move_player(POSSIBLE_MOVES);
            else if (move == 2) break;
        }
        move_bullet();
        usleep(50000);
    }
    system("clear");
    printf("GAME OVER\nScore: %d\n", score);
    return 0;
}

void init_screen() {
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            if (i == SCREEN_HEIGHT - 1) screen[i][j] = '_';
            else screen[i][j] = ' ';
        }
    }
    player_x = SCREEN_WIDTH / 2;
    player_y = SCREEN_HEIGHT - 5;
    screen[player_y][player_x] = PLAYER_SYMBOL;

    bullet_x = -1;
    bullet_y = player_y - 1;
}

void display() {
    system("clear");
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
}

void move_player(int x) {
    if ((player_x + x < SCREEN_WIDTH) && (player_x + x >= 0)) {
        screen[player_y][player_x] = ' ';
        player_x += x;
        screen[player_y][player_x] = PLAYER_SYMBOL;
    }
}

void create_enemy() {
    enemy_x = rand() % (SCREEN_WIDTH - 2) + 1;
    enemy_y = rand() % (SCREEN_HEIGHT / 2);
    screen[enemy_y][enemy_x] = ENEMY_SYMBOL;
}

void move_bullet() {
    if (bullet_y >= 0) {
        screen[bullet_y][bullet_x] = ' ';
        bullet_y--;
        if ((bullet_x == enemy_x) && (bullet_y == enemy_y)) {
            screen[enemy_y][enemy_x] = ' ';
            score++;
            create_enemy();
        }
        if (bullet_y >= 0) {
            screen[bullet_y][bullet_x] = BULLET_SYMBOL;
        }
    }
    else {
        bullet_x = -1;
        bullet_y = player_y - 1;
    }

    if ((rand() % 5 == 0) && (enemy_y < SCREEN_HEIGHT - 2)) {
        screen[enemy_y][enemy_x] = ' ';
        enemy_y++;
        if ((enemy_y == player_y) && (enemy_x == player_x)) {
            game_over = true;
        }
        else {
            screen[enemy_y][enemy_x] = ENEMY_SYMBOL;
        }
    }

    if (bullet_x == -1) {
        bullet_x = player_x;
    }
}

int kbhit() {
    struct termios oldt, newt;
    fd_set rfd;
    int ret;
    struct timeval tv = {0L,0L};
    if (tcgetattr(STDIN_FILENO, &oldt) < 0) {
        perror("tcsetattr()");
        return -1;
    }
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    if (tcsetattr(STDIN_FILENO, TCSANOW, &newt) < 0) {
        perror("tcsetattr()");
        return -1;
    }
    FD_ZERO(&rfd);
    FD_SET(STDIN_FILENO, &rfd);
    ret = select(STDIN_FILENO+1, &rfd, NULL, NULL, &tv);
    if (ret == 1) {
        if (FD_ISSET(STDIN_FILENO, &rfd)) {
            char ch = getchar();
            if (ch == 'q') return 2;
            else if (ch == 'a') return 0;
            else if (ch == 'd') return 1;
        }
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return -1;
}