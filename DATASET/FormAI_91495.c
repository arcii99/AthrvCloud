//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define MAP_HEIGHT 20
#define MAP_WIDTH 30

int kbhit() {
    struct timeval tv = {0L, 0L};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(1, &fds, NULL, NULL, &tv);
}

int getch() {
    int r;
    unsigned char c;
    static struct termios tc, saved_tc;
    if (!tcgetattr(STDIN_FILENO, &tc)) {
        cfmakeraw(&tc);
        tcsetattr(STDIN_FILENO, TCSANOW, &tc);
        r = read(STDIN_FILENO, &c, sizeof(c));
        tcsetattr(STDIN_FILENO, TCSANOW, &saved_tc);
        return r == 1 ? c : -1;
    }
    return -1;
}

void clear_screen() {
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

void print_map(int map[MAP_HEIGHT][MAP_WIDTH], int player_x, int player_y) {
    clear_screen();
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (x == player_x && y == player_y) {
                printf("*");
            } else {
                if (map[y][x] == 0) {
                    printf(".");
                } else {
                    printf("#");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    int map[MAP_HEIGHT][MAP_WIDTH];
    srand(time(NULL));
    int player_x = rand() % MAP_WIDTH;
    int player_y = rand() % MAP_HEIGHT;
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = rand() % 2; // 0 = empty, 1 = obstacle
        }
    }
    
    int score = 0;
    while (1) {
        print_map(map, player_x, player_y);
        printf("Score: %d\n", score);
        if (map[player_y][player_x] == 1) {
            printf("You crashed!\n");
            break;
        }
        if (player_y == MAP_HEIGHT - 1) {
            printf("You reached the end!\n");
            break;
        }
        if (kbhit()) {
            char c = getch();
            if (c == 'a' && player_x > 0) {
                player_x--;
            }
            if (c == 'd' && player_x < MAP_WIDTH - 1) {
                player_x++;
            }
        }
        usleep(100000);
        player_y++;
        score++;
    }
    return 0;
}