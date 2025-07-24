//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 20

char map[HEIGHT][WIDTH];

void generateMap() {
    srand(time(NULL)); // Seed the random number generator

    // Fill the map with walls
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            map[y][x] = '#';
        }
    }

    // Add some rooms
    for (int i = 0; i < 10; i++) {
        // Determine the size and position of the room
        int roomWidth = rand() % 10 + 5;
        int roomHeight = rand() % 5 + 3;
        int roomX = rand() % (WIDTH - roomWidth - 2) + 1;
        int roomY = rand() % (HEIGHT - roomHeight - 2) + 1;

        // Carve out the room
        for (int y = roomY; y < roomY + roomHeight; y++) {
            for (int x = roomX; x < roomX + roomWidth; x++) {
                map[y][x] = '.';
            }
        }
    }

    // Connect the rooms with corridors
    for (int i = 0; i < 10; i++) {
        // Choose two random rooms
        int room1X = rand() % (WIDTH - 2) + 1;
        int room1Y = rand() % (HEIGHT - 2) + 1;
        int room2X = rand() % (WIDTH - 2) + 1;
        int room2Y = rand() % (HEIGHT - 2) + 1;

        // Draw a corridor between the two rooms
        int x = room1X, y = room1Y;
        while (x != room2X) {
            if (x < room2X) x++;
            else x--;
            if (map[y][x] == '#') map[y][x] = '.';
        }
        while (y != room2Y) {
            if (y < room2Y) y++;
            else y--;
            if (map[y][x] == '#') map[y][x] = '.';
        }
    }
}

void displayMap() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
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