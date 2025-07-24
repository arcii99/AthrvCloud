//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

char map[MAP_HEIGHT][MAP_WIDTH];

void init_map() {
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = '#';
        }
    }
}

void print_map() {
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void generate_map() {
    int i, j, n;
    srand(time(NULL));
    for (n = 0; n < 5; n++) {
        int x = rand() % (MAP_WIDTH - 2) + 1;
        int y = rand() % (MAP_HEIGHT - 2) + 1;
        map[y][x] = '.';
        for (i = -1; i <= 1; i++) {
            for (j = -1; j <= 1; j++) {
                if (i != 0 || j != 0) {
                    int dx = x + i;
                    int dy = y + j;
                    if (dx >= 0 && dx < MAP_WIDTH && dy >= 0 && dy < MAP_HEIGHT) {
                        map[dy][dx] = '.';
                    }
                }
            }
        }
    }
}

int main() {
    init_map();
    generate_map();
    print_map();
    return 0;
}