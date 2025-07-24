//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAP_WIDTH 80
#define MAP_HEIGHT 24

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

typedef enum {
    EMPTY,
    WALL,
    FLOOR,
    PLAYER
} Tile;

typedef struct {
    int x;
    int y;
} Point;

Tile map[MAP_HEIGHT][MAP_WIDTH];
Point player_pos;

void generate_map() {
    srand(time(NULL));
    for(int y=0; y<MAP_HEIGHT; y++) {
        for(int x=0; x<MAP_WIDTH; x++) {
            int rand_val = rand() % 100;
            if (rand_val < 40) {
                map[y][x] = WALL;
            } else {
                map[y][x] = FLOOR;
            }
        }
    }
}

void print_map() {
    for(int y=0; y<MAP_HEIGHT; y++) {
        for(int x=0; x<MAP_WIDTH; x++) {
            if (player_pos.x == x && player_pos.y == y) {
                printf("@");
            } else if (map[y][x] == WALL) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

bool is_walkable(int x, int y) {
    if (x < 0 || y < 0 || x >= MAP_WIDTH || y >= MAP_HEIGHT) {
        return false;
    }
    if (map[y][x] == WALL) {
        return false;
    }
    return true;
}

void move_player(char direction) {
    int new_x = player_pos.x;
    int new_y = player_pos.y;
    if (direction == UP) {
        new_y--;
    } else if (direction == DOWN) {
        new_y++;
    } else if (direction == LEFT) {
        new_x--;
    } else if (direction == RIGHT) {
        new_x++;
    }

    if (is_walkable(new_x, new_y)) {
        player_pos.x = new_x;
        player_pos.y = new_y;
    }
}

int main() {
    generate_map();
    player_pos.x = MAP_WIDTH / 2;
    player_pos.y = MAP_HEIGHT / 2;

    while (true) {
        system("clear");
        print_map();

        printf("Move with WASD: ");
        char input = tolower(getchar());
        while (getchar() != '\n'); // Clear the input buffer

        move_player(input);
    }
    return 0;
}