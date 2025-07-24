//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAP_SIZE_X 50
#define MAP_SIZE_Y 20
#define ROOM_WIDTH_MIN 4
#define ROOM_WIDTH_MAX 12
#define ROOM_HEIGHT_MIN 3
#define ROOM_HEIGHT_MAX 8
#define MAX_ROOMS 8

// Prototype function
void generateRooms(bool map[MAP_SIZE_Y][MAP_SIZE_X]);
bool isRoomEmpty(bool map[MAP_SIZE_Y][MAP_SIZE_X], int y, int x, int height, int width);

int main()
{
    bool map[MAP_SIZE_Y][MAP_SIZE_X] = { false };

    printf("Generating map...\n");

    // Generate initial rooms
    srand(time(NULL));
    generateRooms(map);

    // Print map
    for(int y = 0; y < MAP_SIZE_Y; y++)
    {
        for(int x = 0; x < MAP_SIZE_X; x++)
        {
            if(map[y][x] == true)
            {
                printf(".");
            }
            else
            {
                printf("#");
            }
        }

        printf("\n");
    }

    return 0;
}

// Recursive function to generate rooms
void generateRooms(bool map[MAP_SIZE_Y][MAP_SIZE_X])
{
    // If maximum number of rooms is reached or map is full, stop recursion
    static int numRooms = 0;

    if(numRooms == MAX_ROOMS || numRooms == MAP_SIZE_X * MAP_SIZE_Y)
    {
        return;
    }

    // Generate random dimensions for room
    int roomHeight = rand() % (ROOM_HEIGHT_MAX - ROOM_HEIGHT_MIN + 1) + ROOM_HEIGHT_MIN;
    int roomWidth = rand() % (ROOM_WIDTH_MAX - ROOM_WIDTH_MIN + 1) + ROOM_WIDTH_MIN;

    // Generate random position for room
    int roomY = rand() % (MAP_SIZE_Y - roomHeight - 1) + 1;
    int roomX = rand() % (MAP_SIZE_X - roomWidth - 1) + 1;

    // Check if room overlaps other rooms
    if(isRoomEmpty(map, roomY, roomX, roomHeight, roomWidth) == true)
    {
        // Fill room
        for(int y = roomY; y < roomY + roomHeight; y++)
        {
            for(int x = roomX; x < roomX + roomWidth; x++)
            {
                map[y][x] = true;
            }
        }

        numRooms++;

        // Generate more rooms recursively
        generateRooms(map);
    }
    else
    {
        // Try again
        generateRooms(map);
    }
}

// Check if a room overlaps other rooms
bool isRoomEmpty(bool map[MAP_SIZE_Y][MAP_SIZE_X], int y, int x, int height, int width)
{
    for(int i = y - 1; i < y + height + 1; i++)
    {
        for(int j = x - 1; j < x + width + 1; j++)
        {
            if(map[i][j] == true)
            {
                return false;
            }
        }
    }

    return true;
}