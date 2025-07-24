//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#define WIDTH 80
#define HEIGHT 25

/* block enum */
enum block {
    NONE,
    WALL,
    BRICK,
    BALL,
    PADDLE
};

char screen[HEIGHT][WIDTH];      /* screen buffer */
int ball_x, ball_y;             /* ball coordinates */
int paddle_x, paddle_y;         /* paddle coordinates */
int score;                      /* game score */

/* initialize the game */
void init_game() {
    srand(time(NULL));
    /* initialize the screen with blocks */
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                screen[i][j] = WALL;
            } else if (i < HEIGHT / 2) {
                screen[i][j] = BRICK;
            } else {
                screen[i][j] = NONE;
            }
        }
    }
    /* initialize the ball */
    ball_x = WIDTH / 2;
    ball_y = HEIGHT / 2;
    screen[ball_y][ball_x] = BALL;
    /* initialize the paddle */
    paddle_x = WIDTH / 2;
    paddle_y = HEIGHT - 2;
    for (int i = paddle_x - 2; i <= paddle_x + 2; i++) {
        screen[paddle_y][i] = PADDLE;
    }
    /* initialize the score */
    score = 0;
}

/* draw the screen on the terminal */
void draw_screen() {
    printf("\033[2J\033[H"); // clear screen
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (screen[i][j] == NONE) {
                printf(" ");
            } else if (screen[i][j] == WALL) {
                printf("#");
            } else if (screen[i][j] == BRICK) {
                printf("*");
            } else if (screen[i][j] == BALL) {
                printf("O");
            } else if (screen[i][j] == PADDLE) {
                printf("=");
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

/* move the ball */
void move_ball(int dx, int dy) {
    if (screen[ball_y + dy][ball_x + dx] == NONE) {
        screen[ball_y][ball_x] = NONE;
        ball_x += dx;
        ball_y += dy;
        screen[ball_y][ball_x] = BALL;
    } else if (screen[ball_y + dy][ball_x + dx] == WALL) {
        move_ball(-dx, -dy);
    } else if (screen[ball_y + dy][ball_x + dx] == BRICK) {
        screen[ball_y][ball_x] = NONE;
        ball_x += dx;
        ball_y += dy;
        screen[ball_y][ball_x] = BALL;
        screen[ball_y + dy][ball_x + dx] = NONE;
        score++;
    } else if (screen[ball_y + dy][ball_x + dx] == PADDLE) {
        move_ball(dx, -dy);
    }
}

/* move the paddle */
void move_paddle(int dx) {
    if (paddle_x + dx >= 2 && paddle_x + dx <= WIDTH - 3) {
        for (int i = paddle_x - 2; i <= paddle_x + 2; i++) {
            screen[paddle_y][i] = NONE;
        }
        paddle_x += dx;
        for (int i = paddle_x - 2; i <= paddle_x + 2; i++) {
            screen[paddle_y][i] = PADDLE;
        }
    }
}

int main() {
    init_game();
    draw_screen();
    usleep(1000000);
    while (true) {
        /* move the ball */
        move_ball(rand() % 3 - 1, -1);
        /* move the paddle */
        int c = getchar();
        if (c == 'a') {
            move_paddle(-1);
        } else if (c == 'd') {
            move_paddle(1);
        } else if (c == 'q') {
            printf("\033[2J\033[H"); // clear screen
            printf("Game over! Final score: %d\n", score);
            break;
        }
        /* check for game over */
        if (ball_y == HEIGHT - 2) {
            printf("\033[2J\033[H"); // clear screen
            printf("Game over! Final score: %d\n", score);
            break;
        }
        /* check for win */
        bool win = true;
        for (int i = 1; i < HEIGHT / 2; i++) {
            for (int j = 1; j < WIDTH - 1; j++) {
                if (screen[i][j] == BRICK) {
                    win = false;
                }
            }
        }
        if (win) {
            printf("\033[2J\033[H"); // clear screen
            printf("You win! Final score: %d\n", score);
            break;
        }
        draw_screen();
        usleep(10000);
    }
    return 0;
}