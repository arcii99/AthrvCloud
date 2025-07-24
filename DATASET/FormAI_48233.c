//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BOARD_WIDTH 50
#define BOARD_HEIGHT 20
#define PADDLE_WIDTH 5
#define BALL_SIZE 1

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    int width;
} Paddle;

typedef struct {
    Position pos;
    int vel_x;
    int vel_y;
} Ball;

typedef struct {
    int bricks[BOARD_WIDTH][BOARD_HEIGHT];
} Board;

Board create_board() {
    Board board;
    int i, j;
    
    for (i = 0; i < BOARD_WIDTH; i++) {
        for (j = 0; j < BOARD_HEIGHT; j++) {
            board.bricks[i][j] = 1;
        }
    }
    
    return board;
}

bool is_game_over(Board board, Ball ball) {
    int i, j;
    bool is_bottom_row = false;
    
    if (ball.pos.y >= BOARD_HEIGHT - 1) {
        is_bottom_row = true;
    }
    
    for (i = 0; i < BOARD_WIDTH; i++) {
        for (j = 0; j < BOARD_HEIGHT; j++) {
            if (board.bricks[i][j] == 1 && 
                ball.pos.x == i &&
                (is_bottom_row || ball.pos.y == j)) {
                return true;
            }
        }
    }
    
    return false;
}

void print_board(Board board, Paddle paddle, Ball ball) {
    int i, j;
    
    system("clear");
    
    for (i = 0; i < BOARD_WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");
    
    for (j = 0; j < BOARD_HEIGHT; j++) {
        printf("#");
        for (i = 0; i < BOARD_WIDTH; i++) {
            if (board.bricks[i][j] == 1) {
                printf("x");
            } else {
                printf(" ");
            }
        }
        printf("#\n");
    }
    
    printf("#");
    for (i = 0; i < BOARD_WIDTH; i++) {
        if (i >= paddle.pos.x && i < paddle.pos.x + paddle.width) {
            printf("-");
        } else {
            printf(" ");
        }
    }
    printf("#\n");
    
    printf("#");
    for (i = 0; i < BOARD_WIDTH; i++) {
        if (i == ball.pos.x && j == ball.pos.y) {
            printf("*");
        } else {
            printf(" ");
        }
    }
    printf("#\n");
    
    for (i = 0; i < BOARD_WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");
}

int main() {
    Board board = create_board();
    
    Paddle paddle;
    paddle.pos.x = BOARD_WIDTH / 2 - PADDLE_WIDTH / 2;
    paddle.pos.y = BOARD_HEIGHT - 1;
    paddle.width = PADDLE_WIDTH;
    
    Ball ball;
    ball.pos.x = BOARD_WIDTH / 2;
    ball.pos.y = BOARD_HEIGHT / 2;
    srand(time(NULL));
    ball.vel_x = rand() % 2 == 0 ? 1 : -1;
    ball.vel_y = -1;
    
    while (!is_game_over(board, ball)) {
        print_board(board, paddle, ball);
        
        // move paddle
        char input = getchar();
        if (input == 'a' && paddle.pos.x > 0) {
            paddle.pos.x--;
        } else if (input == 'd' && paddle.pos.x < BOARD_WIDTH - paddle.width) {
            paddle.pos.x++;
        }
        
        // move ball
        if (ball.pos.x < 1 || ball.pos.x > BOARD_WIDTH - BALL_SIZE) {
            ball.vel_x *= -1;
        }
        if (ball.pos.y < 1) {
            ball.vel_y *= -1;
        } else if (ball.pos.y >= BOARD_HEIGHT - 2) {
            ball.vel_y *= -1;
            if (ball.pos.x >= paddle.pos.x && ball.pos.x <= paddle.pos.x + paddle.width) {
                ball.vel_x = rand() % 2 == 0 ? 1 : -1;
            } else {
                break;
            }
        }
        ball.pos.x += ball.vel_x;
        ball.pos.y += ball.vel_y;
    }
    
    printf("Game Over\n");
    
    return 0;
}