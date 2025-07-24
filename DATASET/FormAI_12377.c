//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define MAX_ROOMS 6
#define MIN_ROOM_SIZE 3
#define MAX_ROOM_SIZE 6

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Room;

typedef struct {
    int x;
    int y;
    char ch;
} Tile;

void printMap(Tile map[MAP_SIZE][MAP_SIZE])
{
    for (int y = 0; y < MAP_SIZE; y++)
    {
        for (int x = 0; x < MAP_SIZE; x++)
        {
            printf("%c", map[x][y].ch);
        }
        printf("\n");
    }
    printf("\n");
}

void initMap(Tile map[MAP_SIZE][MAP_SIZE])
{
    for (int y = 0; y < MAP_SIZE; y++)
    {
        for (int x = 0; x < MAP_SIZE; x++)
        {
            map[x][y].x = x;
            map[x][y].y = y;
            map[x][y].ch = '#';
        }
    }
}

int checkRoomOverlap(Room rooms[], int totalRooms, Room room)
{
    for (int i = 0; i < totalRooms; i++)
    {
        if ((room.x >= rooms[i].x - MAX_ROOM_SIZE) &&
            (room.x <= rooms[i].x + rooms[i].width + MAX_ROOM_SIZE) &&
            (room.y >= rooms[i].y - MAX_ROOM_SIZE) &&
            (room.y <= rooms[i].y + rooms[i].height + MAX_ROOM_SIZE))
        {
            return 1;
        }
    }
    return 0;
}

void placeRoom(Tile map[MAP_SIZE][MAP_SIZE], Room room)
{
    for (int y = room.y; y < room.y + room.height; y++)
    {
        for (int x = room.x; x < room.x + room.width; x++)
        {
            if ((x == room.x) || (x == room.x + room.width - 1) ||
                (y == room.y) || (y == room.y + room.height - 1))
            {
                map[x][y].ch = '#';
            }
            else
            {
                map[x][y].ch = '.';
            }
        }
    }
}

void generateMap(Tile map[MAP_SIZE][MAP_SIZE])
{
    Room rooms[MAX_ROOMS];
    int totalRooms = 0;
  
    while (totalRooms < MAX_ROOMS)
    {
        Room room;
        room.x = rand() % (MAP_SIZE - MAX_ROOM_SIZE - 1) + 1;
        room.y = rand() % (MAP_SIZE - MAX_ROOM_SIZE - 1) + 1;
        room.width = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
        room.height = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;

        if (!checkRoomOverlap(rooms, totalRooms, room))
        {
            placeRoom(map, room);
            rooms[totalRooms] = room;
            totalRooms++;
        }
    }
}

int main()
{
    Tile map[MAP_SIZE][MAP_SIZE];
    initMap(map);
    srand(time(NULL));
    generateMap(map);
    printMap(map);
    return 0;
}