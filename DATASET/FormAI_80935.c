//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10

void generate_map(int map[MAP_SIZE][MAP_SIZE]) {
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Generate the map
    for (int x = 0; x < MAP_SIZE; x++) {
        for (int y = 0; y < MAP_SIZE; y++) {
            // For each tile, randomly choose between 0 and 1
            int tile_type = rand() % 2;
            
            // Set the tile in the map
            map[x][y] = tile_type;
        }
    }
}

int main() {
    // Create the map array
    int map[MAP_SIZE][MAP_SIZE];
    
    // Generate the map
    generate_map(map);
    
    // Print the map
    for (int x = 0; x < MAP_SIZE; x++) {
        for (int y = 0; y < MAP_SIZE; y++) {
            printf("%d ", map[x][y]);
        }
        printf("\n");
    }
    
    return 0;
}