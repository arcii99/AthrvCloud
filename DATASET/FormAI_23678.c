//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

int map[HEIGHT][WIDTH];

enum TileType {
    WALL,
    FLOOR,
    DOOR
};

int countWalls(int x, int y) {
    int count = 0;
    if (map[y-1][x] == WALL) count++;
    if (map[y+1][x] == WALL) count++;
    if (map[y][x-1] == WALL) count++;
    if (map[y][x+1] == WALL) count++;
    return count;
}

void generateMap() {
    // Initialize random number generator
    srand(time(NULL));

    // Set all tiles to walls
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            map[y][x] = WALL;
        }
    }

    // Create starting room
    int startX = WIDTH / 2;
    int startY = HEIGHT / 2;
    map[startY][startX] = FLOOR;

    // Fill map randomly
    for (int i = 0; i < 50; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;

        int walls = countWalls(x, y);

        if (map[y][x] == WALL && walls >= 3) {
            map[y][x] = FLOOR;
        }
    }

    // Place doors
    for (int y = 1; y < HEIGHT-1; y++) {
        for (int x = 1; x < WIDTH-1; x++) {
            if (map[y][x] == WALL && countWalls(x, y) == 1) {
                map[y][x] = DOOR;
            }
        }
    }
}

void printMap() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            switch (map[y][x]) {
                case WALL:
                    printf("#");
                    break;
                case FLOOR:
                    printf(".");
                    break;
                case DOOR:
                    printf("+");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    generateMap();
    printMap();
    return 0;
}