//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 32
#define MAP_HEIGHT 16

typedef enum {
    FLOOR,
    WALL
} Tile;

typedef struct {
    int x;
    int y;
} Point;

Tile level[MAP_HEIGHT][MAP_WIDTH];
Point player;

void generate_map() {
    srand(time(NULL));
    int i, j;

    // Initialize the level to all walls
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            level[i][j] = WALL;
        }
    }

    // Set a random starting position for the player
    player.x = rand() % MAP_WIDTH;
    player.y = rand() % MAP_HEIGHT;

    // Define the parameters for the cave generation algorithm
    int num_iterations = 5;
    int threshold = 4;

    // Perform the cave generation algorithm
    for (i = 0; i < num_iterations; i++) {
        int x, y;

        for (y = 1; y < MAP_HEIGHT-1; y++) {
            for (x = 1; x < MAP_WIDTH-1; x++) {
                int wall_count = 0;

                // Count the number of walls and floors in the 3x3 grid centered on (x,y)
                int dx, dy;
                for (dy = -1; dy <= 1; dy++) {
                    for (dx = -1; dx <= 1; dx++) {
                        if (level[y+dy][x+dx] == WALL) {
                            wall_count++;
                        }
                    }
                }

                // If more than `threshold` of the tiles in the 3x3 grid are walls, set this tile to a wall
                if (wall_count > threshold) {
                    level[y][x] = WALL;
                } else {
                    level[y][x] = FLOOR;
                }
            }
        }
    }

    // Set the player's starting tile to a floor
    level[player.y][player.x] = FLOOR;
}

void print_map() {
    int i, j;

    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            if (i == player.y && j == player.x) {
                printf("@");
            } else if (level[i][j] == WALL) {
                printf("#");
            } else {
                printf(".");
            }
        }

        printf("\n");
    }
}

int main() {
    generate_map();
    print_map();

    return 0;
}