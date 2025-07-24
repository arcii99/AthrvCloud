//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define GRID_SIZE 10
#define MAX_ROOMS 6
#define MIN_ROOM_SIZE 3
#define MAX_ROOM_SIZE 6

// Function prototypes
void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]);
void printGrid(char grid[GRID_SIZE][GRID_SIZE]);
void generateRooms(char grid[GRID_SIZE][GRID_SIZE], int numRooms);
void generateRoom(char grid[GRID_SIZE][GRID_SIZE], int roomId);
void generateCorridors(char grid[GRID_SIZE][GRID_SIZE], int roomId1, int roomId2);
int getRandomInt(int min, int max);
int max(int a, int b);
int min(int a, int b);

// Main function
int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize grid
    char grid[GRID_SIZE][GRID_SIZE];
    initializeGrid(grid);

    // Generate rooms and corridors
    generateRooms(grid, MAX_ROOMS);

    // Print grid
    printGrid(grid);

    return 0;
}

// Initialize grid with walls ('#')
void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '#';
        }
    }
}

// Print grid to console
void printGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// Generate specified number of rooms
void generateRooms(char grid[GRID_SIZE][GRID_SIZE], int numRooms) {
    for (int i = 0; i < numRooms; i++) {
        generateRoom(grid, i + 1);
    }

    // Generate corridors between rooms
    generateCorridors(grid, 1, 2);
    generateCorridors(grid, 2, 3);
    generateCorridors(grid, 3, 4);
    generateCorridors(grid, 4, 5);
    generateCorridors(grid, 5, 6);
}

// Generate room with specified id
void generateRoom(char grid[GRID_SIZE][GRID_SIZE], int roomId) {
    // Calculate random room dimensions
    int width = getRandomInt(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
    int height = getRandomInt(MIN_ROOM_SIZE, MAX_ROOM_SIZE);

    // Calculate random room position
    int x = getRandomInt(0, GRID_SIZE - width);
    int y = getRandomInt(0, GRID_SIZE - height);

    // Draw room on grid
    for (int i = x; i < x + width; i++) {
        for (int j = y; j < y + height; j++) {
            grid[i][j] = '.';
        }
    }
}

// Generate corridors between two rooms with specified ids
void generateCorridors(char grid[GRID_SIZE][GRID_SIZE], int roomId1, int roomId2) {
    // Get random starting and ending positions for corridor
    int startX, startY, endX, endY;

    if (roomId1 < roomId2) {
        // Corridor goes from top of room1 to bottom of room2
        startX = getRandomInt(roomId1 - 1, roomId1 + 2);
        startY = getRandomInt(0, GRID_SIZE);
        endX = getRandomInt(roomId2 - 1, roomId2 + 2);
        endY = getRandomInt(0, GRID_SIZE);
    } else {
        // Corridor goes from left of room1 to right of room2
        startX = getRandomInt(0, GRID_SIZE);
        startY = getRandomInt(roomId1 - 1, roomId1 + 2);
        endX = getRandomInt(0, GRID_SIZE);
        endY = getRandomInt(roomId2 - 1, roomId2 + 2);
    }

    // Draw corridor on grid
    int x = startX;
    int y = startY;

    while (x != endX || y != endY) {
        if (x < endX) {
            x++;
        } else if (x > endX) {
            x--;
        }

        if (y < endY) {
            y++;
        } else if (y > endY) {
            y--;
        }

        if (grid[x][y] == '#') { // Do not overwrite existing rooms/corridors
            grid[x][y] = '.';
        }
    }
}

// Get random integer between min and max (inclusive)
int getRandomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Get max of two integers
int max(int a, int b) {
    return a > b ? a : b;
}

// Get min of two integers
int min(int a, int b) {
    return a < b ? a : b;
}