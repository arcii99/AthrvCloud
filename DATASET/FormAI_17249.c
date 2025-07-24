//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 40
#define PADDLE_LENGTH 4
#define PADDLE_OFFSET 1

int ball_x, ball_y, player_y, ai_y, ai_speed;
int ball_vel_x, ball_vel_y;

void init_game() {
    ball_x = WIDTH / 2;
    ball_y = HEIGHT / 2;
    player_y = HEIGHT / 2 - PADDLE_OFFSET;
    ai_y = HEIGHT / 2 - PADDLE_OFFSET;
    ai_speed = 1;
    srand(time(NULL));
    ball_vel_x = rand() % 3 - 1;
    ball_vel_y = rand() % 3 - 1;
    if (ball_vel_x == 0) ball_vel_x = 1;
    if (ball_vel_y == 0) ball_vel_y = 1;
}

void render_game(char board[HEIGHT][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1) {
                board[i][j] = '-';
            } else if (j == 0 || j == WIDTH - 1) {
                board[i][j] = '|';
            } else if (i == ball_y && j == ball_x) {
                board[i][j] = 'O';
            } else if (i >= player_y && i < player_y + PADDLE_LENGTH && j == 2) {
                board[i][j] = '|';
            } else if (i >= ai_y && i < ai_y + PADDLE_LENGTH && j == WIDTH - 3) {
                board[i][j] = '|';
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

void update_ai() {
    if (ai_y + PADDLE_LENGTH / 2 > ball_y) {
        if (ai_y - ai_speed >= 1) {
            ai_y -= ai_speed;
        } else {
            ai_y = 1;
        }
    } else if (ai_y + PADDLE_LENGTH / 2 < ball_y) {
        if (ai_y + PADDLE_LENGTH + ai_speed < HEIGHT - 1) {
            ai_y += ai_speed;
        } else {
            ai_y = HEIGHT - 1 - PADDLE_LENGTH;
        }
    }
}

void update_ball() {
    int new_ball_x = ball_x + ball_vel_x;
    int new_ball_y = ball_y + ball_vel_y;
    if (new_ball_y <= 0 || new_ball_y >= HEIGHT - 1) {
        ball_vel_y = -ball_vel_y;
        new_ball_y = ball_y + ball_vel_y;
    }
    if (new_ball_x == 2 && new_ball_y >= player_y && new_ball_y < player_y + PADDLE_LENGTH) {
        ball_vel_x = -ball_vel_x;
        new_ball_x = ball_x + ball_vel_x;
    }
    if (new_ball_x == WIDTH - 3 && new_ball_y >= ai_y && new_ball_y < ai_y + PADDLE_LENGTH) {
        ball_vel_x = -ball_vel_x;
        new_ball_x = ball_x + ball_vel_x;
    }
    ball_x = new_ball_x;
    ball_y = new_ball_y;
}

int main() {
    char board[HEIGHT][WIDTH];
    init_game();
    while (1) {
        render_game(board);
        update_ai();
        update_ball();
        system("clear");
        int i, j;
        for (i = 0; i < HEIGHT; i++) {
            for (j = 0; j < WIDTH; j++) {
                printf("%c", board[i][j]);
            }
            printf("\n");
        }
        printf("Player: %d | AI: %d\n", player_y, ai_y);
    }
    return 0;
}