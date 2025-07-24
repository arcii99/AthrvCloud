//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <time.h>

// global constants
#define ROWS 20
#define COLS 50
#define PADDLE_LEN 5
#define BRICKS_PER_ROW 10
#define BRICKS_ROWS 5
#define BRICKS_TOTAL BRICKS_ROWS * BRICKS_PER_ROW
#define BALL_CHAR 'o'
#define PADDLE_CHAR '='
#define BRICK_CHAR '@'

// colors
#define COLOR_RED "\033[0;31m"
#define COLOR_GREEN "\033[0;32m"
#define COLOR_YELLOW "\033[0;33m"
#define COLOR_BLUE "\033[0;34m"
#define COLOR_MAGENTA "\033[0;35m"
#define COLOR_CYAN "\033[0;36m"
#define COLOR_RESET "\033[0m"

// game objects
char board[ROWS][COLS];
int paddle_pos = (COLS - PADDLE_LEN) / 2;
int ball_x = ROWS - 2;
int ball_y = COLS / 2;
int ball_dx = 1;
int ball_dy = -1;
int bricks[BRICKS_TOTAL];
int score = 0;
int lives = 3;

// function prototypes
void draw_board();
void draw_ball();
void draw_paddle();
void draw_bricks();
void move_ball();
void move_paddle(int direction);
int kbhit();
void set_terminal_flags();

int main()
{
    // init board and bricks
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) {
                board[i][j] = '*';
            } else {
                board[i][j] = ' ';
            }
        }
    }
    for (int i = 0; i < BRICKS_TOTAL; i++) {
        bricks[i] = 1;
    }

    // set terminal flags
    set_terminal_flags();

    // game loop
    while (1) {
        // draw game objects
        draw_board();
        draw_ball();
        draw_paddle();
        draw_bricks();

        // move ball and paddle
        move_ball();
        int c = kbhit();
        if (c == 'a' || c == 'A') {
            move_paddle(-1);
        } else if (c == 'd' || c == 'D') {
            move_paddle(1);
        }

        // check for game over
        if (ball_x == ROWS - 2) {
            lives--;
            if (lives <= 0) {
                printf(COLOR_RED "GAME OVER\n" COLOR_RESET);
                exit(0);
            }
            ball_x = ROWS - 2;
            ball_y = COLS / 2;
            ball_dx = 1;
            ball_dy = -1;
            paddle_pos = (COLS - PADDLE_LEN) / 2;
        }

        // check for game win
        if (score >= BRICKS_TOTAL) {
            printf(COLOR_GREEN "YOU WIN!\n" COLOR_RESET);
            exit(0);
        }

        // sleep for a short while
        usleep(20000);
    }

    return 0;
}

void draw_board()
{
    system("clear");
    printf("Score: %d, Lives: %d\n", score, lives);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void draw_ball()
{
    board[ball_x][ball_y] = BALL_CHAR;
}

void draw_paddle()
{
    for (int i = 0; i < PADDLE_LEN; i++) {
        board[ROWS - 2][paddle_pos + i] = PADDLE_CHAR;
    }
}

void draw_bricks()
{
    for (int i = 0; i < BRICKS_ROWS; i++) {
        for (int j = 0; j < BRICKS_PER_ROW; j++) {
            if (bricks[i*BRICKS_PER_ROW+j]) {
                board[i+1][j*(COLS/BRICKS_PER_ROW)+1] = BRICK_CHAR;
            }
        }
    }
}

void move_ball()
{
    // save old position
    int old_x = ball_x;
    int old_y = ball_y;

    // move ball
    ball_x += ball_dx;
    ball_y += ball_dy;

    // check for collision with walls
    if (ball_x == 0 || ball_y == 0 || ball_y == COLS - 1) {
        ball_dx *= -1;
        ball_x = old_x;
        ball_y = old_y;
        return;
    }

    // check for collision with paddle
    if (ball_x == ROWS - 2) {
        if (ball_y >= paddle_pos && ball_y < paddle_pos + PADDLE_LEN) {
            ball_dy *= -1;
            score++;
        }
    }

    // check for collision with bricks
    int brick_x = ball_x - 1;
    int brick_y = (ball_y - 1) / (COLS/BRICKS_PER_ROW);
    int brick_pos = brick_x * BRICKS_PER_ROW + brick_y;
    if (brick_x >= 0 && brick_x < BRICKS_ROWS && brick_y >= 0 && brick_y < BRICKS_PER_ROW && bricks[brick_pos]) {
        ball_dy *= -1;
        bricks[brick_pos] = 0;
        score++;
    }
}

void move_paddle(int direction)
{
    if (paddle_pos + direction >= 0 && paddle_pos + direction + PADDLE_LEN <= COLS) {
        paddle_pos += direction;
    }
}

int kbhit()
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
        return ch;
    }

    return 0;
}

void set_terminal_flags()
{
    printf("\033[?25l"); // hide cursor
    printf("\033[2J"); // clear screen
    printf("\033[1;1H"); // move cursor to top left
    system("stty -echo"); // turn off echoing of keyboard input
    system("stty -icanon"); // turn off canonical mode
}