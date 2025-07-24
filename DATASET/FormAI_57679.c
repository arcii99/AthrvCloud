//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20
#define MAX_ROOMS 10
#define MAX_ROOM_WIDTH 10
#define MAX_ROOM_HEIGHT 5

// Define structure for a tile
typedef struct {
    int x;
    int y;
    char symbol;
} Tile;

// Define structure for a room
typedef struct {
    int x;
    int y;
    int width;
    int height;
} Room;

// Define array to hold tiles
Tile tiles[WIDTH][HEIGHT];

// Generate random integer within range
int randInt(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Generate a random room
Room randRoom() {
    Room room;
    room.width = randInt(3, MAX_ROOM_WIDTH);
    room.height = randInt(3, MAX_ROOM_HEIGHT);
    room.x = randInt(2, WIDTH - room.width - 1);
    room.y = randInt(2, HEIGHT - room.height - 1);
    return room;
}

// Determine if two rooms intersect
int intersect(Room a, Room b) {
    if (a.x + a.width <= b.x || b.x + b.width <= a.x) {
        return 0;
    } else if (a.y + a.height <= b.y || b.y + b.height <= a.y) {
        return 0;
    } else {
        return 1;
    }
}

// Generate the tile map
void generateMap() {
    int i, j, k, l;
    Room rooms[MAX_ROOMS];
    int numRooms = 0;
    
    // Initialize the tiles array
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            tiles[i][j].x = i;
            tiles[i][j].y = j;
            tiles[i][j].symbol = '#';
        }
    }
    
    // Generate the rooms
    for (i = 0; i < MAX_ROOMS; i++) {
        Room newRoom = randRoom();
        int failed = 0;
        for (j = 0; j < numRooms; j++) {
            if (intersect(newRoom, rooms[j])) {
                failed = 1;
                break;
            }
        }
        if (!failed) {
            rooms[numRooms] = newRoom;
            numRooms++;
        }
    }
    
    // Draw the rooms
    for (i = 0; i < numRooms; i++) {
        Room room = rooms[i];
        for (j = room.x; j < room.x + room.width; j++) {
            for (k = room.y; k < room.y + room.height; k++) {
                tiles[j][k].symbol = '.';
            }
        }
    }
    
    // Connect the rooms
    for (i = 0; i < numRooms - 1; i++) {
        Room a = rooms[i];
        Room b = rooms[i+1];
        int ax = a.x + a.width/2;
        int ay = a.y + a.height/2;
        int bx = b.x + b.width/2;
        int by = b.y + b.height/2;
        
        if (randInt(0, 1) == 0) {
            for (j = ax; j <= bx; j++) {
                tiles[j][ay].symbol = '.';
            }
            for (j = ay; j <= by; j++) {
                tiles[bx][j].symbol = '.';
            }
        } else {
            for (j = ay; j <= by; j++) {
                tiles[ax][j].symbol = '.';
            }
            for (j = ax; j <= bx; j++) {
                tiles[j][by].symbol = '.';
            }
        }
    }
}

// Print the tile map
void printMap() {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            printf("%c", tiles[i][j].symbol);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    generateMap();
    printMap();
    return 0;
}