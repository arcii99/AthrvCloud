//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAP_SIZE 20 // Size of the game map
#define MAX_ROOMS 8 // Maximum number of rooms to generate
#define ROOM_MAX_SIZE 6 // Maximum size of a room
#define ROOM_MIN_SIZE 3 // Minimum size of a room

char map[MAP_SIZE][MAP_SIZE]; // The game map

typedef struct {
    int x, y, w, h; // Position and size of the room
} Room;

// Function to generate a random number between min and max (inclusive)
int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to check if a cell is within the bounds of the map
int is_within_map(int x, int y) {
    return x >= 0 && x < MAP_SIZE && y >= 0 && y < MAP_SIZE;
}

// Function to check if a room overlaps with any other rooms
int does_overlap(Room room) {
    for (int x = room.x - 1; x < room.x + room.w + 1; x++) {
        for (int y = room.y - 1; y < room.y + room.h + 1; y++) {
            if (is_within_map(x, y) && map[x][y] == '#') {
                return 1;
            }
        }
    }

    return 0;
}

// Function to add a room to the map
void add_room(Room room) {
    for (int x = room.x; x < room.x + room.w; x++) {
        for (int y = room.y; y < room.y + room.h; y++) {
            map[x][y] = '#';
        }
    }
}

// Function to generate the game map
void generate_map(int num_rooms) {
    // Initialize the map with empty spaces
    memset(map, ' ', sizeof(map));

    // Generate the rooms
    Room rooms[MAX_ROOMS];
    for (int i = 0; i < num_rooms; i++) {
        int w = random_int(ROOM_MIN_SIZE, ROOM_MAX_SIZE);
        int h = random_int(ROOM_MIN_SIZE, ROOM_MAX_SIZE);
        int x = random_int(0, MAP_SIZE - w - 1);
        int y = random_int(0, MAP_SIZE - h - 1);

        Room room = {x, y, w, h};

        if (!does_overlap(room)) {
            add_room(room);
            rooms[i] = room;
        }
    }

    // Connect the rooms with corridors
    for (int i = 0; i < num_rooms - 1; i++) {
        Room A = rooms[i];
        Room B = rooms[i+1];

        // Connect the centers of the rooms
        int x1 = A.x + A.w/2;
        int y1 = A.y + A.h/2;
        int x2 = B.x + B.w/2;
        int y2 = B.y + B.h/2;

        while (x1 != x2 || y1 != y2) {
            if (x1 < x2) {
                x1++;
            }
            else if (x1 > x2) {
                x1--;
            }

            if (y1 < y2) {
                y1++;
            }
            else if (y1 > y2) {
                y1--;
            }

            map[x1][y1] = '#';
        }
    }
}

// Function to print the game map
void print_map() {
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            printf("%c", map[x][y]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    generate_map(5);
    print_map();

    return 0;
}