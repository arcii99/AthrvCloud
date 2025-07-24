//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

// Define constants for different cell types
enum CELL_TYPE {
    FLOOR,
    WALL,
};

// Define struct for game map
struct GameMap {
    enum CELL_TYPE cells[HEIGHT][WIDTH];
};

// Initialize game map with random values
void init_map(struct GameMap *map) {
    srand(time(NULL));
    for(int y=0; y<HEIGHT; y++) {
        for(int x=0; x<WIDTH; x++) {
            int rand_num = rand() % 100;
            if(rand_num < 40) {
                map->cells[y][x] = WALL;
            } else {
                map->cells[y][x] = FLOOR;
            }
        }
    }
}

// Print game map
void print_map(struct GameMap *map) {
    for(int y=0; y<HEIGHT; y++) {
        for(int x=0; x<WIDTH; x++) {
            if(map->cells[y][x] == WALL) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    struct GameMap map;

    init_map(&map);
    print_map(&map);

    return 0;
}