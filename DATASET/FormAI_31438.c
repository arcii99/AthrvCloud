//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 80
#define MAP_HEIGHT 24

char map[MAP_WIDTH][MAP_HEIGHT];

// Function to create a new map
void create_map() {
    int x, y;
    for (y = 0; y < MAP_HEIGHT; y++) {
        for (x = 0; x < MAP_WIDTH; x++) {
            // Add walls around the edges
            if (x == 0 || y == 0 || x == MAP_WIDTH - 1 || y == MAP_HEIGHT - 1) {
                map[x][y] = '#';
            } else {
                // Randomly generate floors and walls
                if (rand() % 100 < 40) {
                    map[x][y] = '#';
                } else {
                    map[x][y] = '.';
                }
            }
        }
    }
}

// Function to print the map to the console
void print_map() {
    int x, y;
    for (y = 0; y < MAP_HEIGHT; y++) {
        for (x = 0; x < MAP_WIDTH; x++) {
            printf("%c", map[x][y]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    create_map(); // Generate the map
    print_map(); // Display the map
    return 0;
}