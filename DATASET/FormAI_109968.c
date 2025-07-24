//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PADDLE_LEFT 1
#define PADDLE_RIGHT 2

#define BOARD_WIDTH 80
#define BOARD_HEIGHT 24

#define BALL_INITIAL_X BOARD_WIDTH/2
#define BALL_INITIAL_Y BOARD_HEIGHT/2

#define MAX_SCORE 5

#define SLEEP_TIME 100000

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point position;
    int direction_x;
    int direction_y;
    int speed;
} Ball;

typedef struct {
    Point position;
    int size;
    int score;
} Paddle;

int getRandomNumber(int start, int end) {
    return rand() % (end - start + 1) + start;
}

void moveBall(Ball* ball) {
    ball->position.x += ball->direction_x * ball->speed;
    ball->position.y += ball->direction_y * ball->speed;
}

void initializeBall(Ball* ball) {
    ball->position.x = BALL_INITIAL_X;
    ball->position.y = BALL_INITIAL_Y;
    ball->direction_x = getRandomNumber(0, 1) == 0 ? -1 : 1;
    ball->direction_y = getRandomNumber(0, 1) == 0 ? -1 : 1;
    ball->speed = 1;
}

void initializePaddle(Paddle* paddle, int x) {
    paddle->position.x = x;
    paddle->position.y = BOARD_HEIGHT / 2;
    paddle->size = 4;
    paddle->score = 0;
}

void drawBoard(Ball ball, Paddle left, Paddle right) {
    system("clear");

    for (int i = 0; i < BOARD_HEIGHT; i++) {
        printf("|");

        for (int j = 0; j < BOARD_WIDTH - 2; j++) {
            if (i == ball.position.y && j == ball.position.x) {
                printf("O");
            } else if (i == left.position.y && j >= left.position.x && j < left.position.x + left.size) {
                printf("=");
            } else if (i == right.position.y && j >= right.position.x && j < right.position.x + right.size) {
                printf("=");
            } else {
                printf(" ");
            }
        }

        printf("|\n");
    }

    printf("\n");
    printf("Player 1: %d\n", left.score);
    printf("Player 2: %d\n", right.score);
}

int checkCollision(Ball ball, Paddle left, Paddle right) {
    if (ball.position.y == 0 || ball.position.y == BOARD_HEIGHT - 1) {
        ball.direction_y *= -1;
    }

    if (ball.position.x == left.position.x + left.size && ball.position.y >= left.position.y && ball.position.y < left.position.y + left.size) {
        ball.direction_x *= -1;
        ball.speed += 1;
    } else if (ball.position.x == right.position.x && ball.position.y >= right.position.y && ball.position.y < right.position.y + right.size) {
        ball.direction_x *= -1;
        ball.speed += 1;
    } else if (ball.position.x == 0) {
        right.score += 1;
        return PADDLE_RIGHT;
    } else if (ball.position.x == BOARD_WIDTH - 3) {
        left.score += 1;
        return PADDLE_LEFT;
    }

    return 0;
}

void movePaddle(Paddle* paddle, int direction) {
    if (direction == -1 && paddle->position.y > 0) {
        paddle->position.y -= 1;
    } else if (direction == 1 && paddle->position.y < BOARD_HEIGHT - paddle->size) {
        paddle->position.y += 1;
    }
}

int getOpponentMove(Ball ball, Paddle paddle) {
    if (ball.direction_x == -1) { // ball is moving towards the opponent
        if (ball.position.y < paddle.position.y + paddle.size / 2) {
            return -1; // move the paddle up
        } else if (ball.position.y > paddle.position.y + paddle.size / 2) {
            return 1; // move the paddle down
        }
    } else { // ball is moving away from the opponent
        if (paddle.position.y < BOARD_HEIGHT / 2) {
            return 1; // move the paddle down
        } else {
            return -1; // move the paddle up
        }
    }

    return 0; // don't move the paddle
}

int main() {
    srand(time(0));

    Ball ball;
    Paddle left_paddle, right_paddle;

    initializeBall(&ball);
    initializePaddle(&left_paddle, 1);
    initializePaddle(&right_paddle, BOARD_WIDTH - 5);

    int game_over = 0;
    int winner = 0;
    int opponent_move = 0;

    while (!game_over) {
        if (left_paddle.score >= MAX_SCORE) {
            game_over = 1;
            winner = PADDLE_LEFT;
        } else if (right_paddle.score >= MAX_SCORE) {
            game_over = 1;
            winner = PADDLE_RIGHT;
        }

        drawBoard(ball, left_paddle, right_paddle);
        moveBall(&ball);
        int collision = checkCollision(ball, left_paddle, right_paddle);

        if (collision == PADDLE_LEFT) {
            initializeBall(&ball);
        } else if (collision == PADDLE_RIGHT) {
            initializeBall(&ball);
        }

        opponent_move = getOpponentMove(ball, right_paddle);
        movePaddle(&left_paddle, opponent_move);

        char input;

        if (ball.direction_x == -1) { // ball is moving towards the player
            printf("Press 'w' to move up, 's' to move down: ");
            scanf("%c", &input);

            if (input == 'w') {
                movePaddle(&right_paddle, -1);
            } else if (input == 's') {
                movePaddle(&right_paddle, 1);
            }
        }

        usleep(SLEEP_TIME);
    }

    drawBoard(ball, left_paddle, right_paddle);

    if (winner == PADDLE_LEFT) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }

    return 0;
}