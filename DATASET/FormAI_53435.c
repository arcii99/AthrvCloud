//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20
#define PLAYER_CHAR 'X'
#define ENEMY_CHAR '*'
#define SPACE_CHAR ' '

int player_x, player_y;
int enemies[10][2];
int num_enemies = 0;

char screen[HEIGHT][WIDTH];

void init_screen() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            screen[i][j] = SPACE_CHAR;
        }
    }
}

void update_screen() {
    system("cls");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
}

void spawn_player() {
    player_x = WIDTH / 2;
    player_y = HEIGHT - 2;
    screen[player_y][player_x] = PLAYER_CHAR;
}

void spawn_enemy() {
    if (num_enemies < 10) {
        enemies[num_enemies][0] = rand() % WIDTH;
        enemies[num_enemies][1] = rand() % (HEIGHT / 2);
        screen[enemies[num_enemies][1]][enemies[num_enemies][0]] = ENEMY_CHAR;
        num_enemies++;
    }
}

void update_enemies() {
    for (int i = 0; i < num_enemies; i++) {
        if (enemies[i][1] < HEIGHT - 1) {
            screen[enemies[i][1]][enemies[i][0]] = SPACE_CHAR;
            enemies[i][1]++;
            screen[enemies[i][1]][enemies[i][0]] = ENEMY_CHAR;
        } else {
            num_enemies--;
            enemies[i][0] = enemies[num_enemies][0];
            enemies[i][1] = enemies[num_enemies][1];
            screen[enemies[num_enemies][1]][enemies[num_enemies][0]] = SPACE_CHAR;
        }
    }
}

void move_player(char direction) {
    int new_x = player_x;
    switch (direction) {
        case 'a':
            new_x--;
            break;
        case 'd':
            new_x++;
            break;
    }
    if (new_x >= 0 && new_x < WIDTH) {
        screen[player_y][player_x] = SPACE_CHAR;
        player_x = new_x;
        screen[player_y][player_x] = PLAYER_CHAR;
    }
}

int check_collision() {
    for (int i = 0; i < num_enemies; i++) {
        if (enemies[i][0] == player_x && enemies[i][1] == player_y) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(0));
    init_screen();
    spawn_player();
    char input;
    while (1) {
        spawn_enemy();
        update_enemies();
        update_screen();
        if (check_collision()) {
            printf("Game over\n");
            break;
        }
        printf("Use a and d to move, q to quit\n");
        input = getchar();
        if (input == 'q') {
            break;
        }
        move_player(input);
    }
    return 0;
}