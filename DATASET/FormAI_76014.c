//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_HEIGHT 30
#define MAP_WIDTH 50
#define ROOM_MIN_SIZE 3
#define ROOM_MAX_SIZE 12
#define MAX_ROOMS 10
#define PLAYER '@'

// Map tiles
enum {
    TILE_WALL,
    TILE_ROOM,
    TILE_CORRIDOR
};

// Player coordinates
int playerx;
int playery;

int map[MAP_HEIGHT][MAP_WIDTH];

// Generate a random integer between min and max (inclusive)
int randInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Generate a map with procedural generation
void generateMap()
{
    // Initialize the map with all walls
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = TILE_WALL;
        }
    }

    srand(time(NULL));

    // Generate rooms
    int numRooms = 0;
    while (numRooms < MAX_ROOMS) {
        int roomx = randInt(1, MAP_WIDTH - ROOM_MAX_SIZE - 1);
        int roomy = randInt(1, MAP_HEIGHT - ROOM_MAX_SIZE - 1);
        int roomw = randInt(ROOM_MIN_SIZE, ROOM_MAX_SIZE);
        int roomh = randInt(ROOM_MIN_SIZE, ROOM_MAX_SIZE);

        // Check if room overlaps with an existing room
        int overlaps = 0;
        for (int y = roomy - 1; y < roomy + roomh + 1; y++) {
            for (int x = roomx - 1; x < roomx + roomw + 1; x++) {
                if (map[y][x] == TILE_ROOM) {
                    overlaps = 1;
                    break;
                }
            }
            if (overlaps) {
                break;
            }
        }

        // If room doesn't overlap, create it
        if (!overlaps) {
            for (int y = roomy; y < roomy + roomh; y++) {
                for (int x = roomx; x < roomx + roomw; x++) {
                    map[y][x] = TILE_ROOM;
                }
            }

            // Remember the coordinates of the center tile of the room for later
            int centerx = roomx + roomw / 2;
            int centery = roomy + roomh / 2;

            // Place the player in the first room
            if (numRooms == 0) {
                playerx = centerx;
                playery = centery;
            }

            numRooms++;
        }
    }

    // Generate corridors
    for (int y = 1; y < MAP_HEIGHT - 1; y++) {
        for (int x = 1; x < MAP_WIDTH - 1; x++) {
            if (map[y][x] == TILE_ROOM) {
                // Try to connect to the room to the right
                if (map[y][x+1] == TILE_WALL) {
                    int corridorLength = randInt(2, 8);
                    for (int i = 0; i < corridorLength; i++) {
                        if (x+1+i < MAP_WIDTH-1) {
                            map[y][x+1+i] = TILE_CORRIDOR;
                        }
                    }
                }

                // Try to connect to the room below
                if (map[y+1][x] == TILE_WALL) {
                    int corridorLength = randInt(2, 8);
                    for (int i = 0; i < corridorLength; i++) {
                        if (y+1+i < MAP_HEIGHT-1) {
                            map[y+1+i][x] = TILE_CORRIDOR;
                        }
                    }
                }
            }
        }
    }
}

// Display the map
void displayMap()
{
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (x == playerx && y == playery) {
                putchar(PLAYER);
            } else {
                switch (map[y][x]) {
                    case TILE_WALL:
                        putchar('#');
                        break;
                    case TILE_ROOM:
                        putchar('.');
                        break;
                    case TILE_CORRIDOR:
                        putchar(',');
                        break;
                }
            }
        }
        putchar('\n');
    }
}

int main()
{
    generateMap();
    displayMap();

    return 0;
}