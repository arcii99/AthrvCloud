//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 30
#define NUM_ROOMS 10

int map[MAP_WIDTH][MAP_HEIGHT];

void createMap() {
    int x, y;
    
    // Initialize map to all walls
    for (x = 0; x < MAP_WIDTH; x++) {
        for (y = 0; y < MAP_HEIGHT; y++) {
            map[x][y] = 1;
        }
    }
    
    // Generate rooms
    int numRooms = 0;
    while (numRooms < NUM_ROOMS) {
        int roomWidth = rand() % 8 + 5;
        int roomHeight = rand() % 8 + 5;
        int roomX = rand() % (MAP_WIDTH - roomWidth - 1) + 1;
        int roomY = rand() % (MAP_HEIGHT - roomHeight - 1) + 1;
        
        if (!checkCollision(roomX, roomY, roomWidth, roomHeight)) {
            numRooms++;
            for (x = roomX; x < roomX + roomWidth; x++) {
                for (y = roomY; y < roomY + roomHeight; y++) {
                    map[x][y] = 0;
                }
            }
        }
    }
    
    // Connect rooms with corridors
    int currentX = -1, currentY = -1;
    for (x = 0; x < MAP_WIDTH; x++) {
        for (y = 0; y < MAP_HEIGHT; y++) {
            if (map[x][y] == 0) {
                if (currentX == -1) {
                    currentX = x;
                    currentY = y;
                }
                else {
                    while (currentX != x || currentY != y) {
                        if (currentX < x) {
                            currentX++;
                        }
                        else if (currentX > x) {
                            currentX--;
                        }
                        if (currentY < y) {
                            currentY++;
                        }
                        else if (currentY > y) {
                            currentY--;
                        }
                        map[currentX][currentY] = 0;
                    }
                    currentX = -1;
                    currentY = -1;
                }
            }
        }
    }
}

int checkCollision(int x, int y, int width, int height) {
    int i, j;
    for (i = x - 1; i < x + width + 1; i++) {
        for (j = y - 1; j < y + height + 1; j++) {
            if (i < 0 || i >= MAP_WIDTH || j < 0 || j >= MAP_HEIGHT) {
                if (i == -1 || i == MAP_WIDTH || j == -1 || j == MAP_HEIGHT) {
                    return 1;
                }
            }
            else if (map[i][j] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

void printMap() {
    int x, y;
    for (y = 0; y < MAP_HEIGHT; y++) {
        for (x = 0; x < MAP_WIDTH; x++) {
            if (map[x][y] == 1) {
                printf("#");
            }
            else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    createMap();
    printMap();
    return 0;
}