//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 30
#define MIN_ROOM_SIZE 3
#define MAX_ROOM_SIZE 10

int map[80][21];

struct Room {
    int x, y, width, height;
};

void init_map() {
    int x, y;
    for (x = 0; x < 80; x++) {
        for (y = 0; y < 21; y++) {
            map[x][y] = 0;
        }
    }
}

int is_valid(struct Room r) {
    int x, y;
    for (x = r.x - 1; x < r.x + r.width + 1; x++) {
        for (y = r.y - 1; y < r.y + r.height + 1; y++) {
            if (map[x][y]) {
                return 0;
            }
        }
    }
    return 1;
}

void carve_room(struct Room r) {
    int x, y;
    for (x = r.x; x < r.x + r.width; x++) {
        for (y = r.y; y < r.y + r.height; y++) {
            map[x][y] = 1;
        }
    }
}

void carve_hallway(int x1, int y1, int x2, int y2) {
    int x, y, dx, dy;
    dx = (x1 < x2) ? 1 : -1;
    dy = (y1 < y2) ? 1 : -1;
    x = x1;
    y = y1;
    while (x != x2) {
        map[x][y] = 1;
        x += dx;
    }
    while (y != y2) {
        map[x][y] = 1;
        y += dy;
    }
}

void connect_rooms(struct Room *rooms) {
    int i, j, x1, y1, x2, y2, dist_x, dist_y, max_dist;
    max_dist = (MAX_ROOM_SIZE + MAX_ROOM_SIZE) * 2;
    for (i = 0; i < MAX_ROOMS; i++) {
        x1 = rooms[i].x + (rooms[i].width / 2);
        y1 = rooms[i].y + (rooms[i].height / 2);
        for (j = i + 1; j < MAX_ROOMS; j++) {
            x2 = rooms[j].x + (rooms[j].width / 2);
            y2 = rooms[j].y + (rooms[j].height / 2);
            dist_x = abs(x2 - x1);
            dist_y = abs(y2 - y1);
            if (dist_x + dist_y < max_dist) {
                carve_hallway(x1, y1, x2, y2);
            }
        }
    }
}

void print_map() {
    int x, y;
    for (y = 0; y < 21; y++) {
        for (x = 0; x < 80; x++) {
            if (map[x][y]) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    init_map();
    struct Room rooms[MAX_ROOMS];
    int num_rooms = 0;
    while (num_rooms < MAX_ROOMS) {
        struct Room r;
        r.width = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE) + MIN_ROOM_SIZE;
        r.height = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE) + MIN_ROOM_SIZE;
        r.x = rand() % (80 - r.width - 1) + 1;
        r.y = rand() % (21 - r.height - 1) + 1;
        if (is_valid(r)) {
            carve_room(r);
            rooms[num_rooms] = r;
            num_rooms++;
        }
    }
    connect_rooms(rooms);
    print_map();
    return 0;
}