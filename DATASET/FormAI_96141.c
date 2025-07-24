//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MAP_HEIGHT 30
#define MAP_WIDTH 80
#define ROOM_MIN_SIZE 4
#define ROOM_MAX_SIZE 10
#define MAX_ROOMS 20

// Struct for rooms
typedef struct {
    int x;
    int y;
    int width;
    int height;
} Room;

// Function prototypes
void generateMap(char map[MAP_HEIGHT][MAP_WIDTH]);
void createRooms(Room* rooms, int numRooms, char map[MAP_HEIGHT][MAP_WIDTH]);
void connectRooms(Room room1, Room room2, char map[MAP_HEIGHT][MAP_WIDTH]);
void printMap(char map[MAP_HEIGHT][MAP_WIDTH]);

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the map array
    char map[MAP_HEIGHT][MAP_WIDTH];

    // Generate the map
    generateMap(map);

    // Print the map
    printMap(map);

    return 0;
}

// Function to generate the map
void generateMap(char map[MAP_HEIGHT][MAP_WIDTH]) {
    // Fill the map with walls
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = '#';
        }
    }

    // Create the rooms
    Room rooms[MAX_ROOMS];
    int numRooms = 0;
    for (int i = 0; i < MAX_ROOMS; i++) {
        // Generate a random size for the room
        int width = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
        int height = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;

        // Generate a random position for the room
        int x = rand() % (MAP_WIDTH - width - 1) + 1;
        int y = rand() % (MAP_HEIGHT - height - 1) + 1;

        // Create the room
        Room room = {x, y, width, height};

        // Check if the room overlaps with any other room and is not too close to the edge of the map
        int overlap = 0;
        for (int j = 0; j < numRooms; j++) {
            if (room.x < rooms[j].x + rooms[j].width + 2 &&
                room.x + room.width + 2 > rooms[j].x &&
                room.y < rooms[j].y + rooms[j].height + 2 &&
                room.y + room.height + 2 > rooms[j].y) {
                overlap = 1;
                break;
            }
            if (room.x < 1 || room.x + room.width + 1 > MAP_WIDTH ||
                room.y < 1 || room.y + room.height + 1 > MAP_HEIGHT) {
                overlap = 1;
                break;
            }
        }

        // If the room does not overlap, create it
        if (!overlap) {
            rooms[numRooms++] = room;
            for (int y = room.y + 1; y < room.y + room.height + 1; y++) {
                for (int x = room.x + 1; x < room.x + room.width + 1; x++) {
                    map[y][x] = '.';
                }
            }
        }
    }

    // Connect the rooms with tunnels
    for (int i = 1; i < numRooms; i++) {
        connectRooms(rooms[i - 1], rooms[i], map);
    }

    // Add the player character to a random room
    int roomIndex = rand() % numRooms;
    int x = rand() % rooms[roomIndex].width + rooms[roomIndex].x + 1;
    int y = rand() % rooms[roomIndex].height + rooms[roomIndex].y + 1;
    map[y][x] = '@';
}

// Function to create the rooms
void createRooms(Room* rooms, int numRooms, char map[MAP_HEIGHT][MAP_WIDTH]) {
    // Create the rooms
    for (int i = 0; i < numRooms; i++) {
        // Generate a random size for the room
        int width = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
        int height = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;

        // Generate a random position for the room
        int x = rand() % (MAP_WIDTH - width - 1) + 1;
        int y = rand() % (MAP_HEIGHT - height - 1) + 1;

        // Create the room
        Room room = {x, y, width, height};

        // Check if the room overlaps with any other room and is not too close to the edge of the map
        int overlap = 0;
        for (int j = 0; j < i; j++) {
            if (room.x < rooms[j].x + rooms[j].width + 2 &&
                room.x + room.width + 2 > rooms[j].x &&
                room.y < rooms[j].y + rooms[j].height + 2 &&
                room.y + room.height + 2 > rooms[j].y) {
                overlap = 1;
                break;
            }
            if (room.x < 1 || room.x + room.width + 1 > MAP_WIDTH ||
                room.y < 1 || room.y + room.height + 1 > MAP_HEIGHT) {
                overlap = 1;
                break;
            }
        }

        // If the room does not overlap, create it
        if (!overlap) {
            rooms[i] = room;
            for (int y = room.y + 1; y < room.y + room.height + 1; y++) {
                for (int x = room.x + 1; x < room.x + room.width + 1; x++) {
                    map[y][x] = '.';
                }
            }
        }
    }
}

// Function to connect the rooms
void connectRooms(Room room1, Room room2, char map[MAP_HEIGHT][MAP_WIDTH]) {
    // Find a random point in each room and connect them with a tunnel
    int x1 = rand() % room1.width + room1.x + 1;
    int y1 = rand() % room1.height + room1.y + 1;
    int x2 = rand() % room2.width + room2.x + 1;
    int y2 = rand() % room2.height + room2.y + 1;
    while (x1 != x2 || y1 != y2) {
        if (x1 < x2) {
            x1++;
        } else if (x1 > x2) {
            x1--;
        }
        if (y1 < y2) {
            y1++;
        } else if (y1 > y2) {
            y1--;
        }
        map[y1][x1] = '.';
    }
}

// Function to print the map
void printMap(char map[MAP_HEIGHT][MAP_WIDTH]) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}