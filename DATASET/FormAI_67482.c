//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define HEIGHT 30
#define WIDTH 50

enum dir {UP, DOWN, LEFT, RIGHT};

struct Ball {
    int x;
    int y;
    enum dir direction;
};

struct Paddle {
    int x;
    int y;
    int length;
};

struct Brick {
    int x;
    int y;
    int strength;
};

void draw_paddle(struct Paddle paddle) {
    for (int i = 0; i < paddle.length; i++) {
        printf("\033[%d;%dH=", paddle.y, paddle.x+i);
    }
    printf("\033[0m");
}

void move_paddle(struct Paddle *paddle, int dx) {
    if (paddle->x + dx >= 0 && paddle->x + paddle->length + dx <= WIDTH) {
        paddle->x += dx;
        draw_paddle(*paddle);
    }
}

void draw_ball(struct Ball ball) {
    printf("\033[%d;%dH@", ball.y, ball.x);
    printf("\033[0m");
}

int check_wall_collision(struct Ball ball) {
    if (ball.x == 0 || ball.x == WIDTH-1) {
        // hit left or right wall
        return 1;
    } else if (ball.y == HEIGHT-1) {
        // hit bottom wall
        return 2;
    }
    return 0;
}

int check_brick_collision(struct Ball ball, struct Brick bricks[], int num_bricks) {
    for (int i = 0; i < num_bricks; i++) {
        if (bricks[i].strength > 0 &&
            ball.x >= bricks[i].x &&
            ball.x < bricks[i].x + 5 &&
            ball.y == bricks[i].y) {
            // hit brick
            bricks[i].strength--;
            if (bricks[i].strength == 0) {
                printf("\033[%d;%dH     ", bricks[i].y, bricks[i].x);
            } else {
                printf("\033[%d;%dH#####", bricks[i].y, bricks[i].x);
            }
            printf("\033[0m");
            return 3;
        }
    }
    return 0;
}

void move_ball(struct Ball *ball) {
    switch (ball->direction) {
        case UP:
            ball->y--;
            break;
        case DOWN:
            ball->y++;
            break;
        case LEFT:
            ball->x--;
            break;
        case RIGHT:
            ball->x++;
            break;
    }
    draw_ball(*ball);
}

void change_ball_direction(struct Ball *ball, int collision) {
    if (collision == 1) {
        // hit left or right wall
        if (ball->direction == LEFT) {
            ball->direction = RIGHT;
        } else {
            ball->direction = LEFT;
        }
    } else if (collision == 2) {
        // hit bottom wall
        ball->direction = UP;
    } else if (collision == 3) {
        // hit brick
        if (ball->direction == UP) {
            ball->direction = DOWN;
        } else {
            ball->direction = UP;
        }
    }
}

int get_input() {
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

int main() {
    int score = 0;
    int num_bricks = 20;
    int brick_strength = 3;
    struct Brick bricks[num_bricks];
    struct Paddle paddle = {20, HEIGHT-1, 10};
    struct Ball ball = {25, HEIGHT-2, UP};

    srand(time(NULL));

    // create bricks
    for (int i = 0; i < num_bricks; i++) {
        bricks[i].x = 5 + (i % 10) * 5;
        bricks[i].y = 4 + (i / 10) * 2;
        bricks[i].strength = brick_strength;
        printf("\033[%d;%dH#####", bricks[i].y, bricks[i].x);
    }
    printf("\033[0m");

    draw_paddle(paddle);
    draw_ball(ball);

    while (1) {
        usleep(50000); // sleep for 50 milliseconds

        // move ball
        move_ball(&ball);

        // check for collision with walls
        int wall_collision = check_wall_collision(ball);
        if (wall_collision > 0) {
            change_ball_direction(&ball, wall_collision);
            continue;
        }

        // check for collision with bricks
        int brick_collision = check_brick_collision(ball, bricks, num_bricks);
        if (brick_collision > 0) {
            change_ball_direction(&ball, brick_collision);
            score++;
            printf("\033[%d;%dHSCORE: %d", HEIGHT+1, 0, score);
            fflush(stdout);
            continue;
        }

        // check for input
        int input = get_input();
        if (input == 'a') {
            move_paddle(&paddle, -1);
        } else if (input == 'd') {
            move_paddle(&paddle, 1);
        }
    }

    return 0;
}