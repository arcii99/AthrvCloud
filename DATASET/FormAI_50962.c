//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 30
#define MAP_HEIGHT 20

// Function to create a new random map
void generate_map(char map[MAP_HEIGHT][MAP_WIDTH]) {
    // Initialize the random seed
    srand(time(NULL));
    
    // Loop through each cell of the map
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            // Generate a random number between 0 and 100
            int rand_num = rand() % 100;
            
            // Determine the type of terrain for the current cell based on the random number
            if (rand_num < 40) {
                map[y][x] = '.';
            } else if (rand_num < 60) {
                map[y][x] = '#';
            } else if (rand_num < 80) {
                map[y][x] = '~';
            } else {
                map[y][x] = 'T';
            }
        }
    }
}

// Function to print the current map
void print_map(char map[MAP_HEIGHT][MAP_WIDTH]) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            printf("%c ", map[y][x]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    char map[MAP_HEIGHT][MAP_WIDTH];
    generate_map(map);
    print_map(map);
    return 0;
}