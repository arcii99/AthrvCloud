//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <string.h>
#include <signal.h>
#include <time.h>

struct Paddle {
    int y;
    int x;
    int length;
    char symbol;
};

struct Ball {
    int y;
    int x;
    int ydir;
    int xdir;
    int speed;
    char symbol;
};

struct AI {
    int difficulty;
    int ydistance;
    int ypos;
    struct Paddle *paddle;
};

int cols, rows;  // dimensions of the terminal
int score_left = 0, score_right = 0;  // scores of left and right players
struct Paddle paddle_left, paddle_right;  // paddles of left and right players
struct Ball ball;  // the ball object
struct AI ai;  // the AI opponent object
int quit_flag = 0;  // flag for quitting the game 

void reset_ball(int); // function for resetting the ball
void init_paddles();  // function for initializing the paddles
void init_ball();  // function for initializing the ball
void init_ai();  // function for initializing the AI
void move_ball();  // function for moving the ball
void move_paddle(struct Paddle *, int);  // function for moving a paddle
void move_ai();  // function for moving the AI
void draw_border();  // function for drawing the border of the game
void draw_paddle(struct Paddle *);  // function for drawing a paddle
void draw_ball();  // function for drawing the ball
void draw_score();  // function for drawing the score
void handle_collision(struct Paddle *);  // function for handling collisions between ball and paddle
void handle_ai_collision();  // function for handling collisions between ball and AI paddle
void handle_signal(int);  // signal handler function for quitting the game

int main() {

    struct termios term, term_orig;
    ioctl(0, TCGETS, &term);
    term_orig = term;
    term.c_cc[VMIN] = 0;
    term.c_cc[VTIME] = 0;
    ioctl(0, TCSETS, &term);

    signal(SIGINT, handle_signal);
    signal(SIGABRT, handle_signal);
    signal(SIGTERM, handle_signal);

    // get dimensions of the terminal
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    cols = w.ws_col;
    rows = w.ws_row - 1;

    // initialize paddles, ball, and AI
    init_paddles();
    init_ball();
    init_ai();

    while (!quit_flag) {
        // clear screen
        printf("\033[2J");
        // move ball
        move_ball();
        // move AI
        move_ai();
        // draw game elements
        draw_border();
        draw_paddle(&paddle_left);
        draw_paddle(&paddle_right);
        draw_ball();
        draw_score();
        usleep(1000000 / 60);  // wait for 1/60th of a second
    }

    ioctl(0, TCSETS, &term_orig);
    printf("\033[2J");
    printf("\033[%d;%dH", rows/2, (cols-strlen("GAME OVER"))/2);
    printf("GAME OVER\n");

    return 0;
}

void reset_ball(int player) {
    ball.x = cols/2;
    ball.y = rows/2;
    ball.xdir = (player == 1) ? -1 : 1;
    ball.ydir = 1;
    ball.speed = 1;
}

void init_paddles() {
    paddle_left.x = 2;
    paddle_left.y = rows/2;
    paddle_left.length = 5;
    paddle_left.symbol = '|';

    paddle_right.x = cols - 3;
    paddle_right.y = rows/2;
    paddle_right.length = 5;
    paddle_right.symbol = '|';
}

void init_ball() {
    reset_ball(1);
    ball.symbol = '*';
}

void init_ai() {
    ai.difficulty = 2;
    ai.ydistance = 1;
    ai.ypos = rows/2;
    ai.paddle = &paddle_right;
}

void move_ball() {
    // update position
    ball.x += ball.xdir * ball.speed;
    ball.y += ball.ydir * ball.speed;
    // check for collisions with walls
    if (ball.y == 0 || ball.y == rows - 1) {
        ball.ydir *= -1;
    }
    // check for collision with left paddle
    if (ball.x == paddle_left.x + 1 && ball.y >= paddle_left.y && ball.y <= paddle_left.y + paddle_left.length - 1) {
        handle_collision(&paddle_left);
    }
    // check for collision with right paddle
    if (ball.x == paddle_right.x - 1 && ball.y >= paddle_right.y && ball.y <= paddle_right.y + paddle_right.length - 1) {
        handle_collision(&paddle_right);
    }
    // check for scoring
    if (ball.x == 0) {
        score_right++;
        reset_ball(2);
    }
    if (ball.x == cols - 1) {
        score_left++;
        reset_ball(1);
    }
}

void move_paddle(struct Paddle *paddle, int direction) {
    if (paddle->y <= 1 && direction == -1) {
        return;
    }
    if (paddle->y + paddle->length >= rows - 1 && direction == 1) {
        return;
    }
    paddle->y += direction;
}

void move_ai() {
    // calculate distance to ball
    ai.ydistance = ball.y - ai.ypos;
    // move paddle towards ball
    if (abs(ai.ydistance) > ai.difficulty) {
        move_paddle(ai.paddle, ai.ydistance > 0 ? 1 : -1);
    }
}

void draw_border() {
    int i, j;
    for (i = 0; i <= rows - 1; i++) {
        printf("\033[%d;%dH", i + 1, 1);
        printf("|");
        printf("\033[%d;%dH", i + 1, cols);
        printf("|");
    }
    for (j = 2; j <= cols - 1; j++) {
        printf("\033[%d;%dH", 1, j);
        printf("-");
        printf("\033[%d;%dH", rows, j);
        printf("-");
    }
}

void draw_paddle(struct Paddle *paddle) {
    int i;
    for (i = 0; i < paddle->length; i++) {
        printf("\033[%d;%dH", paddle->y + i, paddle->x);
        printf("%c", paddle->symbol);
    }
}

void draw_ball() {
    printf("\033[%d;%dH", ball.y, ball.x);
    printf("%c", ball.symbol);
}

void draw_score() {
    printf("\033[%d;%dH", rows + 1, 1);
    printf("Player 1: %d", score_left);
    printf("\033[%d;%dH", rows + 1, cols - 10);
    printf("Player 2: %d", score_right);
}

void handle_collision(struct Paddle *paddle) {
    // calculate where the ball hit the paddle
    int hit_offset = ball.y - paddle->y - paddle->length/2;
    // calculate new direction for the ball
    ball.xdir *= -1;
    ball.ydir = hit_offset / ((float) paddle->length/2) * 2;
    ball.speed++;
}

void handle_ai_collision() {
    // calculate where the ball hit the paddle
    int hit_offset = ball.y - paddle_right.y - paddle_right.length/2;
    // calculate new direction for the ball
    ball.xdir *= -1;
    ball.ydir = hit_offset / ((float) paddle_right.length/2) * 2;
    ball.speed++;
}

void handle_signal(int signal) {
    quit_flag = 1;
}