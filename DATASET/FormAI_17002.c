//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define MAX_ROOMS 6

typedef struct room {
    int x, y, width, height;
} room_t;

void generate_map(char map[MAP_SIZE][MAP_SIZE], room_t rooms[MAX_ROOMS]) {
    // fill map with walls
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = '#';
        }
    }

    // generate rooms
    int num_rooms = 0;
    while (num_rooms < MAX_ROOMS) {
        int w = rand() % 5 + 4; // random width between 4-8
        int h = rand() % 5 + 4; // random height between 4-8
        int x = rand() % (MAP_SIZE - w - 1) + 1; // random x-coordinate within map
        int y = rand() % (MAP_SIZE - h - 1) + 1; // random y-coordinate within map
        room_t new_room = (room_t){x, y, w, h};

        // check if room overlaps with previous rooms
        int overlaps = 0;
        for (int i = 0; i < num_rooms; i++) {
            room_t prev_room = rooms[i];
            if (new_room.x < prev_room.x + prev_room.width + 1 &&
                new_room.x + new_room.width + 1 > prev_room.x &&
                new_room.y < prev_room.y + prev_room.height + 1 &&
                new_room.y + new_room.height + 1 > prev_room.y) {
                overlaps = 1;
                break;
            }
        }

        if (!overlaps) {
            // carve out the room
            for (int i = x; i < x + w; i++) {
                for (int j = y; j < y + h; j++) {
                    map[i][j] = '.';
                }
            }
            rooms[num_rooms] = new_room;
            num_rooms++;
        }
    }

    // connect rooms with hallways
    for (int i = 0; i < num_rooms - 1; i++) {
        int start_x = rooms[i].x + rooms[i].width / 2;
        int start_y = rooms[i].y + rooms[i].height / 2;
        int end_x = rooms[i+1].x + rooms[i+1].width / 2;
        int end_y = rooms[i+1].y + rooms[i+1].height / 2;

        while (start_x != end_x) {
            if (start_x < end_x) {
                start_x++;
            } else {
                start_x--;
            }
            map[start_x][start_y] = '.';
        }

        while (start_y != end_y) {
            if (start_y < end_y) {
                start_y++;
            } else {
                start_y--;
            }
            map[start_x][start_y] = '.';
        }
    }
}

int main() {
    char map[MAP_SIZE][MAP_SIZE];
    room_t rooms[MAX_ROOMS];
    srand(time(NULL));
    generate_map(map, rooms);

    // print out the map
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}