//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 20
#define PADDLE_HEIGHT 5
#define PADDLE_WIDTH 1
#define BALL_RADIUS 1

typedef struct {
    int x;
    int y;
    int vx;
    int vy;
} Ball;

typedef struct {
    int x;
    int y;
    int direction; // 1 for up, -1 for down
} Paddle;

int main() {
    srand(time(NULL));

    // initialize ball
    Ball ball = {
        .x = WIDTH/2,
        .y = HEIGHT/2,
        .vx = rand() % 2 == 0 ? -1 : 1,
        .vy = rand() % 2 == 0 ? -1 : 1
    };

    // initialize paddles
    Paddle human_paddle = {
        .x = 2,
        .y = HEIGHT/2 - PADDLE_HEIGHT/2,
        .direction = 0
    };

    Paddle ai_paddle = {
        .x = WIDTH - 2 - PADDLE_WIDTH,
        .y = HEIGHT/2 - PADDLE_HEIGHT/2,
        .direction = 0
    };

    // initialize board
    char board[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT-1) {
                board[i][j] = '-';
            } else if (j == 0 || j == WIDTH-1) {
                board[i][j] = '|';
            } else {
                board[i][j] = ' ';
            }
        }
    }

    // main game loop
    while (1) {
        // clear screen
        system("clear");

        // move ball
        ball.x += ball.vx;
        ball.y += ball.vy;

        // check for collision with top or bottom walls
        if (ball.y < BALL_RADIUS+1 || ball.y > HEIGHT-BALL_RADIUS-2) {
            ball.vy = -ball.vy;
        }

        // check for collision with paddles
        if (ball.x == human_paddle.x + PADDLE_WIDTH) {
            for (int i = 0; i < PADDLE_HEIGHT; i++) {
                if (ball.y == human_paddle.y + i) {
                    ball.vx = -ball.vx;
                }
            }
        } else if (ball.x == ai_paddle.x - 1) {
            for (int i = 0; i < PADDLE_HEIGHT; i++) {
                if (ball.y == ai_paddle.y + i) {
                    ball.vx = -ball.vx;
                }
            }
        }

        // move human paddle
        if (human_paddle.direction == -1 && human_paddle.y > 1) {
            human_paddle.y--;
        } else if (human_paddle.direction == 1 && human_paddle.y < HEIGHT-PADDLE_HEIGHT-2) {
            human_paddle.y++;
        }

        // move ai paddle (simple AI, follows ball)
        if (ball.y < ai_paddle.y + PADDLE_HEIGHT/2 && ai_paddle.y > 1) {
            ai_paddle.y--;
        } else if (ball.y > ai_paddle.y + PADDLE_HEIGHT/2 && ai_paddle.y < HEIGHT-PADDLE_HEIGHT-2) {
            ai_paddle.y++;
        }

        // update board
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (i == ball.y && j == ball.x) {
                    board[i][j] = 'O';
                    continue;
                }
                if (j == human_paddle.x && i >= human_paddle.y && i < human_paddle.y+PADDLE_HEIGHT) {
                    board[i][j] = '|';
                    continue;
                }
                if (j == ai_paddle.x && i >= ai_paddle.y && i < ai_paddle.y+PADDLE_HEIGHT) {
                    board[i][j] = '|';
                    continue;
                }
                printf("%c", board[i][j]);
            }
            printf("\n");
        }

        // read user input
        char input = getchar();
        if (input == 'w') {
            human_paddle.direction = -1;
        } else if (input == 's') {
            human_paddle.direction = 1;
        }

        // check for game over
        if (ball.x == 1 || ball.x == WIDTH-2) {
            break;
        }
    }

    // print game over message
    if (ball.x == 1) {
        printf("You won!\n");
    } else {
        printf("You lost :(\n");
    }

    return 0;
}