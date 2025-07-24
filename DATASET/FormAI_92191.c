//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20
#define MAX_ROOMS 6
#define MIN_ROOM_WIDTH 4
#define MIN_ROOM_HEIGHT 3

typedef struct
{
    int x, y, w, h;
} Room;

int map[WIDTH][HEIGHT];

void generate_map()
{
    //Fill with walls
    for(int i = 0; i < WIDTH; i++)
        for(int j = 0; j < HEIGHT; j++)
            map[i][j] = 1;

    //Seed random number generator
    srand(time(NULL));

    Room rooms[MAX_ROOMS];
    int room_count = 0;

    //Generate rooms
    for(int i = 0; i < MAX_ROOMS; i++)
    {
        int x = rand() % (WIDTH - MIN_ROOM_WIDTH - 1) + 1;
        int y = rand() % (HEIGHT - MIN_ROOM_HEIGHT - 1) + 1;
        int w = rand() % (WIDTH - x - MIN_ROOM_WIDTH) + MIN_ROOM_WIDTH;
        int h = rand() % (HEIGHT - y - MIN_ROOM_HEIGHT) + MIN_ROOM_HEIGHT;

        //Check if new room overlaps with an existing room
        int overlaps = 0;
        for(int j = 0; j < room_count; j++)
        {
            if(x < rooms[j].x + rooms[j].w &&
               x + w > rooms[j].x &&
               y < rooms[j].y + rooms[j].h &&
               y + h > rooms[j].y)
            {
                overlaps = 1;
                break;
            }
        }

        if(!overlaps)
        {
            Room new_room = {x, y, w, h};

            //Add new room to map
            for(int j = x; j < x + w; j++)
                for(int k = y; k < y + h; k++)
                    map[j][k] = 0;

            rooms[room_count++] = new_room;
        }
    }

    //Generate corridors
    for(int i = 0; i < room_count-1; i++)
    {
        int x1 = rooms[i].x + rooms[i].w/2;
        int y1 = rooms[i].y + rooms[i].h/2;
        int x2 = rooms[i+1].x + rooms[i+1].w/2;
        int y2 = rooms[i+1].y + rooms[i+1].h/2;

        //Add horizontal corridor
        for(int j = x1; j != x2; j += (x1 < x2) ? 1 : -1)
            map[j][y1] = 0;

        //Add vertical corridor
        for(int k = y1; k != y2; k += (y1 < y2) ? 1 : -1)
            map[x2][k] = 0;
    }
}

int main()
{
    generate_map();

    //Print map
    for(int j = 0; j < HEIGHT; j++)
    {
        for(int i = 0; i < WIDTH; i++)
        {
            switch(map[i][j])
            {
                case 0: printf("."); break;
                case 1: printf("#"); break;
            }
        }
        printf("\n");
    }

    return 0;
}