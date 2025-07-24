//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: detailed
#include <stdlib.h>
#include <stdio.h>

#define MAX_LEVEL 5
#define MAX_ROOMS_PER_LEVEL 6
#define MIN_ROOM_WIDTH 5
#define MIN_ROOM_HEIGHT 3
#define MAX_ROOM_WIDTH 10
#define MAX_ROOM_HEIGHT 7
#define MAP_WIDTH 80
#define MAP_HEIGHT 25

// Struct definition for a room
typedef struct Room {
    int x, y, width, height;
} Room;

// Struct definition for a map
typedef struct Map {
    char tiles[MAP_HEIGHT][MAP_WIDTH];
    Room rooms[MAX_LEVEL][MAX_ROOMS_PER_LEVEL];
    int numRooms[MAX_LEVEL];
} Map;

// Function prototypes
void initMap(Map* map);
void generateRooms(Map* map);
void connectRooms(Map* map, int level);
void printMap(Map* map);

// Entry point of the program
int main() {
    Map map;
    initMap(&map);
    generateRooms(&map);
    connectRooms(&map, 0);
    printMap(&map);
    return 0;
}

// Initializes the map
void initMap(Map* map) {
    int i, j;
    // Initialize all tiles as walls
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            map->tiles[i][j] = '#';
        }
    }
    // Initialize number of rooms to zero for every level
    for (i = 0; i < MAX_LEVEL; i++) {
        map->numRooms[i] = 0;
    }
}

// Generates random rooms for each level
void generateRooms(Map* map) {
    int i, j, k;
    for (i = 0; i < MAX_LEVEL; i++) {
        // Generate a random number of rooms for this level
        int numRooms = rand() % MAX_ROOMS_PER_LEVEL + 1;
        map->numRooms[i] = numRooms;
        // Generate each room
        for (j = 0; j < numRooms; j++) {
            Room room;
            room.width = rand() % (MAX_ROOM_WIDTH - MIN_ROOM_WIDTH + 1) + MIN_ROOM_WIDTH;
            room.height = rand() % (MAX_ROOM_HEIGHT - MIN_ROOM_HEIGHT + 1) + MIN_ROOM_HEIGHT;
            room.x = rand() % (MAP_WIDTH - room.width - 1) + 1;
            room.y = rand() % (MAP_HEIGHT - room.height - 1) + 1;
            // Check if the room overlaps with any previous room
            int overlaps = 0;
            for (k = 0; k < j; k++) {
                Room prevRoom = map->rooms[i][k];
                if (room.x < prevRoom.x + prevRoom.width &&
                    room.x + room.width > prevRoom.x &&
                    room.y < prevRoom.y + prevRoom.height &&
                    room.y + room.height > prevRoom.y) {
                    overlaps = 1;
                    break;
                }
            }
            if (!overlaps) {
                map->rooms[i][j] = room;
                // Fill the room with floor tiles
                int x, y;
                for (y = room.y; y < room.y + room.height; y++) {
                    for (x = room.x; x < room.x + room.width; x++) {
                        map->tiles[y][x] = '.';
                    }
                }
            }
        }
    }
}

// Connects the rooms of a given level
void connectRooms(Map* map, int level) {
    int i;
    // Connect each adjacent pair of rooms
    for (i = 0; i < map->numRooms[level] - 1; i++) {
        Room room1 = map->rooms[level][i];
        Room room2 = map->rooms[level][i+1];
        // Choose a random point in each room
        int x1 = room1.x + rand() % room1.width;
        int y1 = room1.y + rand() % room1.height;
        int x2 = room2.x + rand() % room2.width;
        int y2 = room2.y + rand() % room2.height;
        // Connect the rooms with a straight corridor
        int x;
        for (x = x1; x <= x2; x++) {
            map->tiles[y1][x] = '.';
        }
        int y;
        for (y = y1; y <= y2; y++) {
            map->tiles[y][x2] = '.';
        }
    }
}

// Prints the map
void printMap(Map* map) {
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map->tiles[i][j]);
        }
        printf("\n");
    }
}