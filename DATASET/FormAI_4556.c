//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_MAP_SIZE 50
#define NUM_ROOMS 6
#define ROOM_MIN_SIZE 3
#define ROOM_MAX_SIZE 10

typedef struct {
    int x, y;
} Position;

typedef struct {
    Position position;
    int width, height;
} Room;

char dungeon[MAX_MAP_SIZE][MAX_MAP_SIZE];

Room rooms[NUM_ROOMS];

int randomInt(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

bool isRoomOverlapping(Room room, Room compareRoom) {
    if (room.position.x + room.width > compareRoom.position.x && room.position.x < compareRoom.position.x + compareRoom.width && room.position.y + room.height > compareRoom.position.y && room.position.y < compareRoom.position.y + compareRoom.height) {
        return true;
    }
    return false;
}

bool isRoomWithinBounds(Room room) {
    if (room.position.x < 0 || room.position.y < 0 || room.position.x + room.width > MAX_MAP_SIZE - 1 || room.position.y + room.height > MAX_MAP_SIZE - 1) {
        return false;
    }
    return true;
}

void generateRooms() {
    // Generate rooms until there are no overlaps
    int count = 0;
    while (count < NUM_ROOMS) {
        Room room;
        room.width = randomInt(ROOM_MIN_SIZE, ROOM_MAX_SIZE);
        room.height = randomInt(ROOM_MIN_SIZE, ROOM_MAX_SIZE);
        room.position.x = randomInt(0, MAX_MAP_SIZE - room.width);
        room.position.y = randomInt(0, MAX_MAP_SIZE - room.height);
        
        bool overlaps = false;
        for (int i = 0; i < count; i++) {
            if (isRoomOverlapping(room, rooms[i])) {
                overlaps = true;
                break;
            }
        }
        
        if (!overlaps && isRoomWithinBounds(room)) {
            rooms[count] = room;
            count++;
        }
    }
}

void generateDungeon() {
    for (int row = 0; row < MAX_MAP_SIZE; row++) {
        for (int col = 0; col < MAX_MAP_SIZE; col++) {
            dungeon[row][col] = '#';
        }
    }
    
    generateRooms();
    
    for (int i = 0; i < NUM_ROOMS; i++) {
        Room room = rooms[i];
        for (int row = room.position.y; row < room.position.y + room.height; row++) {
            for (int col = room.position.x; col < room.position.x + room.width; col++) {
                dungeon[row][col] = ' ';
            }
        }
    }
}

void printDungeon() {
    for (int row = 0; row < MAX_MAP_SIZE; row++) {
        for (int col = 0; col < MAX_MAP_SIZE; col++) {
            printf("%c", dungeon[row][col]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    generateDungeon();
    printDungeon();
    return 0;
}