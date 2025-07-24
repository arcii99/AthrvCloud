//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 25
#define MAX_ROOMS 10
#define ROOM_MIN_SIZE 3
#define ROOM_MAX_SIZE 10

char map[MAP_HEIGHT][MAP_WIDTH];

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point pos;
    int width, height;
} Room;

void generate_map() {
    srand(time(NULL));

    // Fill map with solid walls
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = '#';
        }
    }

    // Create rooms
    Room *rooms = malloc(sizeof(Room) * MAX_ROOMS);
    int num_rooms = 0;
    for (int room = 0; room < MAX_ROOMS; room++) {
        int width = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
        int height = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
        int x = rand() % (MAP_WIDTH - width - 1) + 1;
        int y = rand() % (MAP_HEIGHT - height - 1) + 1;

        Room new_room = {{x, y}, width, height};

        // Check for overlap with existing rooms
        int overlap = 0;
        for (int r = 0; r < num_rooms; r++) {
            Room old_room = rooms[r];
            if (new_room.pos.x < old_room.pos.x + old_room.width &&
                new_room.pos.x + new_room.width > old_room.pos.x &&
                new_room.pos.y < old_room.pos.y + old_room.height &&
                new_room.pos.y + new_room.height > old_room.pos.y) {
                overlap = 1;
                break;
            }
        }

        if (!overlap) {
            // Carve out room from map
            for (int y = new_room.pos.y; y < new_room.pos.y + new_room.height; y++) {
                for (int x = new_room.pos.x; x < new_room.pos.x + new_room.width; x++) {
                    map[y][x] = '.';
                }
            }

            // Add room to list of rooms
            rooms[num_rooms++] = new_room;
        }
    }

    // Create corridors between rooms
    for (int r1 = 0; r1 < num_rooms - 1; r1++) {
        Point center1 = {rooms[r1].pos.x + rooms[r1].width / 2, rooms[r1].pos.y + rooms[r1].height / 2};
        Point center2 = {rooms[r1 + 1].pos.x + rooms[r1 + 1].width / 2, rooms[r1 + 1].pos.y + rooms[r1 + 1].height / 2};

        while (center1.x != center2.x) {
            if (center1.x < center2.x) {
                center1.x++;
            } else {
                center1.x--;
            }

            map[center1.y][center1.x] = '.';
        }

        while (center1.y != center2.y) {
            if (center1.y < center2.y) {
                center1.y++;
            } else {
                center1.y--;
            }

            map[center1.y][center1.x] = '.';
        }
    }

    free(rooms);
}

void print_map() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}

int main() {
    generate_map();
    print_map();
    return 0;
}