//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10
#define MAX_ROOMS 6

typedef struct {
    int x, y;
    int w, h;
} Room;

void printMap(int map[WIDTH][HEIGHT]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (map[x][y] == 0) printf(".");
            else printf("#");
        }
        printf("\n");
    }
}

void generateMap(int map[WIDTH][HEIGHT], Room rooms[MAX_ROOMS], int *numRooms) {
    // Initialize map to all walls
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            map[x][y] = 1;
        }
    }

    // Add rooms
    srand(time(NULL)); // Seed random number generator
    *numRooms = rand() % MAX_ROOMS + 1;
    for (int i = 0; i < *numRooms; i++) {
        // Generate random room dimensions
        rooms[i].w = rand() % 6 + 5;
        rooms[i].h = rand() % 4 + 3;

        // Generate random room position
        rooms[i].x = rand() % (WIDTH - rooms[i].w);
        rooms[i].y = rand() % (HEIGHT - rooms[i].h);

        // Check if room overlaps with existing rooms
        int overlap = 0;
        for (int j = 0; j < i; j++) {
            if (rooms[i].x < (rooms[j].x + rooms[j].w) &&
                (rooms[i].x + rooms[i].w) > rooms[j].x &&
                rooms[i].y < (rooms[j].y + rooms[j].h) &&
                (rooms[i].y + rooms[i].h) > rooms[j].y) {
                overlap = 1;
                break;
            }
        }

        // Only add room if it does not overlap with existing rooms
        if (!overlap) {
            for (int y = rooms[i].y; y < (rooms[i].y + rooms[i].h); y++) {
                for (int x = rooms[i].x; x < (rooms[i].x + rooms[i].w); x++) {
                    map[x][y] = 0;
                }
            }
        }
    }
}

int main() {
    int map[WIDTH][HEIGHT];
    Room rooms[MAX_ROOMS];
    int numRooms;

    generateMap(map, rooms, &numRooms);
    printMap(map);

    return 0;
}