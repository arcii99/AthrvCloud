//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

char map[HEIGHT][WIDTH];

void generateMap() {
    srand(time(NULL));
    int x, y;

    // Fill the map with walls
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            map[y][x] = '#';
        }
    }

    // Place the player at the center
    map[HEIGHT / 2][WIDTH / 2] = '@';

    // Generate some random rooms
    int numRooms = 5 + rand() % 5;
    int i;
    for (i = 0; i < numRooms; i++) {
        int roomWidth = 3 + rand() % 5;
        int roomHeight = 3 + rand() % 3;
        int roomX = rand() % (WIDTH - roomWidth - 1);
        int roomY = rand() % (HEIGHT - roomHeight - 1);

        // Add the room to the map
        int j, k;
        for (j = roomY; j < roomY + roomHeight; j++) {
            for (k = roomX; k < roomX + roomWidth; k++) {
                map[j][k] = ' ';
            }
        }
    }
}

void displayMap() {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}

int main() {
    generateMap();
    displayMap();

    return 0;
}