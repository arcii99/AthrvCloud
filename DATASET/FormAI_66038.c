//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH  50
#define MAP_HEIGHT 20

typedef struct {
    int x, y;
} point;

typedef struct {
    char tiles[MAP_HEIGHT][MAP_WIDTH];
    point player_pos;
} map;

int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

char random_tile() {
    switch (random_int(0, 2)) {
        case 0: return '#';
        case 1: return '.';
        case 2: return '@';
    }
}

void generate_map(map *m) {
    int i, j;

    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            m->tiles[i][j] = random_tile();
            if (m->tiles[i][j] == '@') {
                m->player_pos.x = j;
                m->player_pos.y = i;
            }
        }
    }
}

void print_map(map *m) {
    int i, j;

    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            printf("%c", m->tiles[i][j]);
        }
        printf("\n");
    }
}

int main() {
    map m;
    srand(time(NULL));

    generate_map(&m);
    print_map(&m);

    return 0;
}