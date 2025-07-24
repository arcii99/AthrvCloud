//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 10
#define MAX_ROOMS 6
#define ROOM_MIN_SIZE 3
#define ROOM_MAX_SIZE 6

int map[MAP_HEIGHT][MAP_WIDTH];

typedef struct {
    int x, y, width, height;
} Room;

Room* rooms[MAX_ROOMS];

void generate_map() {
    // Initialize map with walls
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = '#';
        }
    }

    // Generate rooms
    int num_rooms = 0;
    while (num_rooms < MAX_ROOMS) {
        int room_x = rand() % (MAP_WIDTH - ROOM_MAX_SIZE);
        int room_y = rand() % (MAP_HEIGHT - ROOM_MAX_SIZE);
        int room_width = ROOM_MIN_SIZE + (rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE));
        int room_height = ROOM_MIN_SIZE + (rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE));

        Room* new_room = malloc(sizeof(Room));
        new_room->x = room_x;
        new_room->y = room_y;
        new_room->width = room_width;
        new_room->height = room_height;

        // Check if the new room overlaps with any existing rooms
        int overlap = 0;
        for (int i = 0; i < num_rooms; i++) {
            Room* other_room = rooms[i];
            if (room_x < other_room->x + other_room->width &&
                room_x + room_width > other_room->x &&
                room_y < other_room->y + other_room->height &&
                room_y + room_height > other_room->y) {
                overlap = 1;
                break;
            }
        }

        if (!overlap) {
            // Add the new room to the map
            for (int y = room_y; y < room_y + room_height; y++) {
                for (int x = room_x; x < room_x + room_width; x++) {
                    map[y][x] = '.';
                }
            }
            rooms[num_rooms] = new_room;
            num_rooms++;
        } else {
            // The new room overlaps with an existing room, so free it
            free(new_room);
        }
    }
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
    // Seed the random number generator
    srand(time(NULL));

    generate_map();
    print_map();

    return 0;
}