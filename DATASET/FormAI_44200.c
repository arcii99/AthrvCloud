//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40
#define BRICK_ROWS 5
#define BRICK_COLS 10

char screen[ROWS][COLS] = {0};
char paddle[3] = {'=', '=', '='};
char ball = 'o';
int paddle_position = (COLS - 3) / 2;
int ball_row = ROWS - 2;
int ball_col = (COLS - 3) / 2;
int ball_direction_row = -1;
int ball_direction_col = 1;
int bricks[BRICK_ROWS][BRICK_COLS] = {0};

void clear_screen() {
    system("clear");
}

void display_screen() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
}

void init_bricks() {
    for(int i = 0; i < BRICK_ROWS; i++) {
        for(int j = 0; j < BRICK_COLS; j++) {
            bricks[i][j] = 1;
        }
    }
}

void draw_paddle() {
    for(int i = 0; i < 3; i++) {
        screen[ROWS - 1][paddle_position + i] = paddle[i];   
    }
}

void draw_ball() {
    screen[ball_row][ball_col] = ball;
}

void move_paddle_left() {
    if(paddle_position - 1 >= 0) {
        paddle_position--;
    }
}

void move_paddle_right() {
    if(paddle_position + 3 <= COLS) {
        paddle_position++;
    }
}

void move_ball() {
    screen[ball_row][ball_col] = ' ';
    ball_row += ball_direction_row;
    ball_col += ball_direction_col;
    if(ball_row == ROWS - 2) {
        if(ball_col >= paddle_position && ball_col <= paddle_position + 2) {
            ball_direction_row = -1;
        } else {
            ball_direction_row = 1;
            ball_row = ROWS - 2;
            ball_col = (COLS - 3) / 2;
            paddle_position = (COLS - 3) / 2;
        }
    }
    if(ball_row == 0) {
        ball_direction_row = 1;
    }
    if(ball_col == COLS - 1) {
        ball_direction_col = -1;
    }
    if(ball_col == 0) {
        ball_direction_col = 1;
    }
    if(ball_row < BRICK_ROWS && ball_col < BRICK_COLS && bricks[ball_row][ball_col]) {
        bricks[ball_row][ball_col] = 0;
        ball_direction_row = -ball_direction_row;
    }
}

void draw_bricks() {
    for(int i = 0; i < BRICK_ROWS; i++) {
        for(int j = 0; j < BRICK_COLS; j++) {
            if(bricks[i][j]) {
                screen[i][j * 4] = '[';
                screen[i][j * 4 + 1] = ']';
                screen[i][j * 4 + 2] = '[';
                screen[i][j * 4 + 3] = ']';
            } else {
                screen[i][j * 4] = ' ';
                screen[i][j * 4 + 1] = ' ';
                screen[i][j * 4 + 2] = ' ';
                screen[i][j * 4 + 3] = ' ';
            }
        }
    }
}

int main() {
    clear_screen();
    init_bricks();
    while(1) {
        clear_screen();
        draw_bricks();
        draw_paddle();
        draw_ball();
        display_screen();
        move_ball();
        char c = getchar();
        if(c == 'a') {
            move_paddle_left();
        } else if(c == 'd') {
            move_paddle_right();
        } else if(c == 'q') {
            return 0;
        }
    }
    return 0;
}