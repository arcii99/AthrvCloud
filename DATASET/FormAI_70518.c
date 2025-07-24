//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24
#define MAX_ROOMS 6
#define MIN_ROOM_WIDTH 4
#define MIN_ROOM_HEIGHT 3
#define MAX_ROOM_WIDTH 10
#define MAX_ROOM_HEIGHT 8

char map[HEIGHT][WIDTH];

struct Room {
    int x, y, width, height;
};

struct Room rooms[MAX_ROOMS];

void init_map() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            map[y][x] = '#';
        }
    }
}

void draw_map() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}

void add_room(int i) {
    int x = rand() % (WIDTH - MAX_ROOM_WIDTH), y = rand() % (HEIGHT - MAX_ROOM_HEIGHT);
    int width = rand() % (MAX_ROOM_WIDTH - MIN_ROOM_WIDTH) + MIN_ROOM_WIDTH;
    int height = rand() % (MAX_ROOM_HEIGHT - MIN_ROOM_HEIGHT) + MIN_ROOM_HEIGHT;
    rooms[i] = (struct Room) { x, y, width, height };

    for (int ry = y; ry < y + height; ry++) {
        for (int rx = x; rx < x + width; rx++) {
            map[ry][rx] = '.';
        }
    }
}

void connect_rooms() {
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        int x1 = rooms[i].x + rooms[i].width / 2, y1 = rooms[i].y + rooms[i].height / 2;
        int x2 = rooms[i+1].x + rooms[i+1].width / 2, y2 = rooms[i+1].y + rooms[i+1].height / 2;

        int dx = x2 - x1, dy = y2 - y1;
        while (x1 != x2 || y1 != y2) {
            if (rand() % 2 == 0 && x1 != x2) {
                x1 += dx > 0 ? 1 : -1;
            } else if (y1 != y2) {
                y1 += dy > 0 ? 1 : -1;
            }
            map[y1][x1] = '.';
        }
    }
}

int main() {
    srand(time(NULL));

    init_map();

    for (int i = 0; i < MAX_ROOMS; i++) {
        add_room(i);
    }

    connect_rooms();

    draw_map();

    return 0;
}