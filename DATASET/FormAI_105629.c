//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20
#define MAX_ROOMS 10
#define ROOM_MAX_SIZE 10
#define ROOM_MIN_SIZE 5

char map[MAP_WIDTH][MAP_HEIGHT];

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Room;

void createMap()
{
    int i, j, k;

    // Fill the map with walls
    for (i = 0; i < MAP_WIDTH; i++) {
        for (j = 0; j < MAP_HEIGHT; j++) {
            map[i][j] = '#';
        }
    }

    // Generate rooms
    srand(time(NULL));
    Room rooms[MAX_ROOMS];

    for (i = 0; i < MAX_ROOMS; i++) {
        int roomWidth = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
        int roomHeight = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
        int roomX = rand() % (MAP_WIDTH - roomWidth - 1) + 1;
        int roomY = rand() % (MAP_HEIGHT - roomHeight - 1) + 1;

        Room newRoom = {roomX, roomY, roomWidth, roomHeight};

        int failed = 0;
        for (j = 0; j < i; j++) {
            if (newRoom.x < rooms[j].x + rooms[j].width &&
                newRoom.x + newRoom.width > rooms[j].x &&
                newRoom.y < rooms[j].y + rooms[j].height &&
                newRoom.y + newRoom.height > rooms[j].y) {
                failed = 1; // Intersection with another room
                break;
            }
        }

        if (!failed) {
            // Dig room
            for (j = newRoom.x + 1; j < newRoom.x + newRoom.width; j++) {
                for (k = newRoom.y + 1; k < newRoom.y + newRoom.height; k++) {
                    map[j][k] = '.';
                }
            }

            rooms[i] = newRoom;
        }
    }
}

void printMap()
{
    int i, j;
    for (j = 0; j < MAP_HEIGHT; j++) {
        for (i = 0; i < MAP_WIDTH; i++) {
            putchar(map[i][j]);
        }
        putchar('\n');
    }
}

int main()
{
    createMap();
    printMap();
    return 0;
}