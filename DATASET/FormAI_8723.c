//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define MAX_BALL_SPEED 3
#define PADDLE_WIDTH 5
#define PADDLE_HEIGHT 1
#define BRICK_WIDTH 6
#define BRICK_HEIGHT 2

int ball_x, ball_y, ball_x_direction, ball_y_direction, ball_speed;
int paddle_x, paddle_y;
int lives, score;
int bricks_left;
char screen[30][80];
char empty_screen[30][80];

void setup()
{
    int i, j;
    for (i = 0; i < 30; i++) {
        for (j = 0; j < 80; j++) {
            empty_screen[i][j] = ' ';
        }
    }
    ball_x = 39;
    ball_y = 15;
    ball_x_direction = rand() % 2 ? -1 : 1;
    ball_y_direction = -1;
    ball_speed = 1;
    paddle_x = 37;
    paddle_y = 28;
    lives = 3;
    score = 0;
    bricks_left = 0;
    for (i = 4; i < 10; i++) {
        for (j = 9; j < 70; j += BRICK_WIDTH + 1) {
            int brick_type = rand() % 3;
            char brick_char;
            switch (brick_type) {
                case 0:
                    brick_char = 'O';
                    break;
                case 1:
                    brick_char = 'X';
                    break;
                case 2:
                    brick_char = '#';
                    break;
            }
            int k, l;
            for (k = 0; k < BRICK_HEIGHT; k++) {
                for (l = 0; l < BRICK_WIDTH; l++) {
                    screen[i + k][j + l] = brick_char;
                }
            }
            bricks_left++;
        }
    }
}

void draw()
{
    int i, j;
    printf("\033[2J");
    for (i = 0; i < 30; i++) {
        for (j = 0; j < 80; j++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
    printf("\nLives: %d      Score: %d\n", lives, score);
    printf("Use the arrow keys to move the paddle.\n");
}

void input()
{
    int c = 0;
    struct termios old = {0};
    fflush(stdout);
    if (tcgetattr(0, &old) < 0) {
        perror("tcsetattr()");
    }
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(STDIN_FILENO, TCSANOW, &old) < 0) {
        perror("tcsetattr ICANON");
    }
    c = getchar();
    if (tcsetattr(STDIN_FILENO, TCSANOW, &old) < 0) {
        perror("tcsetattr ~ICANON");
    }
    switch(c) {
        case 68:
            paddle_x--;
            if (paddle_x < 0) {
                paddle_x = 0;
            }
            break;
        case 67:
            paddle_x++;
            if (paddle_x > 73) {
                paddle_x = 73;
            }
            break;
    }
}

void move_ball()
{
    ball_x += ball_x_direction * ball_speed;
    ball_y += ball_y_direction * ball_speed;
    if (ball_y == 0 || (ball_y == paddle_y - 1 && ball_x >= paddle_x && ball_x < paddle_x + PADDLE_WIDTH)) {
        ball_y_direction = 1;
        ball_speed++;
        if (ball_speed > MAX_BALL_SPEED) {
            ball_speed = MAX_BALL_SPEED;
        }
    }
    if (ball_x == 0 || ball_x == 79) {
        ball_x_direction = -ball_x_direction;
    }
    if (ball_y == 29) {
        lives--;
        if (lives == 0) {
            printf("\033[2J\033[H");
            printf("Game Over\n");
            printf("You scored %d points.\n", score);
            exit(0);
        }
        ball_x = 39;
        ball_y = 15;
        ball_x_direction = rand() % 2 ? -1 : 1;
        ball_y_direction = -1;
        ball_speed = 1;
        paddle_x = 37;
    }
    int i, j;
    for (i = 4; i < 10; i++) {
        for (j = 9; j < 70; j++) {
            if (screen[i][j] != ' ' && ball_x >= j && ball_x < j + BRICK_WIDTH && ball_y >= i && ball_y < i + BRICK_HEIGHT) {
                if (ball_x == j || ball_x == j + BRICK_WIDTH - 1) {
                    ball_x_direction = -ball_x_direction;
                }
                if (ball_y == i || ball_y == i + BRICK_HEIGHT - 1) {
                    ball_y_direction = -ball_y_direction;
                }
                score += 10;
                bricks_left--;
                int k, l;
                for (k = 0; k < BRICK_HEIGHT; k++) {
                    for (l = 0; l < BRICK_WIDTH; l++) {
                        screen[i + k][j + l] = ' ';
                    }
                }
                if (bricks_left == 0) {
                    printf("\033[2J\033[H");
                    printf("You win!\n");
                    printf("You scored %d points.\n", score);
                    exit(0);
                }
            }
        }
    }
}

int main()
{
    struct timespec tim, tim2;
    tim.tv_sec = 0;
    tim.tv_nsec = 50000000L;
    srand(time(NULL));
    setup();
    while (1) {
        memcpy(screen, empty_screen, sizeof(char) * 30 * 80);
        move_ball();
        int i, j;
        for (i = 0; i < PADDLE_HEIGHT; i++) {
            for (j = 0; j < PADDLE_WIDTH; j++) {
                screen[paddle_y + i][paddle_x + j] = '=';
            }
        }
        screen[ball_y][ball_x] = '0';
        draw();
        input();
        nanosleep(&tim , &tim2);
    }
    return 0;
}