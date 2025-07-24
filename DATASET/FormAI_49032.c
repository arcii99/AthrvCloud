//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20
#define MAX_ROOMS 10
#define ROOM_MIN_SIZE 3
#define ROOM_MAX_SIZE 8

int map[HEIGHT][WIDTH];

void init_map() {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            map[y][x] = -1;
        }
    }
}

void add_horizontal_tunnel(int x1, int x2, int y) {
    int x;
    for (x = x1; x <= x2; x++) {
        map[y][x] = 0;
    }
}

void add_vertical_tunnel(int y1, int y2, int x) {
    int y;
    for (y = y1; y <= y2; y++) {
        map[y][x] = 0;
    }
}

void add_room(int x1, int y1, int x2, int y2) {
    int x, y;
    for (y = y1; y <= y2; y++) {
        for (x = x1; x <= x2; x++) {
            map[y][x] = 0;
        }
    }
}

void generate_dungeon() {
    int i;
    int num_rooms = 0;
    srand(time(NULL));
    init_map();
    for (i = 0; i < MAX_ROOMS; i++) {
        int room_width = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE) + ROOM_MIN_SIZE;
        int room_height = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE) + ROOM_MIN_SIZE;
        int x = rand() % (WIDTH - room_width - 1) + 1;
        int y = rand() % (HEIGHT - room_height - 1) + 1;
        if (map[y][x] == -1) {
            add_room(x, y, x + room_width - 1, y + room_height - 1);
            if (num_rooms == 0) {
                /* First room */
            } else {
                /* All other rooms */
                int prev_x = rand() % (room_width) + x;
                int prev_y = rand() % (room_height) + y;
                add_horizontal_tunnel(prev_x, x + room_width / 2, prev_y);
                add_vertical_tunnel(prev_y, y + room_height / 2, x + room_width / 2);
            }
            num_rooms++;
        }
    }
}

void print_dungeon() {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            if (map[y][x] == -1) {
                printf("#");
            } else if (map[y][x] == 0) {
                printf(".");
            } else {
                printf("%c", map[y][x]);
            }
        }
        printf("\n");
    }
}

int main() {
    generate_dungeon();
    print_dungeon();
    return 0;
}