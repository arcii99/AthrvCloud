//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define ROWS 30
#define COLS 80

// Game board
int board[ROWS][COLS];

// Paddle variables
int paddle_x;
int paddle_y;

// Ball variables
int ball_x;
int ball_y;
int dx;
int dy;

// Brick variables
int num_bricks;
int bricks[ROWS][COLS];

// Input variables
struct termios initial_settings, new_settings;
int peek_char = -1;

// Function to initialize terminal settings to enable non-blocking input
void init_terminal() {
    tcgetattr(STDIN_FILENO, &initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_lflag &= ~ISIG;
    new_settings.c_cc[VMIN] = 0;
    new_settings.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
}

// Function to reset terminal settings to original settings
void reset_terminal() {
    tcsetattr(STDIN_FILENO, TCSANOW, &initial_settings);
}

// Function to read input character without blocking
int kbhit() {
    char ch;
    int nread;
    if (peek_char != -1) {
        return 1;
    }
    new_settings.c_cc[VMIN] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
    nread = read(STDIN_FILENO, &ch, 1);
    new_settings.c_cc[VMIN] = 1;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
    if (nread == 1) {
        peek_char = ch;
        return 1;
    }
    return 0;
}

// Function to get input character
int getch() {
    char ch;
    if (peek_char != -1) {
        ch = peek_char;
        peek_char = -1;
        return ch;
    }
    read(STDIN_FILENO, &ch, 1);
    return ch;
}

// Function to initialize game board
void init_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS-1 || j == 0 || j == COLS-1) {
                board[i][j] = 1;
            } else {
                board[i][j] = 0;
            }
        }
    }
}

// Function to print game board
void print_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                printf(" ");
            } else if (board[i][j] == 1) {
                printf("#");
            } else if (board[i][j] == 2) {
                printf("-");
            } else if (board[i][j] == 3) {
                printf("*");
            }
        }
        printf("\n");
    }
}

// Function to initialize paddle and ball positions
void init_paddle_ball() {
    paddle_x = COLS/2 - 5;
    paddle_y = ROWS - 2;
    ball_x = COLS/2;
    ball_y = ROWS - 3;
    dx = -1;
    dy = -1;
}

// Function to print paddle
void print_paddle() {
    int i;
    for (i = 0; i < 10; i++) {
        board[paddle_y][paddle_x+i] = 2;
    }
}

// Function to print ball
void print_ball() {
    board[ball_y][ball_x] = 3;
}

// Function to move paddle to left
void move_paddle_left() {
    if (paddle_x > 1) {
        paddle_x--;
    }
}

// Function to move paddle to right
void move_paddle_right() {
    if (paddle_x < COLS-11) {
        paddle_x++;
    }
}

// Function to move ball
void move_ball() {
    int x, y;
    x = ball_x + dx;
    y = ball_y + dy;
    if (x == 0 || x == COLS-1) {
        dx *= -1;
    }
    if (y == 0) {
        dy *= -1;
    }
    if (y == paddle_y && (x >= paddle_x && x < paddle_x+10)) {
        dy *= -1;
    }
    if (y == ROWS-1) {
        printf("Game over!\n");
        exit(0);
    }
    if (bricks[y][x] == 1) {
        num_bricks--;
        bricks[y][x] = 0;
        dy *= -1;
    }
    ball_x += dx;
    ball_y += dy;
}

// Function to initialize bricks
void init_bricks() {
    int i, j;
    num_bricks = 0;
    for (i = 0; i < ROWS/2; i++) {
        for (j = 0; j < COLS; j++) {
            if ((i % 2 == 0) && (j % 4 == 2)) {
                bricks[i][j] = 1;
                num_bricks++;
            } else {
                bricks[i][j] = 0;
            }
        }
    }
}

// Function to print bricks
void print_bricks() {
    int i, j;
    for (i = 0; i < ROWS/2; i++) {
        for (j = 0; j < COLS; j++) {
            if (bricks[i][j] == 1) {
                board[i][j] = 1;
            }
        }
    }
}

int main() {
    init_board();
    init_paddle_ball();
    init_bricks();
    init_terminal();
    while (num_bricks > 0) {
        system("clear");
        print_board();
        print_paddle();
        print_ball();
        print_bricks();
        if (kbhit()) {
            // Get input character
            int ch = getch();
            if (ch == 'q') {
                break;
            } else if (ch == 'a') {
                move_paddle_left();
            } else if (ch == 'd') {
                move_paddle_right();
            }
        }
        move_ball();
        usleep(50000);
    }
    system("clear");
    printf("You won!\n");
    reset_terminal();
    return 0;
}