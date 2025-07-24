//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20
#define MAX_ROOMS 10
#define ROOM_MIN_SIZE 3
#define ROOM_MAX_SIZE 10

char dungeon_map[MAP_HEIGHT][MAP_WIDTH];

struct room_t {
    int x, y;
    int width, height;
};

// Returns the randomly generated size of a room
int get_random_room_size() {
    return rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
}

// Returns true if the given new room does not overlap with existing rooms, false otherwise 
int is_valid_room(struct room_t new_room, struct room_t* existing_rooms, int num_existing_rooms) {
    for (int i = 0; i < num_existing_rooms; i++) {
        if (new_room.x < existing_rooms[i].x + existing_rooms[i].width &&
            new_room.x + new_room.width > existing_rooms[i].x &&
            new_room.y < existing_rooms[i].y + existing_rooms[i].height &&
            new_room.y + new_room.height > existing_rooms[i].y) {
            return 0;
        }
    }
    return 1;
}

// Fill the given map with '#'
void initialize_map() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            dungeon_map[y][x] = '#';
        }
    }
}

// Draw a given room on the given map
void draw_room(struct room_t room) {
    for (int y = room.y; y < room.y + room.height; y++) {
        for (int x = room.x; x < room.x + room.width; x++) {
            dungeon_map[y][x] = '.';
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    initialize_map(); // Fill the map with '#'

    struct room_t rooms[MAX_ROOMS];
    int num_rooms = 0;

    // Generate and add rooms to the map
    for (int i = 0; i < MAX_ROOMS; i++) {
        int new_room_x = rand() % (MAP_WIDTH - ROOM_MAX_SIZE - 1) + 1;
        int new_room_y = rand() % (MAP_HEIGHT - ROOM_MAX_SIZE - 1) + 1;
        struct room_t new_room = {new_room_x, new_room_y, get_random_room_size(), get_random_room_size()};
        if (is_valid_room(new_room, rooms, num_rooms)) {
            rooms[num_rooms] = new_room;
            draw_room(rooms[num_rooms]);
            num_rooms++;
        }
    }

    // Print out the map
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            printf("%c", dungeon_map[y][x]);
        }
        printf("\n");
    }

    return 0;
}