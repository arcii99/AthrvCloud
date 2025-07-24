//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20
#define ROOM_MAX_SIZE 10
#define ROOM_MIN_SIZE 5
#define MAX_ROOMS 10

char map[MAP_HEIGHT][MAP_WIDTH];

// Room struct with x,y coordinates and width, height values
typedef struct {
    int x, y;
    int width, height;
} Room;

// Function to clear the map
void clearMap() {
    for(int i = 0; i < MAP_HEIGHT; i++) {
        for(int j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = '#';
        }
    }
}

// Function to print the map
void printMap() {
    for(int i = 0; i < MAP_HEIGHT; i++) {
        for(int j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

// Function to add a room to the map
void addRoom(Room room) {
    for(int i = room.y; i < room.y + room.height; i++) {
        for(int j = room.x; j < room.x + room.width; j++) {
            map[i][j] = '.';
        }
    }
}

// Function to generate a random room
Room generateRoom() {
    Room room;
    room.width = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
    room.height = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
    room.x = rand() % (MAP_WIDTH - room.width - 1) + 1;
    room.y = rand() % (MAP_HEIGHT - room.height - 1) + 1;

    return room;
}

// Function to check if two rooms overlap
int checkOverlap(Room room1, Room room2) {
    if(room1.x <= room2.x + room2.width &&
        room1.x + room1.width >= room2.x &&
        room1.y <= room2.y + room2.height &&
        room1.y + room1.height >= room2.y) {
            return 1;
        }
    return 0;
}

// Function to generate the map
void generateMap() {
    clearMap();
    Room rooms[MAX_ROOMS];
    int numberOfRooms = 0;

    for(int i = 0; i < MAX_ROOMS; i++) {
        Room newRoom = generateRoom();

        int overlap = 0;
        for(int j = 0; j < numberOfRooms; j++) {
            if(checkOverlap(newRoom, rooms[j])) {
                overlap = 1;
                break;
            }
        }

        if(!overlap) {
            addRoom(newRoom);
            rooms[numberOfRooms] = newRoom;
            numberOfRooms++;
        }
    }
}

// Thread function for generating the map
void* generateMapThread(void* arg) {
    srand(time(NULL));
    generateMap();
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, &generateMapThread, NULL);
    pthread_join(thread, NULL);

    printMap();
    return 0;
}