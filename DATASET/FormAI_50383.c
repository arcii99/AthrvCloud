//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24
#define MIN_ROOM_SIZE 5
#define MAX_ROOM_SIZE 12

// Struct for holding the position of a tile on the map
typedef struct Pos {
    int x, y;
} Pos;

// Struct for holding information about a room
typedef struct Room {
    Pos pos;
    int w, h;
} Room;

// 2D array to represent the map
char map[HEIGHT][WIDTH];

// Function to randomize the seed for the RNG
void seedRNG() {
    srand(time(NULL));
}

// Function to generate a random integer within a specified range
int randomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to check if a position is inside the map bounds
int isPosInBounds(Pos p) {
    return p.x >= 0 && p.x < WIDTH && p.y >= 0 && p.y < HEIGHT;
}

// Function to check if two rooms overlap
int doRoomsOverlap(Room r1, Room r2) {
    return r1.pos.x < r2.pos.x + r2.w &&
           r1.pos.x + r1.w > r2.pos.x && 
           r1.pos.y < r2.pos.y + r2.h &&
           r1.pos.y + r1.h > r2.pos.y;
}

// Function to create a new room with random dimensions and position
Room generateRoom() {
    Room r;
    r.w = randomInt(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
    r.h = randomInt(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
    r.pos.x = randomInt(0, WIDTH - r.w);
    r.pos.y = randomInt(0, HEIGHT - r.h);
    return r;
}

// Function to draw a room onto the map
void drawRoom(Room r) {
    for (int y = r.pos.y; y < r.pos.y + r.h; y++) {
        for (int x = r.pos.x; x < r.pos.x + r.w; x++) {
            map[y][x] = '.';
        }
    }
}

// Function to generate a new map with random rooms
void generateMap() {
    // Fill the map with walls
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            map[y][x] = '#';
        }
    }

    // Generate some rooms
    Room rooms[10];
    int numRooms = 0;
    while (numRooms < 10) {
        Room r = generateRoom();
        int overlaps = 0;
        for (int i = 0; i < numRooms; i++) {
            if (doRoomsOverlap(r, rooms[i])) {
                overlaps = 1;
                break;
            }
        }
        if (!overlaps) {
            rooms[numRooms++] = r;
        }
    }

    // Draw the rooms onto the map
    for (int i = 0; i < numRooms; i++) {
        drawRoom(rooms[i]);
    }
}

// Function to print the map to the console
void printMap() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}

int main() {
    seedRNG();
    generateMap();
    printMap();

    return 0;
}