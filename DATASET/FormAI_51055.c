//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define S_WIDTH 80
#define S_HEIGHT 24

char screen[S_HEIGHT][S_WIDTH];

pthread_mutex_t mutex;

struct Enemy {
    int x, y;
};

int player_x, score, lives;
struct Enemy enemies[5];
pthread_t enemy_threads[5];

void clear_screen() {
    for (int i = 0; i < S_HEIGHT; i++) {
        for (int j = 0; j < S_WIDTH; j++) {
            screen[i][j] = ' ';
        }
    }
}

void display_screen() {
    printf("Score: %d | Lives: %d\n", score, lives);

    for (int i = 0; i < S_HEIGHT; i++) {
        for (int j = 0; j < S_WIDTH; j++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
}

void setup() {
    clear_screen();

    player_x = S_WIDTH / 2;
    score = 0;
    lives = 3;

    for (int i = 0; i < 5; i++) {
        enemies[i].x = rand() % S_WIDTH;
        enemies[i].y = rand() % 3;
    }

    pthread_mutex_init(&mutex, NULL);
}

void move_player(int x) {
    player_x += x;

    if (player_x < 0) {
        player_x = 0;
    }

    if (player_x >= S_WIDTH) {
        player_x = S_WIDTH - 1;
    }
}

void move_enemy(int i) {
    while (1) {
        pthread_mutex_lock(&mutex);

        screen[enemies[i].y][enemies[i].x] = ' ';
        enemies[i].y++;

        if (enemies[i].y >= S_HEIGHT) {
            enemies[i].x = rand() % S_WIDTH;
            enemies[i].y = rand() % 3;
            lives--;
        }

        if (enemies[i].x == player_x && enemies[i].y == S_HEIGHT - 1) {
            score++;
            enemies[i].x = rand() % S_WIDTH;
            enemies[i].y = rand() % 3;
        }

        pthread_mutex_unlock(&mutex);

        usleep(500000);
    }
}

int main() {
    setup();

    for (int i = 0; i < 5; i++) {
        pthread_create(&enemy_threads[i], NULL, (void *)move_enemy, (void *)i);
    }

    while (1) {
        display_screen();

        char c = getchar();

        if (c == 'a') {
            move_player(-1);
        } else if (c == 'd') {
            move_player(1);
        }

        if (lives <= 0) {
            printf("Game Over!\n");
            exit(0);
        }

        usleep(100000);
    }
}