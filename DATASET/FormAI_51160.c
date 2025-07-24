//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH  80
#define MAP_HEIGHT 24
#define MAX_ROOMS  12
#define MIN_ROOM_WIDTH  4
#define MIN_ROOM_HEIGHT 3
#define MAX_ROOM_WIDTH  10
#define MAX_ROOM_HEIGHT 6
#define MAX_ITERATIONS  1000

enum Tile {
    TILE_WALL = '#',
    TILE_FLOOR = '.'
};

typedef struct {
    int x, y, w, h;
} Room;

char map[MAP_HEIGHT][MAP_WIDTH];

void init_map() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = TILE_WALL;
        }
    }
}

void print_map() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}

int rand_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

void create_room(Room room) {
    for (int y = room.y; y < room.y + room.h; y++) {
        for (int x = room.x; x < room.x + room.w; x++) {
            map[y][x] = TILE_FLOOR;
        }
    }
}

int intersects(Room r1, Room r2) {
    if (r1.x + r1.w < r2.x || r2.x + r2.w < r1.x)
        return 0;
    if (r1.y + r1.h < r2.y || r2.y + r2.h < r1.y)
        return 0;
    return 1;
}

void generate_dungeon(int max_rooms, int min_room_width, int min_room_height,
                       int max_room_width, int max_room_height) {
    Room rooms[max_rooms];
    int num_rooms = 0;

    int iterations = 0;
    while (num_rooms < max_rooms && iterations < MAX_ITERATIONS) {
        Room new_room;
        new_room.x = rand_int(1, MAP_WIDTH - max_room_width);
        new_room.y = rand_int(1, MAP_HEIGHT - max_room_height);
        new_room.w = rand_int(min_room_width, max_room_width);
        new_room.h = rand_int(min_room_height, max_room_height);

        int failed = 0;
        for (int i = 0; i < num_rooms; i++) {
            if (intersects(new_room, rooms[i])) {
                failed = 1;
                break;
            }
        }
        if (!failed) {
            create_room(new_room);
            rooms[num_rooms] = new_room;
            num_rooms++;
        }
        iterations++;
    }
}

int main() {
    srand(time(NULL));
    init_map();
    generate_dungeon(MAX_ROOMS, MIN_ROOM_WIDTH, MIN_ROOM_HEIGHT, MAX_ROOM_WIDTH, MAX_ROOM_HEIGHT);
    print_map();
    return 0;
}