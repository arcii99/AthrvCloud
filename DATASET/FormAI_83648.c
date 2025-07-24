//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define WIDTH 50
#define HEIGHT 20
#define MAX_ROOMS 10

// Define a room struct
typedef struct _room {
    int x, y, w, h;
} Room;

// Declare global variables
char map[WIDTH][HEIGHT];
Room rooms[MAX_ROOMS];
int numRooms = 0;

// Function to initialize the map
void initMap() {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            map[i][j] = '#';
        }
    }
}

// Function to print the map
void printMap() {
    int i, j;
    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

// Function to generate a random integer between min and max
int randInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to create a room with the given parameters
Room createRoom(int x, int y, int w, int h) {
    Room room;
    room.x = x;
    room.y = y;
    room.w = w;
    room.h = h;
    return room;
}

// Function to check if a room overlaps with any other rooms
int roomOverlaps(Room room) {
    int i;
    for (i = 0; i < numRooms; i++) {
        Room other = rooms[i];
        if (room.x < other.x + other.w && room.x + room.w > other.x &&
            room.y < other.y + other.h && room.y + room.h > other.y) {
            return 1;
        }
    }
    return 0;
}

// Function to add a room to the map and the rooms array
void addRoom(Room room) {
    int i, j;
    for (i = room.x; i < room.x + room.w; i++) {
        for (j = room.y; j < room.y + room.h; j++) {
            map[i][j] = '.';
        }
    }
    rooms[numRooms++] = room;
}

// Function to generate the dungeon
void generateDungeon() {
    int i;
    for (i = 0; i < MAX_ROOMS; i++) {
        int x = randInt(1, WIDTH - 10);
        int y = randInt(1, HEIGHT - 10);
        int w = randInt(4, 10);
        int h = randInt(4, 10);
        Room room = createRoom(x, y, w, h);
        if (!roomOverlaps(room)) {
            addRoom(room);
        }
    }
}

int main() {
    srand(time(NULL));
    initMap();
    generateDungeon();
    printMap();
    return 0;
}