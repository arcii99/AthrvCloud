//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>

#define HEIGHT 25
#define WIDTH 80
#define BALL_SPEED 10000

int kbhit(void);

int main()
{
    char screen[HEIGHT][WIDTH];
    int x_pos = WIDTH / 2;
    int y_pos = HEIGHT / 2;
    int ball_x_pos = x_pos - 1;
    int ball_y_pos = y_pos;
    int ball_motion_x = 1;
    int ball_motion_y = 1;
    int left_paddle_pos = HEIGHT / 2 - 2;
    int right_paddle_pos = HEIGHT / 2 - 2;
    int left_score = 0;
    int right_score = 0;
    int i, j;
    int ai_difficulty = 0; 
    int ai_y_pos;
    srand(time(NULL));
    memset(screen, ' ', sizeof(screen)); // initialize screen array with spaces

    // prepare screen borders
    for (i = 0; i < HEIGHT; i++) {
        screen[i][0] = '|';
        screen[i][WIDTH - 1] = '|';
    }
    for (i = 0; i < WIDTH; i++) {
        screen[0][i] = '-';
        screen[HEIGHT - 1][i] = '-';
    }
    // prepare ball and paddles
    screen[y_pos][x_pos] = 'O';
    for (i = left_paddle_pos; i < left_paddle_pos + 5; i++) {
        screen[i][2] = '|';
    }
    for (i = right_paddle_pos; i < right_paddle_pos + 5; i++) {
        screen[i][WIDTH - 3] = '|';
    }

    // game loop
    while (1) {
        // update ball position
        screen[ball_y_pos][ball_x_pos] = ' ';
        if (ball_x_pos == 2 && ball_y_pos >= left_paddle_pos && ball_y_pos <= left_paddle_pos + 4) { // left paddle collision
            ball_motion_x = 1;
            if (ball_y_pos == left_paddle_pos || ball_y_pos == left_paddle_pos + 4) {
                ball_motion_y = -1;
            } else if (ball_y_pos == left_paddle_pos + 1 || ball_y_pos == left_paddle_pos + 3) {
                ball_motion_y = 0;
            } else if (ball_y_pos == left_paddle_pos + 2) {
                ball_motion_y = 1;
            }
        } else if (ball_x_pos == WIDTH - 3 && ball_y_pos >= right_paddle_pos && ball_y_pos <= right_paddle_pos + 4) { // right paddle collision
            ball_motion_x = -1;
            if (ball_y_pos == right_paddle_pos || ball_y_pos == right_paddle_pos + 4) {
                ball_motion_y = -1;
            } else if (ball_y_pos == right_paddle_pos + 1 || ball_y_pos == right_paddle_pos + 3) {
                ball_motion_y = 0;
            } else if (ball_y_pos == right_paddle_pos + 2) {
                ball_motion_y = 1;
            }
        } else if (ball_x_pos == 1) { // right side wins
            right_score++;
            if (right_score >= 10) { // game over
                printf("Right side wins!\n");
                break;
            }
            ball_x_pos = x_pos - 1;
            ball_y_pos = y_pos;
            ball_motion_x = 1;
            ball_motion_y = 1;
        } else if (ball_x_pos == WIDTH - 2) { // left side wins
            left_score++;
            if (left_score >= 10) { // game over
                printf("Left side wins!\n");
                break;
            }
            ball_x_pos = x_pos - 1;
            ball_y_pos = y_pos;
            ball_motion_x = -1;
            ball_motion_y = 1;
        }
        ball_x_pos += ball_motion_x;
        ball_y_pos += ball_motion_y;
        screen[ball_y_pos][ball_x_pos] = 'O';
        // update left paddle position
        if (kbhit()) {
            char key = getchar();
            if (key == 'w' && left_paddle_pos > 1) {
                left_paddle_pos--;
            } else if (key == 's' && left_paddle_pos < HEIGHT - 6) {
                left_paddle_pos++;
            }
        }

        // update right paddle (AI)
        if (ai_difficulty == 0) {
            ai_y_pos = ball_y_pos - 2;
        } else if (ai_difficulty == 1) {
            if (rand() % 2 == 0) {
                ai_y_pos = ball_y_pos - 2;
            } else {
                if (ball_y_pos > right_paddle_pos + 2 && right_paddle_pos < HEIGHT - 6) {
                    ai_y_pos = right_paddle_pos + 1;
                } else if (ball_y_pos < right_paddle_pos + 2 && right_paddle_pos > 1) {
                    ai_y_pos = right_paddle_pos - 1;
                } else {
                    ai_y_pos = right_paddle_pos;
                }
            }
        } else if (ai_difficulty == 2) {
            if (ball_motion_x == 1) {
                if (ball_y_pos > right_paddle_pos + 2 && right_paddle_pos < HEIGHT - 6) {
                    ai_y_pos = right_paddle_pos + 1;
                } else if (ball_y_pos < right_paddle_pos + 2 && right_paddle_pos > 1) {
                    ai_y_pos = right_paddle_pos - 1;
                } else {
                    ai_y_pos = right_paddle_pos;
                }
            } else {
                if (right_paddle_pos < HEIGHT / 2) {
                    ai_y_pos = right_paddle_pos + 1;
                } else if (right_paddle_pos > HEIGHT / 2) {
                    ai_y_pos = right_paddle_pos - 1;
                } else {
                    ai_y_pos = right_paddle_pos;
                }
            }
        }        // update screen
        for (i = 0; i < HEIGHT; i++) {
            for (j = 0; j < WIDTH; j++) {
                putchar(screen[i][j]);
            }
            putchar('\n');
        }
        printf("Left side score: %d  Right side score: %d", left_score, right_score);
        usleep(BALL_SPEED);
        system("clear");
        // update right paddle position
        right_paddle_pos = ai_y_pos;
        for (i = right_paddle_pos; i < right_paddle_pos + 5; i++) {
            screen[i][WIDTH - 3] = '|';
        }    
    }
    return 0;
}

// detect keyboard input
int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}