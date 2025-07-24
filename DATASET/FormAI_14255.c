//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10
#define MAX_ROOMS 6
#define MAX_ROOM_SIZE 6
#define MIN_ROOM_SIZE 3

struct Room
{
    int x, y, w, h;
};

char map[WIDTH][HEIGHT];

void createMap();
void placeRooms(struct Room rooms[]);
void placeRoom(struct Room room);
void connectRooms(struct Room rooms[]);
void addBorders();
void printMap();

int main()
{
    srand(time(NULL));
    createMap();
    printMap();
}

void createMap()
{
    struct Room rooms[MAX_ROOMS];

    for(int i = 0; i < WIDTH; i++)
    {
        for(int j = 0; j < HEIGHT; j++)
        {
            map[i][j] = '#';
        }
    }

    placeRooms(rooms);
    connectRooms(rooms);
    addBorders();
}

void placeRooms(struct Room rooms[])
{
    for(int i = 0; i < MAX_ROOMS; i++)
    {
        int x = rand() % (WIDTH - MAX_ROOM_SIZE - 1) + 1;
        int y = rand() % (HEIGHT - MAX_ROOM_SIZE - 1) + 1;
        int w = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
        int h = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;

        struct Room room = {x, y, w, h};
        placeRoom(room);

        rooms[i] = room;
    }
}

void placeRoom(struct Room room)
{
    for(int i = room.x; i < room.x + room.w; i++)
    {
        for(int j = room.y; j < room.y + room.h; j++)
        {
            map[i][j] = '.';
        }
    }
}

void connectRooms(struct Room rooms[])
{
    for(int i = 0; i < MAX_ROOMS - 1; i++)
    {
        struct Room room1 = rooms[i];
        struct Room room2 = rooms[i+1];

        int x1 = room1.x + rand() % room1.w;
        int y1 = room1.y + rand() % room1.h;
        int x2 = room2.x + rand() % room2.w;
        int y2 = room2.y + rand() % room2.h;

        if(x2 < x1)
        {
            int temp = x1;
            x1 = x2;
            x2 = temp;
        }

        if(y2 < y1)
        {
            int temp = y1;
            y1 = y2;
            y2 = temp;
        }

        for(int j = x1; j <= x2; j++)
        {
            map[j][y1] = '.';
        }

        for(int j = y1; j <= y2; j++)
        {
            map[x2][j] = '.';
        }
    }
}

void addBorders()
{
    for(int i = 0; i < WIDTH; i++)
    {
        map[i][0] = '#';
        map[i][HEIGHT-1] = '#';
    }

    for(int i = 0; i < HEIGHT; i++)
    {
        map[0][i] = '#';
        map[WIDTH-1][i] = '#';
    }
}

void printMap()
{
    for(int i = 0; i < WIDTH; i++)
    {
        for(int j = 0; j < HEIGHT; j++)
        {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}