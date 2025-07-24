//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE_X 10
#define GRID_SIZE_Y 10
#define MAX_ROOMS 8
#define MIN_ROOM_SIZE 3
#define MAX_ROOM_SIZE 6

typedef struct Room {
    int x, y;
    int width, height;
} Room;

void printGrid(char grid[GRID_SIZE_Y][GRID_SIZE_X]) {
    for (int i = 0; i < GRID_SIZE_Y; i++) {
        for (int j = 0; j < GRID_SIZE_X; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void initializeGrid(char grid[GRID_SIZE_Y][GRID_SIZE_X]) {
    for (int i = 0; i < GRID_SIZE_Y; i++) {
        for (int j = 0; j < GRID_SIZE_X; j++) {
            grid[i][j] = '#';
        }
    }
}

void generateMap(char grid[GRID_SIZE_Y][GRID_SIZE_X], Room rooms[]) {
    int numRooms = 0;
    int newRoomX, newRoomY;

    while (numRooms < MAX_ROOMS) {
        // randomly generate new room
        newRoomX = rand() % (GRID_SIZE_X - (MAX_ROOM_SIZE + 1));
        newRoomY = rand() % (GRID_SIZE_Y - (MAX_ROOM_SIZE + 1));

        Room newRoom = {
            newRoomX,
            newRoomY,
            rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE,
            rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE
        };

        // check for overlap with existing rooms
        int overlap = 0;
        for (int i = 0; i < numRooms; i++) {
            if ((newRoom.x < rooms[i].x + rooms[i].width + 1) &&
                (newRoom.x + newRoom.width + 1 > rooms[i].x) &&
                (newRoom.y < rooms[i].y + rooms[i].height + 1) &&
                (newRoom.y + newRoom.height + 1 > rooms[i].y)) {
                overlap = 1;
                break;
            }
        }

        // if no overlap, add new room to grid
        if (!overlap) {
            for (int i = newRoom.y; i < newRoom.y + newRoom.height; i++) {
                for (int j = newRoom.x; j < newRoom.x + newRoom.width; j++) {
                    grid[i][j] = '.';
                }
            }

            // add new room to rooms list
            rooms[numRooms] = newRoom;
            numRooms++;
        }
    }
}

int main() {
    char grid[GRID_SIZE_Y][GRID_SIZE_X];
    Room rooms[MAX_ROOMS];

    srand(time(NULL));
    initializeGrid(grid);
    generateMap(grid, rooms);
    printGrid(grid);

    return 0;
}