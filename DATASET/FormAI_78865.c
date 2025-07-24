//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define game dimensions
#define MAP_WIDTH 40
#define MAP_HEIGHT 20

// Define character icons
#define PLAYER_ICON 'P'
#define WALL_ICON '#'
#define FLOOR_ICON '.'

// Declare the map array
char map[MAP_HEIGHT][MAP_WIDTH];

// Function to generate random map
void generate_map() {
    // Set seed for random number generator
    srand(time(NULL)); 
    
    // Generate random map
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (rand() % 100 < 40) {
                map[y][x] = WALL_ICON;
            } else {
                map[y][x] = FLOOR_ICON;
            }
        }
    }
}

// Function to print map
void print_map() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Generate random map
    generate_map();
    
    // Place player in center of map
    map[MAP_HEIGHT / 2][MAP_WIDTH / 2] = PLAYER_ICON;
    
    // Print map
    print_map();
    
    return 0;
}