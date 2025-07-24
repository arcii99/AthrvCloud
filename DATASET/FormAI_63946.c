//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 25
#define MAX_ROOMS 10

void generate_map(char map[MAP_WIDTH][MAP_HEIGHT]);
void place_rooms(char map[MAP_WIDTH][MAP_HEIGHT], int num_rooms);
void place_corridors(char map[MAP_WIDTH][MAP_HEIGHT]);

int main() {
    char map[MAP_WIDTH][MAP_HEIGHT];
    generate_map(map);

    // Display the map
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            putchar(map[x][y]);
        }
        putchar('\n');
    }

    return 0;
}

void generate_map(char map[MAP_WIDTH][MAP_HEIGHT]) {
    // Fill the map with walls
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[x][y] = '#';
        }
    }

    srand(time(NULL));

    // Place rooms
    int num_rooms = rand() % MAX_ROOMS + 1;
    place_rooms(map, num_rooms);

    // Place corridors
    place_corridors(map);
}

void place_rooms(char map[MAP_WIDTH][MAP_HEIGHT], int num_rooms) {
    // Generate rooms
    for (int i = 0; i < num_rooms; i++) {
        int x = rand() % (MAP_WIDTH - 6) + 2;
        int y = rand() % (MAP_HEIGHT - 6) + 2;
        int width = rand() % 5 + 3;
        int height = rand() % 5 + 3;

        // Check if the room overlaps with another room
        int overlap = 0;
        for (int j = -1; j < width + 1; j++) {
            for (int k = -1; k < height + 1; k++) {
                if (map[x+j][y+k] == '.') {
                    overlap = 1;
                }
            }
        }

        if (!overlap) {
            // Draw the room
            for (int j = 0; j < width; j++) {
                for (int k = 0; k < height; k++) {
                    map[x+j][y+k] = '.';
                }
            }
        }
    }
}

void place_corridors(char map[MAP_WIDTH][MAP_HEIGHT]) {
    // Generate corridors between adjacent rooms
    for (int y = 1; y < MAP_HEIGHT - 1; y++) {
        for (int x = 1; x < MAP_WIDTH - 1; x++) {
            if (map[x][y] == '.' && map[x-1][y] == '.') {
                // Corridor going right
                for (int j = x; j < MAP_WIDTH - 1 && map[j][y] != '#'; j++) {
                    map[j][y] = '.';
                }
            }
            if (map[x][y] == '.' && map[x][y-1] == '.') {
                // Corridor going down
                for (int k = y; k < MAP_HEIGHT - 1 && map[x][k] != '#'; k++) {
                    map[x][k] = '.';
                }
            }
        }
    }
}