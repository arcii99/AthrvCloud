//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h>
#include <fcntl.h>

#define BOARD_SIZE 20
#define ENEMY_COUNT 20
#define BULLET_COUNT 50

int x, y, score, lives, game_over = 0;
int enemy_positions[ENEMY_COUNT][2], bullet_positions[BULLET_COUNT][2], bullet_status[BULLET_COUNT];
struct termios initial_settings, new_settings;

void set_keyboard_mode(void) {
    tcgetattr(STDIN_FILENO, &initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_cc[VMIN] = 0;
    new_settings.c_cc[VTIME] = 1;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
}

void reset_keyboard_mode(void) {
    tcsetattr(STDIN_FILENO, TCSANOW, &initial_settings);
}

void handle_input(void) {
    char c;
    if(read(STDIN_FILENO, &c, 1) == -1) {
        return;
    }
    if(c == 'q') {
        game_over = 1;
    }
    if(c == 'a') {
        if(x > 0) {
            x -= 1;
        }
    }
    if(c == 'd') {
        if(x < BOARD_SIZE - 1) {
            x += 1;
        }
    }
    if(c == ' ') {
        for(int i = 0; i < BULLET_COUNT; i++) {
            if(bullet_status[i] == 0) {
                bullet_status[i] = 1;
                bullet_positions[i][0] = x;
                bullet_positions[i][1] = y - 1;
                break;
            }
        }
    }
}

void draw_board(void) {
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
    for(int i = 0; i < BOARD_SIZE + 2; i++) {
        printf("#");
    }
    printf("\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("#");
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(i == y && j == x) {
                printf("@");
            } else if(bullet_status[i] == 1 && bullet_positions[i][0] == j && bullet_positions[i][1] == i - 1) {
                printf("|");
            } else {
                int enemy_here = 0;
                for(int k = 0; k < ENEMY_COUNT; k++) {
                    if(enemy_positions[k][0] == j && enemy_positions[k][1] == i) {
                        printf("E");
                        enemy_here = 1;
                        break;
                    }
                }
                if(!enemy_here) {
                    printf(" ");
                }
            }
        }
        printf("#\n");
    }
    for(int i = 0; i < BOARD_SIZE + 2; i++) {
        printf("#");
    }
    printf("\nScore: %d    Lives: %d\n", score, lives);
}

void update_positions(void) {
    y--;
    if(y < 1) {
        game_over = 1;
    }
    for(int i = 0; i < BULLET_COUNT; i++) {
        if(bullet_status[i] == 1) {
            bullet_positions[i][1] = bullet_positions[i][1] - 1;
            if(bullet_positions[i][1] < 1) {
                bullet_status[i] = 0;
            }
        }
    }
    for(int i = 0; i < ENEMY_COUNT; i++) {
        if(enemy_positions[i][1] == y) {
            if(enemy_positions[i][0] == x || enemy_positions[i][0] == x + 1 || enemy_positions[i][0] == x - 1) {
                lives--;
                if(lives == 0) {
                    game_over = 1;
                }
            }
        }
        if(enemy_positions[i][1] < y) {
            enemy_positions[i][1] = y;
        }
    }
}

void generate_enemies(void) {
    for(int i = 0; i < ENEMY_COUNT; i++) {
        enemy_positions[i][0] = rand() % BOARD_SIZE;
        enemy_positions[i][1] = (rand() % 5) * -1;
    }
}

void handle_collisions(void) {
    for(int i = 0; i < BULLET_COUNT; i++) {
        if(bullet_status[i] == 1) {
            for(int j = 0; j < ENEMY_COUNT; j++) {
                if(enemy_positions[j][0] == bullet_positions[i][0] && enemy_positions[j][1] == bullet_positions[i][1]) {
                    score++;
                    bullet_status[i] = 0;
                    enemy_positions[j][0] = -1;
                    enemy_positions[j][1] = -1;
                    break;
                }
            }
        }
    }
}

void main_loop(void) {
    set_keyboard_mode();
    x = BOARD_SIZE / 2;
    y = BOARD_SIZE - 1;
    score = 0;
    lives = 3;
    generate_enemies();
    while(!game_over) {
        draw_board();
        handle_input();
        update_positions();
        handle_collisions();
        usleep(100000);
    }
    reset_keyboard_mode();
}

int main(void) {
    srand(time(NULL));
    main_loop();
    return 0;
}