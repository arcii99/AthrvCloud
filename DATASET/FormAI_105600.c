//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <signal.h>
#include <termios.h>

#define WIDTH 40
#define HEIGHT 20
#define BRICK_COUNT 20
#define PADDLE_LEN 5
#define BALL_START_X 20
#define BALL_START_Y 18
#define PADDLE_START_X 18
#define PADDLE_START_Y 19

typedef struct {
    int x, y, dx, dy;
} Ball;

typedef struct {
    int x, y, len;
} Paddle;

typedef struct {
    int x, y;
    bool broken;
} Brick;

/* Global game objects */
Ball ball = { .x = BALL_START_X, .y = BALL_START_Y, .dx = 1, .dy = -1 };
Paddle paddle = { .x = PADDLE_START_X, .y = PADDLE_START_Y, .len = PADDLE_LEN };
Brick bricks[BRICK_COUNT];

/* Terminal I/O setup */
struct termios orig_termios, new_termios;

void disable_raw_mode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enable_raw_mode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    new_termios = orig_termios;
    new_termios.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &new_termios);
    atexit(disable_raw_mode);
}

/* Signal handler */
void sigint_handler(int sig) {
    /* Restore terminal before exiting */
    disable_raw_mode();

    /* Print game over and exit */
    printf("\nGame over!\n");
    exit(0);
}

/* Utility functions */
int get_input() {
    int c = 0;

    /* Read input without blocking */
    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;

    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);

    select(1, &fds, NULL, NULL, &timeout);

    if (FD_ISSET(STDIN_FILENO, &fds)) {
        c = getchar();
    }

    return c;
}

void clear_screen() {
    printf("\033[H\033[J");
}

void move_cursor(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void draw_bricks() {
    for (int i = 0; i < BRICK_COUNT; i++) {
        if (!bricks[i].broken) {
            move_cursor(bricks[i].x, bricks[i].y);
            printf("#");
        }
    }
}

void generate_bricks() {
    int brick_x = 1, brick_y = 1;

    for (int i = 0; i < BRICK_COUNT; i++) {
        bricks[i].x = brick_x;
        bricks[i].y = brick_y;
        bricks[i].broken = false;

        brick_x++;

        if (brick_x > WIDTH - 2) {
            brick_x = 1;
            brick_y += 2;
        }
    }
}

void draw_paddle() {
    for (int i = 0; i < paddle.len; i++) {
        move_cursor(paddle.x + i, paddle.y);
        printf("-");
    }
}

void draw_ball() {
    move_cursor(ball.x, ball.y);
    printf("O");
}

/* Collision detection */
bool is_collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
    return (x1 < (x2 + w2)) && ((x1 + w1) > x2) && (y1 < (y2 + h2)) && ((y1 + h1) > y2);
}

bool check_ball_collision() {
    /* Check collision with screen boundaries */
    if ((ball.x <= 0) || (ball.x >= WIDTH - 1)) {
        ball.dx = -ball.dx;
        return true;
    }

    if (ball.y <= 0) {
        ball.dy = -ball.dy;
        return true;
    }

    if (ball.y >= HEIGHT - 1) {
        return false; /* Game over */
    }

    /* Check collision with bricks */
    for (int i = 0; i < BRICK_COUNT; i++) {
        if (!bricks[i].broken) {
            if (is_collision(ball.x, ball.y, 1, 1, bricks[i].x, bricks[i].y, 1, 1)) {
                bricks[i].broken = true;
                ball.dy = -ball.dy;
                return true;
            }
        }
    }

    /* Check collision with paddle */
    if (is_collision(ball.x, ball.y, 1, 1, paddle.x, paddle.y, paddle.len, 1)) {
        ball.dy = -ball.dy;

        if (ball.dx == 0) {
            ball.dx = 1;
        }

        ball.dx = (ball.x - paddle.x - (paddle.len / 2)) / (paddle.len / 2);
        return true;
    }

    return false;
}

/* Game loop */
void game_loop() {
    while (true) {
        /* Draw game objects */
        clear_screen();
        draw_bricks();
        draw_paddle();
        draw_ball();

        /* Check for user input */
        int c = get_input();

        if (c == 'q' || c == 'Q') {
            /* Quit game */
            break;
        }

        if (c == 'a' || c == 'A') {
            /* Move paddle left */
            if (paddle.x > 1) {
                paddle.x--;
            }
        }

        if (c == 'd' || c == 'D') {
            /* Move paddle right */
            if ((paddle.x + paddle.len) < (WIDTH - 1)) {
                paddle.x++;
            }
        }

        /* Update ball position */
        ball.x += ball.dx;
        ball.y += ball.dy;

        /* Check for collisions */
        if (!check_ball_collision()) {
            /* Game over */
            break;
        }

        /* Sleep to control game speed */
        usleep(50000);
    }

    /* Restore terminal before exiting */
    disable_raw_mode();

    /* Print game over and exit */
    printf("\nGame over!\n");
}

/* Main function */
int main() {
    srand(time(NULL));

    /* Initialize bricks, ball and paddle */
    generate_bricks();

    /* Enable raw mode for input */
    enable_raw_mode();

    /* Setup signal handler for ctrl-c */
    signal(SIGINT, sigint_handler);

    /* Start game loop */
    game_loop();

    return 0;
}