//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define MAX_ROW  20
#define MAX_COL  40

char screen[MAX_ROW][MAX_COL] = {0};
int x_pos = MAX_COL/2 - 1;
int y_pos = MAX_ROW - 2;
int x_dir = 1;
int y_dir = -1;

struct termios org_opts, new_opts;
int org_flags, new_flags;

void init_keyboard(void) {
    tcgetattr(STDIN_FILENO, &org_opts);
    memcpy(&new_opts, &org_opts, sizeof(new_opts));
    new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ISIG | IEXTEN);
    new_opts.c_oflag &= ~OPOST;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
    org_flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, org_flags | O_NONBLOCK);
}

void close_keyboard(void) {
    tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
    fcntl(STDIN_FILENO, F_SETFL, org_flags);
}

void bounce_ball() {
    if (screen[y_pos][x_pos] == 'X') {
        y_dir = -y_dir;
        screen[y_pos][x_pos] = 0;
    } else if (screen[y_pos+y_dir][x_pos] != 0) {
        x_dir = (screen[y_pos][x_pos+x_dir] != 0)? -x_dir : x_dir;
        y_dir = -y_dir;
    } else if (y_pos+y_dir < 0) {
        x_dir = (rand()%2)? -1 : 1;
        y_dir = 1;
    }

    if (x_pos+x_dir >= MAX_COL || x_pos+x_dir < 0) {
        x_dir = -x_dir;
    }

    x_pos += x_dir;
    y_pos += y_dir;

    screen[y_pos][x_pos] = 'O';
}

void draw_screen() {
    printf("\033[H");
    for (int j = 0; j < MAX_ROW; j++) {
        printf("%s\n", screen[j]);
    }
}

int main() {
    for (int i=0; i<MAX_ROW; i++) {
        for (int j=0; j<MAX_COL; j++) {
            screen[i][j] = ' ';
        }
    }
    for (int i=0; i<MAX_COL; i++) {
        screen[0][i] = 'X';
        screen[MAX_ROW-1][i] = 'X';
    }
    for (int i=0; i<MAX_ROW; i++) {
        screen[i][0] = 'X';
        screen[i][MAX_COL-1] = 'X';
    }

    screen[y_pos][x_pos] = 'O';

    init_keyboard();

    while (1) {
        if (getchar() == 'q') break;

        bounce_ball();

        draw_screen();

        usleep(50000);
    }

    close_keyboard();

    return 0;
}