//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20
#define ROOM_MIN_SIZE 6
#define ROOM_MAX_SIZE 10
#define MAX_ROOMS 7

char map[MAP_WIDTH][MAP_HEIGHT];

typedef struct {
    int x, y, width, height;
} room_t;

void generate_map() {
    int num_rooms = 0;
    room_t rooms[MAX_ROOMS];

    // initialize the map with walls
    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            map[x][y] = '#';
        }
    }

    // randomly generate rooms
    srand(time(NULL));
    while (num_rooms < MAX_ROOMS) {
        int room_width = (rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE)) + ROOM_MIN_SIZE;
        int room_height = (rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE)) + ROOM_MIN_SIZE;
        int room_x = rand() % (MAP_WIDTH - room_width - 1) + 1;
        int room_y = rand() % (MAP_HEIGHT - room_height - 1) + 1;

        // make sure the room doesn't overlap with any existing rooms
        int overlapping = 0;
        for (int i = 0; i < num_rooms; i++) {
            if (room_x < rooms[i].x + rooms[i].width + 1 &&
                room_x + room_width + 1 > rooms[i].x &&
                room_y < rooms[i].y + rooms[i].height + 1 &&
                room_y + room_height + 1 > rooms[i].y) {
                overlapping = 1;
                break;
            }
        }

        if (!overlapping) {
            for (int x = room_x; x < room_x + room_width; x++) {
                for (int y = room_y; y < room_y + room_height; y++) {
                    if (x == room_x || x == room_x + room_width - 1 ||
                        y == room_y || y == room_y + room_height - 1) {
                        map[x][y] = '#';
                    } else {
                        map[x][y] = '.';
                    }
                }
            }

            rooms[num_rooms].x = room_x;
            rooms[num_rooms].y = room_y;
            rooms[num_rooms].width = room_width;
            rooms[num_rooms].height = room_height;
            num_rooms++;
        }
    }
}

void print_map() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            printf("%c", map[x][y]);
        }
        printf("\n");
    }
}

int main() {
    generate_map();
    print_map();
    return 0;
}