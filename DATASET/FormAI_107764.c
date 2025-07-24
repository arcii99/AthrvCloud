//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20
#define MAX_ROOMS 6
#define MIN_ROOM_SIZE 3
#define MAX_ROOM_SIZE 6

char map[MAP_HEIGHT][MAP_WIDTH];

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position position;
    int width;
    int height;
} Room;

void createMap() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = '#'; // set all tiles as walls
        }
    }

    Room rooms[MAX_ROOMS];
    int numRooms = 0;
    srand(time(NULL));

    for (int i = 0; i < MAX_ROOMS; i++) {
        int roomWidth = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
        int roomHeight = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
        int x = rand() % (MAP_WIDTH - roomWidth);
        int y = rand() % (MAP_HEIGHT - roomHeight);

        Room room = {
            .position = { x, y },
            .width = roomWidth,
            .height = roomHeight
        };

        if (numRooms == 0) {
            rooms[numRooms++] = room;
        } else {
            int intersects = 0;
            for (int j = 0; j < numRooms; j++) {
                Room other = rooms[j];
                if (x < other.position.x + other.width &&
                    x + roomWidth > other.position.x &&
                    y < other.position.y + other.height &&
                    y + roomHeight > other.position.y) {
                    intersects = 1;
                    break;
                }
            }
            if (!intersects) {
                rooms[numRooms++] = room;

                // dig out the corridor to connect the rooms
                Position currentPosition = { x + roomWidth / 2, y + roomHeight / 2 };
                Position targetPosition = rooms[numRooms - 2].position;
                targetPosition.x += rooms[numRooms - 2].width / 2;
                targetPosition.y += rooms[numRooms - 2].height / 2;

                while (currentPosition.x != targetPosition.x) {
                    currentPosition.x += (currentPosition.x < targetPosition.x) ? 1 : -1;
                    map[currentPosition.y][currentPosition.x] = '.';
                }

                while (currentPosition.y != targetPosition.y) {
                    currentPosition.y += (currentPosition.y < targetPosition.y) ? 1 : -1;
                    map[currentPosition.y][currentPosition.x] = '.';
                }
            }
        }
    }

    // place the player in the first room
    Room startRoom = rooms[0];
    Position playerPosition = {
        .x = startRoom.position.x + 1,
        .y = startRoom.position.y + 1
    };
    map[playerPosition.y][playerPosition.x] = '@';

    // print the map
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            putchar(map[y][x]);
        }
        putchar('\n');
    }
}

int main() {
    createMap();
    return 0;
}