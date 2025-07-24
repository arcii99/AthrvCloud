//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

/* set terminal to non-canonical input mode */
void set_terminal_mode() {
    struct termios term;
    tcgetattr(0, &term);
    term.c_lflag &= ~ICANON;
    term.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &term);
}

/* reset terminal input mode */
void reset_terminal_mode() {
    struct termios term;
    tcgetattr(0, &term);
    term.c_lflag |= ICANON;
    term.c_lflag |= ECHO;
    tcsetattr(0, TCSANOW, &term);
}

/* game variables */
int ball_x, ball_y, ball_velocity_x, ball_velocity_y;
int paddle1_x, paddle1_y, paddle2_x, paddle2_y, paddle2_velocity_y;
int score1, score2;

/* initialize game */
void init_game() {
    score1 = 0;
    score2 = 0;
    ball_x = 30;
    ball_y = 10;
    if (rand() % 2 == 0)
        ball_velocity_x = -1;
    else
        ball_velocity_x = 1;
    ball_velocity_y = 1;
    paddle1_x = 3;
    paddle1_y = 8;
    paddle2_x = 58;
    paddle2_y = 8;
    paddle2_velocity_y = 0;
}

/* draw game board */
void draw_board() {
    int i, j;
    system("clear");
    for (i = 0; i < 60; i++)
        printf("#");
    printf("\n");
    for (i = 1; i < 20; i++) {
        for (j = 0; j < 60; j++) {
            if (j == 0 || j == 59)
                printf("#");
            else if (ball_x == j && ball_y == i)
                printf("*");
            else if (paddle1_x == j && paddle1_y == i)
                printf("|");
            else if (paddle2_x == j && paddle2_y == i)
                printf("|");
            else
                printf(" ");
        }
        printf("\n");
    }
    for (i = 0; i < 60; i++)
        printf("#");
    printf("\n");
}

/* update ball position */
void update_ball() {
    ball_x += ball_velocity_x;
    ball_y += ball_velocity_y;
    if (ball_x == 1 || ball_x == 58) {
        if (ball_y >= paddle1_y && ball_y <= paddle1_y + 2) {
            ball_velocity_x *= -1;
        } else if (ball_y >= paddle2_y && ball_y <= paddle2_y + 2) {
            ball_velocity_x *= -1;
        } else if (ball_x == 1) {
            score2++;
            init_game();
        } else if (ball_x == 58) {
            score1++;
            init_game();
        }
    }
    if (ball_y == 0 || ball_y == 19)
        ball_velocity_y *= -1;
}

/* update paddle 1 position */
void update_paddle1(char c) {
    if (c == 'w') {
        if (paddle1_y > 1) {
            paddle1_y--;
        }
    } else if (c == 's') {
        if (paddle1_y < 16) {
            paddle1_y++;
        }
    }
}

/* update paddle 2 position with AI */
void update_paddle2() {
    if (ball_y > paddle2_y + 2) {
        paddle2_velocity_y = 1;
    } else if (ball_y < paddle2_y) {
        paddle2_velocity_y = -1;
    } else {
        paddle2_velocity_y = 0;
    }
    if (paddle2_y + paddle2_velocity_y > 0 && paddle2_y + paddle2_velocity_y < 17) {
        paddle2_y += paddle2_velocity_y;
    }
}

int main() {
    set_terminal_mode();
    init_game();
    while (1) {
        draw_board();
        update_ball();
        if (ball_y >= paddle1_y && ball_y <= paddle1_y + 2 && ball_x == paddle1_x + 1) {
            ball_velocity_x *= -1;
        } else if (ball_y >= paddle2_y && ball_y <= paddle2_y + 2 && ball_x == paddle2_x - 1) {
            ball_velocity_x *= -1;
        }
        if (score1 == 11) {
            printf("Player 1 Wins!\n");
            break;
        } else if (score2 == 11) {
            printf("Player 2 Wins!\n");
            break;
        }
        char c;
        if (read(0, &c, 1) == 1) {
            update_paddle1(c);
        }
        update_paddle2();
        usleep(50000);
    }
    reset_terminal_mode();
    return 0;
}