//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define MAX_ENEMIES 5

typedef struct {
    int x;
    int y;
    bool alive;
} Enemy;

Enemy enemies[MAX_ENEMIES];
int player_pos = SCREEN_WIDTH / 2;

void draw();
void input();
void update();
void spawn_enemies();
bool is_enemy_alive();

int main() {
    srand(time(NULL));
    while (true) {
        draw();
        input();
        update();
        system("cls"); //clear screen
    }
    return 0;
}

/* Draws the game screen */
void draw() {
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            if (i == SCREEN_HEIGHT - 1 && j == player_pos) {
                printf("A"); //the player
            } else {
                bool enemy_found = false;
                for (int k = 0; k < MAX_ENEMIES; k++) {
                    if (enemies[k].alive && enemies[k].x == j && enemies[k].y == i) {
                        printf("X"); //an alive enemy
                        enemy_found = true;
                        break;
                    }
                }
                if (!enemy_found) {
                    printf("."); //an empty space
                }
            }
        }
        printf("\n");
    }
}

/* Handles user input */
void input() {
    char c = getchar();
    if (c == 'a' && player_pos > 0) {
        player_pos--;
    } else if (c == 'd' && player_pos < SCREEN_WIDTH - 1) {
        player_pos++;
    }
}

/* Updates the game state */
void update() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].alive) {
            enemies[i].y++;
            if (enemies[i].y == SCREEN_HEIGHT - 1) {
                enemies[i].alive = false;
            }
        }
    }
    if (!is_enemy_alive()) {
        spawn_enemies();
    }
}

/* Spawns new enemies */
void spawn_enemies() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i].x = rand() % SCREEN_WIDTH;
        enemies[i].y = 1;
        enemies[i].alive = true;
    }
}

/* Checks if there are any alive enemies */
bool is_enemy_alive() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].alive) {
            return true;
        }
    }
    return false;
}