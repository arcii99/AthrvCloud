//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAP_SIZE 10
#define MAX_ROOMS 6

// Struct to represent a room in the game
typedef struct {
    int x, y, width, height;
} Room;

// Function to generate a random integer in a given range
int random_int(int low, int high) {
    return rand() % (high - low + 1) + low;
}

// Function to initialize the game map with '#' (Walls) and '.' (Floors)
void initialize_map(char map[][MAP_SIZE]) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (i == 0 || j == 0 || i == MAP_SIZE - 1 || j == MAP_SIZE - 1) {
                map[i][j] = '#';
            } else {
                map[i][j] = '.';
            }
        }
    }
}

// Function to generate a new room
Room create_room() {
    Room room;
    room.width = random_int(3, 6);
    room.height = random_int(3, 6);
    room.x = random_int(1, MAP_SIZE - room.width - 1);
    room.y = random_int(1, MAP_SIZE - room.height - 1);
    return room;
}

// Function to check if two rooms intersect
bool rooms_overlap(Room r1, Room r2) {
    bool x_overlap = (r1.x <= r2.x && r1.x + r1.width >= r2.x) ||
                     (r2.x <= r1.x && r2.x + r2.width >= r1.x);
    bool y_overlap = (r1.y <= r2.y && r1.y + r1.height >= r2.y) ||
                     (r2.y <= r1.y && r2.y + r2.height >= r1.y);
    return x_overlap && y_overlap;
}

// Function to draw a room in the game map
void draw_room(char map[][MAP_SIZE], Room room) {
    for (int i = room.x; i < room.x + room.width; i++) {
        for (int j = room.y; j < room.y + room.height; j++) {
            map[i][j] = '.';
        }
    }
}

// Function to connect two rooms with a corridor
void connect_rooms(char map[][MAP_SIZE], Room r1, Room r2) {
    int x1 = r1.x + random_int(1, r1.width - 1);
    int y1 = r1.y + random_int(1, r1.height - 1);
    int x2 = r2.x + random_int(1, r2.width - 1);
    int y2 = r2.y + random_int(1, r2.height - 1);

    while (x1 != x2 || y1 != y2) {
        if (x1 != x2) {
            map[x1][y1] = '.';
            if (x1 < x2) {
                x1++;
            } else {
                x1--;
            }
        } else {
            map[x1][y1] = '.';
            if (y1 < y2) {
                y1++;
            } else {
                y1--;
            }
        }
    }
}

// Main function
int main(void) {
    srand(time(NULL)); // Initialize the random number generator

    char map[MAP_SIZE][MAP_SIZE];
    initialize_map(map); // Initialize empty game map

    Room rooms[MAX_ROOMS];
    int num_rooms = 0;

    // Generate rooms and check for overlaps to ensure they don't overlap
    while (num_rooms < MAX_ROOMS) {
        Room new_room = create_room();
        bool overlaps = false;

        for (int i = 0; i < num_rooms; i++) {
            if (rooms_overlap(new_room, rooms[i])) {
                overlaps = true;
                break;
            }
        }

        if (!overlaps) {
            rooms[num_rooms] = new_room;
            draw_room(map, new_room);
            num_rooms++;
        }
    }

    // Connect all rooms with corridors
    for (int i = 0; i < num_rooms - 1; i++) {
        connect_rooms(map, rooms[i], rooms[i + 1]);
    }

    // Print out the generated map
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}