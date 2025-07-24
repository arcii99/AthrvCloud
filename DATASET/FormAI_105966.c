//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 10
#define ROOM_MAX_SIZE 6
#define ROOM_MIN_SIZE 3
#define MAX_ROOMS 5

// Game map
int map[MAP_WIDTH][MAP_HEIGHT];

// Room struct
typedef struct {
    int x, y, width, height;
} Room;

// Function to create rooms on the game map
void createRoom(Room room) {
    int x, y;
    for (x = room.x; x < room.x+room.width; x++) {
        for (y = room.y; y < room.y+room.height; y++) {
            map[x][y] = 0;
        }
    }
}

// Function to create a path between two points
void createPath(int x1, int y1, int x2, int y2) {
    int x, y;

    // Horizontal path
    if (x1 < x2) {
        for (x = x1; x < x2; x++) {
            map[x][y1] = 0;
        }
    } else {
        for (x = x1; x > x2; x--) {
            map[x][y1] = 0;
        }
    }

    // Vertical path
    if (y1 < y2) {
        for (y = y1; y < y2; y++) {
            map[x2][y] = 0;
        }
    } else {
        for (y = y1; y > y2; y--) {
            map[x2][y] = 0;
        }
    }
}

// Function to generate a random position for a room
int randPosition(int size) {
    return rand() % (size - 2) + 1;
}

// Function to generate a random room
Room randRoom() {
    Room room;
    room.width = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
    room.height = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
    room.x = randPosition(MAP_WIDTH - room.width);
    room.y = randPosition(MAP_HEIGHT - room.height);
    return room;
}

// Function to check if two rooms overlap
int overlap(Room room1, Room room2) {
    return (room1.x <= room2.x + room2.width && room1.x + room1.width >= room2.x &&
            room1.y <= room2.y + room2.height && room1.y + room1.height >= room2.y);
}

// Function to generate the dungeon map
void generateMap() {
    // Fill the map with walls
    int x, y;
    for (x = 0; x < MAP_WIDTH; x++) {
        for (y = 0; y < MAP_HEIGHT; y++) {
            map[x][y] = 1;
        }
    }

    // Create rooms
    int numRooms = 0;
    Room rooms[MAX_ROOMS];
    while (numRooms < MAX_ROOMS) {
        Room room = randRoom();
        int i;
        for (i = 0; i < numRooms; i++) {
            if (overlap(room, rooms[i])) {
                break;
            }
        }
        if (i == numRooms) {
            rooms[numRooms] = room;
            createRoom(room);
            numRooms++;
        }
    }

    // Create paths between the rooms
    int i;
    for (i = 0; i < numRooms-1; i++) {
        createPath(rooms[i].x + rooms[i].width/2, rooms[i].y + rooms[i].height/2,
                   rooms[i+1].x + rooms[i+1].width/2, rooms[i+1].y + rooms[i+1].height/2);
    }
}

int main() {
    srand(time(NULL));

    // Generate map and print it
    generateMap();
    int x, y;
    for (y = 0; y < MAP_HEIGHT; y++) {
        for (x = 0; x < MAP_WIDTH; x++) {
            if (map[x][y] == 1) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }

    return 0;
}