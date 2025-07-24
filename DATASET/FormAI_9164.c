//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 40
#define HEIGHT 20

static struct termios initial_settings, new_settings;
static int peek_char = -1;

void init_keyboard();
void close_keyboard();
int kbhit();

int main() {
    init_keyboard();
    int gameover = 0;
    int x = WIDTH / 2, y = HEIGHT - 2;
    int ballx = x, bally = y - 1;
    int dx = 1, dy = -1;
    int score = 0, lives = 3;

    char board[HEIGHT][WIDTH];
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            board[i][j] = ' ';
        }
    }

    while (!gameover) {
        usleep(50000);
        board[y][x] = ' ';
        board[bally][ballx] = ' ';

        if (kbhit()) {
            switch (getchar()) {
                case 'a':
                    x = x > 1 ? x - 1 : x;
                    break;
                case 'd':
                    x = x < WIDTH - 2 ? x + 1 : x;
                    break;
                case 'q':
                    gameover = 1;
                    break;
            }
        }

        ballx += dx;
        bally += dy;

        if (ballx < 1 || ballx > WIDTH - 2) {
            dx *= -1;
        }

        if (bally < 1) {
            dy *= -1;
        } else if (bally == y - 1 && ballx >= x - 2 && ballx <= x + 2) {
            dy *= -1;
            score++;
        } else if (bally == y) {
            lives--;
            if (lives == 0) {
                gameover = 1;
            } else {
                ballx = x;
                bally = y - 1;
                dx = 1;
                dy = -1;
            }
        }

        board[y][x] = '=';
        board[bally][ballx] = '*';

        system("clear");
        printf("Score: %d    Lives: %d\n", score, lives);
        for (i = 0; i < HEIGHT; i++) {
            for (j = 0; j < WIDTH; j++) {
                putchar(board[i][j]);
            }
            putchar('\n');
        }
    }

    close_keyboard();
    return 0;
}

void init_keyboard() {
    tcgetattr(0, &initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_lflag &= ~ISIG;
    new_settings.c_cc[VMIN] = 0;
    new_settings.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
}

void close_keyboard() {
    tcsetattr(0, TCSANOW, &initial_settings);
}

int kbhit() {
    char ch;
    int nread;

    if (peek_char != -1) {
        return 1;
    }

    new_settings.c_cc[VMIN] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
    nread = read(0, &ch, 1);
    new_settings.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &new_settings);

    if (nread == 1) {
        peek_char = ch;
        return 1;
    }

    return 0;
}