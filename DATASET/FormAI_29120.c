//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define MAX_ROOMS 8
#define MIN_ROOM_SIZE 4
#define MAX_ROOM_SIZE 10

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point pos;
    int width, height;
} Room;

int map[MAP_SIZE][MAP_SIZE];
Room rooms[MAX_ROOMS];
int num_rooms = 0;

void init_map() {
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            map[y][x] = 1;
        }
    }
}

int rng(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void create_room(Room room) {
    for (int y = room.pos.y; y < room.pos.y + room.height; y++) {
        for (int x = room.pos.x; x < room.pos.x + room.width; x++) {
            map[y][x] = 0;
        }
    }
}

int intersect(Room a, Room b) {
    if (a.pos.x >= b.pos.x + b.width ||
            a.pos.x + a.width <= b.pos.x ||
            a.pos.y >= b.pos.y + b.height ||
            a.pos.y + a.height <= b.pos.y) {
        return 0;
    }
    return 1;
}

void connect_rooms(Room a, Room b) {
    Point center_a = {a.pos.x + a.width / 2, a.pos.y + a.height / 2};
    Point center_b = {b.pos.x + b.width / 2, b.pos.y + b.height / 2};
    while (center_a.x != center_b.x || center_a.y != center_b.y) {
        if (center_a.x < center_b.x) {
            center_a.x++;
        } else if (center_a.x > center_b.x) {
            center_a.x--;
        }
        if (center_a.y < center_b.y) {
            center_a.y++;
        } else if (center_a.y > center_b.y) {
            center_a.y--;
        }
        map[center_a.y][center_a.x] = 0;
    }
}

void generate_map() {
    init_map();

    for (int i = 0; i < MAX_ROOMS; i++) {
        int width = rng(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
        int height = rng(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
        int x = rng(1, MAP_SIZE - width - 1);
        int y = rng(1, MAP_SIZE - height - 1);
        Room new_room = {{x, y}, width, height};
        int overlaps = 0;
        for (int j = 0; j < num_rooms; j++) {
            if (intersect(new_room, rooms[j])) {
                overlaps = 1;
                break;
            }
        }
        if (!overlaps) {
            rooms[num_rooms] = new_room;
            num_rooms++;
            create_room(new_room);
        }
    }

    for (int i = 0; i < num_rooms - 1; i++) {
        connect_rooms(rooms[i], rooms[i + 1]);
    }
}

void print_map() {
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            if (map[y][x] == 1) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    generate_map();
    print_map();
    return 0;
}