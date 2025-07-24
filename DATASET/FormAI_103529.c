//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 20
#define COLS 80
#define MAX_ROOMS 10

// Struct to represent a room
typedef struct Room {
    int x, y;
    int w, h;
} Room;

// Struct to represent a tile on the map
typedef struct Tile {
    char symbol;
    int explored;
} Tile;

// Function to create a new room
Room new_room(int x, int y, int w, int h) {
    Room room;
    room.x = x;
    room.y = y;
    room.w = w;
    room.h = h;
    return room;
}

// Function to check if two rooms intersect
int intersect(Room a, Room b) {
    return (a.x <= b.x + b.w &&
            a.x + a.w >= b.x &&
            a.y <= b.y + b.h &&
            a.y + a.h >= b.y);
}

// Function to generate a random number within a range
int rand_range(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random room
Room random_room() {
    int w = rand_range(5, 15);
    int h = rand_range(5, 10);
    int x = rand_range(1, COLS - w - 1);
    int y = rand_range(1, ROWS - h - 1);
    return new_room(x, y, w, h);
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Create the map and fill it with walls
    Tile map[ROWS][COLS];
    memset(map, '#', sizeof(map));

    // Generate a set of random rooms
    Room rooms[MAX_ROOMS];
    int num_rooms = 0;
    while (num_rooms < MAX_ROOMS) {
        Room room = random_room();

        // Check if the new room overlaps with any existing rooms
        int overlap = 0;
        for (int i = 0; i < num_rooms; i++) {
            if (intersect(room, rooms[i])) {
                overlap = 1;
                break;
            }
        }

        // If the new room doesn't overlap, add it to the map
        if (!overlap) {
            rooms[num_rooms] = room;
            num_rooms++;

            for (int y = room.y; y < room.y + room.h; y++) {
                for (int x = room.x; x < room.x + room.w; x++) {
                    map[y][x].symbol = '.';
                }
            }
        }
    }

    // Connect the rooms with corridors
    for (int i = 0; i < num_rooms - 1; i++) {
        int x1 = rooms[i].x + rand() % rooms[i].w;
        int y1 = rooms[i].y + rand() % rooms[i].h;
        int x2 = rooms[i + 1].x + rand() % rooms[i + 1].w;
        int y2 = rooms[i + 1].y + rand() % rooms[i + 1].h;

        int dx = (x2 > x1) ? 1 : -1;
        int dy = (y2 > y1) ? 1 : -1;

        while (x1 != x2) {
            x1 += dx;
            map[y1][x1].symbol = '.';
        }
        while (y1 != y2) {
            y1 += dy;
            map[y1][x1].symbol = '.';
        }
    }

    // Print the map
    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLS; x++) {
            printf("%c", map[y][x].symbol);
        }
        printf("\n");
    }

    return 0;
}