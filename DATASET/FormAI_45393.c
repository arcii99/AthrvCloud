//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define ROW 10
#define COLUMN 16

int brick[ROW][COLUMN];
int ball_x, ball_y, ball_dir;
int paddle_x, score;

void init_game();
void draw();
void drop_ball();
void move_paddle();
void move_ball();
void check_lose();
void check_brick();

int getch() 
{
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int main()
{
    init_game();
    while (1) {
        draw();
        drop_ball();
        move_paddle();
        move_ball();
        check_brick();
        check_lose();
        usleep(50000);
    }
    return 0;
}

void init_game()
{
    int i, j;

    // Initialize the bricks
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COLUMN; j++) {
            brick[i][j] = 1;
        }
    }

    // Initialize the ball
    ball_x = ROW - 2;
    ball_y = COLUMN / 2;
    ball_dir = -1;

    // Initialize the paddle
    paddle_x = ROW - 1;
}

void draw()
{
    int i, j;
    system("clear");
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COLUMN; j++) {
            if (brick[i][j] == 1) {
                printf("*");
            } else if (ball_x == i && ball_y == j) {
                printf("o");
            } else if (paddle_x == i && (j == ball_y || j == ball_y-1 || j == ball_y+1)) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("Score: %d\n", score);
}

void drop_ball()
{
    if (ball_dir == -1) {
        ball_x--;
    } else if (ball_dir == 1) {
        ball_x++;
    }
}

void move_paddle()
{
    int ch;
    if (kbhit()) {
        ch = getch();
        if (ch == 'a') {
            paddle_x--;
        } else if (ch == 'd') {
            paddle_x++;
        }
    }
}

void move_ball()
{
    int hit = 0;
    if (ball_x == 0) {
        ball_dir = 1;
    } else if (ball_x == ROW - 1 && ball_y >= paddle_x-1 && ball_y <= paddle_x+1) {
        ball_dir = -1;
        hit = 1;
    } else if (ball_y == 0 || ball_y == COLUMN - 1) {
        ball_dir = -ball_dir;
        hit = 1;
    }

    if (hit == 1) {
        score++;
    }

    ball_y += ball_dir;
}

void check_brick()
{
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COLUMN; j++) {
            if (brick[i][j] == 1 && ball_x == i && ball_y == j) {
                brick[i][j] = 0;
                ball_dir = -ball_dir;
                score += 10;
            }
        }
    }
}

void check_lose()
{
    int i;
    for (i = 0; i < COLUMN; i++) {
        if (brick[ROW-1][i] == 1) {
            printf("Game Over! Your Score: %d\n", score);
            exit(0);
        }
    }
}

int kbhit()
{
    struct timeval tv;
    fd_set read_fd;

    tv.tv_sec = 0;
    tv.tv_usec = 0;

    FD_ZERO(&read_fd);
    FD_SET(0, &read_fd);

    if (select(1, &read_fd, NULL, NULL, &tv) == -1) {
        return 0;
    }

    if (FD_ISSET(0, &read_fd)) {
        return 1;
    }

    return 0;
}