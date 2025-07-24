//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_HEIGHT 20
#define MAP_WIDTH 50
#define MAX_ROOMS 6
#define MIN_ROOM_HEIGHT 3
#define MIN_ROOM_WIDTH 3
#define MAX_ROOM_HEIGHT 6
#define MAX_ROOM_WIDTH 10
#define PLAYER '@'
#define WALL '#'
#define FLOOR '.'

void print_map(char map[MAP_HEIGHT][MAP_WIDTH]);
void generate_map(char map[MAP_HEIGHT][MAP_WIDTH]);

int main()
{
    srand(time(NULL));
    
    char map[MAP_HEIGHT][MAP_WIDTH];
    
    generate_map(map);
    
    print_map(map);

    return 0;
}

void print_map(char map[MAP_HEIGHT][MAP_WIDTH])
{
    for(int i = 0; i < MAP_HEIGHT; i++)
    {
        for(int j = 0; j < MAP_WIDTH; j++)
        {
            printf("%c", map[i][j]);
        }
        
        printf("\n");
    }
}

void generate_map(char map[MAP_HEIGHT][MAP_WIDTH])
{
    // Fill map with walls
    for(int i = 0; i < MAP_HEIGHT; i++)
    {
        for(int j = 0; j < MAP_WIDTH; j++)
        {
            map[i][j] = WALL;
        }
    }
    
    // Create rooms
    int num_rooms = rand() % MAX_ROOMS + 1;
    int room_height, room_width, start_x, start_y;
    
    for(int i = 0; i < num_rooms; i++)
    {
        room_height = rand() % (MAX_ROOM_HEIGHT - MIN_ROOM_HEIGHT + 1) + MIN_ROOM_HEIGHT;
        room_width = rand() % (MAX_ROOM_WIDTH - MIN_ROOM_WIDTH + 1) + MIN_ROOM_WIDTH;
        start_x = rand() % (MAP_WIDTH - room_width - 1) + 1;
        start_y = rand() % (MAP_HEIGHT - room_height - 1) + 1;
        
        for(int j = start_y; j < start_y + room_height; j++)
        {
            for(int k = start_x; k < start_x + room_width; k++)
            {
                map[j][k] = FLOOR;
            }
        }
    }
    
    // Connect rooms with corridors
    int current_x, current_y, target_x, target_y;
    
    for(int i = 0; i < num_rooms - 1; i++)
    {
        current_x = rand() % (MAP_WIDTH - 1) + 1;
        current_y = rand() % (MAP_HEIGHT - 1) + 1;
        
        do
        {
            target_x = rand() % (MAP_WIDTH - 1) + 1;
            target_y = rand() % (MAP_HEIGHT - 1) + 1;
        } while((target_x == current_x) && (target_y == current_y));
        
        while(current_x != target_x)
        {
            map[current_y][current_x] = FLOOR;
            
            if(current_x < target_x)
            {
                current_x++;
            }
            else
            {
                current_x--;
            }
        }
        
        while(current_y != target_y)
        {
            map[current_y][current_x] = FLOOR;
            
            if(current_y < target_y)
            {
                current_y++;
            }
            else
            {
                current_y--;
            }
        }
    }
    
    // Place player in random room
    int player_x, player_y;
    
    do
    {
        player_x = rand() % (MAP_WIDTH - 1) + 1;
        player_y = rand() % (MAP_HEIGHT - 1) + 1;
    } while(map[player_y][player_x] != FLOOR);
    
    map[player_y][player_x] = PLAYER;
}