//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

// Struct for each tile in the map
struct Tile {
    int x;
    int y;
    char symb; // Symbol to represent this tile 
};

// Struct for the player character
struct Player {
    int x;
    int y;
};

int main() {
    srand(time(NULL)); // Seed random number generator

    // Create map tiles
    struct Tile map[WIDTH][HEIGHT];
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            map[x][y].x = x;
            map[x][y].y = y;
            map[x][y].symb = '-';
        }
    }

    // Generate random walls
    for (int i = 0; i < 30; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        map[x][y].symb = '#';
    }

    // Generate player character
    struct Player player;
    player.x = rand() % WIDTH;
    player.y = rand() % HEIGHT;
    map[player.x][player.y].symb = '@';

    // Print out the map
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", map[x][y].symb);
        }
        printf("\n");
    }

    return 0;
}