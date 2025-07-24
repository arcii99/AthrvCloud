//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: mathematical
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAP_WIDTH 30
#define MAP_HEIGHT 20

#define TILE_FLOOR ' '
#define TILE_WALL  '#'

#define MAX_FEATURES 10

void generate_map(char map[MAP_HEIGHT][MAP_WIDTH])
{
    // Initialize map with walls
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            map[y][x] = TILE_WALL;
        }
    }

    // Randomly add features (floors) to the map
    srand(time(NULL));  // Seed random number generator

    int num_features = rand() % (MAX_FEATURES + 1);

    for (int i = 0; i < num_features; i++)
    {
        int x = rand() % MAP_WIDTH;
        int y = rand() % MAP_HEIGHT;
        map[y][x] = TILE_FLOOR;
    }
}

int main()
{
    char map[MAP_HEIGHT][MAP_WIDTH];

    // Generate the map
    generate_map(map);

    // Print the map
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }

    return 0;
}