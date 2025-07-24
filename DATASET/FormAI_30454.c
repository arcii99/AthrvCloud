//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 40
#define MAP_HEIGHT 20
#define WALL_TILE '#'
#define FLOOR_TILE ' '

void generate_map(char map[][MAP_WIDTH]) {
    srand(time(NULL));
    int i, j;
    for(i = 0; i < MAP_HEIGHT; i++) {
        for(j = 0; j < MAP_WIDTH; j++) {
            if(rand() % 100 < 40) {
                map[i][j] = WALL_TILE;
            }
            else {
                map[i][j] = FLOOR_TILE;
            }
        }
    }
}

void print_map(char map[][MAP_WIDTH]) {
    int i, j;
    for(i = 0; i < MAP_HEIGHT; i++) {
        for(j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char game_map[MAP_HEIGHT][MAP_WIDTH];
    generate_map(game_map);
    print_map(game_map);
    return 0;
}