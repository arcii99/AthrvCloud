//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define WIDTH 80
#define HEIGHT 24
#define ENEMY_ROW 4
#define ENEMY_COL 8

int player_pos = WIDTH/2;
int score = 0;

int enemy_pos[ENEMY_ROW][ENEMY_COL];

void draw_screen() {
    system("clear");
    printf("Score: %d\n", score);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == HEIGHT-1) {
                if (j == player_pos) {
                    printf("H");
                } else {
                    printf("_");
                }
            } else {
                int is_enemy = 0;
                for (int k = 0; k < ENEMY_ROW; k++) {
                    for (int l = 0; l < ENEMY_COL; l++) {
                        if (enemy_pos[k][l] == i*WIDTH+j) {
                            printf("E");
                            is_enemy = 1;
                            break;
                        }
                    }
                    if (is_enemy) {
                        break;
                    }
                }
                if (!is_enemy) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

void* enemy_thread(void* arg) {
    int enemy_dir = 1;
    while (1) {
        for (int i = 0; i < ENEMY_ROW; i++) {
            for (int j = 0; j < ENEMY_COL; j++) {
                enemy_pos[i][j] += enemy_dir;
                if (enemy_pos[i][j] % WIDTH == 0 || enemy_pos[i][j] % WIDTH == WIDTH-1) {
                    enemy_dir = -enemy_dir;
                    for (int k = 0; k < ENEMY_ROW; k++) {
                        for (int l = 0; l < ENEMY_COL; l++) {
                            enemy_pos[k][l] += WIDTH;
                        }
                    }
                }
                if ((enemy_pos[i][j]+WIDTH) >= WIDTH*HEIGHT) {
                    exit(0);
                }
            }
        }
        draw_screen();
        usleep(100000);
    }
}

int main() {
    pthread_t enemy_tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&enemy_tid, &attr, enemy_thread, NULL);

    while (1) {
        char c = getchar();
        if (c == 'a' && player_pos > 0) {
            player_pos--;
        }
        if (c == 'd' && player_pos < WIDTH-1) {
            player_pos++;
        }
        draw_screen();
    }

    return 0;
}