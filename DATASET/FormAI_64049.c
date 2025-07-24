//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 20

int missile_x, missile_y, missile_live;  // missile coordinates and state
int player_x, player_y;  // player coordinates
int enemy_x, enemy_y;  // enemy coordinates

char gameboard[HEIGHT][WIDTH];  // gameboard array

// initialize gameboard to all spaces
void init_gameboard() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            gameboard[i][j] = ' ';
        }
    }
}

// print gameboard to console
void print_gameboard() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", gameboard[i][j]);
        }
        printf("\n");
    }
}

// update gameboard with player, enemy, and missile positions
void update_gameboard() {
    init_gameboard();  // reset gameboard
    gameboard[player_y][player_x] = 'P';  // player
    gameboard[enemy_y][enemy_x] = 'E';  // enemy
    if (missile_live) {
        gameboard[missile_y][missile_x] = '|';  // missile
    }
}

// move missile up the screen
void move_missile() {
    if (missile_live) {
        missile_y--;
        if (missile_y < 0) {
            missile_live = 0;  // missile off screen
            gameboard[missile_y][missile_x] = ' ';
        }
    }
}

// move enemy randomly left or right
void move_enemy() {
    int move = rand() % 3 - 1;  // -1, 0, or 1
    enemy_x += move;
    if (enemy_x < 0) {
        enemy_x = 0;
    } else if (enemy_x >= WIDTH) {
        enemy_x = WIDTH - 1;
    }
}

// check for collision between missile and enemy
void check_collision() {
    if (missile_live && missile_x == enemy_x && missile_y == enemy_y) {
        missile_live = 0;
        gameboard[missile_y][missile_x] = ' ';
        enemy_x = rand() % WIDTH;  // respawn enemy
        enemy_y = 1;
    }
}

int main() {
    srand(time(NULL));  // seed random number generator

    // initialize player, enemy, and missile positions and states
    player_x = WIDTH / 2;
    player_y = HEIGHT - 1;
    enemy_x = rand() % WIDTH;
    enemy_y = 1;
    missile_live = 0;

    while (1) {
        update_gameboard();
        print_gameboard();
        move_missile();
        move_enemy();
        check_collision();
        usleep(50000);  // delay for smooth animation
        system("clear");  // clear console
    }

    return 0;
}