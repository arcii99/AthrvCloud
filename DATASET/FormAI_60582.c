//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 20

char screen[SCREEN_HEIGHT][SCREEN_WIDTH];
int pacman_x, pacman_y, score, lives, blinky_x, blinky_y;
bool game_over;

void init_screen() {
    memset(screen, ' ', SCREEN_HEIGHT * SCREEN_WIDTH);
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        screen[i][0] = '|';
        screen[i][SCREEN_WIDTH - 1] = '|';
    }
    for (int i = 0; i < SCREEN_WIDTH; i++) {
        screen[0][i] = '-';
        screen[SCREEN_HEIGHT - 1][i] = '-';
    }
    pacman_x = SCREEN_WIDTH / 2;
    pacman_y = SCREEN_HEIGHT / 2;
    screen[pacman_y][pacman_x] = 'C';
    score = 0;
    lives = 3;
    blinky_x = 1 + rand() % (SCREEN_WIDTH - 2);
    blinky_y = 1 + rand() % (SCREEN_HEIGHT - 2);
    screen[blinky_y][blinky_x] = 'B';
    game_over = false;
}

void draw_screen() {
    printf("\033[2J\033[H");
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
    printf("SCORE: %d   LIVES: %d\n", score, lives);
}

void move_pacman(char c) {
    int new_x = pacman_x, new_y = pacman_y;
    if (c == 'w') new_y--;
    else if (c == 'a') new_x--;
    else if (c == 's') new_y++;
    else if (c == 'd') new_x++;
    if (new_x == 0) new_x = SCREEN_WIDTH - 2;
    else if (new_x == SCREEN_WIDTH - 1) new_x = 1;
    if (screen[new_y][new_x] == '.') {
        score++;
        screen[new_y][new_x] = ' ';
    } else if (screen[new_y][new_x] == 'B') {
        lives--;
        if (lives == 0) game_over = true;
        else init_screen();
    }
    screen[pacman_y][pacman_x] = ' ';
    pacman_x = new_x;
    pacman_y = new_y;
    screen[pacman_y][pacman_x] = 'C';
}

void move_blinky() {
    int new_x = blinky_x, new_y = blinky_y;
    if (pacman_x < blinky_x) new_x--;
    else if (pacman_x > blinky_x) new_x++;
    if (pacman_y < blinky_y) new_y--;
    else if (pacman_y > blinky_y) new_y++;
    if (new_x == 0) new_x = SCREEN_WIDTH - 2;
    else if (new_x == SCREEN_WIDTH - 1) new_x = 1;
    blinky_x = new_x;
    blinky_y = new_y;
    screen[blinky_y][blinky_x] = 'B';
}

int main() {
    srand(time(NULL));
    init_screen();
    while (!game_over) {
        draw_screen();
        char c = getchar();
        if (c == '\033') {
            getchar(); // skip the ESC
            c = getchar();
            if (c == 'A') move_pacman('w');
            else if (c == 'B') move_pacman('s');
            else if (c == 'C') move_pacman('d');
            else if (c == 'D') move_pacman('a');
        }
        if (score == 50) {
            printf("YOU WIN!\n");
            game_over = true;
        }
        move_blinky();
        if (pacman_x == blinky_x && pacman_y == blinky_y) {
            lives--;
            if (lives == 0) {
                printf("GAME OVER\n");
                game_over = true;
            } else {
                init_screen();
            }
        }
    }
    return 0;
}