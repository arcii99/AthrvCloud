//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 40
#define MAP_HEIGHT 20

#define MAX_ROOMS 10
#define MIN_ROOM_WIDTH 3
#define MAX_ROOM_WIDTH 6
#define MIN_ROOM_HEIGHT 3
#define MAX_ROOM_HEIGHT 6

#define PLAYER '@'
#define FLOOR '.'
#define WALL '#'

int map[MAP_HEIGHT][MAP_WIDTH];
int playerX, playerY;

void generateMap();
void placeRooms();
void placeCorridors();
void printMap();

int main() {
    srand(time(NULL));
    
    generateMap();
    printMap();
    
    return 0;
}

void generateMap() {
    placeRooms();
    placeCorridors();
    
    // Place player randomly in a room
    int roomIndex = rand() % MAX_ROOMS;
    playerX = rand() % (MAX_ROOM_WIDTH - 2) + 1 + MAP_WIDTH / 2 - MAX_ROOM_WIDTH * MAX_ROOMS / 2 + roomIndex * MAX_ROOM_WIDTH;
    playerY = rand() % (MAX_ROOM_HEIGHT - 2) + 1 + MAP_HEIGHT / 2 - MAX_ROOM_HEIGHT / 2;
    map[playerY][playerX] = PLAYER;
}

void placeRooms() {
    int roomCount = 0;
    
    while (roomCount < MAX_ROOMS) {
        int roomWidth = rand() % (MAX_ROOM_WIDTH - MIN_ROOM_WIDTH + 1) + MIN_ROOM_WIDTH;
        int roomHeight = rand() % (MAX_ROOM_HEIGHT - MIN_ROOM_HEIGHT + 1) + MIN_ROOM_HEIGHT;
        int roomX = rand() % (MAP_WIDTH - roomWidth - 1) + 1;
        int roomY = rand() % (MAP_HEIGHT - roomHeight - 1) + 1;
        
        // Check if there is any overlapping
        int overlapping = 0;
        for (int y = roomY - 1; y <= roomY + roomHeight; y++) {
            for (int x = roomX - 1; x <= roomX + roomWidth; x++) {
                if (map[y][x] == FLOOR) {
                    overlapping = 1;
                    break;
                }
            }
            if (overlapping) {
                break;
            }
        }
        
        // If not overlapping, place the room
        if (!overlapping) {
            for (int y = roomY; y < roomY + roomHeight; y++) {
                for (int x = roomX; x < roomX + roomWidth; x++) {
                    if (y == roomY || y == roomY + roomHeight - 1 || x == roomX || x == roomX + roomWidth - 1) {
                        map[y][x] = WALL;
                    } else {
                        map[y][x] = FLOOR;
                    }
                }
            }
            roomCount++;
        }
    }
}

void placeCorridors() {
    for (int roomIndex = 0; roomIndex < MAX_ROOMS - 1; roomIndex++) {
        int currentRoomX = rand() % (MAX_ROOM_WIDTH - 2) + 1 + MAP_WIDTH / 2 - MAX_ROOM_WIDTH * MAX_ROOMS / 2 + roomIndex * MAX_ROOM_WIDTH;
        int currentRoomY = rand() % (MAX_ROOM_HEIGHT - 2) + 1 + MAP_HEIGHT / 2 - MAX_ROOM_HEIGHT / 2;
        int nextRoomX = rand() % (MAX_ROOM_WIDTH - 2) + 1 + MAP_WIDTH / 2 - MAX_ROOM_WIDTH * MAX_ROOMS / 2 + (roomIndex + 1) * MAX_ROOM_WIDTH;
        int nextRoomY = rand() % (MAX_ROOM_HEIGHT - 2) + 1 + MAP_HEIGHT / 2 - MAX_ROOM_HEIGHT / 2;
        
        int x = currentRoomX;
        while (x != nextRoomX) {
            if (x < nextRoomX) {
                x++;
            } else {
                x--;
            }
            map[currentRoomY][x] = FLOOR;
        }
        
        int y = currentRoomY;
        while (y != nextRoomY) {
            if (y < nextRoomY) {
                y++;
            } else {
                y--;
            }
            map[y][nextRoomX] = FLOOR;
        }
    }
}

void printMap() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (x == playerX && y == playerY) {
                printf("%c", PLAYER);
            } else {
                printf("%c", map[y][x]);
            }
        }
        printf("\n");
    }
}