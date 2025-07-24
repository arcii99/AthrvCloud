//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

int map[WIDTH][HEIGHT];

void generateMap() {
    srand(time(NULL));

    // Fill the map with walls
    for(int x = 0; x < WIDTH; x++) {
        for(int y = 0; y < HEIGHT; y++) {
            map[x][y] = 1;
        }
    }

    // Create a room in the center of the map
    int roomWidth = 10 + (rand() % 10);
    int roomHeight = 10 + (rand() % 10);
    int roomX = (WIDTH - roomWidth) / 2;
    int roomY = (HEIGHT - roomHeight) / 2;

    for(int x = roomX; x < roomX + roomWidth; x++) {
        for(int y = roomY; y < roomY + roomHeight; y++) {
            map[x][y] = 0;
        }
    }

    // Generate additional rooms
    int numRooms = 3 + (rand() % 3);

    for(int i = 0; i < numRooms; i++) {
        roomWidth = 5 + (rand() % 10);
        roomHeight = 5 + (rand() % 10);
        roomX = rand() % (WIDTH - roomWidth);
        roomY = rand() % (HEIGHT - roomHeight);

        for(int x = roomX; x < roomX + roomWidth; x++) {
            for(int y = roomY; y < roomY + roomHeight; y++) {
                map[x][y] = 0;
            }
        }
    }

    // Add some random corridors
    int numCorridors = 10 + (rand() % 10);

    for(int i = 0; i < numCorridors; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;

        while(map[x][y] == 1) {
            map[x][y] = 0;

            if(rand() % 2 == 0) {
                x += (rand() % 3) - 1;

                if(x < 0) {
                    x = 0;
                } else if(x >= WIDTH) {
                    x = WIDTH - 1;
                }
            } else {
                y += (rand() % 3) - 1;

                if(y < 0) {
                    y = 0;
                } else if(y >= HEIGHT) {
                    y = HEIGHT - 1;
                }
            }
        }
    }
}

int main() {
    generateMap();

    // Print out the map
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            if(map[x][y] == 1) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }

    return 0;
}