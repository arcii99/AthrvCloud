//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

char map[MAP_HEIGHT][MAP_WIDTH]; // The game map
int playerX, playerY; // Player position on map

void generateMap() {
    // Seed based on current time
    srand(time(NULL));
    
    // Fill map with walls
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = '#';
        }
    }
    
    // Add random rooms to map
    for (int i = 0; i < 10; i++) {
        // Random width and height for room
        int roomWidth = rand() % 10 + 5;
        int roomHeight = rand() % 10 + 5;
        
        // Random x and y for top-left corner of room
        int roomX = rand() % (MAP_WIDTH - roomWidth - 2) + 1;
        int roomY = rand() % (MAP_HEIGHT - roomHeight - 2) + 1;
        
        // Add room to map
        for (int y = roomY; y < roomY + roomHeight; y++) {
            for (int x = roomX; x < roomX + roomWidth; x++) {
                map[y][x] = '.';
            }
        }
    }
    
    // Place player randomly in an empty space
    while (1) {
        int randX = rand() % MAP_WIDTH;
        int randY = rand() % MAP_HEIGHT;
        
        if (map[randY][randX] == '.') {
            playerX = randX;
            playerY = randY;
            return;
        }
    }
}

void drawMap() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (playerX == x && playerY == y) {
                printf("@");
            } else {
                printf("%c", map[y][x]);
            }
        }
        printf("\n");
    }
}

int main() {
    generateMap();
    drawMap();
    
    return 0;
}