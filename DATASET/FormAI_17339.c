//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define PADDLE_LEN 4

typedef struct {
    int x, y;
    int dx, dy;
} Ball;

typedef struct {
    int x, y;
} Paddle;

void clear_screen() {
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

void draw_line() {
    for (int i = 0; i < WIDTH; i++) {
        printf("-");
    }
    printf("\n");
}

void draw_ball(Ball ball) {
    printf("\033[%d;%dH", ball.y, ball.x);
    printf("o");
}

void draw_paddle(Paddle paddle) {
    for (int i = 0; i < PADDLE_LEN; i++) {
        printf("\033[%d;%dH", paddle.y + i, paddle.x);
        printf("|");
    }
}

void move_paddle(Paddle *paddle, int dy) {
    paddle->y += dy;
    if (paddle->y < 0) {
        paddle->y = 0;
    } else if (paddle->y + PADDLE_LEN > HEIGHT) {
        paddle->y = HEIGHT - PADDLE_LEN;
    }
}

void move_ball(Ball *ball, Paddle paddle) {
    ball->x += ball->dx;
    ball->y += ball->dy;

    if (ball->y == 0 || ball->y == HEIGHT - 1) {
        ball->dy = -ball->dy;
    }

    if (ball->x == 1 && ball->y >= paddle.y && ball->y < paddle.y + PADDLE_LEN) {
        ball->dx = -ball->dx;
    } else if (ball->x == 0) {
        ball->dx = -ball->dx;
        ball->x = WIDTH / 2;
        ball->y = HEIGHT / 2;
        srand(time(NULL));
        ball->dy = rand() % 3 - 1;
    }
}

int main() {
    clear_screen();
    draw_line();

    Ball ball = {.x = WIDTH / 2, .y = HEIGHT / 2, .dx = -1, .dy = 1};
    Paddle paddle = {.x = 3, .y = HEIGHT / 2 - PADDLE_LEN / 2};

    int score = 0;
    bool game_over = false;
    while (!game_over) {
        clear_screen();
        draw_line();
        draw_ball(ball);
        draw_paddle(paddle);
        move_ball(&ball, paddle);

        srand(time(NULL));
        int ai_move = rand() % 3 - 1;
        move_paddle(&paddle, ai_move);

        printf("\033[%d;%dH", HEIGHT + 1, 0);
        printf("Score: %d", score);

        usleep(100000);

        if (ball.x == WIDTH - 1) {
            game_over = true;
        }
        score++;
    }

    clear_screen();
    printf("\033[%d;%dH", HEIGHT/2, WIDTH/2 - 5);
    printf("GAME OVER");
    printf("\033[%d;%dH", HEIGHT/2 + 1, WIDTH/2 - 6);
    printf("Score: %d", score);

    return 0;
}