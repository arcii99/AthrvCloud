//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20

typedef enum _tile_type_t {
    TILE_EMPTY,
    TILE_WALL,
    TILE_FLOOR,
    TILE_STAIRS_UP,
    TILE_STAIRS_DOWN
} tile_type_t;

typedef struct _tile_t {
    tile_type_t type;
    int is_visible;
} tile_t;

typedef struct _level_t {
    int level_number;
    tile_t map[WIDTH][HEIGHT];
} level_t;

void generate_level(level_t* level) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            level->map[x][y].type = TILE_WALL;
            level->map[x][y].is_visible = 0;
        }
    }

    // Generate floors and walls
    for (int y = 1; y < HEIGHT - 1; ++y) {
        for (int x = 1; x < WIDTH - 1; ++x) {
            if (rand() % 100 < 40) {
                level->map[x][y].type = TILE_FLOOR;
            } else {
                level->map[x][y].type = TILE_WALL;
            }

            level->map[x][y].is_visible = 0;
        }
    }

    // Generate stairs
    int stairs_up_x = rand() % (WIDTH - 2) + 1;
    int stairs_up_y = rand() % (HEIGHT - 2) + 1;
    level->map[stairs_up_x][stairs_up_y].type = TILE_STAIRS_UP;

    int stairs_down_x = rand() % (WIDTH - 2) + 1;
    int stairs_down_y = rand() % (HEIGHT - 2) + 1;
    level->map[stairs_down_x][stairs_down_y].type = TILE_STAIRS_DOWN;
}

void print_level(const level_t* level) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            switch (level->map[x][y].type) {
            case TILE_EMPTY:
                printf(" ");
                break;
            case TILE_WALL:
                printf("#");
                break;
            case TILE_FLOOR:
                printf(".");
                break;
            case TILE_STAIRS_UP:
                printf("<");
                break;
            case TILE_STAIRS_DOWN:
                printf(">");
                break;
            }
        }

        printf("\n");
    }
}

int main(void) {
    level_t level;

    srand(time(NULL));

    generate_level(&level);
    print_level(&level);

    return 0;
}