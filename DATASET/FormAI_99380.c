//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define constants for map size and player position
#define MAP_WIDTH 50
#define MAP_HEIGHT 30
#define PLAYER_MAX_HP 100

// Define a structure for the player
typedef struct player {
    int x, y;
    int hp;
} Player;

// Define a structure for a tile on the map
typedef struct tile {
    bool is_wall;
    bool is_explored;
} Tile;

// Define a function to generate the map using procedural generation
void generate_map(Tile map[MAP_HEIGHT][MAP_WIDTH], Player* player) {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate the walls of the map
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            // Determine if this tile should be a wall or not
            if (rand() % 100 < 40) {
                map[y][x].is_wall = true;
            } else {
                map[y][x].is_wall = false;
            }
            
            // Initialize other properties
            map[y][x].is_explored = false;
        }
    }
    
    // Place the player in a random location on the map
    do {
        player->x = rand() % MAP_WIDTH;
        player->y = rand() % MAP_HEIGHT;
    } while (map[player->y][player->x].is_wall);
    
    // Set the player's initial HP
    player->hp = PLAYER_MAX_HP;
}

int main() {
    // Initialize the map and the player
    Tile map[MAP_HEIGHT][MAP_WIDTH];
    Player player;
    
    // Generate the map
    generate_map(map, &player);
    
    // Print the map
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (player.x == x && player.y == y) {
                printf("@");
            } else if (map[y][x].is_explored) {
                if (map[y][x].is_wall) {
                    printf("#");
                } else {
                    printf(".");
                }
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}