//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 30
#define ENEMY_COUNT 20

int main(void)
{
    int i, j, k, x, y, score;
    char screen[SCREEN_HEIGHT][SCREEN_WIDTH];
    char player = '^';
    char enemy = 'X';
    int enemy_x[ENEMY_COUNT], enemy_y[ENEMY_COUNT];
    char bullet = '|';
    int bullet_x, bullet_y, bullet_fired;
    char input;

    // Initialize screen
    for (i = 0; i < SCREEN_HEIGHT; i++) {
        for (j = 0; j < SCREEN_WIDTH; j++) {
            if (i == SCREEN_HEIGHT - 1) {
                screen[i][j] = '-';
            } else {
                screen[i][j] = ' ';
            }
        }
    }

    // Initialize player
    x = SCREEN_WIDTH / 2;
    y = SCREEN_HEIGHT - 2;
    screen[y][x] = player;

    // Initialize enemies
    srand(time(NULL));
    for (i = 0; i < ENEMY_COUNT; i++) {
        enemy_x[i] = rand() % SCREEN_WIDTH;
        enemy_y[i] = rand() % (SCREEN_HEIGHT - 5);
        screen[enemy_y[i]][enemy_x[i]] = enemy;
    }

    // Initialize bullet
    bullet_fired = 0;

    // Initialize score
    score = 0;

    // Main game loop
    while (1) {
        // Print screen
        system("clear");
        for (i = 0; i < SCREEN_HEIGHT; i++) {
            for (j = 0; j < SCREEN_WIDTH; j++) {
                putchar(screen[i][j]);
            }
            putchar('\n');
        }

        // Move player
        input = tolower(getchar());
        if (input == 'a' && x > 0) {
            screen[y][x] = ' ';
            x--;
        } else if (input == 'd' && x < SCREEN_WIDTH - 1) {
            screen[y][x] = ' ';
            x++;
        } else if (input == ' ') {
            if (!bullet_fired) {
                bullet_x = x;
                bullet_y = y - 1;
                bullet_fired = 1;
            }
        }

        // Move bullet
        if (bullet_fired) {
            screen[bullet_y][bullet_x] = ' ';
            bullet_y--;
            if (bullet_y == 0) {
                bullet_fired = 0;
            } else {
                screen[bullet_y][bullet_x] = bullet;
            }
        }

        // Move enemies and detect collisions
        for (i = 0; i < ENEMY_COUNT; i++) {
            screen[enemy_y[i]][enemy_x[i]] = ' ';
            enemy_y[i]++;
            if (enemy_y[i] == SCREEN_HEIGHT - 1) {
                enemy_x[i] = rand() % SCREEN_WIDTH;
                enemy_y[i] = rand() % (SCREEN_HEIGHT - 5);
            }
            if (enemy_y[i] == bullet_y && enemy_x[i] == bullet_x) {
                score++;
                enemy_x[i] = rand() % SCREEN_WIDTH;
                enemy_y[i] = rand() % (SCREEN_HEIGHT - 5);
                bullet_fired = 0;
            } else {
                screen[enemy_y[i]][enemy_x[i]] = enemy;
            }
            if (enemy_y[i] == y && enemy_x[i] == x) {
                printf("Game Over! Score: %d\n", score);
                return 0;
            }
        }
    }

    return 0;
}