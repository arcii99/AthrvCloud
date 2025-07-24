//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

typedef struct {
    int x;
    int y;
} Point;

typedef enum {
    WALL,
    FLOOR
} TileType;

typedef struct {
    char symbol;
    TileType type;
} Tile;

Tile map[HEIGHT][WIDTH];

void generateMap() {
    int x, y;

    // Randomly generate walls and floors
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            if (rand() % 100 > 40) {
                map[y][x].symbol = '#';
                map[y][x].type = WALL;
            } else {
                map[y][x].symbol = '.';
                map[y][x].type = FLOOR;
            }
        }
    }

    // Add some extra floors
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            if (map[y][x].type == WALL &&
                ((y > 1 && map[y-1][x].type == FLOOR) ||
                 (y < HEIGHT-1 && map[y+1][x].type == FLOOR) ||
                 (x > 1 && map[y][x-1].type == FLOOR) ||
                 (x < WIDTH-1 && map[y][x+1].type == FLOOR))) {
                map[y][x].symbol = '.';
                map[y][x].type = FLOOR;
            }
        }
    }

    // Add player
    Point playerPos;
    do {
        playerPos.x = rand() % WIDTH;
        playerPos.y = rand() % HEIGHT;
    } while (map[playerPos.y][playerPos.x].type == WALL);
    map[playerPos.y][playerPos.x].symbol = '@';

    // Add exit
    Point exitPos;
    do {
        exitPos.x = rand() % WIDTH;
        exitPos.y = rand() % HEIGHT;
    } while (map[exitPos.y][exitPos.x].type == WALL || 
             (exitPos.x == playerPos.x && exitPos.y == playerPos.y));
    map[exitPos.y][exitPos.x].symbol = 'X';
}

void displayMap() {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            putchar(map[y][x].symbol);
        }
        putchar('\n');
    }
}

int main() {
    srand(time(NULL));
    generateMap();
    displayMap();
    return 0;
}