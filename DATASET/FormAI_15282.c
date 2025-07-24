//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 15

struct room {
    int x;
    int y;
    int w;
    int h;
};

struct map {
    char tiles[WIDTH][HEIGHT];
    struct room rooms[10];
    int num_rooms;
};

void init_map(struct map* m, int seed) {
    srand(seed);

    // Fill map with walls
    int x, y;
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            m->tiles[x][y] = '#';
        }
    }

    // Generate rooms
    int i;
    for (i = 0; i < 10; i++) {
        int w = (rand() % 8) + 4;
        int h = (rand() % 6) + 3;
        int x = (rand() % (WIDTH - w - 2)) + 1;
        int y = (rand() % (HEIGHT - h - 2)) + 1;
        m->rooms[i] = (struct room){x, y, w, h};

        // Fill room with floor tiles
        int r, c;
        for (r = y; r < y + h; r++) {
            for (c = x; c < x + w; c++) {
                m->tiles[c][r] = '.';
            }
        }
    }
    m->num_rooms = 10;
}

void print_map(struct map* m) {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            printf("%c", m->tiles[x][y]);
        }
        printf("\n");
    }
}

int main() {
    struct map m;
    init_map(&m, time(NULL));
    print_map(&m);
    return 0;
}