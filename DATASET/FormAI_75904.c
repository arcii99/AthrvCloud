//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 100
#define MAX_ROOMS 20
#define MAX_ROOM_SIZE 10

typedef struct {
    int x, y, w, h;
} room_t;

char map[MAP_SIZE][MAP_SIZE];
room_t rooms[MAX_ROOMS];

void init_map() {
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            map[i][j] = '#';
        }
    }
}

int is_overlap(room_t r1, room_t r2) {
    int r1_x1 = r1.x;
    int r1_x2 = r1.x + r1.w - 1;
    int r1_y1 = r1.y;
    int r1_y2 = r1.y + r1.h - 1;

    int r2_x1 = r2.x;
    int r2_x2 = r2.x + r2.w - 1;
    int r2_y1 = r2.y;
    int r2_y2 = r2.y + r2.h - 1;

    if (r1_x1 <= r2_x2 && r1_x2 >= r2_x1 && r1_y1 <= r2_y2 && r1_y2 >= r2_y1) {
        return 1;
    } else {
        return 0;
    }
}

void place_room(int i) {
    int x, y, w, h, j;
    room_t room;

    do {
        x = rand() % (MAP_SIZE - MAX_ROOM_SIZE);
        y = rand() % (MAP_SIZE - MAX_ROOM_SIZE);
        w = rand() % MAX_ROOM_SIZE + 1;
        h = rand() % MAX_ROOM_SIZE + 1;

        room.x = x;
        room.y = y;
        room.w = w;
        room.h = h;

        for (j = 0; j < i; j++) {
            if (is_overlap(room, rooms[j])) {
                break;
            }
        }

    } while (j < i);

    rooms[i] = room;

    for (x = room.x + 1; x < room.x + room.w - 1; x++) {
        for (y = room.y + 1; y < room.y + room.h - 1; y++) {
            map[x][y] = '.';
        }
    }
}

void connect_rooms() {
    int i, x, y;
    room_t r1, r2;

    for (i = 1; i < MAX_ROOMS; i++) {
        r1 = rooms[i - 1];
        r2 = rooms[i];

        x = rand() % (r1.w - 2) + r1.x + 1;
        y = rand() % (r1.h - 2) + r1.y + 1;

        while (x != r2.x + r2.w / 2) {
            if (x < r2.x + r2.w / 2) {
                x++;
            } else {
                x--;
            }

            if (map[x][y] != '.') {
                map[x][y] = '.';
            }
        }

        while (y != r2.y + r2.h / 2) {
            if (y < r2.y + r2.h / 2) {
                y++;
            } else {
                y--;
            }

            if (map[x][y] != '.') {
                map[x][y] = '.';
            }
        }
    }
}

void print_map() {
    int i, j;

    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            putchar(map[i][j]);
        }
        putchar('\n');
    }
}

int main() {

    srand(time(NULL));

    init_map();

    int i;
    for (i = 0; i < MAX_ROOMS; i++) {
        place_room(i);
    }

    connect_rooms();

    print_map();

    return 0;
}