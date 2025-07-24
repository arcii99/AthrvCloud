//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 10
#define WIDTH 20
#define MAX_ROOMS 6
#define ROOM_MIN_WIDTH 4
#define ROOM_MIN_HEIGHT 3
#define ROOM_MAX_WIDTH 10
#define ROOM_MAX_HEIGHT 8

typedef struct {
    int x, y, w, h;
} Room;

void printMap(char map[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void generateMap(char map[HEIGHT][WIDTH], Room *rooms, int *roomsCount)
{
    // Fill the map with dots
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            map[i][j] = '.';
        }
    }

    // Randomly generate a number of rooms
    srand(time(NULL));
    *roomsCount = rand() % MAX_ROOMS + 1;

    // Allocate memory for the rooms
    Room *newRooms = (Room*)malloc(sizeof(Room) * (*roomsCount));

    // Generate the rooms
    for (int i = 0; i < *roomsCount; i++) {
        int x = rand() % (WIDTH - ROOM_MAX_WIDTH - 1) + 1;
        int y = rand() % (HEIGHT - ROOM_MAX_HEIGHT - 1) + 1;
        int w = rand() % (ROOM_MAX_WIDTH - ROOM_MIN_WIDTH + 1) + ROOM_MIN_WIDTH;
        int h = rand() % (ROOM_MAX_HEIGHT - ROOM_MIN_HEIGHT + 1) + ROOM_MIN_HEIGHT;
        
        // Check if the room intersects with any other room
        int intersects = 0;
        for (int j = 0; j < i; j++) {
            if (x < rooms[j].x + rooms[j].w && x + w > rooms[j].x &&
                y < rooms[j].y + rooms[j].h && y + h > rooms[j].y) {
                intersects = 1;
                break;
            }
        }
        if (intersects) {
            i--;
            continue;
        }

        // Create the room
        Room room = {x, y, w, h};
        for (int j = y; j < y + h; j++) {
            for (int k = x; k < x + w; k++) {
                map[j][k] = ' ';
            }
        }
        newRooms[i] = room;
    }

    // Connect the rooms
    for (int i = 1; i < *roomsCount; i++) {
        // Get the centers of the current room and the previous room
        int cX1 = newRooms[i].x + newRooms[i].w / 2;
        int cY1 = newRooms[i].y + newRooms[i].h / 2;
        int cX2 = newRooms[i-1].x + newRooms[i-1].w / 2;
        int cY2 = newRooms[i-1].y + newRooms[i-1].h / 2;

        // Connect the centers with a rectangle
        for (int j = cX1; j != cX2; j += (cX2 - cX1)/abs(cX2 - cX1)) {
            map[cY1][j] = '#';
        }
        for (int j = cY1; j != cY2; j += (cY2 - cY1)/abs(cY2 - cY1)) {
            map[j][cX2] = '#';
        }
    }

    // Set the output parameters
    *rooms = *newRooms;
    free(newRooms);
}

int main()
{
    char map[HEIGHT][WIDTH];
    Room rooms[MAX_ROOMS];
    int roomsCount;

    generateMap(map, rooms, &roomsCount);

    printMap(map);

    return 0;
}