//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20
#define MAX_ROOMS 10

char map[MAP_WIDTH][MAP_HEIGHT];

typedef struct {
    int x, y, width, height;
} Room;

void init_map() {
    int x, y;
    for (x = 0; x < MAP_WIDTH; x++) {
        for (y = 0; y < MAP_HEIGHT; y++) {
            map[x][y] = '#';
        }
    }
}

void print_map() {
    int x, y;
    for (y = 0; y < MAP_HEIGHT; y++) {
        for (x = 0; x < MAP_WIDTH; x++) {
            printf("%c", map[x][y]);
        }
        printf("\n");
    }
}

int is_room_overlap(Room r, Room rooms[MAX_ROOMS], int num_rooms) {
    int i;
    for (i = 0; i < num_rooms; i++) {
        Room r2 = rooms[i];
        if (r.x < r2.x + r2.width &&
            r.x + r.width > r2.x &&
            r.y < r2.y + r2.height &&
            r.y + r.height > r2.y) {
            return 1;
        }
    }
    return 0;
}

void add_room(Room r) {
    int x, y;
    for (x = r.x; x < r.x + r.width; x++) {
        for (y = r.y; y < r.y + r.height; y++) {
            map[x][y] = '.';
        }
    }
}

void generate_map() {
    Room rooms[MAX_ROOMS];
    int num_rooms = 0;
    int attempts = 0;
    srand(time(NULL));

    while (num_rooms < MAX_ROOMS && attempts < MAX_ROOMS * 10) {
        Room r;
        r.width = rand() % 10 + 5;
        r.height = rand() % 5 + 3;
        r.x = rand() % (MAP_WIDTH - r.width - 1) + 1;
        r.y = rand() % (MAP_HEIGHT - r.height - 1) + 1;

        if (!is_room_overlap(r, rooms, num_rooms)) {
            add_room(r);
            rooms[num_rooms++] = r;
        }

        attempts++;
    }
}

int main(int argc, char **argv) {
    init_map();
    generate_map();
    print_map();

    return 0;
}