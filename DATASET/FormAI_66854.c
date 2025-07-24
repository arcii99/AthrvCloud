//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: scientific
/* ROGUE-LIKE GAME WITH PROCEDURAL GENERATION EXAMPLE */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 10

typedef struct {
    int x;
    int y;
} position;

typedef struct {
    int map[MAP_HEIGHT][MAP_WIDTH];
    position player_pos;
    position exit_pos;
} game_map;

void print_map(game_map* map) {
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            if (map->player_pos.x == j && map->player_pos.y == i) {
                printf("@");
            } else if (map->exit_pos.x == j && map->exit_pos.y == i) {
                printf("E");
            } else if (map->map[i][j] == 1) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

void generate_map(game_map* map, int num_obstacles) {
    int i, j, k;
    srand(time(NULL));
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            map->map[i][j] = 0;
        }
    }
    /* Generate obstacles */
    for (k = 0; k < num_obstacles; k++) {
        int x = rand() % MAP_WIDTH;
        int y = rand() % MAP_HEIGHT;
        map->map[y][x] = 1;
    }
    /* Set player position */
    do {
        map->player_pos.x = rand() % MAP_WIDTH;
        map->player_pos.y = rand() % MAP_HEIGHT;
    } while (map->map[map->player_pos.y][map->player_pos.x] == 1);
    /* Set exit position */
    do {
        map->exit_pos.x = rand() % MAP_WIDTH;
        map->exit_pos.y = rand() % MAP_HEIGHT;
    } while(map->map[map->exit_pos.y][map->exit_pos.x] == 1 
            || (map->exit_pos.x == map->player_pos.x && map->exit_pos.y == map->player_pos.y));
}

int main() {
    game_map map;
    int num_obstacles = 25;
    generate_map(&map, num_obstacles);
    print_map(&map);

    return 0;
}