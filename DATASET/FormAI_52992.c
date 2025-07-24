//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 60
#define HEIGHT 20
#define PADDLE_LENGTH 5
#define BRICK_COUNT 60

struct termios old_settings, new_settings;

// Move cursor to row, col in terminal
void moveCursor(int row, int col) {
    printf("\033[%d;%dH", row, col);
}

// Switch terminal to raw mode
void setTermRawMode(void) {
    tcgetattr(0, &old_settings);
    new_settings = old_settings;
    new_settings.c_lflag &= (~ICANON & ~ECHO);
    new_settings.c_cc[VTIME] = 0;
    new_settings.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &new_settings);
    fcntl(0, F_SETFL, O_NONBLOCK);
}

// Switch terminal back to normal mode
void setTermNormalMode(void) {
    tcsetattr(0, TCSANOW, &old_settings);
    fcntl(0, F_SETFL, fcntl(0, F_GETFL, 0) & ~O_NONBLOCK);
}

// Draw the paddle at row and column positions
void drawPaddle(int row, int col) {
    int i;
    for (i = 0; i < PADDLE_LENGTH; i++) {
        moveCursor(row+i, col);
        printf("|");
    }
}

// Move the paddle up or down based on user input
int movePaddle(int row, int col, int dir) {
    int i;
    if (dir == -1 && row > 0) {
        for (i = 0; i < PADDLE_LENGTH; i++) {
            moveCursor(row+i, col);
            printf(" ");
        }
        return --row;
    }
    else if (dir == 1 && row+PADDLE_LENGTH < HEIGHT) {
        for (i = 0; i < PADDLE_LENGTH; i++) {
            moveCursor(row+i, col);
            printf(" ");
        }
        return ++row;
    }
    else {
        return row;
    }
}

// Draw the ball at row and column position
void drawBall(int row, int col) {
    moveCursor(row, col);
    printf("o");
}

// Check for collision with paddle
bool checkPaddleHit(int ball_row, int ball_col, int paddle_row, int paddle_col) {
    if (ball_row >= paddle_row && ball_row < paddle_row+PADDLE_LENGTH && ball_col == paddle_col) {
        return true;
    }
    else {
        return false;
    }
}

// Check for collision with bricks
int checkBrickHit(int ball_row, int ball_col, int* brick_rows, int* brick_cols, bool* brick_hit) {
    int i;
    for (i = 0; i < BRICK_COUNT; i++) {
        if (ball_row == brick_rows[i] && ball_col == brick_cols[i] && !brick_hit[i]) {
            brick_hit[i] = true;
            return 1;
        }
    }
    return 0;
}

int main() {
    setTermRawMode();
    srand(time(0));

    // Initialize variables
    int paddle_col = 5;
    int paddle_row = HEIGHT/2;
    int ball_col = WIDTH/2;
    int ball_row = paddle_row-1;
    int ball_row_delta = -1;
    int ball_col_delta = 1;
    int points = 0;
    int dir = 0;
    int i, j;

    int brick_rows[BRICK_COUNT];
    int brick_cols[BRICK_COUNT];
    bool brick_hit[BRICK_COUNT];

    // Initialize bricks
    for (i = 0; i < BRICK_COUNT; i++) {
        brick_rows[i] = i/10+1;
        brick_cols[i] = i%10+10;
        brick_hit[i] = false;
    }

    // Main Game Loop
    while(true) {
        // Draw paddle, ball, and bricks
        drawPaddle(paddle_row, paddle_col);
        drawBall(ball_row, ball_col);
        for (i = 0; i < BRICK_COUNT; i++) {
            if (!brick_hit[i]) {
                moveCursor(brick_rows[i], brick_cols[i]);
                printf("#");
            }
        }

        // Calculate new ball position
        int new_ball_row = ball_row + ball_row_delta;
        int new_ball_col = ball_col + ball_col_delta;

        // Check for collision with paddle, change direction
        if (checkPaddleHit(new_ball_row, new_ball_col, paddle_row, paddle_col)) {
            ball_col_delta *= -1;
            points += 10;
        }

        // Check for collision with bricks, change direction and update score
        points += checkBrickHit(new_ball_row, new_ball_col, brick_rows, brick_cols, brick_hit)*100;
        if (points == BRICK_COUNT*100) { // all bricks hit
            break;
        }

        // Check for out-of-bounds, change direction
        if (new_ball_row < 1 || new_ball_row > HEIGHT-1) {
            ball_row_delta *= -1;
        }
        if (new_ball_col < 1 || new_ball_col > WIDTH-1) {
            ball_col_delta *= -1;
        }

        // Erase old ball position
        moveCursor(ball_row, ball_col);
        printf(" ");

        // Update ball position
        ball_row += ball_row_delta;
        ball_col += ball_col_delta;

        // Move paddle up/down based on user input
        char c;
        read(0, &c, 1);
        switch(c) {
            case 'w':
                dir = -1;
                break;
            case 's':
                dir = 1;
                break;
            case 'q':
                setTermNormalMode();
                printf("\n");
                return 0;
        }
        paddle_row = movePaddle(paddle_row, paddle_col, dir);
        dir = 0;

        // Draw score
        moveCursor(1,1);
        printf("Points: %d", points);

        usleep(100000); // delay for smoother animation    
    }

    // Game end
    setTermNormalMode();
    printf("\nCongratulations! You Won.\n");
    return 0;
}