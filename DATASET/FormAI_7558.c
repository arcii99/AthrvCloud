//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

// Character representations of the map tiles
#define TILE_DIRT ' '
#define TILE_WALL '#'
#define TILE_PLAYER '@'
#define TILE_ENEMY 'E'

char map[MAP_HEIGHT][MAP_WIDTH];
int player_x, player_y;

void generate_map() {
    // Use current time as seed for random number generator
    srand(time(0));
    
    // Generate random walls and floor tiles
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            int rand_value = rand() % 100;
            if (rand_value < 40) {
                map[i][j] = TILE_WALL;
            } else {
                map[i][j] = TILE_DIRT;
            }
        }
    }
    
    // Place the player in a random location
    do {
        player_x = rand() % MAP_WIDTH;
        player_y = rand() % MAP_HEIGHT;
    } while (map[player_y][player_x] == TILE_WALL);
    map[player_y][player_x] = TILE_PLAYER;
    
    // Place a few enemies in random locations
    for (int i = 0; i < 3; i++) {
        int enemy_x, enemy_y;
        do {
            enemy_x = rand() % MAP_WIDTH;
            enemy_y = rand() % MAP_HEIGHT;
        } while (map[enemy_y][enemy_x] == TILE_WALL || 
                 map[enemy_y][enemy_x] == TILE_PLAYER);
        map[enemy_y][enemy_x] = TILE_ENEMY;
    }
}

void print_map() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    generate_map();
    print_map();
    return 0;
}