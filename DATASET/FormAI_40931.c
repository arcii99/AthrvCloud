//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define MAX_ROOMS 6

enum tiles {
    FLOOR,
    WALL,
    DOOR,
};

typedef struct {
    int x, y;
    int w, h;
} room_t;

typedef struct {
    int x, y;
    int type;
} tile_t;

tile_t map[MAP_SIZE][MAP_SIZE];

void init_map() {
    int i, j;
    for (i = 0; i < MAP_SIZE; ++i) {
        for (j = 0; j < MAP_SIZE; ++j) {
            map[i][j].x = i;
            map[i][j].y = j;
            if (i == 0 || j == 0 || i == MAP_SIZE - 1 || j == MAP_SIZE - 1) {
                map[i][j].type = WALL;
            } else {
                map[i][j].type = FLOOR;
            }
        }
    }
}

void print_map() {
    int i, j;
    for (i = 0; i < MAP_SIZE; ++i) {
        for (j = 0; j < MAP_SIZE; ++j) {
            switch (map[i][j].type) {
                case FLOOR: printf("."); break;
                case WALL: printf("#"); break;
                case DOOR: printf("+"); break;
            }
        }
        printf("\n");
    }
}

void generate_rooms() {
    int i, x, y, w, h;
    for (i = 0; i < MAX_ROOMS; ++i) {
        w = (rand() % 4 + 4) * 2 + 1;
        h = (rand() % 4 + 4) * 2 + 1;
        x = rand() % (MAP_SIZE - w - 1) + 1;
        y = rand() % (MAP_SIZE - h - 1) + 1;
        room_t room = { x, y, w, h };
        int j, k;
        for (j = x - 1; j < x + w + 1; ++j) {
            for (k = y - 1; k < y + h + 1; ++k) {
                if (map[j][k].type == WALL) {
                    goto next_room;
                }
            }
        }
        for (j = x; j < x + w; ++j) {
            for (k = y; k < y + h; ++k) {
                map[j][k].type = FLOOR;
            }
        }
        next_room:;
    }
}

void generate_doors() {
    int i, x, y;
    for (i = 0; i < MAX_ROOMS; ++i) {
        x = rand() % (MAP_SIZE - 2) + 1;
        y = rand() % (MAP_SIZE - 2) + 1;
        if (map[x][y].type == FLOOR && (
            (map[x-1][y].type == WALL && map[x+1][y].type == FLOOR && map[x+1][y-1].type == WALL && map[x+1][y+1].type == WALL) ||
            (map[x+1][y].type == WALL && map[x-1][y].type == FLOOR && map[x-1][y-1].type == WALL && map[x-1][y+1].type == WALL) ||
            (map[x][y-1].type == WALL && map[x][y+1].type == FLOOR && map[x-1][y+1].type == WALL && map[x+1][y+1].type == WALL) ||
            (map[x][y+1].type == WALL && map[x][y-1].type == FLOOR && map[x-1][y-1].type == WALL && map[x+1][y-1].type == WALL))) {
            map[x][y].type = DOOR;
        }
    }
}

int main() {
    int i, j;

    srand(time(NULL));

    init_map();

    generate_rooms();

    generate_doors();

    print_map();

    return 0;
}