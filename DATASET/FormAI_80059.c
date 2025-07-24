//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define NUM_ROOMS 5
#define ROOM_MAX_SIZE 7
#define ROOM_MIN_SIZE 3

char map[MAP_SIZE][MAP_SIZE];
int startX, startY, endX, endY;

// Function to generate a random number between min and max (inclusive)
int getRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to check if a given position is inside a room
bool isInsideRoom(int x, int y, int roomX, int roomY, int roomWidth, int roomHeight) {
    return x >= roomX && x < roomX + roomWidth && y >= roomY && y < roomY + roomHeight;
}

// Function to create a room at a given position with a given size
void createRoom(int x, int y, int width, int height) {
    for(int i = x; i < x + width; i++) {
        for(int j = y; j < y + height; j++) {
            map[i][j] = '.';
        }
    }
}

// Function to connect two rooms with a corridor
void createCorridor(int x1, int y1, int x2, int y2) {
    int x = x1, y = y1;

    while(x != x2 || y != y2) {
        if(x != x2 && y != y2) {
            if(rand() % 2 == 0) {
                x += x < x2 ? 1 : -1;
            } else {
                y += y < y2 ? 1 : -1;
            }
        } else if(x != x2) {
            x += x < x2 ? 1 : -1;
        } else {
            y += y < y2 ? 1 : -1;
        }

        map[x][y] = '.';
    }
}

// Function to generate the map
void generateMap() {
    // Initialize the map with walls
    for(int i = 0; i < MAP_SIZE; i++) {
        for(int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = '#';
        }
    }

    // Generate some random rooms
    int rooms[NUM_ROOMS][4]; // array to store room positions and sizes

    for(int i = 0; i < NUM_ROOMS; i++) {
        int x = getRandom(1, MAP_SIZE - ROOM_MAX_SIZE - 1);
        int y = getRandom(1, MAP_SIZE - ROOM_MAX_SIZE - 1);
        int width = getRandom(ROOM_MIN_SIZE, ROOM_MAX_SIZE);
        int height = getRandom(ROOM_MIN_SIZE, ROOM_MAX_SIZE);

        createRoom(x, y, width, height);
        rooms[i][0] = x;
        rooms[i][1] = y;
        rooms[i][2] = width;
        rooms[i][3] = height;

        // Make sure rooms don't overlap
        for(int j = 0; j < i; j++) {
            if(isInsideRoom(x, y, rooms[j][0], rooms[j][1], rooms[j][2], rooms[j][3])) {
                i--;
                break;
            }
        }
    }

    // Connect the rooms with corridors
    for(int i = 0; i < NUM_ROOMS - 1; i++) {
        int x1 = rooms[i][0] + rooms[i][2] / 2;
        int y1 = rooms[i][1] + rooms[i][3] / 2;
        int x2 = rooms[i+1][0] + rooms[i+1][2] / 2;
        int y2 = rooms[i+1][1] + rooms[i+1][3] / 2;

        createCorridor(x1, y1, x2, y2);
    }

    // Set the start and end points randomly
    do {
        startX = getRandom(1, MAP_SIZE - 2);
        startY = getRandom(1, MAP_SIZE - 2);
    } while(map[startX][startY] != '.');

    do {
        endX = getRandom(1, MAP_SIZE - 2);
        endY = getRandom(1, MAP_SIZE - 2);
    } while(map[endX][endY] != '.');

    map[startX][startY] = 'S';
    map[endX][endY] = 'E';
}

// Function to print the map
void printMap() {
    for(int i = 0; i < MAP_SIZE; i++) {
        for(int j = 0; j < MAP_SIZE; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator

    generateMap();
    printMap();

    return 0;
}