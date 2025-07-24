//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 10
#define MAX_ROOMS 5

typedef struct Room {
    int x, y, width, height;
} Room;

void initMap(char map[][MAP_WIDTH]);
void printMap(char map[][MAP_WIDTH]);
Room generateRoom();
void addRoom(char map[][MAP_WIDTH], Room room);

int main() {
    srand(time(NULL)); // Seed RNG with current time

    char map[MAP_HEIGHT][MAP_WIDTH]; // Define map array

    initMap(map); // Initialize map with empty spaces

    for (int i = 0; i < MAX_ROOMS; i++) {
        Room newRoom = generateRoom(); // Generate a new room
        addRoom(map, newRoom); // Add the room to the map
    }

    printMap(map); // Print the map to the console

    return 0;
}

void initMap(char map[][MAP_WIDTH]) {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = ' ';
        }
    }
}

void printMap(char map[][MAP_WIDTH]) {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

Room generateRoom() {
    Room room;

    room.width = rand() % 5 + 3; // Random width between 3 and 7
    room.height = rand() % 5 + 3; // Random height between 3 and 7
    room.x = rand() % (MAP_WIDTH - room.width - 2) + 1; // Random x position within map bounds
    room.y = rand() % (MAP_HEIGHT - room.height - 2) + 1; // Random y position within map bounds

    return room;
}

void addRoom(char map[][MAP_WIDTH], Room room) {
    for (int i = 0; i < room.width; i++) {
        for (int j = 0; j < room.height; j++) {
            if (i == 0 || i == room.width - 1 || j == 0 || j == room.height - 1) {
                // Add room walls
                map[room.y + j][room.x + i] = '#';
            } else {
                // Add room floor
                map[room.y + j][room.x + i] = '.';
            }
        }
    }
}