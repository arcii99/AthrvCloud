//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20
#define MAX_ROOMS 10
#define MIN_ROOM_SIZE 3
#define MAX_ROOM_SIZE 10

typedef struct {
    int x, y, width, height;
} Room;

int main() {
    // Set up random seed
    srand(time(NULL));

    // Create map array
    char map[MAP_WIDTH][MAP_HEIGHT];

    // Fill map with walls
    for(int y=0; y<MAP_HEIGHT; y++) {
        for(int x=0; x<MAP_WIDTH; x++) {
            map[x][y] = '#';
        }
    }

    // Create rooms
    int num_rooms = rand() % MAX_ROOMS + 1;
    Room rooms[MAX_ROOMS];
    for(int i=0; i<num_rooms; i++) {
        // Generate random room size
        int width = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
        int height = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;

        // Generate random room position
        int x = rand() % (MAP_WIDTH - width - 1) + 1;
        int y = rand() % (MAP_HEIGHT - height - 1) + 1;

        // Add room to list
        Room room = {x, y, width, height};
        rooms[i] = room;

        // Fill room with floor
        for(int j=y; j<y+height; j++) {
            for(int k=x; k<x+width; k++) {
                map[k][j] = '.';
            }
        }
    }

    // Print map
    for(int y=0; y<MAP_HEIGHT; y++) {
        for(int x=0; x<MAP_WIDTH; x++) {
            printf("%c", map[x][y]);
        }
        printf("\n");
    }

    return 0;
}