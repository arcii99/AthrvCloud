//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20
#define MAX_ROOMS 6
#define MIN_ROOM_SIZE 4
#define MAX_ROOM_SIZE 8

int level[WIDTH][HEIGHT];

void printLevel()
{
    int x, y;
    for (y=0; y<HEIGHT; y++)
    {
        for (x=0; x<WIDTH; x++)
        {
            if (level[x][y]==1)
                printf("#");
            else if (level[x][y]==2)
                printf(".");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void generateLevel()
{
    int i;
    int numRooms = (rand() % MAX_ROOMS) + 1;
    int roomX, roomY, roomWidth, roomHeight;
    int x, y, offset;
    
    // fill level with walls
    for (y=0; y<HEIGHT; y++)
        for (x=0; x<WIDTH; x++)
            level[x][y] = 1;
    
    // add rooms
    for (i=0; i<numRooms; i++)
    {
        roomX = (rand() % (WIDTH-MAX_ROOM_SIZE-1))+1;
        roomY = (rand() % (HEIGHT-MAX_ROOM_SIZE-1))+1;
        roomWidth = (rand() % (MAX_ROOM_SIZE-MIN_ROOM_SIZE))+MIN_ROOM_SIZE;
        roomHeight = (rand() % (MAX_ROOM_SIZE-MIN_ROOM_SIZE))+MIN_ROOM_SIZE;
        
        // check if room collides with existing room
        for (y=roomY-1; y<=roomY+roomHeight; y++)
            for (x=roomX-1; x<=roomX+roomWidth; x++)
                if (level[x][y]!=1)
                    goto skip_room;
        
        // add room
        for (y=roomY; y<roomY+roomHeight; y++)
            for (x=roomX; x<roomX+roomWidth; x++)
                level[x][y] = 0;
        
        skip_room:
        continue;
    }
    
    // add corridors between rooms
    for (i=0; i<numRooms-1; i++)
    {
        int x1, y1, x2, y2;
        
        x1 = (rand() % (roomWidth-0))+roomX;
        y1 = (rand() % (roomHeight-0))+roomY;
        x2 = (rand() % (roomWidth-0))+roomX;
        y2 = (rand() % (roomHeight-0))+roomY;
        
        if (rand()%2)
        {
            offset = (x1<x2) ? 1 : -1;
            for (x=x1; x!=x2+offset; x+=offset)
                level[x][y1] = 0;
            offset = (y1<y2) ? 1 : -1;
            for (y=y1; y!=y2+offset; y+=offset)
                level[x2][y] = 0;
        }
        else
        {
            offset = (y1<y2) ? 1 : -1;
            for (y=y1; y!=y2+offset; y+=offset)
                level[x1][y] = 0;
            offset = (x1<x2) ? 1 : -1;
            for (x=x1; x!=x2+offset; x+=offset)
                level[x][y2] = 0;
        }
    }
}

int main()
{
    srand(time(NULL));
    generateLevel();
    printLevel();
    return 0;
}