//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#define PADDLE_SIZE 4
#define PADDLE_LEFT 2
#define PADDLE_RIGHT 77
#define PADDLE_STEP 5
#define BALL_INIT_X 39
#define BALL_INIT_Y 10
#define BALL_STEP_X 2
#define BALL_STEP_Y 1

int paddle_left_y, paddle_right_y, ball_x, ball_y, ball_step_x, ball_step_y, left_score, right_score;

struct termios original_termios;

void disable_raw_input_mode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_termios);
}

void enable_raw_input_mode() {
    tcgetattr(STDIN_FILENO, &original_termios);
    atexit(disable_raw_input_mode);
    struct termios raw_termios = original_termios;
    raw_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw_termios);
}

int is_key_pressed() {
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);
    struct timeval timeout = { 0, 0 };
    return select(1, &read_fds, NULL, NULL, &timeout) != 0;
}

void move_left_paddle(int step) {
    if (paddle_left_y + step >= PADDLE_SIZE && paddle_left_y + step <= 21 - PADDLE_SIZE)
        paddle_left_y += step;
}

void move_right_paddle(int step) {
    if (paddle_right_y + step >= PADDLE_SIZE && paddle_right_y + step <= 21 - PADDLE_SIZE)
        paddle_right_y += step;
}

int get_ball_next_x() {
    return ball_x + ball_step_x;
}

int get_ball_next_y() {
    return ball_y + ball_step_y;
}

void move_ball() {
    int next_x = get_ball_next_x();
    int next_y = get_ball_next_y();
    if (next_x < PADDLE_LEFT || next_x > PADDLE_RIGHT) {
        if (next_x < PADDLE_LEFT)
            right_score++;
        else
            left_score++;
        ball_x = BALL_INIT_X;
        ball_y = BALL_INIT_Y;
        ball_step_x = BALL_STEP_X;
        ball_step_y = BALL_STEP_Y;
    } else if (next_y < 1 || next_y > 19) {
        ball_step_y = -ball_step_y;
    } else if (next_x <= PADDLE_LEFT + 1 && next_y >= paddle_left_y - PADDLE_SIZE && next_y <= paddle_left_y + PADDLE_SIZE) {
        ball_step_x = BALL_STEP_X;
        ball_step_y = (next_y - paddle_left_y) / 3;
    } else if (next_x >= PADDLE_RIGHT - 1 && next_y >= paddle_right_y - PADDLE_SIZE && next_y <= paddle_right_y + PADDLE_SIZE) {
        ball_step_x = -BALL_STEP_X;
        ball_step_y = (next_y - paddle_right_y) / 3;
    } else {
        ball_x = next_x;
        ball_y = next_y;
    }
}

void draw_frame() {
    printf("\033[H\033[J");
    for (int i = 0; i < 22; i++) {
        for (int j = 0; j < 80; j++) {
            if (i == 0 || i == 20)
                printf("-");
            else if (j == 0 || j == 79)
                printf("|");
            else if (i == ball_y && j == ball_x)
                printf("O");
            else if (j == PADDLE_LEFT && (i >= paddle_left_y - PADDLE_SIZE && i <= paddle_left_y + PADDLE_SIZE))
                printf("|");
            else if (j == PADDLE_RIGHT && (i >= paddle_right_y - PADDLE_SIZE && i <= paddle_right_y + PADDLE_SIZE))
                printf("|");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("Score: %d-%d", left_score, right_score);
    fflush(stdout);
}

void computer_move(int paddle) {
    if (ball_step_x > 0 && ball_x > 40) {
        if (paddle < ball_y)
            move_right_paddle(PADDLE_STEP);
        else if (paddle > ball_y)
            move_right_paddle(-PADDLE_STEP);
    } else {
        if (paddle < 10)
            move_right_paddle(PADDLE_STEP);
        else if (paddle > 10)
            move_right_paddle(-PADDLE_STEP);
    }
}

int main() {
    srand(time(NULL));
    enable_raw_input_mode();
    atexit(disable_raw_input_mode);
    paddle_left_y = paddle_right_y = 10;
    ball_x = BALL_INIT_X;
    ball_y = BALL_INIT_Y;
    left_score = right_score = 0;
    ball_step_x = BALL_STEP_X;
    ball_step_y = BALL_STEP_Y;
    while (1) {
        draw_frame();
        if (is_key_pressed()) {
            char c = getchar();
            if (c == 'i')
                move_left_paddle(-PADDLE_STEP);
            else if (c == 'k')
                move_left_paddle(PADDLE_STEP);
            else if (c == 'q')
                break;
        }
        computer_move(paddle_right_y);
        move_ball();
        usleep(50000);
    }
    return 0;
}