//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 30
#define MAX_ROOMS 10
#define MIN_ROOM_SIZE 4
#define MAX_ROOM_SIZE 10

char map[MAP_HEIGHT][MAP_WIDTH];

typedef struct _room
{
    int x, y;
    int width, height;
} Room;

Room* rooms[MAX_ROOMS];
int num_rooms = 0;

void fill_map(char fill_char)
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            map[y][x] = fill_char;
        }
    }
}

void print_map()
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}

void create_room(Room* room)
{
    for (int y = room->y; y < room->y + room->height; y++)
    {
        for (int x = room->x; x < room->x + room->width; x++)
        {
            map[y][x] = '.';
        }
    }
}

int does_room_overlap(Room* room, int x, int y, int width, int height)
{
    if (x < room->x + room->width + 2 &&
        x + width + 2 > room->x &&
        y < room->y + room->height + 2 &&
        y + height + 2 > room->y)
    {
        return 1;
    }
    return 0;
}

void create_rooms()
{
    srand(time(NULL));
    for (int i = 0; i < MAX_ROOMS; i++)
    {
        int x = rand() % (MAP_WIDTH - MAX_ROOM_SIZE - 1) + 1;
        int y = rand() % (MAP_HEIGHT - MAX_ROOM_SIZE - 1) + 1;
        int width = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
        int height = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;

        Room* new_room = (Room*)malloc(sizeof(Room));
        new_room->x = x;
        new_room->y = y;
        new_room->width = width;
        new_room->height = height;

        int overlap = 0;
        for (int j = 0; j < num_rooms; j++)
        {
            if (does_room_overlap(rooms[j], x, y, width, height))
            {
                overlap = 1;
                break;
            }
        }

        if (!overlap)
        {
            create_room(new_room);
            rooms[num_rooms] = new_room;
            num_rooms++;
        }
        else
        {
            free(new_room);
        }
    }
}

int main()
{
    fill_map('#');
    create_rooms();
    print_map();
    return 0;
}