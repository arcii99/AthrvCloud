//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: puzzling
#include <stdio.h>

// This program is a puzzle game based on the classic Breakout game
// The player has to break all the bricks on the screen to win
// The player controls a paddle that can move left and right 
// The player can also shoot a ball to break the bricks
// If the ball hits the bottom of the screen, the player loses a life
// The player has 3 lives to start with, and can earn extra lives by getting a high score

#define BOARD_WIDTH 20
#define BOARD_HEIGHT 10
#define PADDLE_WIDTH 3
#define BALL_RADIUS 1

#define BRICK_COUNT 10

int score = 0;
int lives = 3;
int bricks_left = BRICK_COUNT;

int board[BOARD_HEIGHT][BOARD_WIDTH] = {0};
int paddle_pos = BOARD_WIDTH / 2;
int ball_pos_x = BOARD_WIDTH / 2;
int ball_pos_y = BOARD_HEIGHT - 2;
int ball_vel_x = 1;
int ball_vel_y = -1;

void draw_board() {
    printf("\nSCORE: %d\tLIVES: %d\n", score, lives);
    for(int i = 0; i < BOARD_HEIGHT; i++) {
        for(int j = 0; j < BOARD_WIDTH; j++) {
            if(board[i][j] == 0) {
                printf(" ");
            } else if(board[i][j] == 1) {
                printf("#");
            } else if(board[i][j] == 2) {
                printf("=");
            } else if(board[i][j] == 3) {
                printf("O");
            }
        }
        printf("\n");
    }
}

void move_paddle(int direction) {
    paddle_pos += direction;
    if(paddle_pos < 0) {
        paddle_pos = 0;
    } else if(paddle_pos > BOARD_WIDTH - PADDLE_WIDTH) {
        paddle_pos = BOARD_WIDTH - PADDLE_WIDTH;
    }
}

void move_ball() {
    ball_pos_x += ball_vel_x;
    ball_pos_y += ball_vel_y;

    // Check for collision with brick
    if(ball_pos_y >= 0 && ball_pos_y < BOARD_HEIGHT) {
        if(board[ball_pos_y][ball_pos_x] == 1) {
            board[ball_pos_y][ball_pos_x] = 0;
            bricks_left--;
            score += 10;
            ball_vel_y = -ball_vel_y;
        }
    }

    // Check for collision with paddle
    if(ball_pos_y == BOARD_HEIGHT - 1) {
        if(ball_pos_x >= paddle_pos && ball_pos_x < paddle_pos + PADDLE_WIDTH) {
            ball_vel_y = -ball_vel_y;
        } else {
            lives--;
            if(lives == 0) {
                printf("\nGAME OVER!\n");
                exit(0);
            }
            ball_pos_x = BOARD_WIDTH / 2;
            ball_pos_y = BOARD_HEIGHT - 2;
            ball_vel_x = 1;
            ball_vel_y = -1;
            draw_board();
        }
    }

    // Check for collision with walls
    if(ball_pos_x < 0 || ball_pos_x >= BOARD_WIDTH) {
        ball_vel_x = -ball_vel_x;
    }
    if(ball_pos_y < 0) {
        ball_vel_y = -ball_vel_y;
    }
}

void init_board() {
    for(int i = 0; i < BRICK_COUNT; i++) {
        int x = i % BOARD_WIDTH;
        int y = i / BOARD_WIDTH;
        board[y][x] = 1;
    }
    for(int i = 0; i < PADDLE_WIDTH; i++) {
        board[BOARD_HEIGHT - 1][paddle_pos + i] = 2;
    }
    board[ball_pos_y][ball_pos_x] = 3;
}

int main() {
    init_board();
    draw_board();

    while(bricks_left > 0) {
        int input = getchar();
        if(input == 'q') {
            printf("\nQUITTING...\n");
            exit(0);
        }
        int direction = 0;
        if(input == 'a') {
            direction = -1;
        } else if(input == 'd') {
            direction = 1;
        }
        move_paddle(direction);
        move_ball();
        board[ball_pos_y][ball_pos_x] = 3;
        draw_board();
    }
    printf("\nYOU WIN!!!\n");
    return 0;
}