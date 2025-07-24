//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MAP_WIDTH 50
#define MAX_MAP_HEIGHT 20
#define NUM_ROOMS 6

typedef struct {
    int x;
    int y;
    int w;
    int h;
} Room;

typedef struct {
    char tile;
    int explored;
} Tile;

typedef struct {
    Tile tiles[MAX_MAP_WIDTH][MAX_MAP_HEIGHT];
} Map;

void init_map(Map *map) {
    int x, y;
    for (y = 0; y < MAX_MAP_HEIGHT; y++) {
        for (x = 0; x < MAX_MAP_WIDTH; x++) {
            map->tiles[x][y].tile = '#';
            map->tiles[x][y].explored = 0;
        }
    }
}

int is_room_overlap(Room *a, Room *b) {
    return (a->x <= b->x + b->w &&
            a->x + a->w >= b->x &&
            a->y <= b->y + b->h &&
            a->y + a->h >= b->y);
}

void create_room(Map *map, Room *room) {
    int x, y;
    for (y = room->y; y < room->y + room->h; y++) {
        for (x = room->x; x < room->x + room->w; x++) {
            map->tiles[x][y].tile = '.';
        }
    }
}

void create_h_tunnel(Map *map, int x1, int x2, int y) {
    int x;
    for (x = x1; x < x2 + 1; x++) {
        map->tiles[x][y].tile = '.';
    }
}

void create_v_tunnel(Map *map, int y1, int y2, int x) {
    int y;
    for (y = y1; y < y2 + 1; y++) {
        map->tiles[x][y].tile = '.';
    }
}

void create_corridors(Map *map, Room *a, Room *b) {
    int x, y, distance;

    if (a->x < b->x) {
        create_h_tunnel(map, a->x + a->w, b->x, a->y + a->h / 2);
    }
    else {
        create_h_tunnel(map, b->x + b->w, a->x, a->y + a->h / 2);
    }

    if (a->y < b->y) {
        create_v_tunnel(map, a->y + a->h / 2, b->y, b->x + b->w / 2);
    }
    else {
        create_v_tunnel(map, b->y + b->h / 2, a->y, b->x + b->w / 2);
    }
}

void place_rooms(Map *map) {
    int i, j;
    Room rooms[NUM_ROOMS];

    srand(time(NULL));

    for (i = 0; i < NUM_ROOMS; i++) {
        int w = rand() % 10 + 5;
        int h = rand() % 10 + 5;
        int x = rand() % (MAX_MAP_WIDTH - w - 2) + 1;
        int y = rand() % (MAX_MAP_HEIGHT - h - 2) + 1;

        rooms[i].x = x;
        rooms[i].y = y;
        rooms[i].w = w;
        rooms[i].h = h;

        for (j = 0; j < i; j++) {
            if (is_room_overlap(&rooms[i], &rooms[j])) {
                i--;
                break;
            }
        }
    }

    for (i = 0; i < NUM_ROOMS; i++) {
        create_room(map, &rooms[i]);
    }

    for (i = 0; i < NUM_ROOMS - 1; i++) {
        create_corridors(map, &rooms[i], &rooms[i + 1]);
    }
}

void print_map(Map *map) {
    int x, y;
    for (y = 0; y < MAX_MAP_HEIGHT; y++) {
        for (x = 0; x < MAX_MAP_WIDTH; x++) {
            printf("%c ", map->tiles[x][y].tile);
        }
        printf("\n");
    }
}

int main() {
    Map map;
    init_map(&map);
    place_rooms(&map);
    print_map(&map);
    return 0;
}