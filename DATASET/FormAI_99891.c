//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

char map[WIDTH][HEIGHT];

void init_map();
void draw_map();
void gen_map();
void place_items();

int main() {
    srand(time(NULL));
    init_map();
    gen_map();
    place_items();
    draw_map();
    return 0;
}

void init_map() {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            map[i][j] = '#';
        }
    }
}

void draw_map() {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void gen_map() {
    int i, j;
    for (i = 1; i < WIDTH - 1; i++) {
        for (j = 1; j < HEIGHT - 1; j++) {
            if (rand() % 100 < 40) {
                map[i][j] = '.';
            }
        }
    }
}

void place_items() {
    int i, x, y;
    for (i = 0; i < 10; i++) {
        x = rand() % (WIDTH - 2) + 1;
        y = rand() % (HEIGHT - 2) + 1;
        map[x][y] = '!';
    }
}